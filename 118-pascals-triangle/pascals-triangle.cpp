class Solution {
public:
    vector<int> generateRow(int row){
        long long ans=1;
        vector<int> answ;
        answ.push_back(1);
        for(int i=1;i<row;i++){
            ans=ans*(row-i);
            ans=ans/i;
            answ.push_back(ans);
        }
        return answ;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> aans;
        for(int i=1;i<=numRows;i++){
            vector<int> row=generateRow(i);
            aans.push_back(row);
        }
        return aans;
    }
};