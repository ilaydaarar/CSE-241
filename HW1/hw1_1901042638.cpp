/*ILAYDA ARAR CSE241 HW1 1901042638*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum state {peg, empty, space}; //Providing enum type for using in boards.

/*In all of the print_board functions, the goal is printing the game board which user chooses. First I print the uppercase characters on top
of the board within the numbers of rows in the loop. I iterate through the 2D vector and print P, . and space according to selected vector.*/

void print_board_1(vector<vector<state>> board_1){

    cout << " " << " " << "A" << " " << "B" << " " << "C" << " " << "D" << " " << "E" << " " << "F" << " " << "G" << " " << endl;

    for (int i = 0; i < board_1.size(); i++)
    {
        cout << i+1 << " ";
        for (int j = 0; j < board_1[i].size(); j++)
        {
            if(board_1[i][j]==peg) cout << "P" << " ";
            else if(board_1[i][j]==empty) cout << "." << " ";
            else if(board_1[i][j]==space) cout << " " << " ";
            
        }   
        cout << endl;
    }

    cout << endl;

}

void print_board_2(vector<vector<state>> board_2){

    cout << " " << " " << "A" << " " << "B" << " " << "C" << " " << "D" << " " << "E" << " " << "F" << " " << "G" << " " << "H" << " " << "I" << " " << endl;


     for (int i = 0; i < board_2.size(); i++)
    {
        cout << i+1 << " ";
        for (int j = 0; j < board_2[i].size(); j++)
        {
            if(board_2[i][j]==peg) cout << "P" << " ";
            else if(board_2[i][j]==empty) cout << "." << " ";
            else if(board_2[i][j]==space) cout << " " << " ";
            
        }   
        cout << endl;
    }
    cout << endl;
}

void print_board_3(vector<vector<state>> board_3){

    cout << " " << " " << "A" << " " << "B" << " " << "C" << " " << "D" << " " << "E" << " " << "F" << " " << "G" << " " << "H" << " " << " " << endl;

     for (int i = 0; i < board_3.size(); i++)
    {
        cout << i+1 << " ";
        for (int j = 0; j < board_3[i].size(); j++)
        {
            if(board_3[i][j]==peg) cout << "P" << " ";
            else if(board_3[i][j]==empty) cout << "." << " ";
            else if(board_3[i][j]==space) cout << " " << " ";
            
        }   
        cout << endl;
    }

     cout << endl;
}

void print_board_4(vector<vector<state>> board_4){

    cout << " " << " " << "A" << " " << "B" << " " << "C" << " " << "D" << " " << "E" << " " << "F" << " " << "G" << " " << endl;

    for (int i = 0; i < board_4.size(); i++)
    {
        cout << i+1 << " ";
        for (int j = 0; j < board_4[i].size(); j++)
        {
            if(board_4[i][j]==peg) cout << "P" << " ";
            else if(board_4[i][j]==empty) cout << "." << " ";
            else if(board_4[i][j]==space) cout << " " << " ";
            
        }   
        cout << endl;
    }

    cout << endl;
}

void print_board_5(vector<vector<state>> board_5){

    cout << " " << " " << "A" << " " << "B" << " " << "C" << " " << "D" << " " << "E" << " " << "F" << " " << "G" << " " << "H" << " " << "I" << " " << endl;
     for (int i = 0; i < board_5.size(); i++)
    {
        cout << i+1 << " ";
        for (int j = 0; j < board_5[i].size(); j++)
        {
            if(board_5[i][j]==peg) cout << "P" << " ";
            else if(board_5[i][j]==empty) cout << "." << " ";
            else if(board_5[i][j]==space) cout << " " << " ";
            
        }   
        cout << endl;
    }

     cout << endl;

}

void print_board_6(vector<vector<state>> board_6){

    cout << " " << " " << " " << " " << "A" << " " << "B" << " " << "C" << " " << "D" << " " << "E" << " " << "F" << " " << "G" << " " << "H" << " " << "I" << " " << endl;
     for (int i = 0; i < board_6.size(); i++)
    {
        cout << i+1 << " ";
        for (int j = 0; j < board_6[i].size(); j++)
        {
            if(board_6[i][j]==peg) cout << "P" << " ";
            else if(board_6[i][j]==empty) cout << "." << " ";
            else if(board_6[i][j]==space) cout << " " << " ";
            
        }   
        cout << endl;
    }
    cout << endl;
}


void getInput(char& column, int& row, char& move_way){ //Getting the move input from the user.

    cout << "Please enter your move as shown in example: B 4 R (Please put spaces between and nothing else. Write in UPPERCASE" << endl;
    cin >> column >> row >> move_way;

}

/*comp_move_1 function (for computer game) makes a valid move on selected board by iterating through the 2D vector and checking if the checked
move is valid. If the move is valid, makes the move and gets out of the function.*/
int comp_move_1(vector<vector<state>>& board_1, int row, int column){  

    int i,j;
    int win = 1;

    for (i = 0; ((i < row) && (win == 1)); i++)   //Checking for move to the right. (P P .)
    {
        
        for (j = 0; ((j < (column - 2)) && (win == 1)); j++)
        {
           
            if(board_1[i][j] == peg && board_1[i][j+1] == peg && board_1[i][j+2] == empty){
                
                board_1[i][j] = empty;
                board_1[i][j+1] = empty;
                board_1[i][j+2] = peg;

                win = 0;    //If a valid move is found and done, the variable win is 0. So the function won't look for anymore valid moves.
            }
            
        }   

           
    }

    //Every loop has win==1 condition because it means, in the previous loop of checking, there wasn't any valid moves.
    
    for (i = row-1; ((i >= 0) && (win == 1)); --i){ //Checking for move to the left. (. P P)
        
            for (j = column-1; ((j >= 2) && (win == 1)); --j)
            {
            
                if(board_1[i][j] == peg && board_1[i][j-1] == peg && board_1[i][j-2] == empty){ 
                    
                    board_1[i][j] = empty;
                    board_1[i][j-1] = empty;
                    board_1[i][j-2] = peg;
                    win = 0;
                }
                
            }   
        
    }

    for (i = 0; ((i < column - 2) && (win == 1)); i++)  //Checking for move to the down.
    {
        
        for (j = 0; ((j < (row)) && (win == 1)); j++)
        {
           
            if(board_1[i][j] == peg && board_1[i+1][j] == peg && board_1[i+2][j] == empty){
                
                board_1[i][j] = empty;
                board_1[i+1][j] = empty;
                board_1[i+2][j] = peg;
                win = 0;
            }
            
        }   
        
    }

    for (i = column-1; ((i >= 2) && (win == 1)); --i)   //Checking for move to the up.
    {
        
        for (j = row-1; ((j >= 0) && (win == 1)); --j)
        {
           
            if(board_1[i][j] == peg && board_1[i-1][j] == peg && board_1[i-2][j] == empty){

                
                board_1[i][j] = empty;
                board_1[i-1][j] = empty;
                board_1[i-2][j] = peg;
                win = 0;
            }
            
        }   
        
    }

    return win;

}


