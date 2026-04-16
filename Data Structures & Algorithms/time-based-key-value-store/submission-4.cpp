class TimeMap {
    private:
    map<string, vector<pair<int, string>>> timeStore;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        timeStore[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(timeStore.find(key)==timeStore.end()) return "";
        string res = "";

        vector<pair<int,string>> values = timeStore[key];
        int start = 0;
        int end = values.size()-1;

        while(start<=end){
            int mid = start + (end-start)/2;
            if(values[mid].first>timestamp) end = mid - 1;
            else {
                res = values[mid].second;
                start = mid+1;
            }
        }
        return res;
    }
};
