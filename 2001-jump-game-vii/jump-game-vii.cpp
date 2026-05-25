class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        queue<int> q;
        q.push(0);
        vector<int> vis(n,0);

        int sbseDur = 0;

        while(!q.empty()){
            int element = q.front();
            q.pop();

            if(element == n-1) return true;

            int start = max(element + minJump,sbseDur);
            int end = min(element + maxJump,n-1);


            for (int i = start;i<=end;i++){
                if(vis[i] == 0 && s[i] == '0'){
                    vis[i] = 1;
                    q.push(i);
                }
            }
            sbseDur = max(sbseDur,end);
        }
        return false;
    }
};