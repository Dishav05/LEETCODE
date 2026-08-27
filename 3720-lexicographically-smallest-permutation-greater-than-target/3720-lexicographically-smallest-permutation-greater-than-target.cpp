class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
       int n = s.size();

        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        int bestPos = -1;
        char bestChar = 0;

        
        for (int i = 0; i < n; i++) {

        
            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    bestPos = i;
                    bestChar = char('a' + c);
                    break;
                }
            }

            int x = target[i] - 'a';

            if (cnt[x] == 0)
                break;

            cnt[x]--;
        }

        
        if (bestPos == -1)
            return "";

        
        vector<int> remaining(26, 0);
        for (char c : s)
            remaining[c - 'a']++;

    
        for (int i = 0; i < bestPos; i++)
            remaining[target[i] - 'a']--;

    
        remaining[bestChar - 'a']--;

    
        string ans = target.substr(0, bestPos);
        ans += bestChar;

        
        for (int c = 0; c < 26; c++) {
            while (remaining[c] > 0) {
                ans += char('a' + c);
                remaining[c]--;
            }
        }

        return ans;
        
    }
};