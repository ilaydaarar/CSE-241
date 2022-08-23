/*ILAYDA ARAR CSE241 HW5 1901042638*/
/*Header file for BoardGame2D class*/
#ifndef BOARDGAME2D_H 
#define BOARDGAME2D_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <unistd.h>

using namespace std;

namespace nsboard2d{

    class BoardGame2D{

        public:

            virtual int playUser(string input) = 0;
           virtual int playUser() final;
           virtual int playAuto() = 0;
            virtual int playAutoAll() final;
            virtual void print() = 0;
            virtual bool endgame() = 0;
            virtual int boardScore() = 0;
            virtual void initialize() = 0;
            static int playVector(vector < BoardGame2D * > vec);
            friend ostream& operator <<(ostream& outputStream, BoardGame2D* board);
        
    


    };
    ostream& operator <<(ostream& outputStream, BoardGame2D* board);

}



#endif // BOARDGAME2D_H