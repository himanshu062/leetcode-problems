class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        int n = q.size();
        map<int, int> mp;
        map<int, int> mp1;
        int ans1 = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int ball = q[i][0];
            int color = q[i][1];
            if (mp.find(ball) != mp.end()) {
                int prevcolor = mp[ball];
                mp1[prevcolor]--;
                if (mp1[prevcolor] == 0)
                    ans1--;
            }
            mp[ball] = color;
            if (mp1[color] == 0)
                ans1++;
            mp1[color]++;
            ans.push_back(ans1);
        }
        return ans;
    }
};