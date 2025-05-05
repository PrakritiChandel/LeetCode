int numTilings(int n) {
    const int MOD = 1000000007;
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 5;

    int x = 1, y = 2, z = 5;
    int t;

    for (int i = 4; i <= n; ++i) {
        t = ((long long)2 * z + x) % MOD;

        // XOR rotate x, y, z -> y, z, t
        x ^= y ^= x ^= y; 
        y ^= z ^= y ^= z; 
        z ^= t ^= z ^= t; 
    }

    return z;
}