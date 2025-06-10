class Solution {
public:
    int maxDifference(string s) {
        int od_max = INT_MIN, ev_min = INT_MAX;

        unordered_map<char,int> frq;
        for(auto& val:s){
            frq[val]++;
        }

        for(auto& val:frq){
            if(val.second&1){
                od_max = max(od_max, val.second);
            }
            else{
                ev_min = min(ev_min, val.second);
            }
        }

        return od_max-ev_min;
    }
};