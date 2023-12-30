class Solution {
public:
    bool makeEqual(vector<string>& words) {
       if(words.size() == 1) return true;

      int m[26] = {0};

       for(auto i : words){
           for(auto j:i){
               m[j - 'a']++;
           }
       } 

       for(int i:m){
           if(i%words.size() != 0)
           return false;
       }

       return true;
    }
};