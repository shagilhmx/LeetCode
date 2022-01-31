class MyCalendar {
public:
    map<int, int> calendar;
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto iterator = calendar.upper_bound(start);
        bool flag = false;
        
        if((iterator == calendar.begin() && (iterator == calendar.end() || end <= iterator -> first)) || (iterator != calendar.begin() && (start >= prev(iterator) -> second && (iterator == calendar.end() || end <= iterator -> first)))) {
            calendar[start] = end;
            flag = true;
        }
        return flag;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */