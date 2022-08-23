/*ILAYDA ARAR CSE241 HW5 1901042638*/
/*Testing file for testing the functions. Some of the test results will be written on txt file*/
#include <vector>
#include <string>
#include <fstream>
#include <time.h>


#include "boardgame2d.cpp"
#include "peg.cpp"
#include "slider.cpp"
#include "klotski.cpp"

using namespace std;
using namespace nsboard2d;

int main(){

    PegSolitaire game1;
    Slider game2;
    Klotski game5;

    string filename = "testresults.txt";
    ofstream myfile (filename);

    cout << "Testing the Klotski game: Initialize function, print function, overloaded << operator and endgame function\n";
    game5.print();
    cout << endl;
    cout << game5;
    cout << "Current score is : " << game5.boardScore() << endl;
    cout << "Is this Klotski board won?\n";
    if(game5.endgame() == false) cout << "No, it has not won \n";
    if(game5.endgame() == true) cout << "Yes, it has won \n";

    myfile << game5;

    cout << "Testing the PegSolitaire game: playVector function, also tests playAuto and playAutoAll\n";
    vector < BoardGame2D * > peggames( 2 );
    peggames[ 0 ] = new PegSolitaire;            
    peggames[ 1 ] = new PegSolitaire;
    
    game1.playVector(peggames);
    delete peggames[ 0 ];
    delete peggames[ 1 ];

    cout << "Testing the Slider game: playVector function, also tests playAuto and playAutoAll\n";
    vector < BoardGame2D * > slidergames( 2 );
    slidergames[ 0 ] = new Slider;            
    slidergames[ 1 ] = new Slider;
    
    game2.playVector(slidergames);
    delete slidergames[ 0 ];
    delete slidergames[ 1 ];

    PegSolitaire game3;
    Slider game4;

    
    cout << "Testing the PegSolitaire game: playUser function, and playAuto, print and << operator\n";
    string input1 = "E3D";
    game3.playUser(input1);
    myfile << game3;
    game3.print();
    game3.playAuto();
    cout << game3;
    myfile << game3;

    cout << "Testing the Slider game: playUser function, and playAuto, print and << operator\n";
    string input2 = "31U";
    game4.playUser(input2);
    cout << game4;
    game4.playAuto();
    game4.print();

    cout << "Testing the PegSolitaire game: initialize function and playAutoOver (calls playAutoAll) functions\n";
    game3.initialize();
    game3.playAutoOver();
    myfile << "Computer score is : " << game3.boardScore() << endl;

    cout << "Testing the Slider game: initialize function and playAutoOver (calls playAutoAll) functions\n";
    game4.initialize();
    game4.playAutoOver();
    myfile << "Computer score is : " << game4.boardScore() << endl;

    myfile.close();

    cout << "Testing the PegSolitaire game: initialize function, boardscore and playUser (calls playUser overload) functions\n";
    game3.initialize();
    game3.playUserOver();
    cout << "Your score is : " << game3.boardScore() << endl;
    

    cout << "Testing the Slider game: initialize function, boardscore and playUser (calls playUser overload) functions\n";
    game4.initialize();
    game4.playUserOver();
    cout << "Your score is : " << game4.boardScore() << endl;
    
    
   
    
    return 0;
}


