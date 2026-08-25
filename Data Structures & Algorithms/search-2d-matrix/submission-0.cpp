class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m-1;

        while (l<=r){
            int mid = (l+r)/2;

            if (target >= matrix[mid][0] && target <= matrix[mid][n-1]){
                int p=0, q=n-1;
                while (p<=q){
                    int s = (p+q)/2;

                    if (target == matrix[mid][s]){
                        return true;
                    }
                    else if (target > matrix[mid][s]){
                        p = s+1;
                    }
                    else {
                        q = s-1;
                    }
                }
                return false;
            }
            else if (target < matrix[mid][0]){
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return false;
    }
};