/*compMove_triangle funtion is designed for Board 6 only because of the cross moves. It is for computer game and it iterates through
the vector and tries to find a valid move by looking at every direction. If finds a valid move, makes the move and gets out of function.*/ 
int compMove_triangle(vector<vector<state>>& board_1, int row, int column){

    int win = 1;
    int i,j;

    for (i = 0; ((i < row) && (win == 1)); i++) //Checking the forward moves. (P P .)
    {
        
        for (j = 0; ((j < (column - 4)) && (win == 1)); j++)
        {
           
            if(board_1[i][j] == peg && board_1[i][j+2] == peg && board_1[i][j+4] == empty){
                
                board_1[i][j] = empty;      // If the condition is valid, changes the vector elements according to the game rule.
                board_1[i][j+2] = empty;
                board_1[i][j+4] = peg;
                win = 0;
            }
            
        }   
        
    }

    for (i = 0; ((i < row-2) && (win == 1)); i++)   //Checking forward for down-right cross moves.
    {
        
        for (j = 0; ((j < (column - 2)) && (win == 1)); j++)
        {
           
            if(board_1[i][j] == peg && board_1[i+1][j+1] == peg && board_1[i+2][j+2] == empty){
                
                board_1[i][j] = empty;
                board_1[i+1][j+1] = empty;
                board_1[i+2][j+2] = peg;
                win = 0;
            }
            
            
        }   
        
    }

    for (i = 2; ((i < row) && (win == 1)); i++) //Checking forward for up-right moves.
    {
        
        for (j = 0; ((j < (column - 2)) && (win == 1)); j++)
        {
           
            
            if(board_1[i][j] == peg && board_1[i-1][j+1] == peg && board_1[i-2][j+2] == empty && win == 1){
                
                board_1[i][j] = empty;
                board_1[i-1][j+1] = empty;
                board_1[i-2][j+2] = peg;
                win = 0;
            }
            
            
        }   
        
    }

    for (i = 2; ((i < row-1) && (win == 1)); i++)   //Checking forward for up-left moves.
    {
        
        for (j = 2; ((j < (column - 1)) && (win == 1)); j++)
        {
           
            if(board_1[i][j] == peg && board_1[i-1][j-1] == peg && board_1[i-2][j-2] == empty){
                
                board_1[i][j] = empty;
                board_1[i-1][j-1] = empty;
                board_1[i-2][j-2] = peg;
                win = 0;
            }
            
        }   
        
    }

    for (i = row-1; ((i >= 0) && (win == 1)); --i)  //Checking backward for backward moves. (. P P)
    {
        
        for (j = column-1; ((j >= 4) && (win == 1)); --j)
        {
           
            if(board_1[i][j] == peg && board_1[i][j-2] == peg && board_1[i][j-4] == empty){
                
                board_1[i][j] = empty;
                board_1[i][j-2] = empty;
                board_1[i][j-4] = peg;
                win = 0;
            }
            
        }   
        
    }
    
    for (i = row-1; ((i >= 2) && (win == 1)); --i) //Checking backward for up-left moves.
    {
        
        for (j = column-1; ((j >= 2) && (win == 1)); --j)
        {
           
            if(board_1[i][j] == peg && board_1[i-1][j-1] == peg && board_1[i-2][j-2] == empty){
                
                board_1[i][j] = empty;
                board_1[i-1][j-1] = empty;
                board_1[i-2][j-2] = peg;
                win = 0;
            }
            
        }   
        
    }

    return win;

}

/*move_board1 function is for the making and controlling (validitiy) moves made by human user on BOARD 1.*/
int move_board1(vector<vector<state>>& board_1, char column, int row, char move_way){

    int control = 0;

    getInput(column, row, move_way);    //Calling the get input function for user input.

    if(((int)column > 64 && (int)column < 72) && row > 0 && row < 8)    //Checking validity of user input's row and column
    {
        control = 1;
    }
    
    //If user tries to make a down or up move for the edge of the board, that is invalid*/
    if((row == 1 && move_way == 'U') || (row == 2 && move_way == 'U') || (row == 6 && move_way == 'D') || (row == 7 && move_way == 'D')){
        control = 0;
    }

    //All of the if conditions below has control == 1. If the move is not valid, control = 0 so the move is not going to happen.

    //Right move
    if( control == 1 && move_way == 'R' && board_1[row-1][((int)column - 65)] == peg && board_1[row-1][((int)column - 64)] == peg && board_1[row-1][((int)column - 63)] == empty){

        board_1[row-1][((int)column - 65)] = empty;
        board_1[row-1][((int)column - 64)] = empty;
        board_1[row-1][((int)column - 63)] = peg;

    }
    //Left move
    else if(control == 1 && move_way == 'L' && board_1[row-1][((int)column - 65)] == peg && board_1[row-1][((int)column - 66)] == peg && board_1[row-1][((int)column - 67)] == empty){

        board_1[row-1][((int)column - 65)] = empty;
        board_1[row-1][((int)column - 66)] = empty;
        board_1[row-1][((int)column - 67)] = peg;

    }
    //Up move
    else if(control == 1 && move_way == 'U' && board_1[row-1][((int)column - 65)] == peg && board_1[row-2][((int)column - 65)] == peg && board_1[row-3][((int)column - 65)] == empty){

        board_1[row-1][((int)column - 65)] = empty;
        board_1[row-2][((int)column - 65)] = empty;
        board_1[row-3][((int)column - 65)] = peg;

    }
    //Down move
    else if(control ==1 && move_way == 'D' && board_1[row-1][((int)column - 65)] == peg && board_1[row][((int)column - 65)] == peg && board_1[row+1][((int)column - 65)] == empty){

        board_1[row-1][((int)column - 65)] = empty;
        board_1[row][((int)column - 65)] = empty;
        board_1[row+1][((int)column - 65)] = peg;

    }
    else cout << "You did not enter a valid input, please try again" << endl;   //If none of the conditions fail to provide, print error mesage.
    
    
    return control;
}

