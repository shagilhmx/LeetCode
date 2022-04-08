// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C


//Function to modify the matrix such that if a matrix cell matrix[i][j]
//is 1 then all the cells in its ith row and jth column will become 1.
void booleanMatrix(int R, int C, int matrix[][C])
{
    int n = R, m = C;
    int rows[n], cols[m];
    memset(rows, n, 0);
    memset(cols, m, 0);
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(matrix[i][j] == 1)
                rows[i] = cols[j] = 1;
        }
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(rows[i]  == 1 || cols[j] == 1)
                matrix[i][j] = 1;
        }
    }
}

// { Driver Code Starts.

int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		int matrix[row][col];
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		
		booleanMatrix(row, col, matrix);
		
		for(int i = 0; i < row; i++) {
		    for(int j = 0; j < col; j++)
		        printf("%d ", matrix[i][j]);
		  
		    printf("\n");
		}
	}
	return 0;
}  // } Driver Code Ends