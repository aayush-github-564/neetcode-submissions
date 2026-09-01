class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2;

        if (B.size() < A.size()) {
            swap(A, B);
        }

        int l = 0;
        int r = A.size();
        while (l <= r) {
            int i = (l + r) / 2;
            int j = half - i;

            int l1 = i > 0 ? A[i - 1] : INT_MIN;
            int l2 = j > 0 ? B[j - 1] : INT_MIN;
            int r1 = i < A.size() ? A[i] : INT_MAX;
            int r2 = j < B.size() ? B[j] : INT_MAX;

            if (l1 <= r2 && l2 <= r1){
                if (total % 2 != 0){ //odd
                    return max(l1, l2);
                }
                else { //even
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            }
            else if (l1 > r2) r = i - 1;
            else l = i + 1;
        }
        return -1;
    }
};
