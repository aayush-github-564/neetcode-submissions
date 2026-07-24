class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){
            return false;
        }
        vector<int> sar(26,0);
        vector<int> tar(26,0);

        for (char c : s){
            sar[c-'a']++;
        }
        for (char c : t){
            tar[c-'a']++;
        }
        if (sar == tar){
            return true;
        }
        return false;
    }
};
