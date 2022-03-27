// { Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;

class GfG { 
    
	public static void main (String[] args) throws IOException  {
	    
	    //reading input using BufferedReader class
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//reading total testcases
		int t = Integer.parseInt(br.readLine().trim());
		while(t-->0){
		    
		    //reading number of eggs and floors
		    String inputLine[] = br.readLine().trim().split(" ");
		    
		    int n = Integer.parseInt(inputLine[0]);
		    int k = Integer.parseInt(inputLine[1]);
		    
		    //calling eggDrop() method of class
		    //EggDrop
		    System.out.println(new Solution().eggDrop(n, k));
		}
	}
}


// } Driver Code Ends


class Solution 
{
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    static int eggDrop(int n, int k) 
	{
	    // Your code here
	    int[][] dp = new int[n + 1][k + 1];
	        
	    for(int i=0;i<=n;i++) {
	        for(int j=0;j<=k;j++) {
	            
	            //if floors or egg is zero return 0.
	            if(i == 0 || j == 0) 
	                dp[i][j] = 0;
	            
	            //if floor is 1 return 1.
	            else if(j == 1)
	                dp[i][j] = 1;
	                
	            //if egg is 1 we need to check at each floor.
	            else if(i == 1)
	                dp[i][j] = j;
	           
	            else {
	                int ans = Integer.MAX_VALUE;
	                for(int f=1;f<=j;f++) {
	                    int val = 1 + Math.max(dp[i - 1][f - 1], dp[i][j - f]);
	                    ans = Math.min(ans, val);
	                }
	                dp[i][j] = ans;
	            }
	        }
	    }
	    return dp[n][k];
	}
}