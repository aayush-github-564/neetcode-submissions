class TimeMap {
private:
    unordered_map<string, vector<pair<int,string>>> store;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string res = "";
        const auto& values = store[key];

        int l = 0, r = values.size()-1;

        while (l<=r){
            int mid = (l+r) / 2;

            if (values[mid].first == timestamp){
                return values[mid].second;
                break;
            }
            if (values[mid].first < timestamp){
                res = values[mid].second;
                l = mid+1;
            }
            else {
                r = mid-1;
            }
        }
        return res;
    }
};
