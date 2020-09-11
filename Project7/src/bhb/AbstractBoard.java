package bhb;
// File: AbstractBoard.java
// AbstractBoard class with the abstract methods which is abstract board
import java.io.*;
/**
 * 
 */

/**
 * @author BARAN_HASAN_BOZDUMAN-171044036
 *
 */

public abstract class AbstractBoard {
	protected int row;				//row number
	protected int colum;			//column number
	protected int blank_x;			//x axis for the blank tile
	protected int blank_y;			//y axis for the blank tile
	protected String filename="xXx"; //filename
	protected int repeat;			//repeat number which is multiplies row by column

	
	private int numberOfMoves;		//keeps number of moves
	private char lastMove;			//keeps the last move of the puzzle
	private static int numberOfBoards=0; //keeps the number of objects
	
	/**
	    * cell function to get number of index
	    * thus  i avoid more code duplicate
	    * @param i row number 
	    * @param j column number
	    * @return the value of index
	    * 
	    */
	public abstract int  cell(int i,int j);
	
	/**
	    * cellPlace function to change the one of index of puzzle 
	    * thus  i avoid more code duplicate
	    * @param i row number 
	    * @param j column number
	    * @param setNUmber the number which is the new value for index
	    * @return the number of placed
	    * 
	    */
	protected abstract int cellPlace(int i, int j,int setNumber);
	
	/**
	    * No-argument constructor 
	    * set the row and column variables for 3 to 3 board 
	    * @see #setSize(int, int)
	    * it sets the blank 2 2 and 
	    * set last move to 'S'
	    * increases number of boards
	    * set number of moves 0
	    * 
	    */
	public AbstractBoard(){
		row=3;			colum=3;
		blank_x=2;		blank_y=2;
		repeat=9;		numberOfMoves=0;
		lastMove='S';	numberOfBoards++;
		setSize(row,colum);
	}
	
	/**
	    * AbstractBoard constructor
	    * @param r row number
	    * @param c column number
	    * @see #setSize(int, int)
	    * set last move to 'S'
	    * increases number of boards
	    * set number of moves 0
	    */
	public AbstractBoard(int r,int c){
		row=r;
		colum=c;
		lastMove='S';
		numberOfMoves=0;
		setSize(r,c);
		numberOfBoards++;
	}
	
	/**
	    * isValidMove method is to check the move is valid or not
	    *@param move_direction the character for the direction
	    * @see cell(int,int)
	    * @return true if the move is valid
	    */
	protected boolean isValidMove(char move_direction) {
		if((move_direction == 'U' || move_direction == 'u') && blank_x > 0 && this.cell(blank_x-1,blank_y)!=0)
            return true;
        if((move_direction == 'D' || move_direction == 'd') && blank_x < row-1 && this.cell(blank_x+1,blank_y)!=0)
            return true;
        if((move_direction == 'L' || move_direction == 'l') && blank_y > 0 && this.cell(blank_x,blank_y-1)!=0)
            return true;
        if((move_direction == 'R' || move_direction == 'r') && blank_y < colum-1 && this.cell(blank_x,blank_y+1)!=0)
            return true;
        return false;
	}
	
	/**
	    * overrided toString method to print the board as a string
	    * @see #cell(int,int)
	    * @return the puzzle as a string
	    */
	@Override
	public String toString() {
		String mypuz= "";
		for (int i = 0; i < row; i++){
            for (int j = 0; j < colum; j++){
                if (this.cell(i,j) > 0)
                	mypuz+=this.cell(i,j)+"\t";
                else if(this.cell(i,j)==-1)
                	mypuz+="bb\t";
                else if(this.cell(i,j)==0)
                	mypuz+="  \t";
                else	
                	mypuz+="xx\t";
            }
            mypuz+="\n\n";
        }
		return mypuz;
	}
	
	/**
	    * it gives the number of boards
	    * @return the number of boards
	    */	
	public static int NumberOfBoards() {
		return numberOfBoards;
	}
	