/*move_board2 function is for the making and controlling (validitiy) moves made by human user on BOARD 2.*/
int move_board2(vector<vector<state>>& board_2, char column, int row, char move_way){

    int control = 0;
    getInput(column, row, move_way); //Calling the get input function for user input.

    if(((int)column > 64 && (int)column < 74) && row > 0 && row < 10)   //Checking validity of user input's row and column
    {
        control = 1;
    }
    //If user tries to make a down or up move for the edge of the board, that is invalid*/
    if((row == 1 && move_way == 'U') || (row == 2 && move_way == 'U') || (row == 8 && move_way == 'D') || (row == 9 && move_way == 'D')){
        control = 0;
    }
    
    //All of the if conditions below has control == 1. If the move is not valid, control = 0 so the move is not going to happen.

    if(control == 1 && move_way == 'R' && board_2[row-1][((int)column - 65)] == peg && board_2[row-1][((int)column - 64)] == peg && board_2[row-1][((int)column - 63)] == empty){

        board_2[row-1][((int)column - 65)] = empty;
        board_2[row-1][((int)column - 64)] = empty;
        board_2[row-1][((int)column - 63)] = peg;

    }
    else if(control == 1 && move_way == 'L' && board_2[row-1][((int)column - 65)] == peg && board_2[row-1][((int)column - 66)] == peg && board_2[row-1][((int)column - 67)] == empty){

        board_2[row-1][((int)column - 65)] = empty;
        board_2[row-1][((int)column - 66)] = empty;
        board_2[row-1][((int)column - 67)] = peg;

    }
    else if(control == 1 && move_way == 'U' && board_2[row-1][((int)column - 65)] == peg && board_2[row-2][((int)column - 65)] == peg && board_2[row-3][((int)column - 65)] == empty){

        board_2[row-1][((int)column - 65)] = empty;
        board_2[row-2][((int)column - 65)] = empty;
        board_2[row-3][((int)column - 65)] = peg;

    }
    else if(control == 1 && move_way == 'D' && board_2[row-1][((int)column - 65)] == peg && board_2[row][((int)column - 65)] == peg && board_2[row+1][((int)column - 65)] == empty){

        board_2[row-1][((int)column - 65)] = empty;
        board_2[row][((int)column - 65)] = empty;
        board_2[row+1][((int)column - 65)] = peg;

    }
    else cout << "You did not enter a valid input, please try again" << endl;
    
   
    return control;
}

/*move_board3 function is for the making and controlling (validitiy) moves made by human user on BOARD 3.*/
int move_board3(vector<vector<state>>& board_3, char column, int row, char move_way){

    int control = 0;

    getInput(column, row, move_way); //Calling the get input function for user input.

    if(((int)column > 64 && (int)column < 73) && row > 0 && row < 9)    //Checking validity of user input's row and column
    {
        control = 1;
    }
    //If user tries to make a down or up move for the edge of the board, that is invalid*/
    if((row == 1 && move_way == 'U') || (row == 2 && move_way == 'U') || (row == 7 && move_way == 'D') || (row == 8 && move_way == 'D')){
        control = 0;
    }
    
    //All of the if conditions below has control == 1. If the move is not valid, control = 0 so the move is not going to happen.
    //Right move
    if(control == 1 && move_way == 'R' && board_3[row-1][((int)column - 65)] == peg && board_3[row-1][((int)column - 64)] == peg && board_3[row-1][((int)column - 63)] == empty){

        board_3[row-1][((int)column - 65)] = empty;
        board_3[row-1][((int)column - 64)] = empty;
        board_3[row-1][((int)column - 63)] = peg;

    }
    //Left move
    else if(control == 1 && move_way == 'L' && board_3[row-1][((int)column - 65)] == peg && board_3[row-1][((int)column - 66)] == peg && board_3[row-1][((int)column - 67)] == empty){

        board_3[row-1][((int)column - 65)] = empty;
        board_3[row-1][((int)column - 66)] = empty;
        board_3[row-1][((int)column - 67)] = peg;

    }
    //Up move
    else if(control == 1 && move_way == 'U' && board_3[row-1][((int)column - 65)] == peg && board_3[row-2][((int)column - 65)] == peg && board_3[row-3][((int)column - 65)] == empty){

        board_3[row-1][((int)column - 65)] = empty;
        board_3[row-2][((int)column - 65)] = empty;
        board_3[row-3][((int)column - 65)] = peg;

    }
    //Down move
    else if(control == 1 && move_way == 'D' && board_3[row-1][((int)column - 65)] == peg && board_3[row][((int)column - 65)] == peg && board_3[row+1][((int)column - 65)] == empty){

        board_3[row-1][((int)column - 65)] = empty;
        board_3[row][((int)column - 65)] = empty;
        board_3[row+1][((int)column - 65)] = peg;

    }
    else cout << "You did not enter a valid input, please try again" << endl;
    
    
    return control;
}

/*move_board4 function is for the making and controlling (validitiy) moves made by human user on BOARD 4.*/
int move_board4(vector<vector<state>>& board_4, char column, int row, char move_way){

    int control = 0;

    getInput(column, row, move_way); //Calling the get input function for user input.

    if(((int)column > 64 && (int)column < 72) && row > 0 && row < 8)    //Checking validity of user input's row and column
    {
        control = 1;
    }
    //If user tries to make a down or up move for the edge of the board, that is invalid*/
    if((row == 1 && move_way == 'U') || (row == 2 && move_way == 'U') || (row == 6 && move_way == 'D') || (row == 7 && move_way == 'D')){
        control = 0;
    }

    //All of the if conditions below has control == 1. If the move is not valid, control = 0 so the move is not going to happen.

    //Right move
    if(control == 1 && move_way == 'R' && board_4[row-1][((int)column - 65)] == peg && board_4[row-1][((int)column - 64)] == peg && board_4[row-1][((int)column - 63)] == empty){

        board_4[row-1][((int)column - 65)] = empty;
        board_4[row-1][((int)column - 64)] = empty;
        board_4[row-1][((int)column - 63)] = peg;

    }
    //Left move
    else if(control == 1 && move_way == 'L' && board_4[row-1][((int)column - 65)] == peg && board_4[row-1][((int)column - 66)] == peg && board_4[row-1][((int)column - 67)] == empty){

        board_4[row-1][((int)column - 65)] = empty;
        board_4[row-1][((int)column - 66)] = empty;
        board_4[row-1][((int)column - 67)] = peg;

    }
    //Up move
    else if(control == 1 && move_way == 'U' && board_4[row-1][((int)column - 65)] == peg && board_4[row-2][((int)column - 65)] == peg && board_4[row-3][((int)column - 65)] == empty){

        board_4[row-1][((int)column - 65)] = empty;
        board_4[row-2][((int)column - 65)] = empty;
        board_4[row-3][((int)column - 65)] = peg;

    }
    //Down move
    else if(control == 1 && move_way == 'D' && board_4[row-1][((int)column - 65)] == peg && board_4[row][((int)column - 65)] == peg && board_4[row+1][((int)column - 65)] == empty){

        board_4[row-1][((int)column - 65)] = empty;
        board_4[row][((int)column - 65)] = empty;
        board_4[row+1][((int)column - 65)] = peg;

    }
    else cout << "You did not enter a valid input, please try again" << endl;
    
   
    return control;
}

