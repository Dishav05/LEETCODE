class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

       
        vector<int> suf(m, -1);

        int p = n - 1;

        for (int j = m - 1; j >= 0; j--) {
            while (p >= 0 && word1[p] != word2[j]) {
                p--;
            }

            if (p < 0)
                break;

            suf[j] = p;
            p--;
        }

        vector<int> ans;

        int j = 0;
        bool usedMismatch = false;

        for (int i = 0; i < n && j < m; i++) {

            
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
                continue;
            }

           
            if (!usedMismatch) {

               
                if (j == m - 1 ||
                    (suf[j + 1] != -1 && suf[j + 1] > i)) {

                    ans.push_back(i);
                    j++;
                    usedMismatch = true;

                   
                    for (int k = i + 1; k < n && j < m; k++) {
                        if (word1[k] == word2[j]) {
                            ans.push_back(k);
                            j++;
                        }
                    }

                    break;
                }
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};