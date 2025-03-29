const int N = sqrt(100000);
vector<bool> isPrime(N + 1, 1);
vector<int> prime;
long long num_idx[100000];
class Solution {
public:
    const static int mod = 1e9 + 7;
    constexpr static void Sieve() {
        if (!prime.empty())
            return;
        isPrime[0] = isPrime[1] = 0;
        for (int i = 2; i * i <= N; i++) {
            if (isPrime[i]) {
                prime.push_back(i);
                for (int j = i * i; j <= N; j += i)
                    isPrime[j] = 0;
            }
        }
        for (int i = 2; i <= N; i++) {
            if (isPrime[i])
                prime.push_back(i);
        }
    }
    static int prime_score(int x) {
        if (x <= N && isPrime[x])
            return 1;
        int xsqrt = sqrt(x);
        int cnt = 0;
        for (int p : prime) {
            if (p > xsqrt)
                break;
            if (x % p != 0)
                continue;
            while (x % p == 0) {
                x /= p;
            }
            cnt++;
        }
        cnt += (x > 1);
        return cnt;
    }

    // Modular exponentiation
    inline static long long modPow(long long x, int exp) {
        long long ans = 1;
        while (exp > 0) {
            if (exp & 1)
                ans = ans * x % mod;
            x = x * x % mod;
            exp /= 2;
        }
        return ans;
    }

    static int maximumScore(vector<int>& nums, int k) {
        const int n = nums.size();
        Sieve();

        vector<int> score(n), left(n), right(n);
        for (int i = 0; i < n; i++)
            score[i] = prime_score(nums[i]);

        vector<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && score[i] > score[st.back()])
                st.pop_back();
            left[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }

        st.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && score[i] >= score[st.back()])
                st.pop_back();
            right[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }

        for (int i = 0; i < n; i++)
            num_idx[i] = ((long long)nums[i] << 20) + i;

        sort(num_idx, num_idx + n, greater<>());

        long long ans = 1;
        for (int i = 0; i < n && k > 0; i++) {
            const long long nI = num_idx[i];
            const int x = nI >> 20, idx = nI & ((1 << 20) - 1);
            const int exp =
                min((long long)(idx - left[idx]) * (right[idx] - idx),
                    (long long)k);
            ans = ans * modPow(x, exp) % mod;
            k -= exp;
        }

        return ans;
    }
};