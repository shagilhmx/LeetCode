// { Driver Code Starts
import java.util.Scanner;
import java.util.Stack;
class SortedStack{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		while(t-->0){
			Stack<Integer> s=new Stack<>();
			int n=sc.nextInt();
			while(n-->0)
			s.push(sc.nextInt());
			GfG g=new GfG();
			Stack<Integer> a=g.sort(s);
			while(!a.empty()){
				System.out.print(a.peek()+" ");
				a.pop();
			}
			System.out.println();
		}
	}
}// } Driver Code Ends


/*Complete the function below*/
class GfG{
    void helper(Stack<Integer> s, int val) {
        if(s.isEmpty() || val >= s.peek()) {
            s.add(val);
            return;
        }
        
        int top = s.peek();
        s.pop();
        helper(s, val);
        s.push(top);
    }
    
	public Stack<Integer> sort(Stack<Integer> s)
	{
		if(!s.isEmpty()) {
		    int x = s.peek();
		    s.pop();
		    sort(s);
		    helper(s, x);
		}
		return s;
	}
}