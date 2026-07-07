class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int i=0;
        // int j=matrix[0].size()-1;
        // while(i<matrix.size() && j>=0){
        //     if(matrix[i][j]==target){
        //         return true;
        //     }
        //     else if(matrix[i][j]>target) j--;
        //     else if(matrix[i][j]<target) i++;
        // }
        // return false;
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=(n*m)-1;
        while(low<=high){
            int mid=(low+high)/2;
            int i=mid/m;
            int j=mid%m;
            if(matrix[i][j]==target){
                return true;
            }
            else if(matrix[i][j]<target) low=mid+1;
            else if(matrix[i][j]>target) high=mid-1;
        }
        return false;
    }
};