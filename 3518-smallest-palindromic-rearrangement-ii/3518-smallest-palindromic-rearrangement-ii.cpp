class Solution {
public:
    using ll = long long;

    ll comb(int n, int r, ll limit) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        ll ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans >= limit) return limit;
        }
        return ans;
    }

    ll countWays(vector<int>& cnt, ll limit) {
        int total = 0;
        for (int x : cnt) total += x;

        ll ans = 1;
        int rem = total;

        for (int x : cnt) {
            if (x == 0) continue;
            ans *= comb(rem, x, limit);
            if (ans >= limit) return limit;
            rem -= x;
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26, 0);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] % 2)
                mid.push_back(char('a' + i));
        }

        int halfLen = s.size() / 2;
        string first = "";

        for (int pos = 0; pos < halfLen; pos++) {

            bool found = false;

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0) continue;

                half[c]--;

                ll ways = countWays(half, k);

                if (ways >= k) {
                    first.push_back(char('a' + c));
                    found = true;
                    break;
                }

                k -= ways;
                half[c]++;
            }

            if (!found) return "";
        }

        string second = first;
        reverse(second.begin(), second.end());

        return first + mid + second;
    }
};