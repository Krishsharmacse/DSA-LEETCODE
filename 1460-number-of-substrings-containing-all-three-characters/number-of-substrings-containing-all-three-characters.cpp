class Solution {
public:
    int numberOfSubstrings(string s) {
        int last[]={-1,-1,-1};
        int count=0;
        for(int i =0;i<s.length();i++){
            last[s[i]-'a']=i;
            if(last[0]!=-1 && last[1]!=-1 && last[2]!=-1){
                int minIdx=min(last[0],min(last[1],last[2]));
                count+=(minIdx+1);
            }
        }
        return count;
    }
};