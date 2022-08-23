/*ILAYDA ARAR CSE241 HW5 1901042638*/
/*Implementation file for boardgame2d.h*/
#include <vector>
#include <string>
#include <fstream>
#include <time.h>

#include "boardgame2d.h"
using namespace std;

namespace nsboard2d{


    int BoardGame2D::playAutoAll(){

        int i=0;
        while((endgame() != true)) 
        {
            playAuto();
            print();
            usleep(1000000);    //This function calls playAuto continously and prints the board.
            i++;
            if(i>35) break;        //If the computer did not finished the game in 35 moves, the game is over
        }
        return 1;
    }

    int BoardGame2D::playUser(){    //This function takes user input and plays accordingly till the game ends.
        string input;
        print();
        while(endgame() != true){
            cout << "Please enter your input, if you are playing Peg Solitaire enter as 'A3R', If you are playing Slider, enter input as 43D (First row, second column)\n";
            cin >> input;
            playUser(input);
            print();
        }
        return 1;
    }

    int BoardGame2D::playVector(vector < BoardGame2D * > vec){  //Takes a vector of objects and plays overrided


        return 1;
    }
}