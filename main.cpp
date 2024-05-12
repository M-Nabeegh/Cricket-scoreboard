#include<iostream>
#include<string>
#include <stdlib.h>
#include <ctime>
#include<fstream>
using namespace std;
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
int main()
{
    ofstream outputFile;
    string filename = "Teamdata.txt";
    outputFile.open(filename);
     if (!outputFile.is_open()) 
    {
        cout << "Error opening file: " << filename << endl;
        return 1;
    }
	cout<<"			                        88              88                             "<<endl;
	cout<<"		          	               ''''             88                      dd     "<<endl;
	cout<<"			            ,d                          88     d8               88     "<<endl;
	cout<<"			 ,adPPYba,  ,b,dPPYba,  88   ,adPPYba,  88   ,d8   ,adPPYba,  88Mm88  "<<endl;
	cout<<"			a8      ''   88P'   'Y8 88  a8          88 ,a8''  a8P  ]  88    88     "<<endl;
	cout<<"			8b          88          88  8b          8888[     8PP  & '&     88    & "<<endl;
	cout<<"			8a,     ,aa 88          88  ''8a,   ,aa 88`Yba,   8b            88   &&  "<<endl;
	cout<<"		  	 `'Ybbd8''  88          88   `'Ybbd8'   88   `Y8a   Ybbd88''  88yy88    "<<endl<<endl<<endl<<endl;
	cout<<"			*******Welcome to GIKI's  Cricket Score Card********"<<endl;
	cout<<"			*******    Let's Have a Thrilling Match   ********"<<endl<<endl<<endl<<endl;
    system("pause");
    system("cls");
	cout<<"Enter Overs : "<<endl;
    cin>>over;
    player striker , non_striker;
    cout<<"Enter Team 1 name: ";
    cin>>team1;
    outputFile<<"Team 1 name: "<<team1<<endl;
    cout<<"Enter Team 2 name: ";
    cin>>team2;
	 outputFile<<"Team 2 name: "<<team2<<endl;
	player *team_1 = team;
	player *team_2 = taem;
    overall(team_1 , team_2 , 11);
    system("cls"); 
    cout<<team1<<" Total : 		"<<total_1<<" 	Extras : 	"<<extra_1<<endl<<endl;
	cout<<team2<<" Total : 		"<<total_2<<" 	Extras : 	"<<extra_2<<endl<<endl;	     
    
    Base bb;
    bb.displaySummary( team,  taem);
     if (total_1 < total_2)
    cout<<"---------------- "<<team2<<" has won the Match---------------- "<<endl;
    else 
	cout<<"---------------- "<<team1<<" has won the Match---------------- "<<endl;
    outputFile.close();
 return 0 ;        
}
    

void manual_toss ()
{  system("clas");
   here:
   cout<<"Enter 1 if "<<team1<<" won the toss & Enter 2 if "<<team2<<" won the toss !!!!"<<endl;
   cin>>temp;
   if (temp == 1)
{ 
   cho_by_team1();
}
  else if (temp == 2)
{
    cho_by_team2(); 
}}

void simulated_toss()
{   system("cls");
	srand(time(0));
	temp = rand();
	temp = temp%2;
	cout<<"Head for "<<team1<<" and tail for "<<team2<<endl;
	system("pause");
	if (temp == 0)
{
    cho_by_team1();
}
	else 
{
	cho_by_team2();
}
}
void cho_by_team1()
{  here:
   cout<<team1<<" has won the Toss !!!!"<<endl; 
   cout<<"what "<<team1<<" has decided to do .......\n Enter 1 for Batting \n Enter 2 for Bowling"<<endl;
   cin>>temp;
   if (temp ==1)
{
   cout<<team1<<" will Bat first !!!"<<endl;
   next_bowler (taem , 11) ;
   team_1_inning(team , taem , over);
   team_2_inning(team , taem , over);

} 
   else if (temp == 2)
{
    cout<<team1<<" will Bowl first !!!"<<endl;
    next_bowler (team , 11) ;
    team_2_inning(team , taem , over);
    team_1_inning(team , taem , over);    
}
   else
{ 
   cout<<"Wrong Input......."<<endl;
   system("pause");
   goto here;
}}

void cho_by_team2()
{  here:
   cout<<team2<<" has won the Toss !!!!"<<endl<<endl;
   cout<<"what "<<team2<<" has decided to do .......\n Enter 1 for Batting \n Enter 2 for Bowling"<<endl;
   cin>>temp;
   cout<<endl;
   if (temp ==1)
{  
   cout<<team2<<" will Bat first !!!"<<endl;
    next_bowler (team , 11) ; 
    team_2_inning(team , taem , over);
    team_1_inning(team , taem , over);
}
   else if (temp == 2)
{  
    cout<<team2<<" will Bowl first !!!"<<endl;
	next_bowler( taem , 11);
	team_1_inning(team , taem , over);
	team_1_inning(team , taem , over);
}
   else
{ 
   cout<<"Wrong Input......."<<endl;
   system("pause");
   goto here;	
}}
 
