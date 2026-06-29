class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map<char, int> mp;
        for (char ch : t) {
            mp[ch]++;
        }

        int left = 0;
        int minLength = INT_MAX;
        int matched = 0;
        int start = 0;
        for (int right = 0; right < s.size(); right++) {
            if (mp.count(s[right])) {
                mp[s[right]]--;

                if (mp[s[right]] >= 0) matched++;
            }

            while (matched == t.size()) {
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                if (mp.count(s[left])) {
                    mp[s[left]]++;

                    if (mp[s[left]] > 0) matched--;
                }
                left++;
            }
        }
        if (minLength == INT_MAX) return "";
        return s.substr(start, minLength);
    }
};
