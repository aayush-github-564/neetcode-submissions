class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freq;

        for (string st : strs){
            vector<int> arr(26,0);
            for (char c : st){
                arr[c - 'a']++;
            }
            string key = "";
            for (int i : arr){
                key += "#" + to_string(i);
            }
            freq[key].push_back(st);
        }
        vector<vector<string>> ans;
        for (auto m : freq){
            ans.push_back(m.second);
        }

        return ans;
    }
};
