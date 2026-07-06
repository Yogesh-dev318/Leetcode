
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     int n1=nums1.size(),n2=nums2.size();
    //     int n=(n1+n2);
    //     int ind2 = n/2 ;
    //     int ind1 = ind2-1;
    //     int el1=-1,el2=-1;
    //     int i=0,j=0,cnt=0;
    //     while(i<n1 && j<n2){
    //         if(nums1[i]<nums2[j]){
    //             if(cnt==ind1) el1=nums1[i];
    //             if(cnt==ind2) el2=nums1[i];

    //             cnt++;
    //             i++;
    //         }
    //         else{
    //             if(cnt==ind1) el1=nums2[j];
    //             if(cnt==ind2) el2=nums2[j];

    //             cnt++;
    //             j++;
    //         }
    //     }
    //     while(i<n1){
    //          if(cnt==ind1) el1=nums1[i];
    //          if(cnt==ind2) el2=nums1[i];

    //             cnt++;
    //             i++;
    //     }
    //     while(j<n2){
    //         if(cnt==ind1) el1=nums2[j];
    //             if(cnt==ind2) el2=nums2[j];

    //             cnt++;
    //             j++;
    //     }
    //     if(n%2==1) return el2;
    //     return ((double)(el1+el2)/2.0);
    // } 
        int n = nums1.size(),m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2,nums1);
        int low = 0,high = n,half = (n + m + 1)/2;
        int t = n + m;
        while(low <= high){
            int mid1 = (low + high)/2;
            int mid2 = half - mid1;
            int l1 = INT_MIN,l2 = INT_MIN,r1 = INT_MAX,r2 = INT_MAX;
            if(mid1 > 0) l1 = nums1[mid1 - 1];
            if(mid1 < n) r1 = nums1[mid1];
            if(mid2 > 0) l2 = nums2[mid2 - 1];
            if(mid2 < m) r2 = nums2[mid2];
            if(l1 <= r2 && l2 <= r1){
                double median = max(l1,l2);
                if(!(t&1)) median = (median + min(r1,r2))/2.0;
                return median;
            }
            else if(l1 > r2){
                high = mid1 - 1;
            }
            else{
                low = mid1 + 1;
            }
        }
        return 0;
    }
};