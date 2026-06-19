class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int i=0;
        int high=0;
        int n = gain.size();
        for(int j=0;j<n;j++){
            i+=gain[j];
            high=max(high,i);
        }
        return high;
        
    }
};