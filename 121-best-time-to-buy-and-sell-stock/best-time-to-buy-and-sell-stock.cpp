class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // int maxi=0;
        // for(int i=0;i<n-1;i++){
        //     int profit;
        //     for(int j=i+1;j<n;j++){
        //         profit=prices[j]-prices[i];
        //         maxi=max(maxi,profit);
        //     }
        // }
        // return maxi;
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            int cost=prices[i]-mini;
            profit=max(profit,cost);
            mini=min(mini,prices[i]);
        }
        return profit;
    }
};