class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        long long mod = 1000000007;
        vector<int> subarraySums;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                subarraySums.push_back(sum);
            }
        }
        
    sort(subarraySums.begin(), subarraySums.end());
        
    long long ans = 0;
    for (int i = left - 1; i < right; i++) {
        ans = (ans + subarraySums[i]) % mod;
    }
    
    return ans;
    }
};