class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for (int i : nums){
            if (!st.empty() && st.count(i)){
                return i;
            }
            st.insert(i);
        }
        return -1;
    }
};
