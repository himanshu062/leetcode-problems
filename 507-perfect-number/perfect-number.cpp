class Solution {
public:
    bool checkPerfectNumber(int num) {
        long long sum = 0;
        for (long long i = 1; i <= num / 2; i++) {
            if (num % i == 0)
                sum += i;
        }
        return sum == num;
    }
};