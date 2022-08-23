/*ILAYDA ARAR CSE241 HW2 1901042638*/

/*IMPORTANT NOTE : file_1.txt, file_2.txt and file_3.txt is original arbitrary board files. file_4.txt is a saved game of BOARD 2
and file_5.txt is a saved game of file_2.txt. You don't need to create a different filename than the original ones while playing.
The save will overwrite to the file if you write the name of file that you are already playing. Thanks, enjoy!!*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

enum state {peg, empty, space}; //Providing enum type for using in boards.

int check_file(string filename){    //This function checks if the file exists or not. If exists return 1, if not, returns 0.

    ifstream myfile(filename);
    
    if (myfile) {
        return 1;
    }
    else {
        cerr << "THIS FILE DOES NOT EXIST!" << endl;
        return 0;
    } 
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

int count_row(string& filename, int& row){  //This function counts the rows in the file for using as rows on boards.

    int count = 0;
    string line;
 
    fstream file(filename);
    getline (file, line);
    getline (file, line);   //Two buffer getline's for not counting gametype and number of moves info in the first 2 lines of files.

    while (getline(file, line)){
        row++;
    }
    
    return 0;

}

int count_column(string& filename, int& column){    //This function counts the columns for using in the board columns.

    string read;
    ifstream myfile(filename);

    getline (myfile, read);
    getline (myfile, read); //Two buffer getline's for not counting gametype and number of moves info in the first 2 lines of files.
    getline (myfile, read);
    column = read.size();   // Third column's size is the column number.

    return 0;
}

//Function for reading the file and constructing the arbitrary board.
int read_file(string& filename, vector<vector<state>>& board, string read, const int& row, const int& column, char& gametype, int& numberOfMoves){

    int i;
    state slot;
    
    ifstream myfile(filename);
    
    getline (myfile, read); //Reading the gametype.
    gametype = read[0];
    getline (myfile, read);
    numberOfMoves = stoi(read); //Reading the number of moves info.
    cout << numberOfMoves << endl;

    board.clear();  //Clearing the board in case of another board in the buffer.

    while(getline (myfile, read)){      //Reading the file line by line
        for (int i = 0; i < 1; i++) {
            
            vector<state> v1;           // In every line, create a temp 1D vector and push_back to the original board.
  
            for (int j = 0; j < column; j++) {
                if(read[j] == 'P') {
                    slot = peg;
                    v1.push_back(slot);
                }
                if(read[j] == ' ') {
                    slot = space;
                    v1.push_back(slot);
                }
                if(read[j] == '.') {
                    slot = empty;
                    v1.push_back(slot);
                }
                
            }
    
            board.push_back(v1);
        }
        
    }
    myfile.close();
    return 0;
}

//This function writes the saved board to the file.
int write_file(string& filename, vector<vector<state>>& board, const int& row, const int& column, char& gametype, int& numberOfMoves){

    cout << "Please enter the file name you want to save " << endl;
    cin >> filename;
    ofstream myfile (filename);
   
    myfile << gametype;     //Writing gametype and number of moves.
    myfile << "\n";
    myfile << numberOfMoves;
    myfile << "\n";
    for (int i = 0; i < board.size(); i++)
    {
        
        for (int j = 0; j < board[i].size(); j++)       //Writing the board.
        {
            if(board[i][j]==peg) myfile << "P";
            else if(board[i][j]==empty) myfile << ".";
            else if(board[i][j]==space) myfile << " ";
            
        }   
        myfile << "\n";
    }
    myfile.close();
    return 0;

}

void print_board(vector<vector<state>> board){      //This function prints the boards.

    int k,l;
    int character=0;
    char ch='A';
    auto i = 0;
    decltype(i) j;
    cout << " " << " ";
    for(k=0; k<board[0].size(); k++){

        character=int(ch);
        cout<<ch<<" ";
        character++;
        ch=char(character);

    }

    cout << endl;
    for (i = 0; i < board.size(); i++)
    {
        cout << i+1 << " ";
        for (j = 0; j < board[i].size(); j++)
        {
            if(board[i][j]==peg) cout << "P" << " ";
            else if(board[i][j]==empty) cout << "." << " ";
            else if(board[i][j]==space) cout << " " << " ";
            
        }   
        cout << endl;
    }

    cout << endl;

}

void print_board_6(vector<vector<state>> board_6){  //This function is special for 6th board.

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

void getInput(char& column, int& row, char& move_way){ //Getting the move input from the user.

    cout << "Please enter your move as shown in example: B 4 R (Please put spaces between and nothing else. Write in UPPERCASE" << endl;
    cin >> column >> row >> move_way;

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

        else cerr << "You did not enter a valid input, please try again" << endl;


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
        else cerr << "You did not enter a valid input, please try again" << endl;



    }

    else cerr << "You did not enter a valid input, please try again" << endl;

    //Error message for invalid input
    if(control != 1) cerr << "You did not enter a valid input, please try again" << endl;
    
    return control;



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

/*check_forward function checks if there is any valid moves left in the given board by iterating through vector*/
int check_forward(vector<vector<state>> board, int row, int column){

    int i, j;
    int win = 1;

    for (i = 0; ((i < row) && (win == 1)); i++)
    {
        
        for (j = 0; ((j < (column - 2)) && (win == 1)); j++)
        {
           
            if(board[i][j] == peg && board[i][j+1] == peg && board[i][j+2] == empty){
                
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
int check_backward(vector<vector<state>> board, int row, int column){

    int i, j;
    int win = 1;

    for (i = row-1; ((i >= 0) && (win == 1)); i--)
    {
        
        for (j = column-1; ((j >= 2) && (win == 1)); j--)
        {
           
            if(board[i][j] == peg && board[i][j-1] == peg && board[i][j-2] == empty){
                
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
int check_downward(vector<vector<state>> board, int row, int column){

    int i, j;
    int win = 1;

    for (i = 0; ((i < row-2) && (win == 1)); i++)
    {
        
        for (j = 0; ((j < (column)) && (win == 1)); j++)
        {
           
            if(board[i][j] == peg && board[i+1][j] == peg && board[i+2][j] == empty){
                
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
int check_upward(vector<vector<state>> board, int row, int column){

    int i, j;
    int win = 1;

    for (i = row-1; ((i >= 2) && (win == 1)); i--)
    {
        
        for (j = column-1; ((j >= 0) && (win == 1)); j--)
        {
           
            if(board[i][j] == peg && board[i-1][j] == peg && board[i-2][j] == empty){
                
                win = 0;    //If there is a move found, stop the loops and return 0.
            }
            
        }   
        
    }
    
    if(win == 0) return 0; 
    else {
        return 1;
    }
}



int move_board(vector<vector<state>>& board,char gametype, string filename, char move_column, char move_way, int move_row, int row, int column, int& numberOfMoves, int& menu_selection){

    int control = 0;
    int option = 0;
    while(option == 0){
    cout << "Please enter the option. You can continue with this game, load another game or save this game." << endl;
    cout << "1- Make a move in this board" << endl;
    cout << "2- LOAD another file" << endl;
    cout << "3- SAVE this file" << endl;
    cin >> option;
    }
    if(option == 1){
    getInput(move_column, move_row, move_way);

    if(((int)move_column > 64 && (int)move_column < (65+column)) && move_row > 0 && move_row <= row)    //Checking validity of user input's row and column
    {
        control = 1;
    }
    
    //If user tries to make a down or up move for the edge of the board, that is invalid*/
    if((move_row == 1 && move_way == 'U') || (move_row == 2 && move_way == 'U') || (move_row == row-1 && move_way == 'D') || (move_row == row && move_way == 'D')){
        control = 0;
    }

    if( control == 1 && move_way == 'R' && board[move_row-1][((int)move_column - 65)] == peg && board[move_row-1][((int)move_column - 64)] == peg && board[move_row-1][((int)move_column - 63)] == empty){

        board[move_row-1][((int)move_column - 65)] = empty;
        board[move_row-1][((int)move_column - 64)] = empty;
        board[move_row-1][((int)move_column - 63)] = peg;

    }
    //Left move
    else if(control == 1 && move_way == 'L' && board[move_row-1][((int)move_column - 65)] == peg && board[move_row-1][((int)move_column - 66)] == peg && board[move_row-1][((int)move_column - 67)] == empty){

        board[move_row-1][((int)move_column - 65)] = empty;
        board[move_row-1][((int)move_column - 66)] = empty;
        board[move_row-1][((int)move_column - 67)] = peg;

    }
    //Up move
    else if(control == 1 && move_way == 'U' && board[move_row-1][((int)move_column - 65)] == peg && board[move_row-2][((int)move_column - 65)] == peg && board[move_row-3][((int)move_column - 65)] == empty){

        board[move_row-1][((int)move_column - 65)] = empty;
        board[move_row-2][((int)move_column - 65)] = empty;
        board[move_row-3][((int)move_column - 65)] = peg;

    }
    //Down move
    else if(control ==1 && move_way == 'D' && board[move_row-1][((int)move_column - 65)] == peg && board[move_row][((int)move_column - 65)] == peg && board[move_row+1][((int)move_column - 65)] == empty){

        board[move_row-1][((int)move_column - 65)] = empty;
        board[move_row][((int)move_column - 65)] = empty;
        board[move_row+1][((int)move_column - 65)] = peg;

    }
    else cerr << "You did not enter a valid input, please try again" << endl;   //If none of the conditions fail to provide, print error mesage.
    }

    else if(option == 2){
        menu_selection = 7;
        control = 0;
        return control;

    }

    else if(option == 3){
        write_file(filename, board, row, column, gametype, numberOfMoves);
        control = 0;
        menu_selection = 8;
        
    }
    
    return control;

}

/*Function for calling the move and win-check functions for human player*/
int humangame(vector<vector<state>>& board,char gametype, string filename, int row, int column, int& numberOfMoves, int& menu_selection){

    char move_column, move_way;
    int move_row;
    int control = 1;
    int ctrl_upward = 0, ctrl_downward = 0, ctrl_forward = 0, ctrl_backward = 0;
    int peg_count;

    //The game will continue till the player wins or decides to save or load a game.
    while((ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward != 4) && control == 1 ){
    //Calling the move function
    control = move_board(board, gametype , filename, move_column, move_way, move_row, row, column, numberOfMoves, menu_selection);
    //Checking for a win
    ctrl_forward = check_forward(board, row, column);
    ctrl_backward = check_backward(board, row, column);
    ctrl_downward = check_downward(board, row, column);
    ctrl_upward = check_upward(board, row, column);
    numberOfMoves++;
    
    
    if(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward != 4) cout << "LETS'S CONTINUE! \n";
    if(ctrl_upward + ctrl_downward + ctrl_forward + ctrl_backward == 4) {
        cout << "GAME OVER \n";
        peg_count = count_peg(board,row,column,peg_count);
        cout << "YOU FINISHED THE GAME IN " << numberOfMoves << " MOVES LEAVING " << peg_count << " PEGS BEHIND" << endl;
        menu_selection = 8; //If finished, exit the game.
    }
    print_board(board);
    
    }
    return 0;


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
    
    for (i = row-1; ((i >= 0) && (win == 1)); i--){ //Checking for move to the left. (. P P)
        
            for (j = column-1; ((j >= 2) && (win == 1)); j--)
            {
            
                if(board_1[i][j] == peg && board_1[i][j-1] == peg && board_1[i][j-2] == empty){ 
                    
                    board_1[i][j] = empty;
                    board_1[i][j-1] = empty;
                    board_1[i][j-2] = peg;
                    win = 0;
                }
                
            }   
        
    }
    
    for (i = 0; ((i < row - 2) && (win == 1)); i++)  //Checking for move to the down.
    {
        
        for (j = 0; ((j < (column-1)) && (win == 1)); j++)
        {
           
            if(board_1[i][j] == peg && board_1[i+1][j] == peg && board_1[i+2][j] == empty){
                
                board_1[i][j] = empty;
                board_1[i+1][j] = empty;
                board_1[i+2][j] = peg;
                win = 0;
            }
            
        }   
        
    }
    
    for (i = row-1; ((i >= 2) && (win == 1)); i--)   //Checking for move to the up.
    {
        
        for (j = column-1; ((j >= 0) && (win == 1)); j--)
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


int main()
{
    
    string command_save;
    string command_load;
    string filename;
    string read;
    string gamestyle;
    char gametype;
    char move_way;
    int gameStyle_input = 0;
    int numberOfMoves = 0;
    int row = 0, column = 0;
    int style_choose = 2;
    int menu_selection = 0;
    int compMove = 1;
    int comp_ctrl = 0;
    int compMoveControl;
    int peg_count = 0;
    int file_check = 0;
    int option_6 = 0;

    vector<vector<state>> board;

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


    cout << "Welcome to the PEG SOLITAIRE. Please input the board or load the file (ENTER 7) that you want to play with. Ex: If you want to play with board 4, enter 4." << endl;
    
    while(menu_selection == 0 || menu_selection > 8){   //Starting the game with the board or load option.

   
    cout << "-----MENU-----" << endl;
    cout << "1 - Board 1 " << endl;
    print_board(board_1);
    cout << "2 - Board 2 " << endl;
    print_board(board_2);
    cout << "3 - Board 3 " << endl;
    print_board(board_3);
    cout << "4 - Board 4 " << endl;
    print_board(board_4);
    cout << "5 - Board 5 " << endl;
    print_board(board_5);
    cout << "6 - Board 6 " << endl;
    print_board(board_6);
    cout << "7 - LOAD A FILE" << endl;
    cout << "8 - EXIT" << endl;
    
    cin >> menu_selection;
    }

/*--------------------BOARD 1-------------------------*/

    if(menu_selection == 1){
        numberOfMoves = 0;
        while(gameStyle_input==0 || gameStyle_input > 2){
        cout << "You choosed Board 1. Please choose the game type \n";
        cout << "1- HUMAN GAME \n";
        cout << "2- COMPUTER GAME \n";
        cin >> gameStyle_input;
        }
        if(gameStyle_input == 1){

            gametype = 'H';
            print_board(board_1);
            humangame(board_1, gametype, filename, 7, 7, numberOfMoves, menu_selection);    //Calling the function for playing.

        }


        if(gameStyle_input == 2){   //Computer game
            gametype = 'C';
            print_board(board_1);
            comp_ctrl = 0;
            while(comp_ctrl == 0){  //While there is still valid moves (see comp_move_1 func) keep going.
            
            compMoveControl = 0;
            while(compMoveControl == 0){    //Asking to user options for move, save or load.
                cout << "Please for to computer make a move, ENTER 1" << endl;
                cout << "If you want to save this game into file, ENTER 2" << endl;
                cout << "If you want to load another file, ENTER 3" << endl;

                cin >> compMove; 
                if(compMove == 1 || compMove == 2 || compMove == 3) compMoveControl = 1;
            }
           
            if(compMove == 1) compMoveControl = 1;  
            if(compMove == 2) comp_ctrl = 2;
            if(compMove == 3) comp_ctrl = 3;

            if(compMove == 1) {
                comp_ctrl = comp_move_1(board_1, 7,7);  //Calling the computer move function to make a move.
                numberOfMoves++;
            }
            if(comp_ctrl == 1) {    //If comp_move_1 returned 1, it means there was no more valid moves, so game ends with displaying score
                cout << "GAME OVER" << endl;
                count_peg(board_1,7,7,peg_count);
                cout << "COMPUTER FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND IN " << numberOfMoves << " MOVES" << endl;
            }
            if(comp_ctrl == 0) cout << "LET'S CONTINUE!" << endl; //If comp_move_1 returned 0, it means there is still valid moves.
            
            if((comp_ctrl == 2)){
                write_file(filename, board_1, 7, 7, gametype, numberOfMoves);   //Saving process
                menu_selection = 8;
            }
            if(comp_ctrl == 3){
                menu_selection = 7; //Loading another file

            }
            
            print_board(board_1); //Printing the board to show the move that was done.
        }

        }

    }

/*-----------------BOARD 2----------------*/

    if(menu_selection == 2){
        numberOfMoves = 0;
        while(gameStyle_input==0 || gameStyle_input > 2){
        cout << "You choosed Board 2. Please choose the game type \n";
        cout << "1- HUMAN GAME \n";
        cout << "2- COMPUTER GAME \n";
        cin >> gameStyle_input;
        }
        if(gameStyle_input == 1){   //Human game

            gametype = 'H';
            print_board(board_2);
            humangame(board_2, gametype, filename, 9, 9, numberOfMoves, menu_selection);     //Calling the function for playing.

        }


        if(gameStyle_input == 2){
            gametype = 'C';
            print_board(board_2);
            comp_ctrl = 0;
            while(comp_ctrl == 0){  //While there is still valid moves (see comp_move_1 func) keep going.
            
            compMoveControl = 0;
            while(compMoveControl == 0){    //Asking to user choose move, load or save
                cout << "Please for to computer make a move, ENTER 1" << endl;
                cout << "If you want to save this game into file, ENTER 2" << endl;
                cout << "If you want to load another file, ENTER 3" << endl;

                cin >> compMove; 
                if(compMove == 1 || compMove == 2 || compMove == 3) compMoveControl = 1;
            }
           
            if(compMove == 1) compMoveControl = 1;
            if(compMove == 2) comp_ctrl = 2;
            if(compMove == 3) comp_ctrl = 3;
            if(compMove == 1) {
                comp_ctrl = comp_move_1(board_2, 9,9);  //Calling the computer move function to make a move.
                numberOfMoves++;
            }
            if(comp_ctrl == 1) {    //If comp_move_1 returned 1, it means there was no more valid moves, so game ends with displaying score
                cout << "GAME OVER" << endl;
                count_peg(board_2,9,9,peg_count);
                cout << "COMPUTER FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND IN " << numberOfMoves << " MOVES" <<endl;
            }
            if(comp_ctrl == 0) cout << "LET'S CONTINUE!" << endl; //If comp_move_1 returned 0, it means there is still valid moves.
            if((comp_ctrl == 2)){
                write_file(filename, board_2, 9, 9, gametype, numberOfMoves);   //Saving the file
                menu_selection = 8;
            }
            if(comp_ctrl == 3){
                menu_selection = 7;     //Loading another file

            }
            
            print_board(board_2); //Printing the board to show the move that was done.
        }

        }

    }

/*------------------------BOARD 3----------------*/

     if(menu_selection == 3){

        numberOfMoves = 0;
        while(gameStyle_input==0 || gameStyle_input > 2){
        cout << "You choosed Board 3. Please choose the game type \n";
        cout << "1- HUMAN GAME \n";
        cout << "2- COMPUTER GAME \n";
        cin >> gameStyle_input;
        }
        if(gameStyle_input == 1){

            gametype = 'H';
            print_board(board_3);
            humangame(board_3, gametype, filename, 8, 8, numberOfMoves, menu_selection); //Calling the function for playing.

        }


        if(gameStyle_input == 2){   //Computer game
            gametype = 'C';
            print_board(board_3);
            comp_ctrl = 0;
            while(comp_ctrl == 0){  //While there is still valid moves (see comp_move_1 func) keep going.
            
            compMoveControl = 0;
            while(compMoveControl == 0){    //Asking to user enter 1 for computer to make a move
                cout << "Please for to computer make a move, ENTER 1" << endl;
                cout << "If you want to save this game into file, ENTER 2" << endl;
                cout << "If you want to load another file, ENTER 3" << endl;

                cin >> compMove; 
                if(compMove == 1 || compMove == 2 || compMove == 3) compMoveControl = 1;
            }
           
            if(compMove == 1) compMoveControl = 1;
            if(compMove == 2) comp_ctrl = 2;
            if(compMove == 3) comp_ctrl = 3;
            if(compMove == 1) {
                comp_ctrl = comp_move_1(board_3, 8,8);  //Calling the computer move function to make a move.
                numberOfMoves++;
            }
            if(comp_ctrl == 1) {    //If comp_move_1 returned 1, it means there was no more valid moves, so game ends with displaying score
                cout << "GAME OVER" << endl;
                count_peg(board_3,8,8,peg_count);
                cout << "COMPUTER FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND IN " << numberOfMoves << " MOVES" <<endl;
            }
            if(comp_ctrl == 0) cout << "LET'S CONTINUE!" << endl; //If comp_move_1 returned 0, it means there is still valid moves.
            if((comp_ctrl == 2)){
                write_file(filename, board_3, 8, 8, gametype, numberOfMoves);
                menu_selection = 8;
            }
            if(comp_ctrl == 3){
                menu_selection = 7;

            }
            
            print_board(board_3); //Printing the board to show the move that was done.
        }

        }

    }

/*-------------------------BOARD 4------------------*/

     if(menu_selection == 4){

        numberOfMoves = 0;
        while(gameStyle_input==0 || gameStyle_input > 2){
        cout << "You choosed Board 4. Please choose the game type \n";
        cout << "1- HUMAN GAME \n";
        cout << "2- COMPUTER GAME \n";
        cin >> gameStyle_input;
        }
        if(gameStyle_input == 1){

            gametype = 'H';
            print_board(board_4);
            humangame(board_4, gametype, filename, 7, 7, numberOfMoves, menu_selection);  //Calling the function for playing.

        }


        if(gameStyle_input == 2){   //Computer game
            gametype = 'C';
            print_board(board_4);
            comp_ctrl = 0;
            while(comp_ctrl == 0){  //While there is still valid moves (see comp_move_1 func) keep going.
            
            compMoveControl = 0;
            while(compMoveControl == 0){    //Asking to user enter 1 for computer to make a move
                cout << "Please for to computer make a move, ENTER 1" << endl;
                cout << "If you want to save this game into file, ENTER 2" << endl;
                cout << "If you want to load another file, ENTER 3" << endl;

                cin >> compMove; 
                if(compMove == 1 || compMove == 2 || compMove == 3) compMoveControl = 1;
            }
           
            if(compMove == 1) compMoveControl = 1;
            if(compMove == 2) comp_ctrl = 2;
            if(compMove == 3) comp_ctrl = 3;
            if(compMove == 1) {
                comp_ctrl = comp_move_1(board_4, 7,7);  //Calling the computer move function to make a move.
                numberOfMoves++;
            }
            if(comp_ctrl == 1) {    //If comp_move_1 returned 1, it means there was no more valid moves, so game ends with displaying score
                cout << "GAME OVER" << endl;
                count_peg(board_4,7,7,peg_count);
                cout << "COMPUTER FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND IN " << numberOfMoves << " MOVES" <<endl;
            }
            if(comp_ctrl == 0) cout << "LET'S CONTINUE!" << endl; //If comp_move_1 returned 0, it means there is still valid moves.
            if((comp_ctrl == 2)){
                write_file(filename, board_4, 7, 7, gametype, numberOfMoves);
                menu_selection = 8;
            }
            if(comp_ctrl == 3){
                menu_selection = 7;

            }
            
            print_board(board_4); //Printing the board to show the move that was done.
        }

        }

    }

/*----------------------------BOARD 5---------------*/

     if(menu_selection == 5){
        numberOfMoves = 0;
        while(gameStyle_input==0 || gameStyle_input > 2){
        cout << "You choosed Board 5. Please choose the game type \n";
        cout << "1- HUMAN GAME \n";
        cout << "2- COMPUTER GAME \n";
        cin >> gameStyle_input;
        }
        if(gameStyle_input == 1){

            gametype = 'H';
            print_board(board_5);
            humangame(board_5, gametype, filename, 9, 9, numberOfMoves, menu_selection);  //Calling the function for playing.

        }


        if(gameStyle_input == 2){   //Computer game
            gametype = 'C';
            print_board(board_5);
            comp_ctrl = 0;
            while(comp_ctrl == 0){  //While there is still valid moves (see comp_move_1 func) keep going.
            
            compMoveControl = 0;
            while(compMoveControl == 0){    //Asking to user enter 1 for computer to make a move
                cout << "Please for to computer make a move, ENTER 1" << endl;
                cout << "If you want to save this game into file, ENTER 2" << endl;
                cout << "If you want to load another file, ENTER 3" << endl;

                cin >> compMove; 
                if(compMove == 1 || compMove == 2 || compMove == 3) compMoveControl = 1;
            }
           
            if(compMove == 1) compMoveControl = 1;
            if(compMove == 2) comp_ctrl = 2;
            if(compMove == 3) comp_ctrl = 3;
            if(compMove == 1) {
                comp_ctrl = comp_move_1(board_5, 9,9);  //Calling the computer move function to make a move.
                numberOfMoves++;
            }
            if(comp_ctrl == 1) {    //If comp_move_1 returned 1, it means there was no more valid moves, so game ends with displaying score
                cout << "GAME OVER" << endl;
                count_peg(board_5,9,9,peg_count);
                cout << "COMPUTER FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND IN " << numberOfMoves << " MOVES" <<endl;
            }
            if(comp_ctrl == 0) cout << "LET'S CONTINUE!" << endl; //If comp_move_1 returned 0, it means there is still valid moves.
            if((comp_ctrl == 2)){
                write_file(filename, board_5, 9, 9, gametype, numberOfMoves);
                menu_selection = 8;
            }
            if(comp_ctrl == 3){
                menu_selection = 7;

            }
            
            print_board(board_5); //Printing the board to show the move that was done.
        }

        }

    }

/*----------------------BOARD 6---------------*/

    if(menu_selection == 6){

        int ctrl_forward = 0;
        int ctrl_backward = 0;
        numberOfMoves = 0;
        while(gameStyle_input==0 || gameStyle_input > 2){
        cout << "You choosed Board 6. Please choose the game type \n";  //Choosing game type
        cout << "1- HUMAN GAME \n";
        cout << "2- COMPUTER GAME \n";
        cin >> gameStyle_input;
        }

        if(gameStyle_input == 1){
            gametype = 'H';
            print_board_6(board_6);
            option_6 = 0;
            while(ctrl_forward + ctrl_backward != 2 && (option_6 < 1 || option_6 > 2)){
                
                cout << "Please select the option, if you want to make a move ENTER 1, if you want to load ENTER 2." << endl;
                cout << "1- Make a move on this board" << endl;
                cout << "2- Load another file" << endl;
                cin >> option_6;                            //Making a choice of move or load.
                
                if(option_6 == 1){
                move_board6(board_6, column, row, move_way);    //Calling the move function
                
                ctrl_forward = check_forward_triangle(board_6, 5, 11);      
                ctrl_backward = check_backward_triangle(board_6, 5, 11);
                
                if(ctrl_forward + ctrl_backward == 2){      //Checking for a win.
                    peg_count = count_peg(board_6, 5, 11, peg_count);
                    cout << "GAME OVER" << endl;
                    cout << "YOU FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND!" << endl;
                    menu_selection = 8;
                } 
                if(ctrl_forward + ctrl_backward != 2) cout << "LET'S CONTINUE!" << endl;
                
                print_board_6(board_6);
                option_6 = 0;
                }
                if(option_6 == 2){
                    option_6 = 2;
                    menu_selection = 7;     //Loading another file.
                }
                

        }

        }

        if(gameStyle_input == 2){   //Computer game
            gametype = 'C';
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
                    cout << "GAME OVER" << endl;        //Finishing the game.
                    count_peg(board_6,5,11,peg_count);  
                    cout << "COMPUTER FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND" << endl;
                    menu_selection = 8;
                }
                if(comp_ctrl == 0) cout << "LET'S CONTINUE!" << endl;
                print_board_6(board_6);
        }
        }


    }
    
    while(menu_selection == 7){     //LOAD option
        numberOfMoves = 0;
        row = 0;
        column = 0;
        file_check = 0;
        while(file_check == 0){ //Checking the file existance
        cout << "You have choosen to LOAD a game from files. Please write the file name that you want to play with. Ex: If the file name is 'file_1.txt', write file_1.txt" << endl;
        cin >> filename;
        file_check = check_file(filename);
        if(file_check == 0) cerr << "Please enter a valid file name." << endl;
        }
        count_row(filename, row);
        count_column(filename, column);
        read_file(filename, board, read, row, column, gametype, numberOfMoves); //Reading from file
        
        if(gametype == 'H') gamestyle = "HUMAN GAME";
        if(gametype == 'C') gamestyle = "COMPUTER GAME";

        cout << "The gametype of the file is: " << gamestyle << endl;
        style_choose = 2;
        while(style_choose < 0 || style_choose > 1){
        cout << "If you want to change the gametype ENTER 1. If you want to keep playing " << gamestyle << " ENTER 0" << endl;
        cin >> style_choose;
        }
        if(style_choose == 0) gametype = gametype;      //Game type changes
        if(style_choose == 1){
            if(gametype == 'H') gametype = 'C';
            else if(gametype == 'C') gametype = 'H';
            if(gametype == 'H') gamestyle = "HUMAN GAME";
            else if(gametype == 'C') gamestyle = "COMPUTER GAME";

        }

        if(gametype == 'H') {   //Human game
            print_board(board);
            
            humangame(board, gametype, filename, row, column, numberOfMoves, menu_selection);
        }


        if(gametype == 'C'){        //Computer game
            print_board(board);
            comp_ctrl = 0;
            while(comp_ctrl == 0){  //While there is still valid moves (see comp_move_1 func) keep going.
                
            compMoveControl = 0;
            while(compMoveControl == 0){    //Asking to user enter 1 for computer to make a move
                cout << "Please for to computer make a move, ENTER 1" << endl;
                cout << "If you want to save this game into file, ENTER 2" << endl;
                cout << "If you want to load another file, ENTER 3" << endl;
                cin >> compMove; 
                if(compMove == 1 || compMove == 2 || compMove == 3) compMoveControl = 1;
            }
            
            if(compMove == 1) compMoveControl = 1;
            if(compMove == 2) comp_ctrl = 2;
            if(compMove == 3) comp_ctrl = 3;
            if(compMove == 1) {
                
                comp_ctrl = comp_move_1(board, row, column);  //Calling the computer move function to make a move.
                
                numberOfMoves++;
            }
            if(comp_ctrl == 1) {    //If comp_move_1 returned 1, it means there was no more valid moves, so game ends with displaying score
                cout << "GAME OVER" << endl;
                count_peg(board,row,column,peg_count);
                cout << "COMPUTER FINISHED THE GAME LEAVING " << peg_count << " PEGS BEHIND IN " << numberOfMoves << " MOVES" <<endl;
                menu_selection = 8;

            }
            if(comp_ctrl == 0) cout << "LET'S CONTINUE!" << endl; //If comp_move_1 returned 0, it means there is still valid moves.
            if((comp_ctrl == 2)){
                write_file(filename, board, row, column, gametype, numberOfMoves);
                menu_selection = 8;
            }
            if(comp_ctrl == 3) menu_selection = 7;
                    

                
            print_board(board); //Printing the board to show the move that was done.    


        }
    }
    }
    if(menu_selection == 8) cout << "YOU EXITED THE GAME, THANKS FOR PLAYING :) \n";    //Exit option.
   
    return 0;
}
