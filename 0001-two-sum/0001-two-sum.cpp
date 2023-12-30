class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //can also be done using two pointer approach

       vector<pair<int, int>> numsWithIndex;
       int s = 0;
       int e = nums.size()-1; 

       for(int i = 0; i<=e; i++) {
           numsWithIndex.push_back({nums[i],i});
       }

       sort(numsWithIndex.begin(), numsWithIndex.end());

       while(1){
           int sum = numsWithIndex[s].first + numsWithIndex[e].first;
           if(sum == target){
              return {numsWithIndex[s].second, numsWithIndex[e].second};
              break;   
           }
           else if(sum > target) {
               e--;
           }
           else {
               s++;
           }
       }
        // vector<int> ans;

        // for(int i = 0; i<nums.size(); i++) {
        //     for (int j = i+1; j<nums.size(); j++) {
        //         if(nums[i] + nums[j] == target) {
        //            ans.push_back(i);
        //            ans.push_back(j);
        //         }
        //     }
        // }
        //return ans;

        return {};
        
    }
};