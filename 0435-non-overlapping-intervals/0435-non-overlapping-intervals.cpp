class Solution {
    
     bool static comparator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), comparator);

        int ans = 0;
        int lastEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < lastEnd) {// overlapping
                ans++;
                
            } else { // No overlap, update the end time
                lastEnd = intervals[i][1];
            }
        }

        return ans;
    }
};