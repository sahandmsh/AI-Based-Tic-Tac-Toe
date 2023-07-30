#include "TTT.hpp"
int main(){
    string s="";
    srand( int ( time(0) ) ); 
    TTT G;
    cout<< "AI-Based bot is learning! Please wait :)\n";
    G.episodic_learning(2000000);
    cout<< "\n\n\n Now it's time to play against the AI-trained bot\n\n\n";
    while (true){
        cout<<"Want to stop playing? enter \"NO\" now! Otherwise, press enter!\n";
        getline(cin, s);
        if (s == "NO" || s== "no" || s=="No" || s== "nO"){break;}
        G.evaluate();
    }
}
