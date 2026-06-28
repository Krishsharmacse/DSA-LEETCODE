class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
            sort(arr.begin(), arr.end());
        int maxi=INT_MIN;
        vector<int>ele;
        int l=0;
        int j=n-1;
        arr[0]=1;
        
        for(int i =1;i<n;i++){
        arr[i]=min(arr[i],arr[i - 1]+1);
            
        }
        return arr.back();
        
    }
};