/*move_board5 function is for the making and controlling (validitiy) moves made by human user on BOARD 5.*/
int move_board5(vector<vector<state>>& board_5, char column, int row, char move_way){

    int control = 0;

    getInput(column, row, move_way); //Calling the get input function for user input.

    if(((int)column > 64 && (int)column < 74) && row > 0 && row < 10)   //Checking validity of user input's row and column
    {
        control = 1;
    }
    //If user tries to make a down or up move for the edge of the board, that is invalid*/
    if((row == 1 && move_way == 'U') || (row == 2 && move_way == 'U') || (row == 8 && move_way == 'D') || (row == 9 && move_way == 'D')){
        control = 0;
    }

    //All of the if conditions below has control == 1. If the move is not valid, control = 0 so the move is not going to happen.

    //Right move
    if(control == 1 && move_way == 'R' && board_5[row-1][((int)column - 65)] == peg && board_5[row-1][((int)column - 64)] == peg && board_5[row-1][((int)column - 63)] == empty){

        board_5[row-1][((int)column - 65)] = empty;
        board_5[row-1][((int)column - 64)] = empty;
        board_5[row-1][((int)column - 63)] = peg;

    }
    //Left move
    else if(control == 1 && move_way == 'L' && board_5[row-1][((int)column - 65)] == peg && board_5[row-1][((int)column - 66)] == peg && board_5[row-1][((int)column - 67)] == empty){

        board_5[row-1][((int)column - 65)] = empty;
        board_5[row-1][((int)column - 66)] = empty;
        board_5[row-1][((int)column - 67)] = peg;

    }
    //Up move
    else if(control == 1 && move_way == 'U' && board_5[row-1][((int)column - 65)] == peg && board_5[row-2][((int)column - 65)] == peg && board_5[row-3][((int)column - 65)] == empty){

        board_5[row-1][((int)column - 65)] = empty;
        board_5[row-2][((int)column - 65)] = empty;
        board_5[row-3][((int)column - 65)] = peg;

    }
    //Down move
    else if(control == 1 && move_way == 'D' && board_5[row-1][((int)column - 65)] == peg && board_5[row][((int)column - 65)] == peg && board_5[row+1][((int)column - 65)] == empty){

        board_5[row-1][((int)column - 65)] = empty;
        board_5[row][((int)column - 65)] = empty;
        board_5[row+1][((int)column - 65)] = peg;

    }
    else cout << "You did not enter a valid input, please try again" << endl;
    
    
    return control;
}

/*move_board6 function is for the making and controlling (validitiy) moves made by human user on BOARD 6.*/
int move_board6(vector<vector<state>>& board_6, char column, int row, char move_way){

    int control = 0;
    int up_down_move;

    getInput(column, row, move_way); //Calling the get input function for user input.

    if(((int)column > 64 && (int)column < 74) && row > 0 && row < 6)    //Checking validity of user input's row and column
    {
        control = 1;

    }
    //If user tries to make a down move for the edge of the board, that is invalid*/
    if((row == 4 && move_way == 'D') || (row == 5 && move_way == 'D')){

        control = 0;
    }

    //All of the if conditions below has control == 1. If the move is not valid, control = 0 so the move is not going to happen.

    //Right move
    if(control == 1 && move_way == 'R' && board_6[row-1][((int)column - 64)] == peg && board_6[row-1][((int)column - 62)] == peg && board_6[row-1][((int)column - 60)] == empty){

        board_6[row-1][((int)column - 64)] = empty;
        board_6[row-1][((int)column - 62)] = empty;
        board_6[row-1][((int)column - 60)] = peg;

    }

    //Left move
    else if(control == 1 && move_way == 'L' && board_6[row-1][((int)column - 64)] == peg && board_6[row-1][((int)column - 66)] == peg && board_6[row-1][((int)column - 68)] == empty){

        board_6[row-1][((int)column - 64)] = empty;
        board_6[row-1][((int)column - 66)] = empty;
        board_6[row-1][((int)column - 68)] = peg;

    }

    //Up right and up left moves
    else if(control == 1 && move_way == 'U' && board_6[row-1][((int)column - 64)] == peg){
        if(board_6[row-2][((int)column - 65)] == peg && board_6[row-2][((int)column - 63)] == peg && board_6[row-3][((int)column - 66)] == empty && board_6[row-3][((int)column - 63)] == empty){
            cout << "You have two options for UP move. If you want to go UP-RIGHT PRESS 1. If you want to go UP-LEFT PRESS 2." << endl;
            cin >> up_down_move;
            cout << up_down_move << endl;
            //If there is 2 options for up move, user decides the way.
            if(up_down_move == 1){  //Up rigth move
                
                board_6[row-1][((int)column - 64)] = empty;
                board_6[row-2][((int)column - 63)] = empty;
                board_6[row-3][((int)column - 62)] = peg;

            }
            else if(up_down_move == 2){ //Up left move
                
                board_6[row-1][((int)column - 64)] = empty;
                board_6[row-2][((int)column - 65)] = empty;
                board_6[row-3][((int)column - 66)] = peg;

            }

        }
        //Up left move with 1 option
        else if(board_6[row-2][((int)column - 65)] == peg && board_6[row-3][((int)column - 66)] == empty){
            
            board_6[row-1][((int)column - 64)] = empty;
            board_6[row-2][((int)column - 65)] = empty;
            board_6[row-3][((int)column - 66)] = peg;

        }
        //Up right move with 1 option
        else if(board_6[row-2][((int)column - 63)] == peg && board_6[row-3][((int)column - 62)] == empty){
            board_6[row-1][((int)column - 64)] = empty;
            board_6[row-2][((int)column - 63)] = empty;
            board_6[row-3][((int)column - 62)] = peg;

        }

        else cout << "You did not enter a valid input, please try again" << endl;


    }
    //Down right and down left moves
    else if(control == 1 && move_way == 'D' && board_6[row-1][((int)column - 64)] == peg){
        if(board_6[row][((int)column - 65)] == peg && board_6[row][((int)column - 63)] == peg && board_6[row+1][((int)column - 66)] == empty && board_6[row+1][((int)column - 62)] == empty){
            cout << "You have two options for DOWN move. If you want to go DOWN-RIGHT PRESS 1. If you want to go DOWN-LEFT PRESS 2." << endl;
            cin >> up_down_move;
            //If there is 2 options for down move, user decides the way.

            if(up_down_move == 1){ //Down right move
                
                board_6[row-1][((int)column - 64)] = empty;
                board_6[row][((int)column - 63)] = empty;
                board_6[row+1][((int)column - 62)] = peg;

            }
            else if(up_down_move == 2){ //Down left move
    
                
                board_6[row-1][((int)column - 64)] = empty;
                board_6[row][((int)column - 65)] = empty;
                board_6[row+1][((int)column - 66)] = peg;

            }
        }
        //Down left move with one option
        else if(board_6[row][((int)column - 65)] == peg && board_6[row+1][((int)column - 66)] == empty){
            board_6[row-1][((int)column - 64)] = empty;
            board_6[row][((int)column - 65)] = empty;
            board_6[row+1][((int)column - 66)] = peg;

        }
        //Down right move with one option
        else if(board_6[row][((int)column - 63)] == peg && board_6[row+1][((int)column - 62)] == empty){
            board_6[row-1][((int)column - 64)] = empty;
            board_6[row][((int)column - 63)] = empty;
            board_6[row+1][((int)column - 62)] = peg;

        }
        else cout << "You did not enter a valid input, please try again" << endl;



    }

    else cout << "You did not enter a valid input, please try again" << endl;

    //Error message for invalid input
    if(control != 1) cout << "You did not enter a valid input, please try again" << endl;
    
    return control;



}

