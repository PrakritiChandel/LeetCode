class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> nums;
        int m=floor(n/2);
        
        for(int i=-m ; i<=m; i++){
            if(i==0 && n%2==0){
            }
            else{nums.push_back(i);}
        }
        return nums;
    }
};