class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<>> minHeap;

        ranges::sort(intervals);

        for (const vector<int>& interval : intervals) {
            if (!minHeap.empty() && interval[0] > minHeap.top())
                minHeap.pop();
            minHeap.push(interval[1]);
        }

        return minHeap.size();
    }
};