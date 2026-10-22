class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int l = 0,r = rows*cols-1;

        while(l <= r){
        int mid = l + (r-l)/2;

        int row = mid/cols;
        int col = mid%cols;
        int value = matrix[row][col];

        if(value == target)
        return true;
        else if(value > target)
        r = mid-1;
        else
        l = mid+1;
        

        }
        return false;
    }
};