int count_peg(vector<vector<state>> board_1, int row, int column, int& peg_count){  //This function counts the pegs on board.

    int i, j;
    
    peg_count = 0;

    for (i = 0; i < row; i++)
    {
        
        for (j = 0; j <column; j++)
        {
           
            if(board_1[i][j] == peg){   //If there is a peg found, peg_count increases by 1.
               
                peg_count++;
            }
            
        }   
        
    }
   
   return peg_count;        //Returning the peg_count for using in the displaying of score at the end of the game.

}

/*check_forward function checks if there is any valid moves left in the given board by iterating through vector*/
int check_forward(vector<vector<state>> board_1, int row, int column){

    int i, j;
    int win = 1;

    for (i = 0; ((i < row) && (win == 1)); i++)
    {
        
        for (j = 0; ((j < (column - 2)) && (win == 1)); j++)
        {
           
            if(board_1[i][j] == peg && board_1[i][j+1] == peg && board_1[i][j+2] == empty){
                
                win = 0;    //If there is a move found, stop the loops and return 0.
            }
            
        }   
        
    }
    
    if(win == 0) return 0;
    else {
        return 1;
    }
}

/*check_backward function checks if there is any valid moves left in the given board by iterates back through vector*/
int check_backward(vector<vector<state>> board_1, int row, int column){

    int i, j;
    int win = 1;

    for (i = row-1; ((i >= 0) && (win == 1)); --i)
    {
        
        for (j = column-1; ((j >= 2) && (win == 1)); --j)
        {
           
            if(board_1[i][j] == peg && board_1[i][j-1] == peg && board_1[i][j-2] == empty){
                
                win = 0;    //If there is a move found, stop the loops and return 0.
            }
            
        }   
        
    }
    
    if(win == 0) return 0;  
    else {
        return 1;
    }
}

/*check_downard function checks if there is any valid moves left in the given board by iterates down to up through vector*/
int check_downward(vector<vector<state>> board_1, int row, int column){

    int i, j;
    int win = 1;

    for (i = 0; ((i < column - 2) && (win == 1)); i++)
    {
        
        for (j = 0; ((j < (row)) && (win == 1)); j++)
        {
           
            if(board_1[i][j] == peg && board_1[i+1][j] == peg && board_1[i+2][j] == empty){
                
                win = 0;    //If there is a move found, stop the loops and return 0.
            }
            
        }   
        
    }
    
    if(win == 0) return 0; 
    else {
        return 1;
    }
}

/*check_upward function checks if there is any valid moves left in the given board by iterates up to down through vector*/
int check_upward(vector<vector<state>> board_1, int row, int column){

    int i, j;
    int win = 1;

    for (i = column-1; ((i >= 2) && (win == 1)); --i)
    {
        
        for (j = row-1; ((j >= 0) && (win == 1)); --j)
        {
           
            if(board_1[i][j] == peg && board_1[i-1][j] == peg && board_1[i-2][j] == empty){
                
                win = 0;    //If there is a move found, stop the loops and return 0.
            }
            
        }   
        
    }
    
    if(win == 0) return 0; 
    else {
        return 1;
    }
}

