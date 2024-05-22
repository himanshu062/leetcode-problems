class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        solve(0,s,path,res);
        return res;
    }
    void solve(int ind, string str, vector<string> &path, vector<vector<string>> &res){
        if(ind == str.size()){
            res.push_back(path);
            return;
        }
        for(int i = ind;i<str.size();++i){
            if(isPalindrome(str, ind, i)){
                path.push_back(str.substr(ind,i-ind+1));
                solve(i+1,str,path,res);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string str, int start,int end){
        while(start<=end){
            if(str[start++] != str[end--]) return false;
        }
        return true;
    }
};