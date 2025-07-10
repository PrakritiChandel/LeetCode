class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        startTime.insert(startTime.begin(),0);
        endTime.insert(endTime.begin(),0);
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);
        int maxi=0,res=0;
        for(int i=1;i<startTime.size()-1;i++){
            if(maxi>=endTime[i]-startTime[i]){
                res=max(res,startTime[i+1]-endTime[i-1]);
            }
            else{
                res=max(res,startTime[i]-endTime[i-1]+startTime[i+1]-endTime[i]);
            }

            maxi=max(maxi,startTime[i]-endTime[i-1]);
        }

        maxi=0;
        for(int i=startTime.size()-2;i>=1;i--){
            if(maxi>=endTime[i]-startTime[i]){
                res=max(res,startTime[i+1]-endTime[i-1]);
            }
            else{
                res=max(res,startTime[i]-endTime[i-1]+startTime[i+1]-endTime[i]);
            }

            maxi=max(maxi,startTime[i+1]-endTime[i]);
        }

        return res;
    }
};