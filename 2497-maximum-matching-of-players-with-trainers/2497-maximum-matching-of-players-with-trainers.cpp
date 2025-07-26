class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int cnt=0;
        sort(trainers.begin(),trainers.end());
        sort(players.begin(),players.end());
        for(int i=0;i<players.size();i++){
            for(int j=0;j<trainers.size();j++){
                if(players[i]<=trainers[j] && trainers.size()>0){
                    cnt++;
                    auto x=find(trainers.begin(),trainers.end(),trainers[j]);
                    trainers.erase(x);
                    break;
                }
            }
        }
        return cnt;
    }
};