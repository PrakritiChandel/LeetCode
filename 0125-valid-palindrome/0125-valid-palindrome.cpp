class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> nums;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                nums.push_back(tolower(s[i]));
            }
        }
        string s1,s2;
        for(int i=0;i<nums.size();i++){
            s1+=nums[i];
        }
        s2=s1;
        reverse(s1.begin(),s1.end());
        if(s1==s2)  return true;
        else return false;
    }
};