class Solution {
public:
    long long distributeCandies(int n, int limit) {
        if (n > 3LL * limit) {
            return 0;
        }
        long long total = comb(n + 2, 2) - 3LL * comb(n - limit + 1, 2) +
                          3LL * comb(n - 2 * limit, 2) -
                          comb(n - 3 * limit - 1, 2);

        return max(total, 0LL);
    }

private:
    long long comb(long long n, long long k) {
        if (n < 0 || k < 0 || n < k) {
            return 0;
        }

        long long res = 1;
        for (long long i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;
        }

        return res;
    }
};