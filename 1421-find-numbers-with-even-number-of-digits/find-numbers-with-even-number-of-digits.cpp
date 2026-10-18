class Solution {
public:
    int findNumbers(vector<int>& nums) {
    int even=0;
    for(int i =0;i<nums.size();i++){
        string digit=to_string(nums[i]);
        if(digit.length()%2==0){
            even++;
        }
    }    
    return even;
    }
};