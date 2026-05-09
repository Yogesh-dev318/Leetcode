class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> positive;
        vector<int> negative;
        vector<int> temp;

        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                positive.push_back(nums[i]);
            }
            else {
                negative.push_back(nums[i]);
            }
        }

        int i = 0;
        int j = 0;

        int n1 = positive.size();
        int n2 = negative.size();

        while(i < n1 && j < n2) {
            temp.push_back(positive[i]);
            i++;

            temp.push_back(negative[j]);
            j++;
        }

        while(i < n1) {
            temp.push_back(positive[i]);
            i++;
        }

        while(j < n2) {
            temp.push_back(negative[j]);
            j++;
        }

        return temp;
    }
};