class Solution {
public:
    bool isVow(char c){
        if(c == 'A'|| c == 'E' || c == 'I' || c == 'O'|| c == 'U'
        || c == 'a' || c == 'e'|| c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }

    string reverseVowels(string s) {
        string s1 = "";
        for(int i = 0; i < s.length(); i++){
            if(isVow(s[i]))
                s1 += s[i];
        }
        reverse(s1.begin(), s1.end());

        for(int i = 0, j = 0; i < s.length() && j < s1.length(); i++){
            if(isVow(s[i]))
                s[i] = s1[j++];
        }
        return s;
    }
};