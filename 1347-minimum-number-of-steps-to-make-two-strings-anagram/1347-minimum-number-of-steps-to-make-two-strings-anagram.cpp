class Solution {
public:
    int minSteps(string s, string t) {
        int m[26] = {0};
        int n = s.size();

        for(int i = 0; i<n; i++){
            m[s[i] - 'a']++;
            m[t[i] - 'a']--;
        }

        int ans = 0;

        for(int i = 0; i<26; i++){
            if(m[i] > 0) ans += m[i];
        }

        return ans;
    }
};