void next_2_batsman(player taem[] , int size )
{  
  cout<<"--------------Enter Player# and press Enter----------- "<<endl<<endl;
   team[bat1] = batter;
   team[bat2] = butter;
   cout<<team2<<" Players are....."<<endl;
   int j = 0 , i = 0;
   while(j<11)
{  cout<<"Player #"<<j+1<<" : "<<taem[j].name<<endl;
   j++;
} 
   cout<<endl;

   cout<<"Enter Striker #No: "<<endl;
   cin>>i;
   cout<<"NON-STRIKER #No: "<<endl;
   cin>>j;
   batter = taem[i-1];
   butter=  taem[j-1];
   bat1=i-1 ; bat2 = j-1; 
   cout<<"Striker : "<<batter.name<<endl;				
   cout<<"NON-Striker : "<<butter.name<<endl;
   system("cls");
}

void next_1_batsman(player team[] , int size )
{  
  team[bat1] = batter;
  team[bat2] = butter;

  cout<<"--------------Enter Player# and press Enter----------- "<<endl<<endl;
   int j = 0 , i = 0;
   cout<<team2<<" Players are....."<<endl;  
   while(j<11)
{  cout<<"Player #"<<j+1<<" : "<<team[j].name<<endl;
   j++;
} 
   cout<<endl;

   cout<<"Enter Striker #No: "<<endl;
   cin>>i;
   batter=team[i-1];
   bat1 = i-1;
   cout<<"NON-STRIKER #No: "<<endl;
   cin>>j;
   butter=team[j-1];
   bat2=j-1;
   cout<<"Striker : "<<batter.name<<endl;				
   cout<<"NON-Striker : "<<butter.name<<endl;
   system("cls");
}

void change_striker()
{
	player temp;
	temp = batter;
	cout<<temp.name<<"   "<<temp.scored<<endl;;
	batter=butter;
	butter = temp;
	cout<<"Striker Changed !!!!"<<endl;
	cout<<"STRIKER : "<<batter.name<<endl;
	cout<<"NON-STRIKER : "<<butter.name<<endl;
	system("pause");
	system("cls");
	
}

