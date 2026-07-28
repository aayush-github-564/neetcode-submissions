class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;

        for (int i : nums){
            freq[i]++;
        }

        vector<pair<int,int>> farr;

        for (auto f : freq){
            farr.push_back({f.second,f.first});
        }
        sort(farr.rbegin(), farr.rend());

        vector<int> res;
        for (int i=0; i<k; i++){
            res.push_back(farr[i].second);
        }
        return res;
    }
};
