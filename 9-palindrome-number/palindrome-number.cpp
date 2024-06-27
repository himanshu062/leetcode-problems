class Solution {
public:
    bool isPalindrome(int n) {
        long long actual =n;
        long long ans =0;
        while(n>0){
            long long rem = n%10;
            n=n/10;
            ans = (ans*10)+rem;
       } 
       if(ans == actual) return true;
       else return false;
    }
};