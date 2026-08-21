class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum=0;
        int maxwealth=0;
  
        int n = accounts.size();
        
        for(int i =0;i<n;i++){

        sum=0;
        for(int j =0;j< accounts[i].size();j++){
            sum+=accounts[i][j];
        }
        maxwealth=max(maxwealth,sum);
        }
        return maxwealth;
    }

};