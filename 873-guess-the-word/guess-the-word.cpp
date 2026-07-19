/**
 * // This is Master's API interface.
 * class Master {
 * public:
 *     int guess(string word);
 * };
 */

class Solution {
public:
    int match(string &a, string &b) {
        int cnt = 0;
        for (int i = 0; i < 6; i++)
            if (a[i] == b[i]) cnt++;
        return cnt;
    }

    void findSecretWord(vector<string>& words, Master& master) {

        while (!words.empty()) {

            int best = 0;
            int bestScore = INT_MAX;

            for (int i = 0; i < words.size(); i++) {

                vector<int> bucket(7);

                for (int j = 0; j < words.size(); j++) {
                    if (i == j) continue;
                    bucket[match(words[i], words[j])]++;
                }

                int worst = *max_element(bucket.begin(), bucket.end());

                if (worst < bestScore) {
                    bestScore = worst;
                    best = i;
                }
            }

            string guessWord = words[best];
            int x = master.guess(guessWord);

            if (x == 6)
                return;

            vector<string> next;

            for (string &w : words)
                if (match(guessWord, w) == x)
                    next.push_back(w);

            words = next;
        }
    }
};