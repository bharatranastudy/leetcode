class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int>ans;

        vector<int>freqp(26,0);
        vector<int>freqs(26,0);
        if(s.size()<p.size()){
            return ans;
        }
        

        for(char ch : p){
            freqp[ch-'a']++;
        }
        int k = p.size();

        for(int i = 0;i<k;i++){
            freqs[s[i]-'a']++;
        }

        if(freqp == freqs){
            ans.push_back(0);

        }
        
        for(int right = k;right<s.size();right++){
            freqs[s[right]-'a']++;
            freqs[s[right-k]-'a']--;

            if(freqs == freqp){
            ans.push_back(right-k+1);
        }

        }
        

        return ans;
    }
};