/*ILAYDA ARAR CSE241 HW5 1901042638*/
/*Implementation file for slider.h*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>

using namespace std;

#include "slider.h"



namespace nsboard2d{


        Slider::Slider(){
            initialize();
        }
         void Slider::initialize(){	//Returns the size of the set
       
            int randvalues[3*3];
            int randomarray[3][3];
            int m=0;
            int i,j,k,l;
                
                
                
            for(i=0;i<3*3;i++) {    				/*Creating an array with the elements of 0-(N*N-1)*/
                randvalues[i]=i;
            }
                for(i=0;i<3*3;i++)     
                    {
                    k=i+rand()/(RAND_MAX/((3*3)-i) + 1);	/*Shuffling the array with swapping the elements using rand() function*/
                    l=randvalues[k];
                    randvalues[k] = randvalues[i];
                    randvalues[i] = l;
                    }
                
                for ( i = 0; i < 3; i++)
                {
                    for ( j = 0; j < 3; j++)
                    {
                        board_slider[i][j] = randvalues[m++];	/*Filling our array with the randomized array's elements*/
                        
                    }
                    
                }  	            
            
        }

        void Slider::print(){
            int i,j,n;

            
                for(i=0; i<8*3+1; i++)					/*Printing '*' character for a pretty format to work for every case of tables*/
                    {
                        cout << "*";
                }
                    cout << endl;
                    for ( i = 0; i < 3; i++)
                {
                        
                        for ( j = 0; j < 3; j++)
                        { 
                            if(board_slider[i][j]!=0)  cout << "*  " << board_slider[i][j] << "\t"; 	/*Printing the elements of the table as well centered and rounded with '*' character*/
                        else cout << "*  \t";
                    }
                    cout << "*\n";
                        for(n=0; n<8*3+1; n++)
                        {
                            cout << "*";				/*Printing '*' character for a pretty format to work for every case of tables*/
                        }
                    cout << endl;
                    
                }            
        }

        int Slider::moveleft(int i, int j){
            int r;
            int temp;
            int a,b,c,k,l;
            int kntrl;
            int check[3][3];
            a=j;
            
            kntrl=1;
            l=j;
            k=i;
                    for ( l = j-1;l >=0; --l)		/*Searching for the blank space in the way of wanted movement*/
                    {
                    
                    if(board_slider[k][l]==0)		/*If there is blank space, movement can be done*/
                    {
                        kntrl=0;
                        break;
                    }
                
                    
                }
            
            if(kntrl==0){
            for(j=a;j>=0;j--)
            {
                if(board_slider[i][j]==0){		/*Searching for the blank space*/
                    
                    r=j;				/*Assigning the blank space position to a variable to use in swap*/
                    
                    break;
                }
            }
            
            
            j=a;
            c=r;
            for(;j>c;j--)
            {
                temp=board_slider[i][r+1];		/*Swapping the elements with eachother for the sliding movement*/
                board_slider[i][r+1] = board_slider[i][r];
                board_slider[i][r] = temp;
                r++;
            }}
            else cout << "This movement cannot be done. Please enter true positions and movement option\n";
            /*If the movement cannot be done, let the player know that they entered the wrong movement*/
            return 1;
        }

        int Slider::moveright(int i, int j){

            int r;
            int temp;
            int a,b,c,k,l;
            int kntrl;
            int check[3][3];
            a=j;
            
            kntrl=1;
            l=j;
            k=i;
                    for ( l = j+1;l < 3; ++l)			/*Searching for the blank space in the way of wanted movement*/
                    {
                    
                    if(board_slider[k][l]==0)
                    {
                        kntrl=0;				/*If there is blank space, movement can be done*/
                        break;
                    }
                
                    
                }
            
            if(kntrl==0){
            for(j=a;j<3;j++)
            {
                if(board_slider[i][j]==0){			/*Searching for the blank space*/
                    
                    r=j;					/*Assigning the blank space position to a variable to use in swap*/
                    
                    break;
                }
            }
            
            
            j=a;
            c=r;
            for(;j<c;j++)
            {
                temp=board_slider[i][r-1];
                board_slider[i][r-1] = board_slider[i][r];	/*Swapping the elements with eachother for the sliding movement*/
                board_slider[i][r] = temp;
                r--;
            }}
            else cout << "This movement cannot be done. Please enter true positions and movement option\n";
            /*If the movement cannot be done, let the player know that they entered the wrong movement*/
            return 1;
        }

        int Slider::moveup(int i, int j){
            int r;
            int temp;
            int a,b,c,k,l;
            int kntrl;
            int check[3][3];
            a=i;
            
            kntrl=1;
            l=j;
            k=i;
                    for ( k = i-1;k >= 0; --k)			/*Searching for the blank space in the way of wanted movement*/
                    {
                    
                    if(board_slider[k][l]==0)			/*If there is blank space, movement can be done*/
                    {
                        kntrl=0;
                        break;
                    }
                
                    
                }
            
            if(kntrl==0)
            {						
            for(i=a;i>=0;i--)					/*Searching for the blank space*/
            {
                if(board_slider[i][j]==0){
                    
                    r=i;					/*Assigning the blank space position to a variable to use in swap*/
                    
                    break;
                }
            }
            
            
            i=a;
            c=r;
            for(;i>c;i--)
            {
                temp=board_slider[r+1][j];			/*Swapping the elements with eachother for the sliding movement*/
                board_slider[r+1][j] = board_slider[r][j];
                board_slider[r][j] = temp;
                r++;
            }}
            else cout << "This movement cannot be done. Please enter true positions and movement option\n";
            /*If the movement cannot be done, let the player know that they entered the wrong movement*/
            return 1;	
        }

        int Slider::movedown(int i, int j){
            int r;
            int temp;
            int a,b,c,k,l;
            int kntrl;
            int check[3][3];
            a=i;
            
            kntrl=1;
            l=j;
            k=i;
                    for ( k = i+1;k < 3; ++k)			/*Searching for the blank space in the way of wanted movement*/
                    {
                    
                    if(board_slider[k][l]==0)
                    {
                        kntrl=0;				/*If there is blank space, movement can be done*/
                        break;
                    }
                
                    
                }
            
            if(kntrl==0){
            for(i=a;i<3;i++)
            {
                if(board_slider[i][j]==0){			/*Searching for the blank space*/
                    
                    r=i;					/*Assigning the blank space position to a variable to use in swap*/
                    
                    break;
                }
            }
            
            
            i=a;
            c=r;
            for(;i<c;i++)
            {
                temp=board_slider[r-1][j];
                board_slider[r-1][j] = board_slider[r][j];	/*Swapping the elements with eachother for the sliding movement*/
                board_slider[r][j] = temp;
                r--;
            }}
            else cout << "This movement cannot be done. Please enter true positions and movement option\n";
            /*If the movement cannot be done, let the player know that they entered the wrong movement*/
            return 1;

        }

        int Slider::playUser(string input){

            int column, row;
            char way;
            row = ((int)input[0])-49;
            column = ((int)input[1])-49;
            
            way = input[2];
           
            if(way == 'U') moveup(row, column); //Calling the move functions for input way
            if(way == 'D') movedown(row, column);
            if(way == 'R') moveright(row, column);
            if(way == 'L') moveleft(row, column);
            cout << "Your current score is: " << boardScore() << endl;
            return 1;
        }

        

        bool Slider::endgame(){
            /*The winning condition is considered as the blank space can be anywhere but with ordered numbers*/
            int i,j;
            int flag;
            int counter=0;
            
            flag=1;
            for ( i = 0; i < 3; ++i)
            {
                    for ( j = 0; j < 3; ++j)
                    {
                    
                    if(board_slider[i][j]!=0)	/*If the number that the loop encountered is not 0, keep counting */
                    {
                        counter=counter+1;
                        
                    
                if(board_slider[i][j]!=counter) flag=0; /*If the counting is not reached to the wanted number(arrays value) send a 0 for continue*/
                    }
                }
            }
            
            if(flag==1) return true;					/*If the counting is equal, return 1 to be considered as the winning condition*/
            else return false;
        }

        int Slider::boardScore(){
            
            int i,j;
            int count = 0;
            for(i=0; i<3; i++){
                for(j=0; j<2; j++){ //If there are non-continuous numbers, board score increases.

                    if(board_slider[i][j] != ((board_slider[i][j+1]) - 1)) count++;
                }
            }
            
            return count;
        }

        int Slider::playUserOver(){

            BoardGame2D::playUser();
            return 1;
        }

        int Slider::playAuto(){

            int chooser;
            int i,j;
            int temp, col, row;
            int control = 0;
            //usleep(1000000);
            srand (time(0));
            chooser = rand()%4 + 1;
            
            if(chooser == 1){   //Forward move

                for(i=0; i<3; i++){
                    for(j=0; j<2; j++){

                        if(board_slider[i][j+1] == 0) { //Finding the zero in vector
                            col = j;
                            row = i;
                            control = 1;
                        }
                    }
                }
                if(control == 1){
                temp=board_slider[row][col];
                board_slider[row][col] = board_slider[row][col+1];	/*Swapping the elements with eachother for the sliding movement*/
                board_slider[row][col+1] = temp;
                }
            }

            if(chooser == 2){   //Backward move

                for(i=0; i<3; i++){
                    for(j=0; j<2; j++){

                        if(board_slider[i][j] == 0) {
                            col = j;
                            row = i;
                            control = 1;
                        }
                    }
                }
                if(control == 1){
                temp=board_slider[row][col];
                board_slider[row][col] = board_slider[row][col+1];	/*Swapping the elements with eachother for the sliding movement*/
                board_slider[row][col+1] = temp;
                }

            }

            if(chooser == 3){   //Downward move

                for(i=0; i<2; i++){
                    for(j=0; j<3; j++){

                        if(board_slider[i][j+1] == 0) {
                            col = j;
                            row = i;
                            control = 1;
                        }
                    }
                }
                if(control == 1){
                temp=board_slider[row][col];
                board_slider[row][col] = board_slider[row+1][col];	/*Swapping the elements with eachother for the sliding movement*/
                board_slider[row+1][col] = temp;
                }
            }

            if(chooser == 4){   //Upward move

                for(i=0; i<2; i++){
                    for(j=0; j<3; j++){

                        if(board_slider[i][j] == 0) {
                            col = j;
                            row = i;
                            control = 1;
                        }
                    }
                }
                if(control == 1){
                temp=board_slider[row][col];
                board_slider[row][col] = board_slider[row+1][col];	/*Swapping the elements with eachother for the sliding movement*/
                board_slider[row+1][col] = temp;
                }

            }
            if(control == 1) print();
            return 1;
        }

        int Slider::playAutoOver(){

            
            BoardGame2D::playAutoAll(); //Calls the function for playing in derived class
            
            return 1;
        }

        int Slider::playVector(vector < BoardGame2D * > vec){

            Slider *derivedPtr =         //Deriving the base class and playing the game
         dynamic_cast < Slider * > 
            ( vec[ 0 ] );

            vec[0]->playAutoAll();
            Slider *derivedPtr2 =         
                dynamic_cast < Slider * > 
                    ( vec[ 1 ] );
            
            vec[1]->playAutoAll();
            vec[1]->print();
            return 1;
        }

        ostream& operator <<(ostream& outputStream, Slider board){
            int i,j,n;

            for(i=0; i<8*3+1; i++)					/*Printing '*' character for a pretty format to work for every case of tables*/
            {
                  outputStream << "*";
            }
            outputStream << endl;
            for ( i = 0; i < 3; i++)
            {
                        
                for ( j = 0; j < 3; j++)
                { 
                    if(board.board_slider[i][j]!=0)  outputStream << "*  " << board.board_slider[i][j] << "\t"; 	/*Printing the elements of the table as well centered and rounded with '*' character*/
                    else outputStream << "*  \t";
                }
                outputStream << "*\n";
                for(n=0; n<8*3+1; n++)
                {
                    outputStream << "*";				/*Printing '*' character for a pretty format to work for every case of tables*/
                }
                outputStream << endl;
                    
            }            
     
            return outputStream;
            
        }

    

}