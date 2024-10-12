class LRUCache {
public:
    list<int>dl;
    map<int,pair<list<int>::iterator,int>>mp;
    int size;
    LRUCache(int capacity) {
        size=capacity;
    }
    void recentlyused(int key)
    {
        dl.erase(mp[key].first);
        dl.push_front(key);
        mp[key].first=dl.begin();
    }
    int get(int key) {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        recentlyused(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            mp[key].second=value;
            recentlyused(key);
        }
        else
        {
            dl.push_front(key);
            mp[key]={dl.begin(),value};
            size--;
        }
        if(size<0)
        {
            int todelete=dl.back();
            dl.pop_back();
            mp.erase(todelete);
            size++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */