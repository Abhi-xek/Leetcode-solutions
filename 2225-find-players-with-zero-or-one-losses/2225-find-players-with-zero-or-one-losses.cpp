class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int>loser;

        for(int i = 0; i<matches.size(); i++){
            loser[matches[i][1]]++;
        }

        vector<int>never_lost;
        vector<int>lost_once;

        for(int i = 0; i<matches.size(); i++){
            if(loser.find(matches[i][0]) == loser.end()){
                never_lost.push_back(matches[i][0]);
                loser[matches[i][0]] = 2;
            }
            if(loser[matches[i][1]] == 1){
                lost_once.push_back(matches[i][1]);
            }
        }

        sort(never_lost.begin(), never_lost.end());
        sort(lost_once.begin(), lost_once.end());

        return {never_lost, lost_once};
    }
};