import java.io.*;

import bhb.AbstractBoard;
import bhb.BoardArray1D;
import bhb.BoardArray2D;

/**
 * 
 */

/**
 * @author BARAN_HASAN_BOZDUMAN-171044036
 *
 */
public class Driver {

	/**
	 * 
	 */
	public Driver() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * test main method
	 * @param args to get command line argument
	 * @throws IOException for the file operations
	 */
	public static void main(String[] args) throws IOException {
		try 
		{
			System.out.println("----------------------------------------TESTING FOR THE BOARD1D CLASSS-------------------------------------\n");
			  //////////////////////////////////////////////for 1dBoard class/////////////////////////////////////////
			      BoardArray1D a =new BoardArray1D();
			       System.out.println(" default Board1D constructor has called (i declare if user didnt determine anything default size 3*3)");
			       System.out.println(a);
			      BoardArray1D b= new BoardArray1D(4,5);
			       System.out.println("new object has been declared for 4*5 (my constructor gets row and colum from user) ");
			       System.out.println(b);      
			      BoardArray1D c= new BoardArray1D();
			      c.readFromFile("filename.txt");
			       System.out.println("read from file has called");
			       System.out.println(c) ;
			       System.out.println("moved left");
			      c.move('L');
			      System.out.println(c) ;
			       System.out.println("moved right");
			      c.move('R');
			      System.out.println( c );
			       System.out.println("moved up");
			      c.move('U');
			      System.out.println(c) ;
			       System.out.println("moved down");
			      c.move('D');
			      System.out.println(c );
			       System.out.println("last board has written to file which name is saved.txt");
			      c.writeToFile("saved.txt");
			       System.out.println("set size called for last object has set to 3*5 (Also reset method has called in setSize method) ");
			      c.setSize(3,5);
			      System.out.println( c );
			       System.out.println("3.txt file is import to c object (3.txt contains solved puzzle)");
			      c.readFromFile("3.txt");
			       System.out.println("The is solved method result is "+c.isSolved());
			       System.out.println(c );
			       System.out.println("for invalid contex it terminates program if you want to try it uncomment the 65th line");
			      // System.out.println(cell(22,13));
			      b.readFromFile("filename.txt");
			      a.readFromFile("filename.txt");
			       System.out.println("equals result is for a and b object(they are the same puzzle which is contex of filename.txt) ");
			       System.out.println(a.equals(b));
			       System.out.println("the number of boards created so far"+AbstractBoard.NumberOfBoards());
			       System.out.println("a objects puzzle moved up and get last move:::");
			      a.move('U');
			       System.out.println(a.lastMove());
			       System.out.println("after 6 movement for b object puzzle the number of moves:::::::::");      
			      b.move('u');
			      b.move('r');
			      b.move('r');
			      b.move('r');
			      b.move('d');
			      b.move('l');
			      System.out.println(b.numberOfMoves());
			      
			       System.out.println(" ");
			     
			     
			     
			       System.out.println("----------------------------------------TESTING FOR THE BOARD2D CLASSS-------------------------------------");
			    /////////////////////////////////////////////////for2dboardclass////////////////////////////////////////////////////
			      BoardArray2D x= new BoardArray2D();
			       System.out.println(" default Board2D constructor has called (i declare if user didnt determine anything default size 3*3)");
			       System.out.println("print is calling for Board2D");
			       System.out.println(x );
			      BoardArray2D y = new BoardArray2D(4,5);
			       System.out.println("new object has been declared for 4*5 (my constructor gets row and colum from user) ");
			       System.out.println( y );      
			      BoardArray2D z=new BoardArray2D();
			      z.readFromFile("filename.txt");
			      System.out.println("read from file has called");
			      System.out.println(z );
			      System.out.println("moved left");
			      z.move('L');
			      System.out.println(z );
			      System.out.println("moved right");
			      z.move('R');
			      System.out.println(z );
			      System.out.println("moved up");
			      z.move('U');
			      System.out.println(z );
			      System.out.println("moved down");
			      z.move('D');
			      System.out.println(z );
			       System.out.println("last board has written to file which name is saved.txt");
			      z.writeToFile("saved.txt");
			       System.out.println("set size called for last object has set to 3*5 (Also reset method has called in setSize method) ");
			      z.setSize(3,5);
			      System.out.println( z );
			       System.out.println("3.txt file is import to z object (3.txt contains solved puzzle)");
			      z.readFromFile("3.txt");
			       System.out.println("The is solved method result is "+z.isSolved());
			      System.out.println(z);
			      System.out.println("the cell result for (1,2) "+z.cell(1,2));
			       System.out.println("for invalid contex it terminates program if you want to try it uncomment the 104th line");
			      // System.out.println(z.operator()(22,13));
			      y.readFromFile("filename.txt");
			      x.readFromFile("filename.txt");
			      System.out.println("the number of boards created so far"+AbstractBoard.NumberOfBoards());
			      System.out.println("x objects puzzle moved up and get last move:::");
			      x.move('U');
			      System.out.println(x.lastMove());
			      System.out.println("after 6 movement for b object puzzle the number of moves:::::::::");      
			      y.move('u');
			      y.move('r');
			      y.move('r');
			      y.move('r');
			      y.move('d');
			      y.move('l');
			      System.out.println(y.numberOfMoves());
			       System.out.println(" ");
			     
			 
			
			
			
			
			
			
			System.out.println("_______1________TEST_OF_THE_GLOBAL_METHOD___________1_______ValidSequence___");
			BoardArray1D A1=new BoardArray1D(),A2=new BoardArray1D(),A3 = new BoardArray1D();
		        BoardArray2D B1=new BoardArray2D(),B2=new BoardArray2D();
		        AbstractBoard[] TestSequence = new AbstractBoard[]{A1, B1, A2, B2, A3};
		        
		        A1.readFromFile( "00.txt");
		        System.out.println(A1);
		        System.out.println("_____________________________________");
		        B1.readFromFile( "0.txt");
		        System.out.println(B1);
		        System.out.println("_____________________________________");
		        A2.readFromFile( "1.txt");
		        System.out.println(A2);
		        System.out.println("_____________________________________");
		        B2.readFromFile( "2.txt");
		        System.out.println(B2);
		        System.out.println("_____________________________________");
		        A3.readFromFile( "3.txt");
		        System.out.println(A3);
		        System.out.println("_____________________________________");
		        System.out.println(A3);
		        if(AbstractBoard.myCheckGlobalfoo(TestSequence))
		            System.out.println("Worked");
		        else
		        	System.out.println("the test sequence is not valid");
		        
		        
		        System.out.println("________2_______TEST_OF_THE_GLOBAL_METHOD________AllDifferent_____________");		        
			        A1.readFromFile( "1.txt");
			        System.out.println(A1);
			        System.out.println("_____________________________________");
			        B1.readFromFile( "0.txt");
			        System.out.println(B1);
			        System.out.println("_____________________________________");
			        A2.readFromFile( "00.txt");
			        System.out.println(A2);
			        System.out.println("_____________________________________");
			        B2.readFromFile( "3.txt");
			        System.out.println(B2);
			        System.out.println("_____________________________________");
			        A3.readFromFile( "2.txt");
			        System.out.println(A3);
			        System.out.println("_____________________________________");
			        System.out.println(A3);
			        if(AbstractBoard.myCheckGlobalfoo(TestSequence))
			            System.out.println("Worked");
			        else
			        	System.out.println("the test sequence is not valid");    
			        
			        
			        System.out.println("________3_______TEST_OF_THE_GLOBAL_METHOD________AllSame_____________");		        
			        A1.readFromFile( "1.txt");
			        System.out.println(A1);
			        System.out.println("_____________________________________");
			        B1.readFromFile( "1.txt");
			        System.out.println(B1);
			        System.out.println("_____________________________________");
			        A2.readFromFile( "1.txt");
			        System.out.println(A2);
			        System.out.println("_____________________________________");
			        B2.readFromFile( "1.txt");
			        System.out.println(B2);
			        System.out.println("_____________________________________");
			        A3.readFromFile( "1.txt");
			        System.out.println(A3);
			        System.out.println("_____________________________________");
			        System.out.println(A3);
			        if(AbstractBoard.myCheckGlobalfoo(TestSequence))
			            System.out.println("Worked");
			        else
			        	System.out.println("the test sequence is not valid");   
			        
			        
			        System.out.println("________4_______TEST_OF_THE_GLOBAL_METHOD________theLastIsNotSolution_____________");
			        System.out.println("_____________________________________");
			        B1.readFromFile( "00.txt");
			        System.out.println(B1);
			        System.out.println("_____________________________________");
			        A2.readFromFile( "0.txt");
			        System.out.println(A2);
			        System.out.println("_____________________________________");
			        B2.readFromFile( "1.txt");
			        System.out.println(B2);
			        System.out.println("_____________________________________");
			        A3.readFromFile( "2.txt");
			        System.out.println(A3);
			        System.out.println("_____________________________________");
			        System.out.println(A3);
			        if(AbstractBoard.myCheckGlobalfoo(TestSequence))
			            System.out.println("Worked");
			        else
			        	System.out.println("the test sequence is not valid");    
			        
			        
			        System.out.println("________5_______TEST_OF_THE_GLOBAL_METHOD__________AllTheSame___________");		        
			        A1.readFromFile( "3.txt");
			        System.out.println(A1);
			        System.out.println("_____________________________________");
			        B1.readFromFile( "3.txt");
			        System.out.println(B1);
			        System.out.println("_____________________________________");
			        A2.readFromFile( "3.txt");
			        System.out.println(A2);
			        System.out.println("_____________________________________");
			        B2.readFromFile( "3.txt");
			        System.out.println(B2);
			        System.out.println("_____________________________________");
			        A3.readFromFile( "3.txt");
			        System.out.println(A3);
			        System.out.println("_____________________________________");
			        System.out.println(A3);
			        if(AbstractBoard.myCheckGlobalfoo(TestSequence))
			            System.out.println("Worked");
			        else
			        	System.out.println("the test sequence is not valid");    
			
		}
		catch(IOException a) {}
		  
		        
		        
	}

}
