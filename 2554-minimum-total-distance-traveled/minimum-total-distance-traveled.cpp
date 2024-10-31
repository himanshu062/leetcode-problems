class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        ranges::sort(robot);
        ranges::sort(factory);
        vector<vector<vector<long>>> mem(
            robot.size(),
            vector<vector<long>>(factory.size(), vector<long>(robot.size())));
        return minimumTotalDistance(robot, factory, 0, 0, 0, mem);
    }

private:
    long minimumTotalDistance(const vector<int>& robot,
                              const vector<vector<int>>& factory, int i, int j,
                              int k, vector<vector<vector<long>>>& mem) {
        if (i == robot.size())
            return 0;
        if (j == factory.size())
            return LONG_MAX;
        if (mem[i][j][k] > 0)
            return mem[i][j][k];
        const long skipFactory =
            minimumTotalDistance(robot, factory, i, j + 1, 0, mem);
        const int position = factory[j][0];
        const int limit = factory[j][1];
        const long useFactory =
            limit > k
                ? minimumTotalDistance(robot, factory, i + 1, j, k + 1, mem) +
                      abs(robot[i] - position)
                : LONG_MAX / 2;
        return mem[i][j][k] = min(skipFactory, useFactory);
    }
};