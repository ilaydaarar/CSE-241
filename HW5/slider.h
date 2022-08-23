/*ILAYDA ARAR CSE241 HW5 1901042638*/
/*Header file for Slider class*/
#ifndef SLIDER_H
#define SLIDER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <unistd.h>

using namespace std;

#include "boardgame2d.h"



namespace nsboard2d{

    class Slider : public BoardGame2D
    {

        public: 

            Slider();
            int playUser(string input);
            int playUserOver();
            int moveleft(int i, int j);
            int moveup(int i, int j);
            int movedown(int i, int j);
            int moveright(int i, int j);
            int playAuto();
            int playAutoOver();
            
            void print();
            bool endgame();
           int boardScore();
            void initialize();
            static int playVector(vector < BoardGame2D * > vec);
            friend ostream& operator <<(ostream& outputStream, Slider board);

        private:
            vector<vector<int>> board_slider ={ //Initial unrandomized board
        
                {0, 1, 2},
                {3, 4, 5},
                {6, 7, 8},
                
            };
            


    };
    ostream& operator <<(ostream& outputStream, Slider board);

}

#endif // SLIDER_H