void next_bowler(player team[] , int size)
{  system("cls");
   cout<<"Choose the bowler Number....."<<endl;
   int j = 0 ;
   while(j<11)
{  cout<<"Player #"<<j+1<<" : "<<team[j].name<<endl;
   j++;
} 
  cout<<endl;
  cin>>j;
  bowler=team[j-1];
  bow = j-1;
  cout<<"Bowler Bowling : "<<bowler.name<<endl;
  system("pause");
  system("cls");
}
void overall(player team[] , player taem [] , int size)
{  
	ofstream outputFil;
    string filename = "Teamdata.txt";
	outputFil.open(filename, ios::app);
   system("cls");
   outputFil<<"Enter Name of players for team "<<team1<<endl;
   cout<<"Enter Name of players for team "<<team1<<endl;
   cin.ignore();
	for (int i=0 ; i<=10 ; i++)
{ 
    cout<<"#"<<i+1<<" player name : ";
	team[i].getname();
	outputFil<<"#"<<i+1<<" player name : "<<team[i].name<<endl;
}
   system("cls");
   outputFil<<"Enter Name of players for team "<<team2<<endl;
   cout<<"Enter Name of players for team "<<team2<<endl;
   cin.ignore();
   cout<<"Press Enter to give names..."<<endl;
	for (int i=0 ; i<=10 ; i++)
{
    cout<<"#"<<i+1<<" player name : ";
	taem[i].getname();
	outputFil<<"#"<<i+1<<" player name : "<<taem[i].name<<endl;
} 
    here:
	system("cls");  
    cout<<endl<<"To Enter Toss Result press 1"<<endl;
    cout<<"To Do simulated Toss enter 2 "<<endl;
    cout<<"For Explanation of process Enter 3"<<endl;
    cin>>temp;
if (temp == 1)
    manual_toss();
else if (temp == 2)
    simulated_toss();
else if (temp ==3 )
{
    cout<<endl<<"**In Simulated toss Computer will generate a random number based on time\n";
    cout<<"And will decide on the basis of generated random number which team has won the toss\n";
    cout<<"In Toss Result person would manually enter the toss results**"<<endl<<endl;
    cout<<"Returning back to menu...."<<endl;
    system("pause");
    goto here;
}
   else
{ 
   cout<<"Wrong Input......."<<endl;
   system("pause");
   goto here;	
} 
outputFil.close();
}
void team_1_inning(player *team_1 , player *team_2 ,int overs )
{    
    next_1_batsman(team_1 , 11);
    int  balls = 0 , test = 0 ;
    system("cls");
	while (test < overs) 
{
while (balls < 6) 
{
	here1:
	cout<<"				--------------------------------- "<<endl;		
    cout<<"				*********** "<<endl;	
	cout<<"				--------------------------------- "<<endl;	
	cout<<"				|    Enter 0 for : DOT          | "<<endl;
	cout<<"				|    Enter 1 for : SINGLE       | "<<endl;
	cout<<"				|    Enter 2 for : DOUBLE       | "<<endl;
	cout<<"				|    Enter 3 for : TRIPLE       | "<<endl;
	cout<<"				|    Enter 4 for : FOUR         | "<<endl;
	cout<<"				|    Enter 5 for : WIDE+FOUR    | "<<endl;
	cout<<"				|    Enter 6 for : SIX          | "<<endl;
	cout<<"				|    Enter 7 for : WIDE/NO BALL | "<<endl;
	cout<<"				|    Enter 8 for : WICKET       | "<<endl;
	cout<<"				--------------------------------- "<<endl;
    cout<<"				*********** "<<endl;			
	cout<<"				--------------------------------- "<<endl;		
	cout<<"			 "<<endl;		
	cin>>temp;
switch (temp)
{
	case 0 :
	{
	batter.totalballsfaced();
	bowler.adddotball();
	balls++;
	break;
	}
	case 1 :
	{
	balls++;	
	batter.addscored(1);
	batter.totalballsfaced();
	bowler.addscore(1);
	bowler.adddotball();
	change_striker();
	total_1 = total_1 + 1;
	break;
	}
	case 2 :
	{
	balls++;
	batter.addscored(2);
	batter.totalballsfaced();
	bowler.addscore(2);
	bowler.adddotball();
	total_1 = total_1 +2 ;
	break;
	}
	case 3 :
	{
	balls++;		
	batter.addscored(3);
	batter.totalballsfaced();
	bowler.addscore(3);
	bowler.adddotball();
	change_striker();
	total_1 = total_1 + 3;
	break;
	}
	case 4:
	{
	balls++;
	batter.addscored(4);
	batter.totalballsfaced();
	bowler.addscore(4);
	bowler.adddotball();
	total_1 = total_1 + 4 ;
	break;	
	}	
	case 5:
	{
	//striker.addscored(3);
	//striker.totalballsfaced();
	bowler.addscore(5);
	//bowler.adddotball();
	//change_striker();
	total_1 = total_1 + 5;
	extra_1 = extra_1 + 5 ;
	break;	
	}
	case 6 :
	{
	balls++;
	batter.addscored(6);
	batter.totalballsfaced();
	bowler.addscore(6);
	bowler.adddotball();
	total_1 = total_1 +6 ;
	break;	
	}
	case 7 :
	{
	bowler.addscore(1);
	extra_1 = extra_1 +1 ;
	total_1 = total_1 +1 ;
	break;
	}	
	case 8 :
	{
	bowler.addwicket();
	bowler.adddotball();
	next_1_batsman(team_1 , 11);
	balls ++ ;	
	}	
	
	default :
	{
	cout<<"wrong Number Entered ..... Please choose from the given menu "<<endl;
	goto here1;
    }
	}
    system("cls");
    cout<<"STRIKER     :"<<batter.name<<"	SCORE	"<<batter.scored<<"	BALLS FACED   "<<batter.ballsfaced<<endl;
    cout<<"NON-STRIKER :"<<butter.name<<"	SCORE	"<<butter.scored<<"	BALLS FACED   "<< butter.ballsfaced<<endl<<endl;
	cout<<"BOWLER      :"<<bowler.name<<"	SCORE	"<<bowler.score <<"	WICKETS	"<<bowler.wickets<<"	BOWLS	"<<bowler.dotballs<<endl<<endl;
	cout<<"TEAM TOTAL  :"<<total_1<<			"EXTRA       :"<<extra_1<<endl;
}   
    cout<<"\n over ended need to add new bowler \n \n "<<endl;
    test = test +1 ;
    cout<<"testing overs = "<<test <<" $ "<<overs<<endl;
	if (test < overs)
{
	next_bowler(team_2 , 11);
}
	balls = 0 ;
}	
  system("cls");
  cout<<"Innings Ended!!!!!! \nTarget : "<<total_1+1<<"\n Extras : "<<extra_1<<endl;
  system("pause");	
}

