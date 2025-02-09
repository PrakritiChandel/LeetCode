class Solution {
public:
    static long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long cnt=n*(n-1LL)/2;
        for(int i=0; i<n; i++)
            nums[i]-=i;
        sort(nums.begin(), nums.end());
        for(int l=0, r=0; r<n; r++){
            int x=nums[l];
            while(r<n && x==nums[r])
                r++;
            long long f=r-l;
            cnt-=f*(f-1)/2;
            l=r;
        }
        return cnt;
    }
};
auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();