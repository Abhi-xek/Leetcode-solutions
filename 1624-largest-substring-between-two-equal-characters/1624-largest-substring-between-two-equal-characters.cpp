class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int temp = -1;
      for(int i = 0; i<s.length(); i++){
          for(int j = s.length()-1; j>i; j--){
              if(s[i] == s[j]){
                  int val = j-i-1;
                  temp = max(temp,val);
              }
          }
      }
      return temp;
    }
};