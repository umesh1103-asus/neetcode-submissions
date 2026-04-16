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

        vector<pair<int,string>> values = timeStore[key];
        //if(values[values.size()-1].first>timestamp)
        cout << values.size() << endl;
        //return "";
        int start = 0;
        int end = values.size()-1;

        while(start<end){
            int mid = start + (end-start+1)/2;
            if(values[mid].first>timestamp) end = mid - 1;
            else start = mid;
        }

        if(values[start].first<=timestamp) return values[start].second;
        return "";
    }
};
