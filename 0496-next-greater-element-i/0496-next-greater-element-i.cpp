class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
         unordered_map<int, int> mp;
        stack<int> st;

        for (int temp : nums2) {
            while (!st.empty() && st.top() < temp) {
                mp[st.top()] = temp;
                st.pop();
            }
            st.push(temp);
        }

        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        vector<int> ans;
        for (int temp : nums1) {
            ans.push_back(mp[temp]);
        }

        return ans;
        
    }
};