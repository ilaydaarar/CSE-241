/*ILAYDA ARAR CSE241 HW3 1901042638*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

enum state {peg, empty, space}; //Providing enum type for using in boards.

class PegSolitaire {

    public:
        class Cell {
            public: 
                int row;
                char column;
                char way;
                //This function gets input and does the constructors work.
                inline void getInput(int r, char c, char w){ 

                    cout << "Please enter your move as shown in example: B 4 R (Please put spaces between and nothing else. Write in UPPERCASE" << endl;
                    cin >> c >> r >> w;
                    row = r; 
                    column = c; 
                    way = w;
                   
                };



        };
        //Constructor for extra objects.
        PegSolitaire(int size_board, int typeOfboard, char game_type){

            sizeb = size_board;
            board_type = typeOfboard;
            gametype = game_type;
        }
        //Constructor for default boards.
        PegSolitaire(vector<vector<state>>& board_0, int size_board, int typeOfboard, char game_type){
            sizeb = size_board;
            board.clear();
            board.resize(sizeb, vector<state>(sizeb));
            
            board_type = typeOfboard;
            for (int i = 0; i < board_0.size(); i++)
            {
                
                for (int j = 0; j < board_0[i].size(); j++)
                {
                    board[i][j] = board_0[i][j];
                    
                }   
                
            }
            gametype = game_type;
            
        }
        //Constructor for loaded boards.
        PegSolitaire(int r, string filename, int& numberOfMoves, char& typeOfGame){
            sizeb = r;
            board.clear();
            board.resize(sizeb, vector<state>(sizeb));
            read(filename, numberOfMoves, typeOfGame);
        }

        void print() const;

        int win();

        int play(char move_row, int move_column, char move_way, int& board_or_file, int& keep_load, int& numberOfMoves);

        int play();
        
        int playGame();

        void read(string& filename, int& numberOfMoves, char& typeOfGame);

        void write(string& filename, int numberOfMoves);

        int countPegs(int& pegs);

        int leftPegs(int& leftpeg);

        int emptycell(int& emptycells);

        static int totalPegs(int& pegs);

        bool compare(PegSolitaire other){

            if(other.pegcount > pegcount) return true;
            else return false;
                   
        }
        
    private:
        vector<vector<state>> board{
        
        {space, space, peg, peg, peg, space, space, space},
        {space, space, peg, peg, peg, space, space, space},
        {space, space, peg, peg, peg, space, space, space},
        {peg, peg, peg, peg, peg, peg, peg, peg},
        {peg, peg, peg, empty, peg, peg, peg, peg},
        {peg, peg, peg, peg, peg, peg, peg, peg},
        {space, space, peg, peg, peg, space, space, space},
        {space, space, peg, peg, peg, space, space, space}
    };
        int sizeb;
        int board_type;
        char gametype;
        int pegcount;
        
        
};


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

int PegSolitaire::totalPegs(int& pegs){ //This function counts the total pegs in all boards.

    static int totalpegs = 0;

    totalpegs = totalpegs+pegs;
    return totalpegs;


}

int PegSolitaire::emptycell(int& emptycells){   //This function count all of the empty cells.

    emptycells = 1;
    for (int i = 0; i < board.size(); i++)
    {
        
        for (int j = 0; j < board.size(); j++)       
        {
            if(board[i][j]==empty) emptycells++;    
            
            
        }   
       
    }
    return emptycells;

}

int PegSolitaire::leftPegs(int& leftpegs){  //Counts the pegs left after game is over

    leftpegs = 0;
    for (int i = 0; i < board.size(); i++)
    {
        
        for (int j = 0; j < board.size(); j++)       
        {
            if(board[i][j]==peg) leftpegs++;    //Counting the peg number.
            
            
        }   
       
    }
    pegcount = leftpegs;
    return leftpegs;

}

int PegSolitaire::countPegs(int& pegs){ 

    pegs = 0;
    for (int i = 0; i < board.size(); i++)
    {
        
        for (int j = 0; j < board.size(); j++)       
        {
            if(board[i][j]==peg) pegs++;    //Counting the initial peg number.
            
            
        }   
       
    }
    return pegs;
}

//This function reads the file and fills the board object.
void PegSolitaire::read(string& filename, int& numberOfMoves, char& typeOfGame){

    string read;
    int i;
    state slot;
    
    ifstream myfile(filename);
    
    getline (myfile, read); //Reading the gametype.
    gametype = read[0];
    typeOfGame = read[0];
    getline (myfile, read);
    numberOfMoves = stoi(read); //Reading the number of moves info.
    

    board.clear();  //Clearing the board in case of another board in the buffer.

    while(getline (myfile, read)){      //Reading the file line by line
        for (int i = 0; i < 1; i++) {
            
            vector<state> v1;           // In every line, create a temp 1D vector and push_back to the original board.
  
            for (int j = 0; j < sizeb; j++) {
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
    
}

//This function saves the board to file (overwriting).
void PegSolitaire::write(string& filename, int numberOfMoves){

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

}

//This function checks if the game is over or not
int PegSolitaire::win(){

    int i, j;
    int c_upward = 1, c_downward = 1, c_backward = 1, c_forward = 1;
    int ctrl = 1;

    for (i = 0; ((i < sizeb) && (c_forward == 1)); i++)
    {
        
        for (j = 0; ((j < (sizeb - 2)) && (c_forward == 1)); j++)
        {
           
            if(board[i][j] == peg && board[i][j+1] == peg && board[i][j+2] == empty){
                
                c_forward = 0;    //If there is a move found, stop the loops and return 0.
            }
            
        }   
        
    }

    for (i = sizeb-1; ((i >= 0) && (c_backward == 1)); i--)
    {
        
        for (j = sizeb-1; ((j >= 2) && (c_backward == 1)); j--)
        {
           
            if(board[i][j] == peg && board[i][j-1] == peg && board[i][j-2] == empty){
                
                c_backward = 0;    //If there is a move found, stop the loops and return 0.
            }
            
        }   
        
    }

    for (i = 0; ((i < sizeb-2) && (c_downward == 1)); i++)
    {
        
        for (j = 0; ((j < (sizeb)) && (c_downward == 1)); j++)
        {
           
            if(board[i][j] == peg && board[i+1][j] == peg && board[i+2][j] == empty){
                
                c_downward = 0;    //If there is a move found, stop the loops and return 0.
            }
            
        }   
        
    }

    for (i = sizeb-1; ((i >= 2) && (c_upward == 1)); i--)
    {
        
        for (j = sizeb-1; ((j >= 0) && (c_upward == 1)); j--)
        {
           
            if(board[i][j] == peg && board[i-1][j] == peg && board[i-2][j] == empty){
                
                c_upward = 0;    //If there is a move found, stop the loops and return 0.
            }
            
        }   
        
    }

    if(c_upward + c_downward + c_backward + c_forward == 4) ctrl = 1;
    if(c_upward + c_downward + c_backward + c_forward != 4) ctrl = 0;
    return ctrl;

}

//This function prints the boards.
void PegSolitaire::print() const{

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

//This function calls the play function continously for computer game
int PegSolitaire::playGame(){

    int win_ctrl = 0;
    
    win_ctrl = play();
    while(win_ctrl == 0){
        
        win_ctrl = play();
        print();
    }
    return 0;
}

// This function makes a random move for computer game.
int PegSolitaire::play(){

    int i,j;
    int win = 1;

    for (i = 0; ((i < sizeb) && (win == 1)); i++)   //Checking for move to the right. (P P .)
    {
        
        for (j = 0; ((j < (sizeb - 2)) && (win == 1)); j++)
        {
           
            if(board[i][j] == peg && board[i][j+1] == peg && board[i][j+2] == empty){
                
                board[i][j] = empty;
                board[i][j+1] = empty;
                board[i][j+2] = peg;

                win = 0;    //If a valid move is found and done, the variable win is 0. So the function won't look for anymore valid moves.
            }
            
        }   

           
    }
    
    //Every loop has win==1 condition because it means, in the previous loop of checking, there wasn't any valid moves.
    
    for (i = sizeb-1; ((i >= 0) && (win == 1)); i--){ //Checking for move to the left. (. P P)
        
            for (j = sizeb-1; ((j >= 2) && (win == 1)); j--)
            {
            
                if(board[i][j] == peg && board[i][j-1] == peg && board[i][j-2] == empty){ 
                    
                    board[i][j] = empty;
                    board[i][j-1] = empty;
                    board[i][j-2] = peg;
                    win = 0;
                }
                
            }   
        
    }
    
    for (i = 0; ((i < sizeb - 2) && (win == 1)); i++)  //Checking for move to the down.
    {
        
        for (j = 0; ((j < (sizeb)) && (win == 1)); j++)
        {
           
            if(board[i][j] == peg && board[i+1][j] == peg && board[i+2][j] == empty){
                
                board[i][j] = empty;
                board[i+1][j] = empty;
                board[i+2][j] = peg;
                win = 0;
            }
            
        }   
        
    }
    
    for (i = sizeb-1; ((i >= 2) && (win == 1)); i--)   //Checking for move to the up.
    {
        
        for (j = sizeb-1; ((j >= 0) && (win == 1)); j--)
        {
           
            if(board[i][j] == peg && board[i-1][j] == peg && board[i-2][j] == empty){

                
                board[i][j] = empty;
                board[i-1][j] = empty;
                board[i-2][j] = peg;
                win = 0;
            }
            
        }   
        
    }
    
    return win;

}

//This function plays the game by user input and makes the move.
int PegSolitaire::play(char move_row, int move_column, char move_way, int& board_or_file, int& keep_load, int& numberOfMoves){

    int control = 0;
    int option = 0;
    string filename;
    PegSolitaire :: Cell point;
    while(option == 0){
    cout << "Please enter the option. You can continue with this game, load another game or save this game." << endl;
    cout << "1- Make a move in this board" << endl;
    cout << "2- LOAD another file" << endl;
    cout << "3- SAVE this file" << endl;
    cin >> option;
    }
    if(option == 1){
        point.getInput(move_row, move_column, move_way);
       

        if(((int)point.column > 64 && (int)point.column < (65+sizeb)) && point.row > 0 && point.row <= sizeb)    //Checking validity of user input's row and column
        {
            control = 1;
        }
        if((point.row == 1 && point.way == 'U') || (point.row == 2 && point.way == 'U') || (point.row == sizeb-1 && point.way == 'D') || (point.row == sizeb && point.way == 'D')){
            control = 0;
        
        }
        if(control == 1 && point.way == 'R' && board[point.row-1][((int)point.column - 65)] == peg && board[point.row-1][((int)point.column - 64)] == peg && board[point.row-1][((int)point.column - 63)] == empty){

            board[point.row-1][((int)point.column - 65)] = empty;
            board[point.row-1][((int)point.column - 64)] = empty;
            board[point.row-1][((int)point.column - 63)] = peg;
            numberOfMoves++;
        }
        else if(control == 1 && point.way == 'L' && board[point.row-1][((int)point.column - 65)] == peg && board[point.row-1][((int)point.column - 66)] == peg && board[point.row-1][((int)point.column - 67)] == empty){

            board[point.row-1][((int)point.column - 65)] = empty;
            board[point.row-1][((int)point.column - 66)] = empty;
            board[point.row-1][((int)point.column - 67)] = peg;
            numberOfMoves++;
        }
        //Up move
        else if(control == 1 && point.way == 'U' && board[point.row-1][((int)point.column - 65)] == peg && board[point.row-2][((int)point.column - 65)] == peg && board[point.row-3][((int)point.column - 65)] == empty){

            board[point.row-1][((int)point.column - 65)] = empty;
            board[point.row-2][((int)point.column - 65)] = empty;
            board[point.row-3][((int)point.column - 65)] = peg;
            numberOfMoves++;
        }
        //Down move
        else if(control ==1 && point.way == 'D' && board[point.row-1][((int)point.column - 65)] == peg && board[point.row][((int)point.column - 65)] == peg && board[point.row+1][((int)point.column - 65)] == empty){

            board[point.row-1][((int)point.column - 65)] = empty;
            board[point.row][((int)point.column - 65)] = empty;
            board[point.row+1][((int)point.column - 65)] = peg;
            numberOfMoves++;
        }
        else cerr << "You did not enter a valid input, please try again" << endl;   //If none of the conditions fail to provide, print error mesage.
        
        print();
    
    }

     if(option == 2){   //Loading another file option.
         control = 0;
         if(board_or_file == 2) keep_load = 0;
         board_or_file = 2;

        
    }
    if(option == 3){    //Save option
        write(filename,numberOfMoves);
        control = 0;
        board_or_file = 3;
        keep_load = 0;
        
    }


    return 1;
}


void print_board(vector<vector<state>> board){      //This function prints the boards (in asking for board type).

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

void setInput(char& column, int& row, char& move_way){ //Getting the move input from the user.

    cout << "Please enter your move as shown in example: B 4 R (Please put spaces between and nothing else. Write in UPPERCASE" << endl;
    cin >> column >> row >> move_way;

} 

int main(){

    PegSolitaire :: Cell point;
    
    int board_or_file = 0;
    int board_choose = 0;
    int gameStyle_input = 0;
    int input_row;
    int file_check = 0;
    int row_number = 0;
    int numberOfMoves = 0;
    int keep_load = 1;
    int compsel;
    int initial_pegs = 0;
    int leftpegs;
    int emptycells;
    static int totalpegs = 0;
    char typeOfGame;
    char input_column; 
    char input_way;
    string filename;
    
    
    vector<vector<state>> board_0;

      vector<vector<state>> board_1   //7x7 BOARD, BOARD 1.
    {
        
        {space, space, peg, empty, peg, space, space},
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

    
    
    while(board_or_file != 1 && board_or_file != 2 && board_or_file != 3){
    cout << "Welcome to the PEG SOLITAIRE. Do you want to load a file or play with default boards?" << endl;
    cout << "1- Play with default boards (ENTER 1)" << endl;
    cout << "2- Load a file (ENTER 2)" << endl;
    cout << "3- EXIT (ENTER 3)" << endl;

    cin >> board_or_file;
    }
    
    

    if(board_or_file == 1){ //Choosing the board type

    while(board_choose < 1 || board_choose > 5){
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
   
    cout << "Please enter the board number" << endl;
    cin >> board_choose;
    } 


//Board 1  
    if(board_choose == 1){
        while(gameStyle_input==0 || gameStyle_input > 2){
        cout << "You choosed Board 1. Please choose the game type " << endl;
        cout << "1- HUMAN GAME" << endl;
        cout << "2- COMPUTER GAME " << endl;
        cin >> gameStyle_input;
        }
        
        
        if(gameStyle_input == 1){   //Human game
            PegSolitaire board1(board_1, 7, 1, 'H');
            board1.countPegs(initial_pegs);
            totalpegs = board1.countPegs(initial_pegs);
            board1.totalPegs(totalpegs);        //Statically counting all of the boards peg number
            numberOfMoves = 0;
            
            board1.print();
            //Playing the game and checking for a win.
            while(board_or_file == 1){
            board1.play(input_row, input_column, input_way, board_or_file, keep_load, numberOfMoves);
            board1.print();
            if(board1.win() == 1){  
               
                board1.leftPegs(leftpegs);
                board1.emptycell(emptycells);
                cout << "GAME OVER. YOU FINISHED THE GAME LEAVING " << leftpegs << " PEGS BEHIND IN " << numberOfMoves << " MOVES." << endl;
                cout << " YOU TOOK " << initial_pegs - leftpegs << " PEGS OUT OF THE BOARD CLEARING " << emptycells << " CELLS" << endl;
                board_or_file = 3;
            } 
            if(board1.win() == 0) cout << "LET'S CONTINUE" << endl;
            }
            
        }
        if(gameStyle_input == 2){   //Computer game
            PegSolitaire board1_2(board_1, 7, 1, 'C');
            board1_2.playGame();    //Computer plays the game automatically
            cout << "Computer finished the game. Do you want to load another file or exit the program?" << endl;
            cout << "1- Load a file (ENTER 1)" << endl;
            cout << "2- EXIT (ENTER 2)" << endl;
            cin >> compsel;
            if(compsel == 1){
                board_or_file = 2;
            }
            if(compsel == 2){
                board_or_file = 3;
            }

        }
    } 

//Board 2   
    if(board_choose == 2){
        while(gameStyle_input==0 || gameStyle_input > 2){
        cout << "You choosed Board 2. Please choose the game type " << endl;
        cout << "1- HUMAN GAME" << endl;
        cout << "2- COMPUTER GAME " << endl;
        cin >> gameStyle_input;
        }
        
        
        if(gameStyle_input == 1){
            PegSolitaire board2(board_2, 9, 2, 'H');    //Constructor for object
            board2.countPegs(initial_pegs);
            totalpegs = board2.countPegs(initial_pegs); //Counting pegs in all boards
            board2.totalPegs(totalpegs);
            numberOfMoves = 0;
            board2.print();
            
            //Playing the game
            while(board_or_file == 1){
            board2.play(input_row, input_column, input_way, board_or_file, keep_load, numberOfMoves);
            board2.print();
            if(board2.win() == 1){
                board2.leftPegs(leftpegs);
                board2.emptycell(emptycells);
                cout << "GAME OVER. YOU FINISHED THE GAME LEAVING " << leftpegs << " PEGS BEHIND IN " << numberOfMoves << " MOVES." << endl;
                cout << " YOU TOOK " << initial_pegs - leftpegs << " PEGS OUT OF THE BOARD CLEARING " << emptycells << " CELLS" << endl;
                board_or_file = 3;
            } 
            if(board2.win() == 0) cout << "LET'S CONTINUE" << endl;
            }
            

        }
        //Computer game
        if(gameStyle_input == 2){
            PegSolitaire board2_2(board_2, 9, 2, 'C');  //Constructor for object
            board2_2.playGame();    //Computer plays the game till it ends
            cout << "Computer finished the game. Do you want to load another file or exit the program?" << endl;
            cout << "1- Load a file (ENTER 1)" << endl;
            cout << "2- EXIT (ENTER 2)" << endl;
            cin >> compsel;
            if(compsel == 1){
                board_or_file = 2;  //Selection for another file or exit
            }
            if(compsel == 2){
                board_or_file = 3;
            }

        }
    } 

//Board 3
    if(board_choose == 3){
        while(gameStyle_input==0 || gameStyle_input > 2){
        cout << "You choosed Board 3. Please choose the game type " << endl;
        cout << "1- HUMAN GAME" << endl;
        cout << "2- COMPUTER GAME " << endl;
        cin >> gameStyle_input;
        }
        
        
        if(gameStyle_input == 1){   //Human game
            PegSolitaire board3(board_3, 8, 3, 'H');
            board3.countPegs(initial_pegs);
            totalpegs = board3.countPegs(initial_pegs);
            board3.totalPegs(totalpegs);
            numberOfMoves = 0;
            board3.print();
            //Playing the game
            while(board_or_file == 1){
            board3.play(input_row, input_column, input_way, board_or_file, keep_load, numberOfMoves);
            board3.print();
            if(board3.win() == 1){
                board3.leftPegs(leftpegs);
                board3.emptycell(emptycells);
                cout << "GAME OVER. YOU FINISHED THE GAME LEAVING " << leftpegs << " PEGS BEHIND IN " << numberOfMoves << " MOVES." << endl;
                cout << " YOU TOOK " << initial_pegs - leftpegs << " PEGS OUT OF THE BOARD CLEARING " << emptycells << " CELLS" << endl;
                board_or_file = 3;
            } 
            if(board3.win() == 0) cout << "LET'S CONTINUE" << endl;
            }
            
        }
        if(gameStyle_input == 2){   //Computer game
            PegSolitaire board3_2(board_3, 8, 3, 'C');
            board3_2.playGame();
            cout << "Computer finished the game. Do you want to load another file or exit the program?" << endl;
            cout << "1- Load a file (ENTER 1)" << endl;
            cout << "2- EXIT (ENTER 2)" << endl;
            cin >> compsel;
            if(compsel == 1){
                board_or_file = 2;
            }
            if(compsel == 2){
                board_or_file = 3;
            }

        }
    }

//Board 4
    if(board_choose == 4){
        while(gameStyle_input==0 || gameStyle_input > 2){
        cout << "You choosed Board 4. Please choose the game type " << endl;
        cout << "1- HUMAN GAME" << endl;
        cout << "2- COMPUTER GAME " << endl;
        cin >> gameStyle_input;
        }
        
        
        if(gameStyle_input == 1){   //Human game
            PegSolitaire board4(board_4, 7, 4, 'H');
            board4.countPegs(initial_pegs);
            totalpegs = board4.countPegs(initial_pegs);
            board4.totalPegs(totalpegs);
            numberOfMoves = 0;
            board4.print();
            
            while(board_or_file == 1){
            board4.play(input_row, input_column, input_way, board_or_file, keep_load, numberOfMoves);
            board4.print();
            if(board4.win() == 1){
                board4.leftPegs(leftpegs);
                board4.emptycell(emptycells);
                cout << "GAME OVER. YOU FINISHED THE GAME LEAVING " << leftpegs << " PEGS BEHIND IN " << numberOfMoves << " MOVES." << endl;
                cout << " YOU TOOK " << initial_pegs - leftpegs << " PEGS OUT OF THE BOARD CLEARING " << emptycells << " CELLS" << endl;
                board_or_file = 3;
            } 
            if(board4.win() == 0) cout << "LET'S CONTINUE" << endl;
            }
            
        }
        if(gameStyle_input == 2){   //Computer game
            PegSolitaire board4_2(board_4, 7, 4, 'C');
            board4_2.playGame();
            cout << "Computer finished the game. Do you want to load another file or exit the program?" << endl;
            cout << "1- Load a file (ENTER 1)" << endl;
            cout << "2- EXIT (ENTER 2)" << endl;
            cin >> compsel;
            if(compsel == 1){
                board_or_file = 2;
            }
            if(compsel == 2){
                board_or_file = 3;
            }

        }
    }

//Board 5
    if(board_choose == 5){      
        while(gameStyle_input==0 || gameStyle_input > 2){
        cout << "You choosed Board 5. Please choose the game type " << endl;
        cout << "1- HUMAN GAME" << endl;
        cout << "2- COMPUTER GAME " << endl;
        cin >> gameStyle_input;
        }
        
        
        if(gameStyle_input == 1){   //Human game
            PegSolitaire board5(board_5, 9, 5, 'H');
            board5.countPegs(initial_pegs);
            totalpegs = board5.countPegs(initial_pegs);
            board5.totalPegs(totalpegs);
            numberOfMoves = 0;
           
            board5.print();
           
            while(board_or_file == 1){  
            board5.play(input_row, input_column, input_way, board_or_file, keep_load, numberOfMoves);
            board5.print();
            if(board5.win() == 1){
                board5.leftPegs(leftpegs);
                board5.emptycell(emptycells);
                cout << "GAME OVER. YOU FINISHED THE GAME LEAVING " << leftpegs << " PEGS BEHIND IN " << numberOfMoves << " MOVES." << endl;
                cout << " YOU TOOK " << initial_pegs - leftpegs << " PEGS OUT OF THE BOARD CLEARING " << emptycells << " CELLS" << endl;
                board_or_file = 3;
            } 
            if(board5.win() == 0) cout << "LET'S CONTINUE" << endl;
            }
           
        }
        if(gameStyle_input == 2){ //Computer game
            PegSolitaire board5_2(board_5, 9, 5, 'C');
            board5_2.playGame();
            cout << "Computer finished the game. Do you want to load another file or exit the program?" << endl;
            cout << "1- Load a file (ENTER 1)" << endl;
            cout << "2- EXIT (ENTER 2)" << endl;
            cin >> compsel;
            if(compsel == 1){
                board_or_file = 2;
            }
            if(compsel == 2){
                board_or_file = 3;
            }

        }
    }   



    }

//Load option
    while(board_or_file == 2){
        file_check = 0;
        numberOfMoves = 0;
        row_number = 0;
        while(file_check == 0){ //Checking the file existance
        cout << "You have choosen to LOAD a game from files. Please write the file name that you want to play with. Ex: If the file name is 'file_1.txt', write file_1.txt" << endl;
        cin >> filename;
        file_check = check_file(filename);
        if(file_check == 0) cerr << "Please enter a valid file name." << endl;
        }

        count_row(filename, row_number);    //Counting the rows so we can know the size of the board (square)
        
        PegSolitaire board7(row_number, filename, numberOfMoves, typeOfGame);   //Constructor for object
        board7.countPegs(initial_pegs);
        totalpegs = board7.countPegs(initial_pegs); //Peg counting (static)
        board7.totalPegs(totalpegs);
            
        if(typeOfGame == 'H'){  //Human game
            keep_load = 1;      //keep_load makes sure the loading process does not end
            board7.print();
            while(keep_load == 1){
                //Playing the game
                board7.play(input_row, input_column, input_way, board_or_file, keep_load, numberOfMoves);
                board7.print();
                
                if(board7.win() == 1) {
                    board7.leftPegs(leftpegs);
                    board7.emptycell(emptycells);
                    cout << "GAME OVER. YOU FINISHED THE GAME LEAVING " << leftpegs << " PEGS BEHIND IN " << numberOfMoves << " MOVES." << endl;
                    cout << " YOU TOOK " << initial_pegs - leftpegs << " PEGS OUT OF THE BOARD CLEARING " << emptycells << " CELLS" << endl;
                    keep_load = 0;
                    board_or_file = 3;
                }
                if(board7.win() == 0) cout << "LET'S CONTINUE" << endl;
            }
        }
        if(typeOfGame == 'C'){  //Computer game
            board7.playGame();
            cout << "Computer finished the game. Do you want to load another file or exit the program?" << endl;
            cout << "1- Load a file (ENTER 1)" << endl;
            cout << "2- EXIT (ENTER 2)" << endl;
            cin >> compsel;
            if(compsel == 1){
                board_or_file = 2;
            }
            if(compsel == 2){
                board_or_file = 3;
            }

        }
        
    }

    if(board_or_file == 3){
        cout << "THANK YOU FOR PLAYING! SEE YOU LATER, TAKE CARE..." << endl;   //Exit and goodbye message for user
    }
    return 0;
}
