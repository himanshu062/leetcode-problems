class Solution {
    private static final int[][] DIRS = { { 1, 1 }, { 1, -1 }, { -1, -1 }, { -1, 1 } };

    public int lenOfVDiagonal(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int[][][] memo = new int[m][n][8];
        int maxLen = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        maxLen = Math.max(maxLen, dfs(i, j, k, 1, 2, grid, memo) + 1);
                    }
                }
            }
        }

        return maxLen;
    }

    private int dfs(int i, int j, int dir, int canTurn, int target, int[][] grid, int[][][] memo) {
        i += DIRS[dir][0];
        j += DIRS[dir][1];

        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] != target)
            return 0;

        int state = (dir << 1) | canTurn;

        if (memo[i][j][state] != 0)
            return memo[i][j][state];

        int res = dfs(i, j, dir, canTurn, 2 - target, grid, memo);

        if (canTurn == 1) {
            int nextDir = (dir + 1) % 4;
            res = Math.max(res, dfs(i, j, nextDir, 0, 2 - target, grid, memo));
        }

        return memo[i][j][state] = res + 1;
    }
}