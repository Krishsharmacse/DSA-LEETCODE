class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    int left=0;
    int right=nums.size()-1;
    long long val=0;
    vector<int> ans(nums.size());
    int pos=nums.size()-1;
        while(left<=right){
            if(abs(nums[left])>abs(nums[right])){
                val=nums[left];
                left++;
            }
            else{
                val=nums[right];
                right--;
            }
          val*=val;
            ans[pos]=val;
            pos--;
        }
        return ans;
    }
};