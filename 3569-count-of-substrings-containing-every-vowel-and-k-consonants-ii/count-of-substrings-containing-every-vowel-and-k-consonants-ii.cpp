class Solution {
public:
    long long solve(string& word, int k) {
        unordered_set<char> vowels_set{'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> freq_vowels;

        int n = word.length(), l = 0, r = 0;
        ;
        long long consonants = 0, res = 0;

        while (r < n) {
            if (vowels_set.find(word[r]) != vowels_set.end())
                freq_vowels[word[r]]++;

            else
                ++consonants;

            while (freq_vowels.size() == 5 && consonants >= k) {

                if (vowels_set.find(word[l]) != vowels_set.end()) {
                    freq_vowels[word[l]]--;

                    if (freq_vowels[word[l]] == 0)
                        freq_vowels.erase(word[l]);
                }

                else
                    --consonants;

                ++l;
            }

            res += l;
            ++r;
        }

        return res;
    }
    long long countOfSubstrings(string word, int k) {
        return solve(word, k) - solve(word, k + 1);
    }
};