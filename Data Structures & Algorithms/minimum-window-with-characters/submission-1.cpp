class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()){
            return "";
        }
        unordered_map<char,int> freqT, freqS;

        for (char c : t){
            freqT[c]++;
        }
        for (auto e : freqT){
            freqS[e.first] = 0;
        }
        int need = freqT.size();
        int have = 0;

        int minLen = INT_MAX;
        int start = 0;

        int l = 0;
        for (int r=0; r<s.size(); r++){
            if (freqS.count(s[r])){
                freqS[s[r]]++;
                if (freqS[s[r]] == freqT[s[r]]){
                    have++;
                }
                while (have == need){
                    if (r - l + 1 < minLen) {
                        minLen = r - l + 1;
                        start = l;
                    }
                    if (freqS.count(s[l])){
                        if (freqS[s[l]] == freqT[s[l]]) {
                            have--;
                        }
                        freqS[s[l]]--;
                    }
                    l++;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
