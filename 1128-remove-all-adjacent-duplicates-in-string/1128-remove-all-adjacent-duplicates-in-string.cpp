class Solution {
public:
    string removeDuplicates(string s) {
        // step 1:choosing any adjacent and two equal letters indx and indx+1
        // step 2: delete those and use this string to repeat step 1
        // step 3: return
        // edge case if no adjacent duplicates

        // find 
        int len=s.length();
        string ans;
        int indx=0;
        while(indx < s.length()){
            if(s[indx]==s[indx+1]){
                s.erase(indx,2);
                indx=0;
            }
          else indx++;
        }
        return s;
    }
};