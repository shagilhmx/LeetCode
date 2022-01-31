class MyCalendar {
    TreeMap<Integer, Integer> tMap;
    public MyCalendar() {
        tMap = new TreeMap<>();
    }
    
    public boolean book(int start, int end) {
        Integer prev = tMap.floorKey(start), next = tMap.ceilingKey(start);
        boolean flag = false;
        if((prev == null || tMap.get(prev) <= start) && (next == null || end <= next)) {
            tMap.put(start, end);
            flag = true;
        }
        return flag;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */