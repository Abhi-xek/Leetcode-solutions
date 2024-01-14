class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!= word2.size()) return false;

        unordered_set<char>set1;
        unordered_set<char>set2;

        for(auto i : word1) set1.insert(i);

        for(auto i : word2) set2.insert(i);

        if(set1 == set2){
            vector<int>temp1(26);
            vector<int>temp2(26);
            
            for(auto i : word1) temp1[i-'a']++;
            for(auto i : word2) temp2[i-'a']++;

           sort(temp1.begin(), temp1.end());
           sort(temp2.begin(), temp2.end());
           return temp1 == temp2;

        }
        else return false;

    }
};