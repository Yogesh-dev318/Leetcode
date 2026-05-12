class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int srow=0;
        int scol=0;
        int erow=matrix.size()-1;
        int ecol=matrix[0].size()-1;
        vector<int> out;
        while(srow<=erow && scol<=ecol){
            for(int j=scol;j<=ecol;j++){
                out.push_back(matrix[srow][j]);
            }
           

            for(int i=srow+1;i<=erow;i++){
                out.push_back(matrix[i][ecol]);
            }
 

            for(int j=ecol-1;j>=scol;j--){
                if(srow==erow){
                break;
                }
                out.push_back(matrix[erow][j]);
            }

            for(int i=erow-1;i>=srow+1;i--){
                if(scol==ecol){
                break;
                }
                out.push_back(matrix[i][scol]);
            }
            srow++; 
            scol++;
            erow--; 
            ecol--;
        }
        return out;
    }
};