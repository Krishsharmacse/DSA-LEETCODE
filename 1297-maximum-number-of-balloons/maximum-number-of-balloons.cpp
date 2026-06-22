class Solution {
public:
    int maxNumberOfBalloons(string text) {
       map<char,int>mp;

int max=0;
       for(int i=0;i<text.length();i++){
        if(text[i]=='b'){
          mp['b']++;
           
        }
         if(text[i]=='a'){
            mp['a']++;
        }
         if(text[i]=='l'){
            mp['l']++;
        }
       
         if(text[i]=='o'){
            mp['o']++;
        }
         if(text[i]=='n'){
            mp['n']++;
        }



       }
       return min({mp['b'], mp['a'], mp['l']/2, mp['o']/2, mp['n']});
    }
};