void team_2_inning(player *team_1 , player *team_2 ,int overs )
{
    next_2_batsman(taem , 11);
	int  balls = 0 , test = 0 ;
    
	while (test < overs) 
{
while (balls < 6) 
{
	here1:
	cout<<"				--------------------------------- "<<endl;		
    cout<<"				*********** "<<endl;	
	cout<<"				--------------------------------- "<<endl;	
	cout<<"				|    Enter 0 for : DOT          | "<<endl;
	cout<<"				|    Enter 1 for : SINGLE       | "<<endl;
	cout<<"				|    Enter 2 for : DOUBLE       | "<<endl;
	cout<<"				|    Enter 3 for : TRIPLE       | "<<endl;
	cout<<"				|    Enter 4 for : FOUR         | "<<endl;
	cout<<"				|    Enter 5 for : WIDE+FOUR    | "<<endl;
	cout<<"				|    Enter 6 for : SIX          | "<<endl;
	cout<<"				|    Enter 7 for : WIDE/NO BALL | "<<endl;
	cout<<"				|    Enter 8 for : WICKET       | "<<endl;
	cout<<"				--------------------------------- "<<endl;
    cout<<"				*********** "<<endl;			
	cout<<"				--------------------------------- "<<endl;		
	cin>>temp;
switch (temp)
{
	case 0 :
	{
	batter.totalballsfaced();
	bowler.adddotball();
	balls++;
	break;
	}
	case 1 :
	{
	balls++;	
	batter.addscored(1);
	batter.totalballsfaced();
	bowler.addscore(1);
	bowler.adddotball();
	change_striker();
	total_2 = total_2 + 1;
	break;
	}
	case 2 :
	{
	balls++;
	batter.addscored(2);
	batter.totalballsfaced();
	bowler.addscore(2);
	bowler.adddotball();
	total_2 = total_2 +2 ;
	break;
	}
	case 3 :
	{
	balls++;		
	batter.addscored(3);
	batter.totalballsfaced();
	bowler.addscore(3);
	bowler.adddotball();
	change_striker();
	total_2 = total_2 + 3;
	break;
	}
	case 4:
	{
	balls++;
	batter.addscored(4);
	batter.totalballsfaced();
	bowler.addscore(4);
	bowler.adddotball();
	total_2 = total_2 + 4 ;
	break;	
	}	
	case 5:
	{
	//striker.addscored(3);
	//striker.totalballsfaced();
	bowler.addscore(5);
	//bowler.adddotball();
	//change_striker();
	total_2 = total_2 + 5;
	extra_2 = extra_2 + 5 ;
	break;	
	}
	case 6 :
	{
	balls++;
	batter.addscored(6);
	batter.totalballsfaced();
	bowler.addscore(6);
	bowler.adddotball();
	total_2 = total_2 +6 ;
	break;	
	}
	case 7 :
	{
	bowler.addscore(1);
	extra_2 = extra_2 +1 ;
	total_2 = total_2 +1 ;
	break;
	}	
	case 8 :
	{
	bowler.addwicket();
	bowler.adddotball();
	next_2_batsman(team_2 , 11);
	balls ++ ;	
	}	
	
	default :
	{
	cout<<"Wrong Number entered ..... please choose from the given menu "<<endl;
	goto here1;
    }
	}
    system("cls");
    cout<<"STRIKER     :"<<batter.name<<"	SCORE	"<<batter.scored<<"	BALLS FACED   "<<batter.ballsfaced<<endl;
    cout<<"NON-STRIKER :"<<butter.name<<"	SCORE	"<<butter.scored<<"	BALLS FACED   "<< butter.ballsfaced<<endl<<endl;
	cout<<"BOWLER      :"<<bowler.name<<"	SCORE	"<<bowler.score <<"	WICKETS	"<<bowler.wickets<<"	BOWLS	"<<bowler.dotballs<<endl<<endl;
	cout<<"TEAM TOTAL  :"<<total_1<<endl;
	cout<<"EXTRA       :"<<extra_1<<endl;
}   
    cout<<"\n over ended need to add new bowler \n \n "<<endl;
    test = test +1 ;
    cout<<"testing overs = "<<test <<" $ "<<overs<<endl;
	if (test < overs)
{
	next_bowler(team_1 , 11);
}
	balls = 0 ;
}
  system("cls");
  cout<<"Innings Ended!!!!!! \nTarget : "<<total_2+1<<"\n Extras : "<<extra_2<<endl;
  system("pause");	

}
 