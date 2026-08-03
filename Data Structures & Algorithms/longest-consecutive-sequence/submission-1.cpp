class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums));
        int best = 0;

        for (int i : nums){
            if (st.count(i-1)){
                continue;
            }
            int count = 1;
            int current = i;

            while (st.count(current+1)){
                count++;
                current++;
            }
            best = max(best,count);
        }
        return best;
    }
};
