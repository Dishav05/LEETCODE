class traget {
    vector<long long> temp;
    int n;

public:
    traget(int n) {
        this->n = n;
        temp.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            temp[idx] += val;
            idx += idx & -idx;
        }
    }

    long long query(int idx) {
        long long sum = 0;
        while (idx > 0) {
            sum += temp[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
         int n = nums.size();

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        vector<int> vals = prefix;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        traget temp(vals.size());

        long long ans = 0;

        for (int p : prefix) {
            int rank = lower_bound(vals.begin(), vals.end(), p) - vals.begin() + 1;
            ans += temp.query(rank - 1);
            temp.update(rank, 1);
        }
        return ans;  
    }
};