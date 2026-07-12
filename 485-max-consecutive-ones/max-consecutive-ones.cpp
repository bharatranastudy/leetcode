class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr = 0;
        int best = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 1){
                curr++;
            }
            else{
                curr = 0;
            }
            best = max(curr,best);
        }
        return best;
    }
};