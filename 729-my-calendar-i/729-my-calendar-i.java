class MyCalendar {
    TreeMap<Integer, Integer> tMap;
    public MyCalendar() {
        tMap = new TreeMap<>();
    }
    
    public boolean book(int start, int end) {
        //condition around start time
        //start < lower entry end time then return false.
        boolean flag = true;
        if(tMap.floorEntry(start) != null && start < tMap.floorEntry(start).getValue()) return false;
        
        //condition around end time
        //end > higher entry start time then return false.
        if(tMap.ceilingEntry(start) != null && end > tMap.ceilingEntry(start).getKey()) return false;
        tMap.put(start, end);
        return true;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */