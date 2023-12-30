class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int>m;
    typedef pair<int, int>p;

    for(auto i:nums) m[i]++;

    priority_queue<p, vector<p>, greater<p>>temp;

    for(auto i : m){
        temp.push({i.second, i.first});
        if(temp.size() > k) temp.pop();
    }

    vector<int>ans;

    while(!temp.empty()){
     ans.push_back(temp.top().second);
     temp.pop();
    }

    return ans;
    }
};