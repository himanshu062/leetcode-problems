class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> count(26, 0);
        for (char c : word) {
            count[c - 'a']++;
        }
        vector<int> freqs;
        for (int c : count) {
            if (c > 0) {
                freqs.push_back(c);
            }
        }
        sort(freqs.begin(), freqs.end());
        int n = freqs.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + freqs[i];
        }

        int total = prefix[n];
        int minDeletions = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int target = freqs[i];
            int maxAllowed = target + k;
            int j = upper_bound(freqs.begin(), freqs.end(), maxAllowed) -
                    freqs.begin();
            int deleteBelow = prefix[i];
            int deleteAbove = total - prefix[j] - (maxAllowed * (n - j));
            int deletions = deleteBelow + deleteAbove;

            minDeletions = min(minDeletions, deletions);
        }

        return minDeletions;
    }
};