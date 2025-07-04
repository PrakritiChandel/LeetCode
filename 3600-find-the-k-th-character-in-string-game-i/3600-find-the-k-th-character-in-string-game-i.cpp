class Solution {
public:
    static char kthCharacter(int k) {
        int x=__builtin_popcount(k-1);
        return 'a'+x;
    }
};
