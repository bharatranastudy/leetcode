class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;
        stringstream ss(s);

        // Split the string into words
        while (ss >> word) {
            words.push_back(word);
        }

        // Number of words must match pattern length
        if (words.size() != pattern.size())
            return false;

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string w = words[i];

            // Check character -> word mapping
            if (charToWord.count(ch)) {
                if (charToWord[ch] != w)
                    return false;
            } else {
                charToWord[ch] = w;
            }

            // Check word -> character mapping
            if (wordToChar.count(w)) {
                if (wordToChar[w] != ch)
                    return false;
            } else {
                wordToChar[w] = ch;
            }
        }

        return true;
    }
};