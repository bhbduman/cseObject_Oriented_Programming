#include<iostream>
#include "AB.h"
#include "B2.h"
#include "B1.h"
#include "BV.h"

 

 using namespace std;
 using namespace BHB;




int main(){
  cout<<"----------------------------------------TESTING FOR THE BOARD1D CLASSS-------------------------------------"<<endl;
  //////////////////////////////////////////////for 1dBoard class/////////////////////////////////////////
      Board1D a;
      cout<<" default Board1D constructor has called (i declare if user didnt determine anything default size 3*3)"<<endl;
      cout<<"print is calling for Board1D"<<endl;
      a.print();
      Board1D b(4,5);
      cout<<"new object has been declared for 4*5 (my constructor gets row and colum from user) "<<endl;
      b.print();      
      Board1D c;
      c.readFromFile("filename.txt");
      cout<<"read from file has called"<<endl;
      c.print();
      cout<<"moved left"<<endl;
      c.move('L');
      c.print();
      cout<<"moved right"<<endl;
      c.move('R');
      c.print();
      cout<<"moved up"<<endl;
      c.move('U');
      c.print();
      cout<<"moved down"<<endl;
      c.move('D');
      c.print();
      cout<<"last board has written to file which name is saved.txt"<<endl;
      c.writeToFile("saved.txt");
      cout<<"set size called for last object has set to 3*5 (Also reset function has called in setSize function) "<<endl;
      c.setSize(3,5);
      c.print();
      cout<<"3.txt file is import to c object (3.txt contains solved puzzle)"<<endl;
      c.readFromFile("3.txt");
      cout<<"The is solved function result is "<<endl<<c.isSolved()<<endl;
      c.print();
      cout<<"the () operator result for (1,2) "<<c.operator()(1,2)<<endl;
      cout<<"for invalid contex it terminates program if you want to try it uncomment the 91th line"<<endl;
      //cout<<c.operator()(22,13)<<endl;
      b.readFromFile("filename.txt");
      a.readFromFile("filename.txt");
      cout<<"operator == result is for a and b object(they are the same puzzle which is contex of filename.txt) "<<endl;
      cout<<a.operator==(b)<<endl;
      cout<<"the number of boards created so far"<<a.NumberOfBoards()<<endl;
      cout<<"a objects puzzle moved up and get last move:::";
      a.move('U');
      cout<<a.lastMove()<<endl;
      cout<<"after 6 movement for b object puzzle the number of moves:::::::::";      
      b.move('u');
      b.move('r');
      b.move('r');
      b.move('r');
      b.move('d');
      b.move('l');
      cout<<b.numberOfMoves()<<endl;
      cout<<" "<<endl;
     
     
     
      cout<<"----------------------------------------TESTING FOR THE BOARD2D CLASSS-------------------------------------"<<endl;
    /////////////////////////////////////////////////for2dboardclass////////////////////////////////////////////////////
      Board2D x;
      cout<<" default Board2D constructor has called (i declare if user didnt determine anything default size 3*3)"<<endl;
      cout<<"print is calling for Board2D"<<endl;
      x.print();
      Board2D y(4,5);
      cout<<"new object has been declared for 4*5 (my constructor gets row and colum from user) "<<endl;
      y.print();      
      Board2D z;
      z.readFromFile("filename.txt");
      cout<<"read from file has called"<<endl;
      z.print();
      cout<<"moved left"<<endl;
      z.move('L');
      z.print();
      cout<<"moved right"<<endl;
      z.move('R');
      z.print();
      cout<<"moved up"<<endl;
      z.move('U');
      z.print();
      cout<<"moved down"<<endl;
      z.move('D');
      z.print();
      cout<<"last board has written to file which name is saved.txt"<<endl;
      z.writeToFile("saved.txt");
      cout<<"set size called for last object has set to 3*5 (Also reset function has called in setSize function) "<<endl;
      z.setSize(3,5);
      z.print();
      cout<<"3.txt file is import to z object (3.txt contains solved puzzle)"<<endl;
      z.readFromFile("3.txt");
      cout<<"The is solved function result is "<<endl<<z.isSolved()<<endl;
      z.print();
      cout<<"the () operator result for (1,2) "<<z.operator()(1,2)<<endl;
      cout<<"for invalid contex it terminates program if you want to try it uncomment the 104th line"<<endl;
      //cout<<z.operator()(22,13)<<endl;
      y.readFromFile("filename.txt");
      x.readFromFile("filename.txt");
      cout<<"operator == result is for x and y object(they are the same puzzle which is contex of filename.txt) "<<endl;
      cout<<x.operator==(y)<<endl;
      cout<<"the number of boards created so far"<<x.NumberOfBoards()<<endl;
      cout<<"x objects puzzle moved up and get last move:::";
      x.move('U');
      cout<<x.lastMove()<<endl;
      cout<<"after 6 movement for b object puzzle the number of moves:::::::::";      
      y.move('u');
      y.move('r');
      y.move('r');
      y.move('r');
      y.move('d');
      y.move('l');
      cout<<y.numberOfMoves()<<endl;
      cout<<" "<<endl;
     
     
     
      cout<<"----------------------------------------TESTING FOR THE BOARDVECTOR CLASSS-------------------------------------"<<endl;
      /////////////////////////////////////////////////for vector boardclass////////////////////////////////////////////////////
      BoardVector q;
      cout<<" default BoardVector constructor has called (i declare if user didnt determine anything default size 3*3)"<<endl;
      cout<<"print is calling for BoardVector"<<endl;
      q.print();
      BoardVector w(4,5);
      cout<<"new object has been declared for 4*5 (my constructor gets row and colum from user) "<<endl;
      w.print();      
      BoardVector e;
      e.readFromFile("filename.txt");
      cout<<"read from file has called"<<endl;
      e.print();
      cout<<"moved left"<<endl;
      e.move('L');
      e.print();
      cout<<"moved right"<<endl;
      e.move('R');
      e.print();
      cout<<"moved up"<<endl;
      e.move('U');
      e.print();
      cout<<"moved down"<<endl;
      e.move('D');
      e.print();
      cout<<"last board has written to file which name is saved.txt"<<endl;
      e.writeToFile("saved.txt");
      cout<<"set size called for last object has set to 3*5 (Also reset function has called in setSize function) "<<endl;
      e.setSize(3,5);
      e.print();
      cout<<"3.txt file is import to e object (3.txt contains solved puzzle)"<<endl;
      e.readFromFile("3.txt");
      cout<<"The is solved function result is "<<endl<<z.isSolved()<<endl;
      e.print();
      cout<<"the () operator result for (1,2) "<<z.operator()(1,2)<<endl;
      cout<<"for invalid contex it terminates program if you want to try it uncomment the 166th line"<<endl;
      //cout<<z.operator()(22,13)<<endl;
      w.readFromFile("filename.txt");
      q.readFromFile("filename.txt");
      cout<<"operator == result is for q and w object(they are the same puzzle which is contex of filename.txt) "<<endl;
      cout<<q.operator==(w)<<endl;
      cout<<"the number of boards created so far"<<q.NumberOfBoards()<<endl;
      cout<<"q objects puzzle moved up and get last move:::";
      q.move('U');
      cout<<q.lastMove()<<endl;
      cout<<"after 6 movement for b object puzzle the number of moves:::::::::";      
      w.move('u');
      w.move('r');
      w.move('r');
      w.move('r');
      w.move('d');
      w.move('l');
      cout<<w.numberOfMoves()<<endl;
      cout<<" "<<endl;

     cout<<"---------------------------------TESTING FOR GLOBAL VALID SEWUENCE FUNCTION----------------------------"<<endl; 
    /////////////////////////////////////////test global function///////////////////////////      
         int boolglobal;
         cout<<"the puzzles are read by five file and its valid sequence (also it assigin them to different classes to test them all) "<<endl;
         AbstractBoard* k[5];
         k[ 0 ] = new Board1D;
         k[ 0 ] -> readFromFile("00.txt");
         k[ 0 ] -> setterlastmove('S');
         k[ 0 ] -> print();
         
         k[ 1 ] = new Board2D;
         k[ 1 ] -> readFromFile("0.txt");
         k[ 1 ] -> setterlastmove('S');
         k[ 1 ] -> print();

         k[ 2 ] = new Board2D;
         k[ 2 ] -> readFromFile("1.txt");
         k[ 2 ] -> setterlastmove('S');
         k[ 2 ] -> print();


         k[ 3 ] = new BoardVector;
         k[ 3 ] -> readFromFile("2.txt");
         k[ 3 ] -> setterlastmove('D');
         k[ 3 ] -> print();

         k[ 4 ] = new Board1D;
         k[ 4 ] -> readFromFile("3.txt");
         k[ 4 ] -> setterlastmove('R');
         k[ 4 ] -> print();

      
         
         boolglobal = myglobalCheckFo( k , 5 );
         cout<<boolglobal<<":::::::::::::::::returned"<<endl;

     
     
     return 0;
}
