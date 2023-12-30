class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int>m;

      for(int i : nums) m[i]++;

      vector<pair<int,int>>temp;

      for(auto i:m){
         temp.push_back(make_pair(i.second, i.first));
      }

      sort(temp.rbegin(), temp.rend());

      vector<int>ans;

      for(int i = 0; i<k; i++) ans.push_back(temp[i].second);

      return ans;
    }
};