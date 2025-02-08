class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> p;
        for(int i=0;i<nums.size();i++){
            p[nums[i]]++;
        }
        map<int,int> :: iterator it = p.begin();
        int cnt=0;
        int maxi=0;
	    while(it!=p.end()){
            maxi=max(maxi,it->second);
            it++;
	    }
        it = p.begin();
        while(it!=p.end()){
            if(maxi==it->second){
                cnt++;
            }
            it++;
	    }
        return (cnt*maxi);
    }
};