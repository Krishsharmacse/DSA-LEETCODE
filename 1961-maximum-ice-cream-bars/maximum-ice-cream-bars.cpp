class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int max=0;
        int n = costs.size();
        vector<int>ice;
        sort(costs.begin(),costs.end());
        for(int i =0;i<n;i++){
            if(costs[i]<=coins){
                max++;
                coins-=costs[i];
            }

        }
        return max;
        
        
    }
};