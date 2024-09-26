class MyCalendar {
    multiset<pair<int,int>>mp;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        mp.insert(make_pair(start,1));
        mp.insert(make_pair(end,-1));
        int sum=0;
        for(auto it:mp)
        {
            sum+=it.second;
            if(sum>1)
            {
                mp.erase(mp.find(make_pair(start,1)));
                mp.erase(mp.find(make_pair(end,-1)));
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