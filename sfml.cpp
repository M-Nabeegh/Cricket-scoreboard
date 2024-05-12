#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

class CricketMatch {
private:
    struct Player {
        std::string name;
        int runs = 0;
        int balls = 0;
        bool isOut = false;
    };

    struct Bowler {
        std::string name;
        int runsGiven = 0;
        int wickets = 0;
        int ballsBowled = 0;
    };

    sf::Font font;
    sf::Text title, teamDisplay, totalScoreDisplay, overDisplay, playerStats, bowlerStats;
    sf::RectangleShape scoreButtons[9];
    std::vector<sf::Text> buttonLabels;
    std::vector<Player> players;
    std::vector<Bowler> bowlers;
    int totalScore = 0, currentPlayer = 0, currentBowler = 0;
    int overs, currentOver = 0, ballsInOver = 0;
    bool firstInnings = true;

    void prepareDisplay() {
        if (!font.loadFromFile("arial.ttf")) {
            std::cerr << "Error loading font 'arial.ttf'!" << std::endl;
            exit(1);
        }

        title.setFont(font);
        title.setString("Cricket Match Simulation");
        title.setCharacterSize(30);
        title.setPosition(20, 10);
        title.setFillColor(sf::Color::White);

        teamDisplay.setFont(font);
        teamDisplay.setCharacterSize(24);
        teamDisplay.setPosition(20, 50);
        teamDisplay.setFillColor(sf::Color::White);

        totalScoreDisplay.setFont(font);
        totalScoreDisplay.setCharacterSize(24);
        totalScoreDisplay.setPosition(300, 50);
        totalScoreDisplay.setFillColor(sf::Color::White);

        overDisplay.setFont(font);
        overDisplay.setCharacterSize(24);
        overDisplay.setPosition(500, 50);
        overDisplay.setFillColor(sf::Color::White);

        playerStats.setFont(font);
        playerStats.setCharacterSize(20);
        playerStats.setPosition(20, 450);
        playerStats.setFillColor(sf::Color::White);

        bowlerStats.setFont(font);
        bowlerStats.setCharacterSize(20);
        bowlerStats.setPosition(400, 450);
        bowlerStats.setFillColor(sf::Color::White);

        prepareButtons();
        updateDisplays();
    }

    void prepareButtons() {
        std::vector<std::string> labels = {"1", "2", "3", "4", "5", "6", "Out", "NB", "Wide"};
        for (int i = 0; i < 9; i++) {
            scoreButtons[i].setSize(sf::Vector2f(50, 50));
            scoreButtons[i].setFillColor(sf::Color(100, 100, 250));
            scoreButtons[i].setPosition(20 + (i % 3) * 60, 300 + (i / 3) * 60);

            sf::Text label(font, labels[i], 24);
            label.setPosition(25 + (i % 3) * 60, 305 + (i / 3) * 60);
            label.setFillColor(sf::Color::White);
            buttonLabels.push_back(label);
        }
    }

    void updateDisplays() {
        teamDisplay.setString(firstInnings ? "Team A" : "Team B");
        totalScoreDisplay.setString("Total Score: " + std::to_string(totalScore));
        overDisplay.setString("Overs: " + std::to_string(currentOver) + "." + std::to_string(ballsInOver) + "/" + std::to_string(overs));

        if (!players.empty()) {
            playerStats.setString("Batsman: " + players[currentPlayer].name + "\nRuns: " + std::to_string(players[currentPlayer].runs) + "\nBalls: " + std::to_string(players[currentPlayer].balls));
        }

        if (!bowlers.empty()) {
            bowlerStats.setString("Bowler: " + bowlers[currentBowler].name + "\nRuns Given: " + std::to_string(bowlers[currentBowler].runsGiven) + "\nWickets: " + std::to_string(bowlers[currentBowler].wickets));
        }
    }

public:
    CricketMatch(int totalOvers) : overs(totalOvers) {
        players = {{"Player 1"}, {"Player 2"}, {"Player 3"}, {"Player 4"}, {"Player 5"},
                   {"Player 6"}, {"Player 7"}, {"Player 8"}, {"Player 9"}, {"Player 10"}, {"Player 11"}};

        bowlers = {{"Bowler 1"}, {"Bowler 2"}, {"Bowler 3"}};

        prepareDisplay();
    }

    void checkClick(sf::Vector2f mousePos) {
        for (int i = 0; i < 9; i++) {
            if (scoreButtons[i].getGlobalBounds().contains(mousePos)) {
                processRunOptions(i);
                break;
            }
        }
    }

    void processRunOptions(int index) {
        int runs = (index < 6) ? index + 1 : 0;
        if (index == 6) { // Out
            players[currentPlayer].isOut = true;
            nextPlayer();
            bowlers[currentBowler].wickets++;
        } else if (index >= 7) { // No Ball or Wide
            totalScore += 1;
        } else { // Runs
            players[currentPlayer].runs += runs;
            players[currentPlayer].balls++;
            totalScore += runs;
            bowlers[currentBowler].runsGiven += runs;
            ballsInOver++;
        }

        if (ballsInOver == 6) {
            currentOver++;
            ballsInOver = 0;
            nextPlayer();
        }

        if (currentOver >= overs) {
            if (firstInnings) {
                switchInnings();
            } else {
                endMatch();
            }
        }

        updateDisplays();
    }

    void nextPlayer() {
        do {
            currentPlayer = (currentPlayer + 1) % players.size();
        } while (players[currentPlayer].isOut);
    }

    void switchInnings() {
        firstInnings = !firstInnings;
        totalScore = 0;
        currentOver = 0;
        ballsInOver = 0;
        currentPlayer = 0;
        currentBowler = 0;
        for (auto &player : players) {
            player.isOut = false;
            player.runs = 0;
            player.balls = 0;
        }
        for (auto &bowler : bowlers) {
            bowler.runsGiven = 0;
            bowler.wickets = 0;
            bowler.ballsBowled = 0;
        }
        updateDisplays();
    }

    void endMatch() {
        std::cout << "Match ended. Final Score: " << totalScore << std::endl;
        // Add any end of match summaries or actions here
    }

    void draw(sf::RenderWindow& window) {
        window.draw(title);
        window.draw(teamDisplay);
        window.draw(totalScoreDisplay);
        window.draw(overDisplay);
        window.draw(playerStats);
        window.draw(bowlerStats);
        for (auto& button : scoreButtons) {
            window.draw(button);
        }
        for (auto& label : buttonLabels) {
            window.draw(label);
        }
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cricket Scorecard Simulator", sf::Style::Close);
    CricketMatch match(2); // 2 overs for demonstration

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    match.checkClick(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
                }
            }
        }

        window.clear(sf::Color::Black);
        match.draw(window);
        window.display();
    }

    return 0;
}