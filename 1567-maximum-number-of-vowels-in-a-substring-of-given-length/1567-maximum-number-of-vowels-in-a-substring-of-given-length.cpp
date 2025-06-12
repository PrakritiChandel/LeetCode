class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int count = 0;
        int maxCount = 0;

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i]))
                count++;
        }
        maxCount = count;
        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i - k]))
                count--;
            if (isVowel(s[i]))
                count++;
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};