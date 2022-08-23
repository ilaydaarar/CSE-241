/*ILAYDA ARAR CSE241 HW5 1901042638*/
/*Header file for Klotski class*/
#ifndef KLOTSKI_H 
#define KLOTSKI_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

#include "boardgame2d.h"

enum block {A, B, C, D, E, F, G, H, I, O, X}; //Providing enum type for using in boards.

namespace nsboard2d{

    class Klotski : public BoardGame2D
    {

        public: 

            Klotski();
           
            void print();
            bool endgame();
            int boardScore();
            void initialize();
            int playUserOver();
            int playUser(string input);
           
            int playAuto();
            
           
            int playAutoOver();
            

            friend ostream& operator <<(ostream& outputStream, Klotski board);
            

        private:
            vector<vector<block>> board_klotski =  {
        
                {A, X, X, B},
                {A, X, X, B},
                {C, D, D, E},
                {C, F, G, E},
                {H, O, O, I}
                
            };
            


    };
    ostream& operator <<(ostream& outputStream, Klotski board);

}

#endif // KLOTSKI_H