	/**
	    * read from file method takes file name and read and fill the puzzle array
	    * @param filename file name
	    * @throws IOException if there is a problem with file throws exception
	    * @see #setSize(int, int)
	    */
	public void readFromFile(String filename) throws IOException {
        int row=0,colum=0;
        int i,j;
        int foreach;
        String[] colnum=null;
        FileReader myf =new FileReader(filename);
        String end;
        BufferedReader wordb = new BufferedReader(myf);
        	while((end = wordb.readLine()) != null) {
        		row++;
        		colnum=end.split(" ");
        		colum=colnum.length;
        	}      
        
        myf.close();
        setSize(row,colnum.length);
        colnum=null;
        row=0;colum=0;
        myf =new FileReader(filename);
        wordb = new BufferedReader(myf);
        	while((end = wordb.readLine()) != null) {
        		colnum=end.split(" ");
        		colum=colnum.length;
        		for( j=0; j<colum; j++){
        			if(colnum[j].toString().equalsIgnoreCase("bb"))
        				this.cellPlace(row,j,-1);
        			else {
        				foreach=Integer.parseInt(colnum[j].toString());
        			if(foreach== 0)
    		            this.cellPlace(row,j,0);
    		    	else if(foreach > 0  )
    		            this.cellPlace(row,j,foreach);
    		        else//if it has two digits it converts first digit and multiply by 10 and add the last digit so thats how i convert them to integer 
    		            this.cellPlace(row,j,-1);
        			}
        		}
        			colum=0;
        			row++;
        	}  	
        myf.close();
        	for ( i = 0; i <row; i++)
        		for ( j = 0; j <colnum.length; j++)
	                if (this.cell(i,j) == -1) {
	                    blank_x=i ;blank_y=j;
	                }    

	}
	
	/**
	    * write file method takes string as a parameter and creates the file
	    * @param filename takes the save file name
	    * @throws IOException for the file operations
	    * @see #cell(int, int)
	    */
	public void writeToFile(String filename) throws IOException {
		String mypuz="";
		File savefile = new File(filename);
		savefile.createNewFile();
		FileWriter savedfile= new FileWriter(savefile);
        for(int i=0; i<row; i++){
                for(int j=0; j<colum; j++){
        
                    if( this.cell(i,j)==-1 )
                        mypuz+="bb";
                    else if(this.cell(i,j)==0)
                        mypuz+="00";
                    else if(this.cell(i,j) != 0 && this.cell(i,j) <10 )
                        mypuz+="0"+this.cell(i,j);					
                    else	
                        mypuz+=this.cell(i,j);
                    if (j!=colum-1)
                        mypuz+=" ";
                }
                mypuz+="\n";     
        }
        savedfile.write(mypuz);
        savedfile.close();
	}
	
