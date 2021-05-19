#ifndef PLAYER_H
#define PLAYER_H
#include<vector>

class player
{
    public:
        player(int str,int nr);
        virtual ~player();
        int fight(int round);
        void result(int x);
        int id_nr();
        int id_str();
        int id_score();
        int id_lm();
        int id_karma();
        void met(player *op);
        void meet(int x, int y,int z);
    protected:

    private:
        int pick(int x);
        int score=0;
        int enemy_karma=0;
        int enemy_score=0;
        int enemy_move=0;
        int _nr;
        int karma = 0;
        int last_move=0;
        int _str;
};

#endif // PLAYER_H
