/*ILAYDA ARAR CSE241 HW5 1901042638*/
/*Header file for PegSolitaire class*/
#ifndef PEG_H 
#define PEG_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

#include "boardgame2d.h"

enum state {peg, empty, space}; //Providing enum type for using in boards.

namespace nsboard2d{

    class PegSolitaire : public BoardGame2D
    {

        public: 

            PegSolitaire();
           int playUser(string input);
           int playUserOver();
           
            int playAuto();
            
            void print();
            bool endgame();
            int boardScore();
            void initialize();
            int playAutoOver();
            static int playVector(vector < BoardGame2D * > vec);
            friend ostream& operator <<(ostream& outputStream, PegSolitaire board);
            

        private:
            vector<vector<state>> board_peg;
            


    };
    ostream& operator <<(ostream& outputStream, PegSolitaire board);

}

#endif // PEG_H