class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum =0;
        int maxsum=0;
        for(int i =0;i<k;i++){
            sum+=nums[i];
        }
        maxsum=sum;
        for(int i =k;i<nums.size();i++){
            sum+=nums[i];
            sum-=nums[i-k];
            maxsum=max(sum,maxsum);
        }
        
        double avg=(double)maxsum/k;
        return avg;
        
    }
};