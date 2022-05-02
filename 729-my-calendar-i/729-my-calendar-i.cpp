class MyCalendar {
public:
    map<int, int> calendar;
    MyCalendar() {}
    
    bool book(int start, int end) {
        calendar[start]++;
        calendar[end]--;
        int sum = 0;
        
        for(auto el : calendar) {
            sum += el.second;
            if(sum > 1) {
                calendar[start]--;
                calendar[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */