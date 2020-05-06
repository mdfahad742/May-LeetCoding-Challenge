class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // O(n), O(1) space algorithm --- MOORE'S VOTING ALGORITHM (Standard Question)
        int n=nums.size();
        int major=0;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(nums[major]==nums[i])cnt++;
            else cnt--;
            if(cnt==0){major=i;cnt=1;}
        }
        return nums[major]; // Since major element always exist no need to check whether its major
    }
};
