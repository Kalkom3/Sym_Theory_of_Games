#include "player.h"
#include<iostream>
#include<vector>
using namespace std;
player::player(int str, int nr)
{
    _nr=nr;
    _str=str;
}
void player::meet(int x,int y,int z)
{
    enemy_karma=z;
    enemy_move=x;
    enemy_score=y;
}
//______________________________________PICK_______________________________
int player::pick(int x)//pick 0 or 1, change karma
{
    if(x==0)
    {
        last_move=0;
        karma++;
        return 0;
    }
    else if(x==1)
    {
        last_move=1;
        karma--;
        return 1;
    }
}
//_______________________________________MET_ENEMY_______________________________________
void player::met(player *op)//opponent stats
{
    enemy_karma= op->id_karma();
    enemy_move= op->id_lm();
    enemy_score= op->id_score();
}
//_______________________________________INFO______________________________________
int player::id_karma()
{
    return karma;
}
int player::id_str()
{
    return _str;
}
int player::id_lm()
{
    return last_move;
}
int player::id_nr()
{
    return _nr;
}
int player::id_score()
{
    return score;
}
//____________________________________________FIGHT_________________________________________
int player::fight(int round)
{
    if(enemy_karma<-(round/2)&&_str!=1&&_str!=3)//punish
    {
        return pick(1);
    }
    switch(_str)
    {
    case 1://good
        return pick(0);
        break;
    case 2://evil
        return pick(1);
        break;
    case 3://random
        if(round%2==1)
        {
            return pick(1);
        }
        else
        {
            return pick(0);
        }
        break;
    case 4://mimic last move
        if(enemy_move==1)
        {
            return pick(1);
        }
        else
        {
            return pick(0);
        }
        break;
    case 5://negate mimic last move
        if(enemy_move==1)
        {
            return pick(0);
        }
        else
        {
            return pick(1);
        }
        break;
    case 6:// karma (betray enemy with - karma)
        if(enemy_karma>=0)
        {
            return pick(0);
        }
        else
        {
            return pick(1);
        }
        break;
    case 7:// negate karma
        if(enemy_karma<=0)
        {
            return pick(0);
        }
        else
        {
            return pick(1);
        }
        break;
    case 8://score (betray better players)
        if(enemy_score<score)
        {
            return pick(0);
        }
        else
        {
            return pick(1);
        }
        break;
    case 9://negate score
        if(enemy_score>score)
        {
            return pick(0);
        }
        else
        {
            return pick(1);
        }
        break;
    case 10:// betray enemy with higher karma
        if(enemy_karma>karma)
        {
            return pick(0);
        }
        else
        {
            return pick(1);
        }

        break;
    case 11:// betray enemy with lower karma
        if(enemy_karma<=karma)
        {
            return pick(0);
        }
        else
        {
            return pick(1);
        }

        break;
    }

}

void player::result(int x)
{
    score+=x;
}

player::~player()
{
    //dtor
}
