class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>left(n);
        vector<int> right(n);
        vector<int> mid(n);
        int l = 0, r = 0, m = 0;


        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                left[l++]=nums[i];
            }
            else if(nums[i]>pivot){
                right[r++]=nums[i];
            }
            else {
                mid[m++]=nums[i];
            }
        }
            vector<int>ans(n);
            int k =0;
            for(int i =0;i<l;i++){
                ans[k++]=left[i];
            }
            for(int i =0;i<m;i++){
                ans[k++]=mid[i];
            }
            for(int i =0;i<r;i++){
                ans[k++]=right[i];
            }

        
    return ans;
        
    }
};