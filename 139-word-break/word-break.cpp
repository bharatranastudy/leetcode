class Solution {
public:

    bool solve(string& s, vector<string>& wordDict,
               int start, vector<int>& dp) {

        if(start == s.size()) {
            return true;
        }

        if(dp[start] != -1) {
            return dp[start];
        }

        for(string word : wordDict) {

            if(start + word.size() <= s.size()) {

                if(s.substr(start, word.size()) == word) {

                    if(solve(s, wordDict,
                             start + word.size(), dp)) {

                        return dp[start] = true;
                    }
                }
            }
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        vector<int> dp(s.size(), -1);

        return solve(s, wordDict, 0, dp);
    }
};