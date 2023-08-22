#include "TTT.hpp"
TTT::TTT(){
    Board = "123456789"; 
    P1 = 'X';
    P2 = '@';
    P_winner = 'X'; // only an initial value
    available_actions = 9;
    P_turn = 0;
    eps = 80;
    alpha = 0.25;
    gamma = 0.9;
    P1_win_count = 0;
}
//###############################################
void TTT::print (){
    for (int i=0;i<9;++i){
        if (i%3==0){std::cout<<"\n-------------\n|";}
        std::cout<<" "<<Board[i]<<" |";
    }
    std::cout<<"\n-------------\n";
}
//###############################################
void TTT::reset(){
    Board = "123456789";
    available_actions = 9;
    P_turn = 0;
    cur_state_action = Board;
}
//###############################################
int TTT::bot_play(char P, float eps_){
    int x;
    if (rand()%100>eps_){x = random_play(P,available_actions);}
    else{x = greedy(P);}
    return x;
}
//###############################################
void TTT::user_play(char P){
    std::string s;
    int x;
    std::cout<<"\nPlease make a selection --- ";
    getline(cin,s);
    x = stoi(s);
    Board[x-1] = P;
}
//###############################################
int TTT::random_play(char P, int x){
    x = rand()%x + 1;
    for (int i=0;i<9;++i){
        if (Board[i]!=P1 && Board[i]!=P2){
            if (--x==0){
                x = i;
                break;
            }
        }
    }
    return x;
}
//###############################################
int TTT::greedy(char P){
    float val=-100;
    std::string S_A;
    vector <int> v;
    for (int i=0;i<9;++i){
        if (Board[i]!=P1 && Board[i]!=P2){
            S_A = Board;
            S_A[i] = P1;
            if (m.find(S_A) == m.end()){m[S_A]=0;}
            if (m[S_A]>val){
                val = m[S_A];
            }
        }
    }
    /*--------  Making random selection in case that there exists
                more than one action with the maximum Q value! */
    for (int i=0;i<9;++i){
        if (Board[i]!=P1 && Board[i]!=P2){
            S_A = Board;
            S_A[i] = P1;
            if (m[S_A]==val){v.push_back(i);}
        }
    }
    int x = rand()%int(v.size());
    return v[x];
}
//###############################################
void TTT::Q_Update(){
    float val=-100;
    std::string S_A;
    for (int i=0;i<9;++i){
        if (Board[i]!=P1 && Board[i]!=P2){
            S_A = Board;
            S_A[i] = P1;
            if (m.find(S_A) == m.end()){m[S_A]=0;}
            if (m[S_A]>val){
                val = m[S_A];
            }
        }
    }
    m[pre_state_action] = (1-alpha)*m[pre_state_action] + alpha*(0 + gamma*val);
}
//###############################################
void TTT::episode(){
    reset();
    pair <std::string, int> S_A;
    while (available_actions>0){
        if (P_turn == 0){
            if (available_actions<9){
                Q_Update();
            }
            Board[bot_play(P1,eps)] = P1;
            pre_state_action = cur_state_action;
            cur_state_action = Board;
            if (m.find(cur_state_action) == m.end()){m[cur_state_action]=0;}
        }
        else{Board[random_play(P2,available_actions)]=P2;}
        -- available_actions;
        
        if (winner()==true){
            if (P_winner == P1){
                m[cur_state_action] = 1;
                P1_win_count++;
                
            }
            else{
                m[cur_state_action] = -0.5;
            }
            break;
        }

        P_turn = 1 - P_turn;
    }
}
//###############################################
void TTT::episodic_learning(int n){
    for (int i=0;i<n;++i){
        episode();
    }
    std::cout<<"THE TOTAL COUNT OF P1 WINS is "<<P1_win_count<<endl;
}
//###############################################
bool TTT::winner(){
    for (int i = 0;i<9;i+=3){
        if (Board[i] == Board[i+1] && Board[i+1] == Board[i+2]){
            P_winner = Board[i];
            return true;}
        else if ((Board[i/3] == Board[i/3+3]) && (Board[i/3+3] == Board[i/3+6])){
            P_winner = Board[i/3];
            return true;
        }
    }
    if (Board[0]==Board[4] && Board[4]==Board[8]){
        P_winner = Board[0];
        return true;
    }
    else if (Board[2]==Board[4] && Board[4]==Board[6]){
        P_winner = Board[2];
        return true;
    }
    return false;
}
//###############################################
void TTT::evaluate(){
    reset();
    eps = 100;
    P_turn = 0;
    pair <std::string , int> S_A;
    std::cout<<"\n ----------------------------------- \n";
    std::cout<<"\n ------------ NEW MATCH ------------ \n";
    std::cout<<"\n ----------------------------------- \n";
    while (available_actions>0){
        if (P_turn == 0){
            if (available_actions<9){
                Q_Update();
            }
                
            Board[bot_play(P1,eps)] = P1;
            pre_state_action = cur_state_action;
            cur_state_action = Board;
            if (m.find(cur_state_action) == m.end()){m[cur_state_action]=0;}
            print();
        }
        else{user_play(P2);}
        -- available_actions;
        
        if (winner()==true){
            if (P_winner == P1){
                m[cur_state_action] = 1;
                P1_win_count++;
                print();
                std::cout<<"BOT WON THIS ROUND!\n";
            }
            else{std::cout<<"YOU WIN! GOOD JOB!\n";}
            break;
        }

        P_turn = 1 - P_turn;
    }
}
