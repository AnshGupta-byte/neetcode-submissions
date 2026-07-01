class Solution {
   public:
    vector<vector<string>> ans;
    vector<string> substring;
    bool ispalindrome(string str) {
        int l = 0;
        int r = str.size()-1;
        while (l < r) {
            if (str[l] != str[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void backtrack(string& s, int idx) {
        if (idx == s.size()) {
            ans.push_back(substring);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            string candidate = s.substr(idx, i - idx + 1);

            if (ispalindrome(candidate)) {
                substring.push_back(candidate);

                backtrack(s, i + 1);

                substring.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        if (s.empty()) return {};

        backtrack(s, 0);
        return ans;
    }
};
