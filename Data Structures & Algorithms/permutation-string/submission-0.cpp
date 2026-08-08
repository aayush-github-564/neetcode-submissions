class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());
        int len = s1.size();

        int l = 0;
        for (int r = len-1; r<s2.size(); r++){
            string sub = s2.substr(l, len);
            sort(sub.begin(), sub.end());
            if (s1 == sub){
                return true;
            }
            l++;
        }

        return false;
    }
};
