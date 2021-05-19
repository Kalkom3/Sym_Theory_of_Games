#ifndef ENVIROMENT_H
#define ENVIROMENT_H
#include<vector>
#include<thread>
#include"player.h"
#include"terminal.h"
#include<fstream>
class enviroment
{
    public:
        enviroment();
        virtual ~enviroment();
        void setup();
        void start();
        void score();

    protected:

    private:
        void players_score();
        void save();
        std::fstream file1;
        terminal Terminal;
        bool check(int x,std::vector<int>y);
        int los(int x);
        void los_clear();
        void eve();
        void game(int x,int y);
        std::vector<int>rep;
        player *deck[1001];
        int round=0;
        int scope,tact;
        bool history;
        std::vector<int>List;
        std::vector<int>tactic;
        std::vector<int>A;
        std::vector<int>S;
        std::vector<int>K;
        int pool,times,tac;
        char his;
};

#endif // ENVIROMENT_H