	/**
	    * reset method takes puzzle to final position
	    * @see #cell(int, int)
	    * @see #cellPlace(int, int, int)
	    */
	public void reset() {
		int fill=1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < colum; j++) {
                if(this.cell(i,j) != 0){
                    this.cellPlace(i,j,fill);
                    fill++;
                }	
            }
        }
        this.cellPlace(row-1,colum-1,-1);

        blank_x=row-1; blank_y=colum-1;
	}
	
	/**
	    * setSize sets the row and column
	    * @param sizevalue_row to assign row the row value
	    * @param sizevalue_colum to assign the column column value
	    */
	public void setSize(int sizevalue_row,int sizevalue_colum) {
		row=sizevalue_row; colum=sizevalue_colum;
	}
	
	/**
	 * move method to move blank tile
	 * @param move_direction the direction of blank tile
	 * @see #isValidMove(char)
	 * @return movement is succes or not if it succes returns true
	 */
	public boolean move (char move_direction) {
		int targetX=0,targetY=0;

        switch(move_direction)
        {
            case 'u':
            case 'U':
                if(isValidMove(move_direction))
                    targetX=-1;
                	numberOfMoves++;
                break;
            case 'd':
            case 'D':
                if(isValidMove(move_direction))
                    targetX=1;
                	numberOfMoves++;
                break;
            case 'l':
            case 'L':
                if(isValidMove(move_direction))
                    targetY = -1;
                	numberOfMoves++;
                break;
            case 'r':
            case 'R':
                if(isValidMove(move_direction))
                    targetY=1;
                	numberOfMoves++;
                break;
        }

        if(targetX != 0 || targetY != 0)
        {
            int temp = this.cell(blank_x,blank_y);
            this.cellPlace(blank_x,blank_y,this.cell(blank_x+targetX,blank_y+targetY)); 
            this.cellPlace(blank_x+targetX,blank_y+targetY,temp);

            blank_x += targetX;
            blank_y += targetY;
            lastMove = move_direction;
            return true;
        }
        return false;
    }
	/**
	 * isSolved method checks the board is solution or not
	 * @return true if its the solution
	 */
	public boolean isSolved() {
		int compare=1;
        int flag =0;
        int i=0,j=0;
        boolean check=false;

        for(i=0; i<row && flag==0; i++){
            for(j=0; j<colum && (flag==0); j++){
                if( this.cell(i,j) == 0 )
                    flag=0;
                else if(this.cell(i,j) != 0 && this.cell(i,j) == compare){
                    check=true;
                    flag=0;
                    compare++;
                    if(this.cell(row-1,colum-1)== -1){
                        flag=1;
                        check=true;
                    }	
                }
                else if(i==row-1 && j==colum-1)
                    flag=1;	
                else{
                    check=false;
                    flag=1;
                }	
            }
        }
        if(i==row && j==colum)
            System.out.println("Problem Solved!");
		return check;
	}
	/**
	 * it compares two board is equal or not
	 * @see cell
	 *@return true if are they equal
	 *
	 */
	@Override
	public boolean equals(Object currentboard) {
		 for (int i = 0; i < row; i++)
	        {
	            for (int j = 0; j < colum; j++)
	            { 
	                if (!(this.cell(i,j)==((AbstractBoard) currentboard).cell(i,j)))
	                    return false;            
	            }	            
	        }
		 	return true;}
	/**
	 * it gets number of moves
	 * @return number of moves
	 */
	public int numberOfMoves(){
		return numberOfMoves;}
	/**
	 * it gets last move
	 * @return last move
	 */
	public char lastMove(){
		return lastMove;}
	/**
	 * it sets last move
	 * @param setLastMove takes char to set last move
	 */
	public void setterlastmove(char setLastMove) {
		lastMove=setLastMove;
	}
	/**
	 * it gets the row
	 * @return row number
	 */
	public int getrow(){return row;}
	/**
	 * it gets the column number
	 * @return	column number
	 */
	public int getcolum(){return colum;}
	/**
	 * it gets the repeat which is the row multiplynig by column
	 * @return repeat number(row*column)
	 */
    public int getrepeat(){return repeat;}
    /**
     * The method to check valid sequence moves
     * @param checkIt the parameter object of abstractboard 
     * @return true if the valid sequence
     */
    public static boolean myCheckGlobalfoo(Object[] checkIt) {
    	int size= checkIt.length;
    	int i= size-1;
    	int roww = ((AbstractBoard) checkIt[0]).getrow();
    	int columm = ((AbstractBoard) checkIt[0]).getcolum();
    	int firstx = 0,firsty = 0,secondx = 0,secondy = 0;
    	int total;
    	int difcounter=0;
    	if( !((AbstractBoard) checkIt[size-1]).isSolved())
    		return false;
    	
    	while(i>0) {
    		difcounter=0; 
    		for (int k = 0; k < roww; k++) {
    			for (int j = 0; j < columm; j++) {
    				if(((AbstractBoard) checkIt[i]).cell(k,j) != ((AbstractBoard) checkIt[i-1]).cell(k,j))
    					difcounter++;
    				if(((AbstractBoard) checkIt[i]).cell(k,j) ==-1) {
                         firstx=k;firsty=j;
    				}     
                    if(((AbstractBoard) checkIt[i-1]).cell(k,j) ==-1) {
                    	secondx=k;secondy=j;
                    }	                    	
    			}				
			}    		
    		total= firstx-secondx+firsty-secondy;
            if((difcounter >2) | !(total ==1 | total ==-1))
            	return false;
            i--;
    	}
    	
		return true;
    }	
	
}
