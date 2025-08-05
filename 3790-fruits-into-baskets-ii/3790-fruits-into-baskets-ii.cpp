class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int left=0;
        for(int i=0;i<fruits.size();i++){
            bool get=false;
            for(int j=0;j<baskets.size();j++){
                if(fruits[i]<=baskets[j]){
                    baskets.erase(baskets.begin()+j);
                    get=true;
                    break;
                }
            }
            if(!get){
                left++;
            }
        }
        return left;
    }
};