class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROW = matrix.size();
        if(ROW<1) return false;
        int COL = matrix[0].size();

        int startRow = 0;
        int endRow = ROW-1;
        int midRow = -1;

        while(startRow<=endRow){
            midRow = startRow + (endRow-startRow+1)/2;
            if(matrix[midRow][0]==target || matrix[midRow][COL-1]==target) return true;
            else if(matrix[midRow][0]>target) endRow=midRow-1;
            else if(matrix[midRow][COL-1]<target) startRow = midRow+1;
            else if(matrix[midRow][0]<target && matrix[midRow][COL-1]>target){
                break;
            }
        }

        cout<< midRow << endl;
        if(midRow == -1) return false;

        int start = 0;
        int end = COL-1;
        while(start<=end){
            int mid = start + (end-start+1)/2;
            if(matrix[midRow][mid]==target) return true;
            else if(matrix[midRow][mid]>target) end = mid-1;
            else start = mid+1;
        }

        return false;
    }
};
