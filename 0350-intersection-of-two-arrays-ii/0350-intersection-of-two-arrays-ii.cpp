class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> ans;
        
        for(int num : nums1){
            map[num]++;
        }
        
        for(int num : nums2){
            if(map[num] > 0){
                ans.push_back(num);
                map[num]--;
            }
        }
        
        return ans;
    }
};