/*check_forward_triangle checks forward by iterating in vector board and looks for valid moves one by one.*/
int check_forward_triangle(vector<vector<state>> board_1, int row, int column){

    int win = 1;
    int i,j;

    for (i = 0; ((i < row) && (win == 1)); i++) //Checking R moves
    {
        
        for (j = 0; ((j < (column - 4)) && (win == 1)); j++)
        {
           
            if(board_1[i][j] == peg && board_1[i][j+2] == peg && board_1[i][j+4] == empty){
                
                win = 0;    //If there is a move found, stop the loop and return 0. Same in every loop in this function.
            }
            
        }   
        
    }

    for (i = 0; ((i < row-2) && (win == 1)); i++)   //Checking Right-Down moves
    {
        
        for (j = 0; ((j < (column - 2)) && (win == 1)); j++)
        {
           
            if(board_1[i][j] == peg && board_1[i+1][j+1] == peg && board_1[i+2][j+2] == empty){
                
                win = 0;
            }
            
            
            
        }   
        
    }

    for (i = 2; ((i < row) && (win == 1)); i++) //Checking Up-right moves
    {
        
        for (j = 0; ((j < (column - 2)) && (win == 1)); j++)
        {
           
            
            if(board_1[i][j] == peg && board_1[i-1][j+1] == peg && board_1[i-2][j+2] == empty){
                
                
                win = 0;
            }
            
            
        }   
        
    }
  
    for (i = 2; ((i < row-1) && (win == 1)); i++)   //Checking Up left moves
    {
        
        for (j = 2; ((j < (column - 1)) && (win == 1)); j++)
        {
           
            if(board_1[i][j] == peg && board_1[i-1][j-1] == peg && board_1[i-2][j-2] == empty){
                
                win = 0;
            }
            
        }   
        
    }

    for (i = 0; ((i < row-2) && (win == 1)); i++)   //Checking Down left moves
    {
        
        for (j = 2; ((j < (column - 2)) && (win == 1)); j++)
        {
           
            if(board_1[i][j] == peg && board_1[i+1][j-1] == peg && board_1[i+2][j-2] == empty){
                
                win = 0;
            }
            
        }   
        
    }
    
    if(win == 0) return 0;
    else {
        return 1;
    }


}

/*check_backward_triangle checks backward by iterating in vector board and looks for valid moves one by one.*/
int check_backward_triangle(vector<vector<state>> board_1, int row, int column){

    int i, j;
    int win = 1;

    for (i = row-1; ((i >= 0) && (win == 1)); --i) //Check L moves
    {
        
        for (j = column-1; ((j >= 4) && (win == 1)); --j)
        {
           
            if(board_1[i][j] == peg && board_1[i][j-2] == peg && board_1[i][j-4] == empty){
                
                win = 0;    //If there is a move found, stop the loop and return 0. Same in every loop in this function.
            }
            
        }   
        
    }
    
    for (i = row-1; ((i >= 2) && (win == 1)); --i)  //Check for Up Left moves
    {
        
        for (j = column-1; ((j >= 2) && (win == 1)); --j)
        {
           
            if(board_1[i][j] == peg && board_1[i-1][j-1] == peg && board_1[i-2][j-2] == empty){
                
                win = 0;
            }
            
        }   
        
    }
    
    
    if(win == 0) return 0;
    else {
        return 1;
    }


}




