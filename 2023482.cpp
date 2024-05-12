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
 