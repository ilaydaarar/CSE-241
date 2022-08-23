/*ILAYDA ARAR CSE241 HW5 1901042638*/
/*Implementation file for peg.h*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#include "peg.h"



namespace nsboard2d{

    

      
        

        PegSolitaire::PegSolitaire(){   //The constructor calls initialize and starts with original board.

            initialize();
        }
         void PegSolitaire::initialize(){	//Assigning the initial board
       
            board_peg = {
        
                {space, space, space, peg, peg, peg, space, space, space},
                {space, space, space, peg, peg, peg, space, space, space},
                {space, space, space, peg, peg, peg, space, space, space},
                {peg, peg, peg, peg, peg, peg, peg, peg, peg},
                {peg, peg, peg, peg, empty, peg, peg, peg, peg},
                {peg, peg, peg, peg, peg, peg, peg, peg, peg},
                {space, space, space, peg, peg, peg, space, space, space},
                {space, space, space, peg, peg, peg, space, space, space},
                {space, space, space, peg, peg, peg, space, space, space}
            };
            
        }

        void PegSolitaire::print(){
            int k,l;
            int character=0;
            char ch='A';
            auto i = 0;
            decltype(i) j;
            cout << " " << " ";
            for(k=0; k<board_peg[0].size(); k++){   //Printing the column alphabets

                character=int(ch);
                cout<<ch<<" ";
                character++;
                ch=char(character);

            }
            
            cout << endl;
            for (i = 0; i < board_peg.size(); i++)
            {
                cout << i+1 << " ";
                for (j = 0; j < board_peg[i].size(); j++)
                {
                    if(board_peg[i][j]==peg) cout << "P" << " ";
                    else if(board_peg[i][j]==empty) cout << "." << " "; //Printing the board according to enum
                    else if(board_peg[i][j]==space) cout << " " << " ";
                    
                }   
                cout << endl;
            }

            cout << endl;  
        }

        int PegSolitaire::playUser(string input){

            
            int control = 0;
            int move_row;
            char move_way, move_column;
            int row = 9, column = 9;
            move_row = ((int)input[1]) - 48;
            move_column = input[0];
            move_way = input[2];
            

            if(((int)move_column > 64 && (int)move_column < (65+column)) && move_row > 0 && move_row <= row)    //Checking validity of user input's row and column
            {
                control = 1;
            }
            
            //If user tries to make a down or up move for the edge of the board, that is invalid*/
            if((move_row == 1 && move_way == 'U') || (move_row == 2 && move_way == 'U') || (move_row == row-1 && move_way == 'D') || (move_row == row && move_way == 'D')){
                control = 0;
            }

            if( control == 1 && move_way == 'R' && board_peg[move_row-1][((int)move_column - 65)] == peg && board_peg[move_row-1][((int)move_column - 64)] == peg && board_peg[move_row-1][((int)move_column - 63)] == empty){

                board_peg[move_row-1][((int)move_column - 65)] = empty;
                board_peg[move_row-1][((int)move_column - 64)] = empty;
                board_peg[move_row-1][((int)move_column - 63)] = peg;

            }
            //Left move
            else if(control == 1 && move_way == 'L' && board_peg[move_row-1][((int)move_column - 65)] == peg && board_peg[move_row-1][((int)move_column - 66)] == peg && board_peg[move_row-1][((int)move_column - 67)] == empty){

                board_peg[move_row-1][((int)move_column - 65)] = empty;
                board_peg[move_row-1][((int)move_column - 66)] = empty;
                board_peg[move_row-1][((int)move_column - 67)] = peg;

            }
            //Up move
            else if(control == 1 && move_way == 'U' && board_peg[move_row-1][((int)move_column - 65)] == peg && board_peg[move_row-2][((int)move_column - 65)] == peg && board_peg[move_row-3][((int)move_column - 65)] == empty){

                board_peg[move_row-1][((int)move_column - 65)] = empty;
                board_peg[move_row-2][((int)move_column - 65)] = empty;
                board_peg[move_row-3][((int)move_column - 65)] = peg;

            }
            //Down move
            else if(control ==1 && move_way == 'D' && board_peg[move_row-1][((int)move_column - 65)] == peg && board_peg[move_row][((int)move_column - 65)] == peg && board_peg[move_row+1][((int)move_column - 65)] == empty){

                board_peg[move_row-1][((int)move_column - 65)] = empty;
                board_peg[move_row][((int)move_column - 65)] = empty;
                board_peg[move_row+1][((int)move_column - 65)] = peg;

            }
            else cerr << "You did not enter a valid input, please try again" << endl;   //If none of the conditions fail to provide, print error mesage.
            cout << "Your current score is: " << boardScore() << endl;
            return 1;
            }

            int PegSolitaire::playAuto(){

                int i,j;
                int win = 1;
                int row = 9;
                int column = 9;
                for (i = 0; ((i < row) && (win == 1)); i++)   //Checking for move to the right. (P P .)
                {
                    
                    for (j = 0; ((j < (column - 2)) && (win == 1)); j++)
                    {
                    
                        if(board_peg[i][j] == peg && board_peg[i][j+1] == peg && board_peg[i][j+2] == empty){
                            
                            board_peg[i][j] = empty;
                            board_peg[i][j+1] = empty;
                            board_peg[i][j+2] = peg;

                            win = 0;    //If a valid move is found and done, the variable win is 0. So the function won't look for anymore valid moves.
                        }
                        
                    }   

                    
                }
                
                //Every loop has win==1 condition because it means, in the previous loop of checking, there wasn't any valid moves.
                
                for (i = row-1; ((i >= 0) && (win == 1)); i--){ //Checking for move to the left. (. P P)
                    
                        for (j = column-1; ((j >= 2) && (win == 1)); j--)
                        {
                        
                            if(board_peg[i][j] == peg && board_peg[i][j-1] == peg && board_peg[i][j-2] == empty){ 
                                
                                board_peg[i][j] = empty;
                                board_peg[i][j-1] = empty;
                                board_peg[i][j-2] = peg;
                                win = 0;
                            }
                            
                        }   
                    
                }
                
                for (i = 0; ((i < row - 2) && (win == 1)); i++)  //Checking for move to the down.
                {
                    
                    for (j = 0; ((j < (column-1)) && (win == 1)); j++)
                    {
                    
                        if(board_peg[i][j] == peg && board_peg[i+1][j] == peg && board_peg[i+2][j] == empty){
                            
                            board_peg[i][j] = empty;
                            board_peg[i+1][j] = empty;
                            board_peg[i+2][j] = peg;
                            win = 0;
                        }
                        
                    }   
                    
                }
                
                for (i = row-1; ((i >= 2) && (win == 1)); i--)   //Checking for move to the up.
                {
                    
                    for (j = column-1; ((j >= 0) && (win == 1)); j--)
                    {
                    
                        if(board_peg[i][j] == peg && board_peg[i-1][j] == peg && board_peg[i-2][j] == empty){

                            
                            board_peg[i][j] = empty;
                            board_peg[i-1][j] = empty;
                            board_peg[i-2][j] = peg;
                            win = 0;
                        }
                        
                    }   
                    
                }
                
                
                return win;
            }


        bool PegSolitaire::endgame(){

            int i, j;
            int c_upward = 1, c_downward = 1, c_backward = 1, c_forward = 1;
            bool ctrl = true;
            int sizeb = 9;
            for (i = 0; ((i < sizeb) && (c_forward == 1)); i++)
            {
                
                for (j = 0; ((j < (sizeb - 2)) && (c_forward == 1)); j++)
                {
                
                    if(board_peg[i][j] == peg && board_peg[i][j+1] == peg && board_peg[i][j+2] == empty){
                        
                        c_forward = 0;    //If there is a move found, stop the loops and return 0.
                    }
                    
                }   
                
            }

            for (i = sizeb-1; ((i >= 0) && (c_backward == 1)); i--)
            {
                
                for (j = sizeb-1; ((j >= 2) && (c_backward == 1)); j--)
                {
                
                    if(board_peg[i][j] == peg && board_peg[i][j-1] == peg && board_peg[i][j-2] == empty){
                        
                        c_backward = 0;    //If there is a move found, stop the loops and return 0.
                    }
                    
                }   
                
            }

            for (i = 0; ((i < sizeb-2) && (c_downward == 1)); i++)
            {
                
                for (j = 0; ((j < (sizeb)) && (c_downward == 1)); j++)
                {
                
                    if(board_peg[i][j] == peg && board_peg[i+1][j] == peg && board_peg[i+2][j] == empty){
                        
                        c_downward = 0;    //If there is a move found, stop the loops and return 0.
                    }
                    
                }   
                
            }

            for (i = sizeb-1; ((i >= 2) && (c_upward == 1)); i--)
            {
                
                for (j = sizeb-1; ((j >= 0) && (c_upward == 1)); j--)
                {
                
                    if(board_peg[i][j] == peg && board_peg[i-1][j] == peg && board_peg[i-2][j] == empty){
                        
                        c_upward = 0;    //If there is a move found, stop the loops and return 0.
                    }
                    
                }   
                
            }

            if(c_upward + c_downward + c_backward + c_forward == 4) ctrl = true;
            if(c_upward + c_downward + c_backward + c_forward != 4) ctrl = false;
            return ctrl;
        }

        int PegSolitaire::boardScore(){

            int pegs = 0;
            for (int i = 0; i < board_peg.size(); i++)
            {
                
                for (int j = 0; j < board_peg.size(); j++)       
                {
                    if(board_peg[i][j]==peg) pegs++;    //Counting the peg number.
                    
                    
                }   
            
            }
            return pegs;
        }

        int PegSolitaire::playAutoOver(){

            BoardGame2D::playAutoAll(); //Calls playAutoAll and plays full game
            return 1;
        }

        int PegSolitaire::playUserOver(){

            BoardGame2D::playUser();    //Calls playUser and plays human game
            return 1;
        }

        int PegSolitaire::playVector(vector < BoardGame2D * > vec){

            PegSolitaire *derivedPtr =         //Deriving the base class and playing the game
         dynamic_cast < PegSolitaire * > 
            ( vec[ 0 ] );

            vec[0]->playAutoAll();
            PegSolitaire *derivedPtr2 =         
                dynamic_cast < PegSolitaire * > 
                    ( vec[ 1 ] );
            
            vec[1]->playAutoAll();
            vec[1]->print();
            return 1;
        }

        ostream& operator <<(ostream& outputStream, PegSolitaire board){
           
            int k,l;
            int character=0;
            char ch='A';
            auto i = 0;
            decltype(i) j;
            outputStream << " " << " ";
            for(k=0; k<board.board_peg[0].size(); k++){ //Printing the column alphabets

                character=int(ch);
                outputStream<<ch<<" ";
                character++;
                ch=char(character);

            }
            
            outputStream << endl;
            for (i = 0; i < board.board_peg.size(); i++)
            {
                outputStream << i+1 << " ";
                for (j = 0; j < board.board_peg[i].size(); j++) //Printing the board according to enum
                {
                    if(board.board_peg[i][j]==peg) outputStream << "P" << " ";
                    else if(board.board_peg[i][j]==empty) outputStream << "." << " ";
                    else if(board.board_peg[i][j]==space) outputStream << " " << " ";
                    
                }   
                outputStream << endl;
            }

            outputStream << endl;  

            return outputStream;    //Returning output stream for printing

        }






}
            



    

