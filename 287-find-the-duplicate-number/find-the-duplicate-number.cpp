class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        unordered_map<int,int>st;
        for(int num : nums){
            st[num]++;
        }

        for(auto it :st){
            if(it.second >= 2){
                return it.first;
            }
        }
        return -1;
        
    }
};