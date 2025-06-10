class Solution {
public:
    int maxDifference(string s) {
        sort(s.begin(), s.end());
        int odd = 0, even = INT_MAX;
        char c = s[0];
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (c == s[i]) {
                cnt++;
            } else {
                
                if (cnt % 2 == 0) {
                    if (cnt<even) {
                        even = cnt;
                    }
                } else {
                    if (cnt > odd) {
                        odd = cnt;
                    }
                }

                c = s[i];
                cnt = 1;

            }
        }
        
                if (cnt % 2 == 0) {
                    if (cnt < even) {
                        even = cnt;
                    }
                } else {
                    if (cnt > odd) {
                        odd = cnt;
                    }
                }
        return (odd-even);
    }
};