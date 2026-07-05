class Solution {
public:
    bool check(int days,vector<int>& bloomDay,int m,int k){
        int n=bloomDay.size();
        int count=0;
        int b=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=days) count++;
            if(count==k){
                b++;
                count=0;
            } 
            else if(bloomDay[i]>days){
                count=0;
            }
        }
        return b>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int mindays=0;
        int maxdays=0;
        if((long)m*k > bloomDay.size()){
            return -1;
        }
        for(int it:bloomDay){
            mindays=min(mindays,it);
            maxdays=max(maxdays,it);
        }
        int ans=0;
        while(mindays<=maxdays){
            int mid=(mindays+maxdays)/2;
            if(check(mid,bloomDay,m,k)){
                ans=mid;
                maxdays=mid-1;
            }
            else{
                mindays=mid+1;
            }
        }
        return ans;
    }
};