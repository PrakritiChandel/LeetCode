// 1-based indexed segmented tree defined recursively
static constexpr int N=128;
int seg[N];// as global variable
struct segTree{
    unsigned n;
    segTree(vector<int>& A) : n(A.size()){
        build(A, 1, 0, n-1);// seg must be cleared 
    }
    ~segTree(){// destructor
        fill(seg, seg+(2u*bit_ceil(n)), 0); // clear seg for the next use
    }
    void build(vector<int>& A, int idx, int l, int r) {
        if (l==r) 
            seg[idx]=A[l];
        else{
            const int m=(l+r)/2;
            build(A, 2*idx, l, m);
            build(A, 2*idx+1, m+1, r);
            seg[idx]=gcd(seg[2*idx], seg[2*idx+1]);
        }
    }

    // query GCD 
    int query(int idx, int l, int r, int ql, int qr) const {
        if (qr<l || r<ql) return 0;
        if (ql<=l && r<=qr) return seg[idx];
        int m=(l+r)/2;
        return gcd(query(idx*2,l,m,ql,qr), query(idx*2+1,m+1,r,ql,qr));
    }
    int GCDamong(int l, int r) const 
    { return query(1,0,n-1,l,r);}
};
class Solution {
public:
    static int minOperations(vector<int>& nums) {
        const int n=nums.size(), cnt1=count(nums.begin(), nums.end(), 1);
        if (cnt1>0) return n-cnt1;
        segTree X(nums);
        int d=INT_MAX;
        for(int l=0, r=0; l<n; l++){
            int g;
            while(r<n && (g=X.GCDamong(l, r))>1) r++;
            if (r<n && g==1) d=min(d, r-l+1);
        }
        return d==INT_MAX?-1:d+n-2;
    }
};