int main()
{

    //Variables for user input and move parameters.
    char column, move_way;
    int row;
    
    //Variables for selecting the board, game type and user input controls of these variables.
    int select_board;
    int ctrl_Board_Input = 0;
    int ctrl_gametype = 0;
    int gametype;

    //Variables for game-win check.
    int ctrl_upward = 0, ctrl_downward = 0, ctrl_forward = 0, ctrl_backward = 0;
    int peg_count = 0;

    //Variables for computer game controls.
    int compMove = 1;
    int comp_ctrl = 0;
    int compMoveControl;
    
    //Initializing the 2D vectors for board types. Space means space (' '), peg means pegs in the game ('P') and empty means empty slots ('.').
    
    vector<vector<state>> board_1   //7x7 BOARD, BOARD 1.
    {
        
        {space, space, peg, peg, peg, space, space},
        {space, peg, peg, peg, peg, peg, space},
        {peg, peg, peg, peg, peg, peg, peg},
        {peg, peg, peg, empty, peg, peg, peg},
        {peg, peg, peg, peg, peg, peg, peg},
        {space, peg, peg, peg, peg, peg, space},
        {space, space, peg, peg, peg, space, space}
    };

    vector<vector<state>> board_2   //9x9 BOARD, BOARD 2.
    {
        
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

    vector<vector<state>> board_3   //8x8 BOARD, BOARD 3.
    {
        
        {space, space, peg, peg, peg, space, space, space},
        {space, space, peg, peg, peg, space, space, space},
        {space, space, peg, peg, peg, space, space, space},
        {peg, peg, peg, peg, peg, peg, peg, peg},
        {peg, peg, peg, empty, peg, peg, peg, peg},
        {peg, peg, peg, peg, peg, peg, peg, peg},
        {space, space, peg, peg, peg, space, space, space},
        {space, space, peg, peg, peg, space, space, space},
        
    };

    vector<vector<state>> board_4   //7x7 BOARD, BOARD 4.
    {
        
        {space, space, peg, peg, peg, space, space},
        {space, space, peg, peg, peg, space, space},
        {peg, peg, peg, peg, peg, peg, peg},
        {peg, peg, peg, empty, peg, peg, peg},
        {peg, peg, peg, peg, peg, peg, peg},
        {space, space, peg, peg, peg, space, space},
        {space, space, peg, peg, peg, space, space}
    };

     vector<vector<state>> board_5  //9x9 BOARD, BOARD 5.
    {
        
        {space, space, space, space, peg, space, space, space, space},
        {space, space, space, peg, peg, peg, space, space, space},
        {space, space, peg, peg, peg, peg, peg, space, space},
        {space, peg, peg, peg, peg, peg, peg, peg, space},
        {peg, peg, peg, peg, empty, peg, peg, peg, peg},
        {space, peg, peg, peg, peg, peg, peg, peg, space},
        {space, space, peg, peg, peg, peg, peg, space, space},
        {space, space, space, peg, peg, peg, space, space, space},
        {space, space, space, space, peg, space, space, space, space}
    };

    vector<vector<state>> board_6   // 5X11 BOARD. BOARD 6. Extra spaces added because of cross moves and compatibility with check conditions.
    {
        
        {space, space, space, space, space, empty, space, space, space, space, space},
        {space, space, space, space, peg, space , peg, space, space, space, space},
        {space, space, space,  peg, space, peg, space, peg, space, space, space},
        {space, space, peg, space, peg, space, peg, space, peg, space, space},
        {space, peg, space, peg, space, peg, space, peg, space, peg, space}
    };

//--------------------------SELECTING THE BOARD AND GAME TYPE------------------------//  
  
    cout << "Welcome to the PEG SOLITAIRE. Please input the board that you want to play with. Ex: If you want to play with board 4, enter 4." << endl;
    
    while(ctrl_Board_Input==0){ //Till the user enters the valid board type input, keep displaying the boards and asking for input.

        cout << "BOARD 1" << endl;  //Displaying the boards by calling the printing functions made for them.
        print_board_1(board_1);
        cout << "BOARD 2" << endl;
        print_board_2(board_2);
        cout << "BOARD 3" << endl;
        print_board_3(board_3);
        cout << "BOARD 4" << endl;
        print_board_4(board_4);
        cout << "BOARD 5" << endl;
        print_board_5(board_5);
        cout << "BOARD 6" << endl;
        print_board_6(board_6);

        cin >> select_board;    //Taking user input for board type.

        if (select_board>6 || select_board <1){
            cout << "The input for board selection should be between 1-6. Please enter a valid input." << endl;
            ctrl_Board_Input = 0;   //Putting a condition on the while loop for invalid user input.

        }
        else if(select_board < 7 || select_board > 0) ctrl_Board_Input = 1;
            
    }

    cout << "You choosed BOARD " << select_board << "." << endl;    //Giving information to user about their choosings.
    cout << "Please choose the game type. If you want to play HUMAN GAME, ENTER 1. If you want to COMPUTER PLAY, ENTER 2" << endl;

    while(ctrl_gametype==0){    //Till the user gives the right input, keep asking for valid input.
        cin >> gametype;

        if(gametype < 1 || gametype >2){
             cout << "The input for gametype selection should be 1 or 2. Please enter a valid input." << endl;
             ctrl_gametype = 0;
        }
        else if(gametype == 1 || gametype == 2) ctrl_gametype = 1;
    }
    
    //Letting the user know the game and board type they have choosed.
    if(gametype == 1) cout << "You choosed to play human game with BOARD " << select_board << endl;
    if(gametype == 2) cout << "You choosed to play computer game with BOARD " << select_board << endl; 


//------------------------GAME PLAY CONDITIONS-----------------------------//

//----------------------------COMPUTER GAME--------------------------------//


    if(select_board == 1 && gametype == 2){ //Condition for COMPUTER GAME FOR BOARD 1.
        
        print_board_1(board_1); //Printing the initial board.
        
        while(comp_ctrl == 0){  //While there is still valid moves (see comp_move_1 func) keep going.
            
            compMoveControl = 0;
            while(compMoveControl == 0){    //Asking to user enter 1 for computer to make a move
                cout << "Please for to computer make a move, enter 1" << endl;
                cin >> compMove; 
                if(compMove == 1) compMoveControl = 1;
            }
           
            if(compMove == 1) compMoveControl = 1;
            comp_ctrl = comp_move_1(board_1, 7,7);  //Calling the computer move function to make a move.
            
            if(comp_ctrl == 1) {    //If comp_move_1 returned 1, it means there was no more valid moves, so game ends with displaying score
                cout << "GAME OVER" << endl;
                count_peg(board_1,7,7,peg_count);
                cout << "COMPUTER FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND" << endl;
            }
            if(comp_ctrl == 0) cout << "LET'S CONTINUE!" << endl; //If comp_move_1 returned 0, it means there is still valid moves.
            print_board_1(board_1); //Printing the board to show the move that was done.
        }
        
        

    }

//The conditions and gameplay is same for all.
//(same with the above if condition with gametype == 2 && select_board == 1) of the computer game conditioned if statements. 

    if(select_board == 2 && gametype == 2){ //Condition for COMPUTER GAME FOR BOARD 2.

        print_board_2(board_2);
        while(comp_ctrl == 0){
            
            compMoveControl = 0;
            while(compMoveControl == 0){
                cout << "Please for to computer make a move, press 1" << endl;
                cin >> compMove; 
                if(compMove == 1) compMoveControl = 1;
            }
           
            if(compMove == 1) compMoveControl = 1;
            comp_ctrl = comp_move_1(board_2, 9,9);
            if(comp_ctrl == 1) {
                cout << "GAME OVER" << endl;
                count_peg(board_2,9,9,peg_count);
                cout << "COMPUTER FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND" << endl;
            }
            if(comp_ctrl == 0) cout << "LET'S CONTINUE!" << endl;
            print_board_2(board_2);
        }
        
        

    }

    if(select_board == 3 && gametype == 2){ //Condition for COMPUTER GAME FOR BOARD 3.

        print_board_3(board_3);
        while(comp_ctrl == 0){
            
            compMoveControl = 0;
            while(compMoveControl == 0){
                cout << "Please for to computer make a move, press 1" << endl;
                cin >> compMove; 
                if(compMove == 1) compMoveControl = 1;
            }
           
            if(compMove == 1) compMoveControl = 1;
            comp_ctrl = comp_move_1(board_3, 8,8);
            if(comp_ctrl == 1) {
                cout << "GAME OVER" << endl;
                count_peg(board_3,8,8,peg_count);
                cout << "COMPUTER FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND" << endl;
            }
            if(comp_ctrl == 0) cout << "LET'S CONTINUE!" << endl;
            print_board_3(board_3);
        }
        

    }

    if(select_board == 4 && gametype == 2){  //Condition for COMPUTER GAME FOR BOARD 4.

        print_board_4(board_4);
        while(comp_ctrl == 0){
            
            compMoveControl = 0;
            while(compMoveControl == 0){
                cout << "Please for to computer make a move, press 1" << endl;
                cin >> compMove; 
                if(compMove == 1) compMoveControl = 1;
            }
           
            if(compMove == 1) compMoveControl = 1;
            comp_ctrl = comp_move_1(board_4, 7,7);
            if(comp_ctrl == 1) {
                cout << "GAME OVER" << endl;
                count_peg(board_4,7,7,peg_count);
                cout << "COMPUTER FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND" << endl;
            }
            if(comp_ctrl == 0) cout << "LET'S CONTINUE!" << endl;
            print_board_4(board_4);
        }
        

    }

    if(select_board == 5 && gametype == 2){ //Condition for COMPUTER GAME FOR BOARD 5.

       print_board_5(board_5);
        while(comp_ctrl == 0){
            
            compMoveControl = 0;
            while(compMoveControl == 0){
                cout << "Please for to computer make a move, press 1" << endl;
                cin >> compMove; 
                if(compMove == 1) compMoveControl = 1;
            }
           
            if(compMove == 1) compMoveControl = 1;
            comp_ctrl = comp_move_1(board_5, 9,9);
            if(comp_ctrl == 1) {
                cout << "GAME OVER" << endl;
                count_peg(board_5,9,9,peg_count);
                cout << "COMPUTER FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND" << endl;
            }
            if(comp_ctrl == 0) cout << "LET'S CONTINUE!" << endl;
            print_board_5(board_5);
        }

    }

    if(select_board == 6 && gametype == 2){ //Condition for COMPUTER GAME FOR BOARD 6.
        print_board_6(board_6);
        while(comp_ctrl == 0){
            
            compMoveControl = 0;
            while(compMoveControl == 0){
                cout << "Please for to computer make a move, press 1" << endl;
                cin >> compMove; 
                if(compMove == 1) compMoveControl = 1;
            }
            comp_ctrl = compMove_triangle(board_6, 5,11);   //Calling the compMove_triangle function which contains cross moves.
            if(comp_ctrl == 1){
                cout << "GAME OVER" << endl;
                count_peg(board_6,5,11,peg_count);  
                cout << "COMPUTER FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND" << endl;

            }
            if(comp_ctrl == 0) cout << "LET'S CONTINUE!" << endl;
            print_board_6(board_6);
        }
        
        

    }

//--------------------END OF COMPUTER GAME--------------------------------//

//------------------------HUMAN GAME--------------------------------------//

    if(select_board==1 && gametype==1){ //Condition for playing HUMAN GAME with BOARD 1.

        print_board_1(board_1); //Printing the initial board.
        while(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward != 4){ //Playing the game till there is no valid move left.

            move_board1(board_1, column, row, move_way);    //Calling the move function.
            
            ctrl_upward = check_upward(board_1, 7, 7);  //Checking upward, downward, forward and backward valid moves.
            ctrl_downward = check_downward(board_1, 7, 7);
            ctrl_forward = check_forward(board_1, 7, 7);
            ctrl_backward = check_backward(board_1, 7, 7);
            
            //If these functions all returned 1 (meaning there is no more valid moves left) we end the game.
            if(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward == 4){
                cout << "GAME OVER" << endl;
                peg_count = count_peg(board_1, 7, 7, peg_count);    //Count the pegs and print score of the player.
                cout << "YOU FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND!" << endl;
            } 
            //If even one of the functions returned 0 (meaning there is at least 1 valid move) keep playing.
            if(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward != 4) cout << "LET'S CONTINUE!" << endl;

            print_board_1(board_1); //Print the board in every round.

            

        }

    }

//The conditions and gameplay is same for all.
//(same with the above if condition with gametype == 1 && select_board == 1) of the human game conditioned if statements.

    if(select_board==2 && gametype==1){ //Condition for playing HUMAN GAME with BOARD 2.
            
        print_board_2(board_2);
        while(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward != 4){

            move_board2(board_2, column, row, move_way);
            
            ctrl_upward = check_upward(board_2, 9, 9);
            ctrl_downward = check_downward(board_2, 9, 9);
            ctrl_forward = check_forward(board_2, 9, 9);
            ctrl_backward = check_backward(board_2, 9, 9);

            if(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward == 4){
                cout << "GAME OVER" << endl;
                peg_count = count_peg(board_2, 9, 9, peg_count);
                cout << "YOU FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND!" << endl;
            } 
            if(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward != 4) cout << "LET'S CONTINUE!" << endl;
            
            print_board_2(board_2);

        }

    }

    if(select_board==3 && gametype==1){ //Condition for playing HUMAN GAME with BOARD 3.

        print_board_3(board_3);

        while(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward != 4){

            move_board3(board_3, column, row, move_way);
            
            ctrl_upward = check_upward(board_3, 8, 8);
            ctrl_downward = check_downward(board_3, 8, 8);
            ctrl_forward = check_forward(board_3, 8, 8);
            ctrl_backward = check_backward(board_3, 8, 8);
            
            if(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward == 4){
                cout << "GAME OVER" << endl;
                peg_count = count_peg(board_3, 8, 8, peg_count);
                cout << "YOU FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND!" << endl;
            } 
            if(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward != 4) cout << "LET'S CONTINUE!" << endl;
            
            print_board_3(board_3);
            

        }

    }

    if(select_board==4 && gametype==1){ //Condition for playing HUMAN GAME with BOARD 4.

        print_board_4(board_4);

        while(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward != 4){

            
            print_board_4(board_4);
            move_board4(board_4, column, row, move_way);
            
            ctrl_upward = check_upward(board_4, 7, 7);
            ctrl_downward = check_downward(board_4, 7, 7);
            ctrl_forward = check_forward(board_4, 7, 7);
            ctrl_backward = check_backward(board_4, 7, 7);
            
             if(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward == 4){
                cout << "GAME OVER" << endl;
                peg_count = count_peg(board_4, 7, 7, peg_count);
                cout << "YOU FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND!" << endl;
            } 
            if(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward != 4) cout << "LET'S CONTINUE!" << endl;
            
            print_board_4(board_4);
            

        }

    }

    if(select_board==5 && gametype==1){ //Condition for playing HUMAN GAME with BOARD 5.

        print_board_5(board_5);

        while(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward != 4){

           
            
            move_board5(board_5, column, row, move_way);
            
            ctrl_upward = check_upward(board_5, 9, 9);
            ctrl_downward = check_downward(board_5, 9, 9);
            ctrl_forward = check_forward(board_5, 9, 9);
            ctrl_backward = check_backward(board_5, 9, 9);
            
            if(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward == 4){
                cout << "GAME OVER" << endl;
                peg_count = count_peg(board_5, 9, 9, peg_count);
                cout << "YOU FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND!" << endl;
            } 
            if(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward != 4) cout << "LET'S CONTINUE!" << endl;
            
            print_board_5(board_5);
            

        }

    }

//In the 6th board there is only 2 checking valid move controls.

    if(select_board==6 && gametype==1){ //Condition for playing HUMAN GAME with BOARD 6.

        print_board_6(board_6);

        while(ctrl_forward + ctrl_backward != 2){
            
            
            move_board6(board_6, column, row, move_way);
            
            ctrl_forward = check_forward_triangle(board_6, 5, 11);  
            
            ctrl_backward = check_backward_triangle(board_6, 5, 11);
            
            if(ctrl_forward + ctrl_backward == 2){
                peg_count = count_peg(board_6, 5, 11, peg_count);
                cout << "GAME OVER" << endl;
                cout << "YOU FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND!" << endl;
            } 
            if(ctrl_forward + ctrl_backward != 2) cout << "LET'S CONTINUE!" << endl;
            
            print_board_6(board_6);

        }

    }

    

     

    
    

    return 0;
}