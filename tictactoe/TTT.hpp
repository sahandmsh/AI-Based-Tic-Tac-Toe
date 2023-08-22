#include <iostream>
#include <utility>
#include <string>
#include <map>

#ifndef CLASS_TTT
#define CLASS_TTT

class TTT{
    std::map <std::string , float> m;
    char P1 , P2, P_winner;
    int available_actions , P_turn, P1_win_count;
    std::string pre_state_action, cur_state_action;
    void print();
    void reset();
    void episode();
    void user_play(char);
    void Q_Update();
    int greedy(char);
    int random_play(char,int);
    int bot_play(char,float);
    bool winner();
public:
    std::string Board;
    float alpha, gamma, eps;
    TTT();
    void episodic_learning(int);
    void evaluate();
    
};

#endif
