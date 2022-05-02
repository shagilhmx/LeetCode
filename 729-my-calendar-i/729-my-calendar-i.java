class Node {
    int start, end;
    Node left, right;
    
    public Node(int start, int end) {
        this.start = start;
        this.end = end;
        left = null;
        right = null;
        
    }
}

class SegmentTree {
    Node root;
    public void add(int start, int end) {
        root = add(start, end, root);
    }
    
    private Node add(int start, int end, Node root) {
        if(start > end)
            return null;
        if(root == null)
            return new Node(start, end);
        if(end < root.start)
            root.left = add(start, end, root.left);
        else if(start > root.end)
            root.right = add(start, end, root.right);
        
        return root;
    } 
    
    public boolean find(int start, int end) {
        return find(start, end, root);
    }
    
    private boolean find(int start, int end, Node root) {
        if(root == null)
            return false;
        if(root.start == start && root.end == end)
            return true;
        if(end < root.start)
            return find(start, end, root.left);
        else if(start > root.end)
            return find(start, end, root.right);
        else return true;
    }
}
class MyCalendar {
    SegmentTree st;
    public MyCalendar() {
        st = new SegmentTree();
    }
    
    public boolean book(int start, int end) {
        if(st.find(start, end - 1))
            return false;
        st.add(start, end - 1);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */