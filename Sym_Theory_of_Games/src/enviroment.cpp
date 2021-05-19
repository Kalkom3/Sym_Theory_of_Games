#include "enviroment.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<fstream>
#include"terminal.h"
using namespace std;
enviroment::enviroment()
{
    srand(time(NULL));
    file1.open("wyniki.txt");
}
//___________________________________________CHECK_UNIQ____________________________________________
bool enviroment::check(int x, std::vector<int>y)
{
    for(int i=0;i<y.size();i++)
    {
        if(x==y[i])
        {
            return false;
        }
    }
    return true;
}
//_________________________________________RANDOMIZE____________________________________________
int enviroment::los(int x)
{
    int y;
    do
    {
    y=(rand()%x)+1;
    }while(check(y,rep)==false);
    rep.push_back(y);
    return y;
}
void enviroment::los_clear()
{
    rep.clear();
}
//___________________________________________GAME___________________________________________
void enviroment::game(int x,int y)//Meeting between players
{
    deck[x]->met(deck[y]);
    deck[y]->met(deck[x]);
    int type1,type2;
    type1=deck[x]->fight(round);
    type2=deck[y]->fight(round);
    if(type1==1 && type2==1)
    {
        deck[x]->result(5);
        deck[y]->result(5);
        if(history==true)
        Terminal.result(0,0);
    }
    else if(type1==1 && type2==0)
    {
        deck[x]->result(0);
        deck[y]->result(10);
        if(history==true)
        Terminal.result(1,x);
    }
    else if(type1==0 && type2==1)
    {
        deck[x]->result(10);
        deck[y]->result(0);
        if(history==true)
        Terminal.result(2,y);
    }
    else if(type1==0 && type2==0)
    {
        deck[x]->result(1);
        deck[y]->result(1);
        if(history==true)
        Terminal.result(3,0);
    }

}
//_________________________________________EVENT____________________________________________
void enviroment::eve()//Picking opponents to fight (game used)
{
int a,b;
for(int i=0;i<(scope/2);i++)
{
    a=los(scope);
    b=los(scope);
    //cout<<a<<" "<<b<<endl;
    if(history==true)
    {
        Terminal.id_player(a,deck[a]);
        Terminal.id_player(b,deck[b]);
        Terminal.line(0);
    }
    game(a,b);
    if(history==true)
    {
      Terminal.line(0);
    }
}
los_clear();
if(history==true)
{
  Terminal.line(1);
}
}
//___________________________________________SETUP____________________________________________
void enviroment::setup()// input variables, create game
{
    Terminal.limits(0);
    cin>>pool;
    scope = pool;
     Terminal.limits(1);
    cin>>times;
     Terminal.limits(2);
    Terminal.SoT();
    cin>>tac;
     Terminal.limits(3);
    cin>>his;
    for(int i=0;i<=tac;i++)
    {
        tactic.push_back(0);
        List.push_back(i);
        A.push_back(0);//average
        S.push_back(0);//sum
        K.push_back(0);//karma
    }
}
//___________________________________________START____________________________________________
void enviroment::start()//create players
{
    if(his=='y')
    {
        history=true;
    }
    else
    {
        history=false;
    }
    int ran;
    tact=tac;
    srand(time(NULL));
    for(int i=1;i<=pool;i++)
    {
        ran=rand()%tact+1;
        deck[i] = new player(ran,i);
        tactic[ran]++;
    }

    for(int i=0;i<times;i++)
    {
        eve();
        round++;
    }
}
//___________________________________________SCORE____________________________________________
void enviroment::score()//output outcome
{
    int ma=0;
    char endgame;
    cout<<"Players:"<<endl;
    for(int i=1;i<=scope;i++)
    {
        Terminal.player_score(deck[i]);
    }
    cout<<"Tactics:"<<endl;
    for(int i=1;i<=(tact);i++)
    {
        if(tactic[i]>0)
        {
        for(int j=1;j<=scope;j++)
        {
            if(deck[j]->id_str()==i)
            {
                S[i]+=deck[j]->id_score();
                K[i]+=deck[j]->id_karma();
            }
        }
        A[i]=S[i]/tactic[i];
        K[i]=K[i]/tactic[i];
        Terminal.stats(i,tactic[i],S[i],A[i],K[i]);
        file1<<i<<": Player="<< tactic[i] << " Score=" << S[i] << " Aaverage=" << A[i] << " Karma=" << K[i] <<endl;
        }

    }
    cout<<endl<<"Rank:"<<endl;
    for(int i=1;i<=tact;i++)
    {
        ma=A[i];
        for(int j=(i+1);j<=tact;j++)
        {
            if(ma<=A[j])
            {
            ma=A[j];
            swap(A[j],A[i]);
            swap(List[j],List[i]);
            }

        }
        cout<<i<<") "<<(List[i])<<": "<<A[i]<<endl;
    }
    Terminal.SoT();
    players_score();
    cin>>endgame;

}
//___________________________________________PLAYER_SCORE____________________________________________
void enviroment::players_score()//players highlights
{
    int winner=0;
    int lowest=99999;
    for(int i=1;i<=pool;i++)
    {
        lowest=deck[i]->id_score();
        for(int j=i+1;j<=pool;j++)
        {
            if(lowest>=deck[j]->id_score())
            {
                lowest=deck[j]->id_score();
                swap(deck[i],deck[j]);
            }
        }

    }
    cout<<"TOP 10:"<<endl;
    for(int i=1;i<=10;i++)
    {
        cout<<i<<") Nr: "<<deck[i]->id_nr()<<", Score: "<<deck[i]->id_score()<<", Tactic: "<<deck[i]->id_str()<<", Karma: "<<deck[i]->id_karma()<<endl;

    }

}
enviroment::~enviroment()
{
    //dtor
}
