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
	cout<<"			******Welcome to GIKI's  Cricket Score Card*"<<endl;
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