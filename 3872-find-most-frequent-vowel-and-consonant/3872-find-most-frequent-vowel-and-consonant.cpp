class Solution {
private:
    bool isVowel(char c){
        return string("aeiou").find(c)!=string::npos ;
    }
public:
    int maxFreqSum(string s) {
        unordered_map<char,int> v;
        unordered_map<char,int> c;
        for(char x:s){
            if(isVowel(x))  v[x]++;
            else c[x]++;
        }

        int maxV=0,maxC=0;
        for(auto &a:v){
            if(maxV<a.second){
                maxV=a.second;
            }
        }
        for(auto &a:c){
            if(maxC<a.second){
                maxC=a.second;
            }
        }

        return maxV+maxC;
    }
};