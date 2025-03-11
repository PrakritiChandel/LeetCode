class Solution {
public:
    int numberOfSubstrings(string str) {
        int n = str.size();

        int s = 0;
        int e = 0;
        int a=0, b=0, c=0;
        int ans = 0;
        while(e<n){
            if(str[e] == 'a') a++;
            else if(str[e] == 'b') b++;
            else c++;

            if(a==0 || b==0 || c==0){
                e++;
            }
            else{
                while(s<e && (a>0 && b>0 && c>0)){
                    ans += n-e;
                    if(str[s] == 'a') a--;
                    else if(str[s] == 'b') b--;
                    else c--;
                    s++;
                }
                e++;
            }
        }
        return ans;
    }
};