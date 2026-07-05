class Solution {
public:
    bool caneatintime(vector<int>& piles,int h,int mid){
        long hr=0;
        for(int it:piles){
            hr+=(it+mid-1)/mid;
        }
        return hr<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int minspeed=1;
        int maxspeed=0;
        for(int it:piles){
            maxspeed=max(maxspeed,it);
        }
        while(minspeed<=maxspeed){
            int mid=(minspeed+maxspeed)/2;
            if(caneatintime(piles,h,mid)){
                maxspeed=mid-1;
            }
            else{
                minspeed=mid+1;
            }
        }
        return minspeed;
    }
};