class player;
int temp , bat1 , bat2 , bow ;
string team1 , team2 ;
void overall(player team[] , player taem [] , int size);
void manual_toss();
void simulated_toss(); 
void cho_by_team1();
void cho_by_team2();
void team_2_inning(player* , player* ,  int );
void team_1_inning(player* , player* ,  int );
void next_2_batsman(player taem[] , int size );
void next_1_batsman(player team[] , int size );
void change_striker();
void next_bowler(player team[] , int size);
class player
{   public:
	string name;
	int scored , score , wickets , overs , ballsfaced , dotballs ;
	player() { scored=0 ; score =0 ; wickets =0 ; ballsfaced=0 ; dotballs =0 ; overs =0 ;	}
    void getname();
	void addscored(int);
    void addscore(int);
    void addwicket();
    void adddotball();
    void totalballsfaced();
    void addovers();
    void operator = (player p )
    {
    name=p.name; scored =p.scored; score =p.score; wickets=p.wickets; overs=p.overs; ballsfaced = p.ballsfaced; dotballs = p.dotballs;
	}
};
class Base : public player
{
    public:
   player findBestBowler(player team[]) {
    int maxWickets = 0;
    player bestBowler;
    for (int i = 0; i < 11; i++) {
      if (team[i].wickets > maxWickets) {
        maxWickets = team[i].wickets;
        bestBowler = team[i];
      }
    }
    return bestBowler;
  }
  // Function to determine the best batter based on runs scored
  player findBestBatter(player team[]) {
    int maxScore = 0;
    player bestBatter;
    for (int i = 0; i < 11; i++) {
      if (team[i].scored > maxScore) {
        maxScore = team[i].scored;
        bestBatter = team[i];
      }
    }
    return bestBatter;
  }
      // Function to display the match summary including best bowler and batter
  void displaySummary(player team1[], player team2[]) {
    player bestBowlerTeam1 = findBestBowler(team1);
    player bestBatterTeam1 = findBestBatter(team1);
    player bestBowlerTeam2 = findBestBowler(team2);
    player bestBatterTeam2 = findBestBatter(team2);

    cout << "Match Summary: \n";
    cout << "Team 1: " << team1[0].name << endl; // Assuming team name is stored in the first player's name
    cout << "  - Best Bowler: " << bestBowlerTeam1.name << " with " << bestBowlerTeam1.wickets << " wickets" << endl;
    cout << "  - Best Batter: " << bestBatterTeam1.name << " with " << bestBatterTeam1.scored << " runs" << endl;

    cout << "Team 2: " << team2[0].name << endl; // Assuming team name is stored in the first player's name
    cout << "  - Best Bowler: " << bestBowlerTeam2.name << " with " << bestBowlerTeam2.wickets << " wickets" << endl;
    cout << "  - Best Batter: " << bestBatterTeam2.name << " with " << bestBatterTeam2.scored << " runs" << endl;
    system("cls");
    system("pause");
    if(bestBatterTeam1.wickets>bestBatterTeam2.wickets)
    {
        cout<<" Best Bowler of the match is "<<bestBatterTeam1.name<<endl;
    }
    else
    {
        cout<<" Best Bowler of the match is "<<bestBatterTeam2.name<<endl;
    }
    if (bestBatterTeam1.scored>bestBatterTeam2.scored)
    {
        cout<<" Best batter of the match is "<<bestBatterTeam1.name<<endl;
    }
    else
    {
     cout<<" Best batter of the match is "<<bestBatterTeam2.name<<endl;   
    }
    
  }

    
};


void player::totalballsfaced()
{   ballsfaced = ballsfaced+1 ; }
void player::addscored(int s)
{   
	ofstream outputF;
    string filename = "Teamdata.txt";
	outputF.open(filename, ios::app);
	scored = scored + s ; 
	outputF<<" scored : "<<scored<<endl; 
	outputF.close();  
}   
void player::addwicket()
{  
	ofstream output;
    string filename = "Teamdata.txt";
	output.open(filename, ios::app);
	wickets = wickets + 1 ;
	output<<"wickets : "<<wickets<<endl;
	output.close();
} 
void player::addscore(int s)
{
	ofstream outputFi;
    string filename = "Teamdata.txt";
	outputFi.open(filename, ios::app);
    score = score + s ; 
	outputFi<<" score = " <<score<<endl; 
	outputFi.close();     
} 
void player::adddotball()
{   dotballs = dotballs + 1 ;   }
void player::addovers()
{  
	ofstream outpu;
    string filename = "Teamdata.txt";
	outpu.open(filename, ios::app);
	overs = overs + 1 ; 
	outpu<<"Overs : "<<overs<<endl;
	outpu.close();
}
void player::getname()
{   getline(cin , name) ;       } 
	player team [11];
	player taem [11];
    player butter , batter , bowler ;
    int total_1 = 0, extra_1 = 0 , total_2 = 0 , extra_2 = 0 ,  over =0 ;