class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int count =0;
        int i =0;
        int j =0;
        int sum =0;
        int size = INT_MAX;
     
        int n =nums.size();
        for( j =0;j<n;j++){
             sum += nums[j];
            while(sum>=target){
                  size=min(size,j-i+1);
                sum-=nums[i];
                i++;

            }
        }
        return size == INT_MAX ? 0 : size;
    }
};