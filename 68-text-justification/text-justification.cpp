class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLength = 0;

            // Find how many words fit in the current line
            while (j < n &&
                   lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }

            int gaps = j - i - 1;
            string line;

            // Last line or only one word -> left justify
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k != j - 1)
                        line += ' ';
                }

                line += string(maxWidth - line.size(), ' ');
            }
            else {
                int totalSpaces = maxWidth - lineLength;
                int evenSpaces = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k != j - 1) {
                        line += string(evenSpaces + (extraSpaces > 0), ' ');
                        if (extraSpaces > 0)
                            extraSpaces--;
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};