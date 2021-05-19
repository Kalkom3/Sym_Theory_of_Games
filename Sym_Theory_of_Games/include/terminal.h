#ifndef TERMINAL_H
#define TERMINAL_H
#include"player.h"

class terminal
{
    public:
        terminal();
        virtual ~terminal();
        void result(int r,int x);
        void id_player(int nr,player *pl);
        void line(int type);
        void limits(int type);
        void SoT();
        void player_score(player *pl);
        void stats(int nr,int T,int S, int A, int K);
    protected:

    private:
};

#endif // TERMINAL_H
