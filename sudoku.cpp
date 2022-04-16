//Program to solve a Sudoku

#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  

class Solution 
{
    public:
    //Function to find a solved Sudoku.
    bool solve(int board[N][N])
    {    
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {    
                if(board[i][j]==0)
                {
                    for(int c=1; c<=9; c++)
                    {
                        if(isValid(board,i,j,c)){
                            board[i][j] = c;
                            if(solve(board)==true)
                                return true;
                            else
                                board[i][j] = 0;
                        }      
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(int board[N][N], int row, int col, int c){
        
        for(int i=0; i<9; i++){
            if(board[row][i] == c)
                return false;
            if(board[i][col] == c)
                return false;
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c)
                return false;
        }
        return true;
    }
    
    
    bool SolveSudoku(int grid[N][N])  
    { 
        
        return solve(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};


int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  
