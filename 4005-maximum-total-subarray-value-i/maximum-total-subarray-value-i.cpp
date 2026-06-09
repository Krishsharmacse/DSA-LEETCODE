class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int mx=INT_MIN;
        int mn=INT_MAX;
        for(int i =0;i<n;i++){
            mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
        }
      
        return 1LL * (mx - mn) * k;
    }
};