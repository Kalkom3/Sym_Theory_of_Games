#include "terminal.h"
#include<iostream>
#include"player.h"
using namespace std;
terminal::terminal()
{
    //ctor
}
void terminal::result(int r,int x)
{
    switch(r)
    {
    case 0:
        cout<<"(1-1)Tie-"<<endl;
        break;
    case 1:
        cout<<"(1-0)Win "<<x<<endl;
        break;
    case 2:
        cout<<"(0-1)Win "<<x<<endl;
        break;
    case 3:
        cout<<"(0-0)Tie+"<<endl;
        break;
    }
}
void terminal::id_player(int nr, player *pl)
{
    cout << nr<< "(" << pl->id_str() << ")["<< pl->id_score() << "]|" << pl->id_lm() << "|   ";
}
void terminal::line(int type)
{
    if(type==0)
        cout<<endl;
    if(type==1)
        cout<<"--------------------------"<<endl;
}
void terminal::limits(int type)
{
    if(type==0)
        cout<<"Players[max 1000]:"<<endl;
    if(type==1)
        cout<<"Rounds[max x]:"<<endl;
    if(type==2)
        cout<<"NoT:"<<endl;
    if(type==3)
        cout<<"History?[y/n]"<<endl;
}
void terminal::SoT()
{
    cout<<"| 1-good      |"<<endl;
    cout<<"| 2-evil      |"<<endl;
    cout<<"| 3-good,evil |"<<endl;
    cout<<"| 4-mimic lm  |"<<endl;
    cout<<"| 5-n.minic lm|"<<endl;
    cout<<"| 6-karma     |"<<endl;
    cout<<"| 7-n.karma   |"<<endl;
    cout<<"| 8-score     |"<<endl;
    cout<<"| 9-n.score   |"<<endl;
    cout<<"| 10-cheater  |"<<endl;
    cout<<"| 11-n.cheater|"<<endl;
}
void terminal::player_score(player *pl)
{
    cout<<pl->id_nr()<<"("<<pl->id_str()<<"): "<<pl->id_score()<<endl;
}
void terminal::stats(int nr,int T,int S, int A, int K)
{
    cout<<nr<<": P="<< T << " S=" << S << " A=" << A << " K=" << K<<endl;
}
terminal::~terminal()
{
    //dtor
}
