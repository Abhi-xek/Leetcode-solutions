class Solution {
public:
    int majorityElement(vector<int>& nums) {
       unordered_map<int, int>m;

       for(int i : nums) m[i]++;

       for(auto i : m){
           if(i.second > nums.size()/2){
            return i.first;
            break;
            }
            continue;
       } 
       return -1;
    }
};