class Solution {
public:
    int numSplits(string s) {
        vector<int> rightFreq(26, 0), leftFreq(26, 0);

        int rightDistinct = 0, leftDistinct = 0;

        // Count frequencies in the whole string
        for (char c : s) {
            if (rightFreq[c - 'a'] == 0)
                rightDistinct++;
            rightFreq[c - 'a']++;
        }

        int ans = 0;

        // Split after index i
        for (int i = 0; i < s.size() - 1; i++) {
            int idx = s[i] - 'a';

            // Add to left
            if (leftFreq[idx] == 0)
                leftDistinct++;
            leftFreq[idx]++;

            // Remove from right
            rightFreq[idx]--;
            if (rightFreq[idx] == 0)
                rightDistinct--;

            if (leftDistinct == rightDistinct)
                ans++;
        }

        return ans;
    }
};