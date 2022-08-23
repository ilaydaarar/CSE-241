/*ILAYDA ARAR CSE241 HW5 1901042638*/
/*Implementation file for klotski.h*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#include "klotski.h"



namespace nsboard2d{

        

        Klotski::Klotski(){   //The constructor calls initialize and starts with original board.

            initialize();
        }
         void Klotski::initialize(){	//Assigning the initial board
       
            board_klotski = {
        
                {A, X, X, B},
                {A, X, X, B},
                {C, D, D, E},
                {C, F, G, E},
                {H, O, O, I}
                
            };
            
        }

        void Klotski::print(){

            int i,j;
            for(i = 0; i<5; i++){
                for(j=0; j<4; j++){
                    if(board_klotski[i][j] == A) cout << 'A' << " ";    //Printing the board according to enum
                    if(board_klotski[i][j] == B) cout << 'B' << " ";
                    if(board_klotski[i][j] == C) cout << 'C' << " ";
                    if(board_klotski[i][j] == D) cout << 'D' << " ";
                    if(board_klotski[i][j] == E) cout << 'E' << " ";
                    if(board_klotski[i][j] == F) cout << 'F' << " ";
                    if(board_klotski[i][j] == G) cout << 'G' << " ";
                    if(board_klotski[i][j] == H) cout << 'H' << " ";
                    if(board_klotski[i][j] == I) cout << 'I' << " ";
                    if(board_klotski[i][j] == O) cout << ' ' << " ";
                    if(board_klotski[i][j] == X) cout << 'X' << " ";
                    
                }
                cout << endl;
            }
        
        }

        bool Klotski::endgame(){    //If the big square's bottom is in the right place, the game is won.

            if(board_klotski[4][1] == X && board_klotski[4][2] == X) return true;
            else return false;
        }
        
        int Klotski::boardScore(){
            int i,j;
            int score;
            int index;
            for(i = 0; i<5; i++){
                for(j=0; j<4; j++){
                    if(board_klotski[i][j] == X) index = i; //Finding the big square's index
                    
                }
                
            }
            score = 4-index;    //Closer the index to the outside, lower the score.
            return score;
        }

        ostream& operator <<(ostream& outputStream, Klotski board){

            int i,j;
            for(i = 0; i<5; i++){
                for(j=0; j<4; j++){
                    if(board.board_klotski[i][j] == A) outputStream << 'A' << " ";
                    if(board.board_klotski[i][j] == B) outputStream << 'B' << " ";
                    if(board.board_klotski[i][j] == C) outputStream << 'C' << " ";
                    if(board.board_klotski[i][j] == D) outputStream << 'D' << " ";
                    if(board.board_klotski[i][j] == E) outputStream << 'E' << " ";
                    if(board.board_klotski[i][j] == F) outputStream << 'F' << " ";
                    if(board.board_klotski[i][j] == G) outputStream << 'G' << " ";
                    if(board.board_klotski[i][j] == H) outputStream << 'H' << " ";
                    if(board.board_klotski[i][j] == I) outputStream << 'I' << " ";
                    if(board.board_klotski[i][j] == O) outputStream << ' ' << " ";
                    if(board.board_klotski[i][j] == X) outputStream << 'X' << " ";
                    
                }
                outputStream << endl;
            }
            return outputStream;    //Printing the board and returning output.

        }
            
        int Klotski::playUserOver(){
            return 1;
        }
            
        int Klotski::playUser(string input){
            return 1;
        }
           
        int Klotski::playAuto(){
            return 1;
        }
            
           
        int Klotski::playAutoOver(){
            return 1;
        }
}