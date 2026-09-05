class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLen = 0;
        int l =0, r = 0;
        unordered_map<char, int>hash;
        while(r<n){
            if(hash.find(s[r]) != hash.end() && hash[s[r]] >= l){
                l = hash[s[r]] + 1;
            }
            hash[s[r]] = r;
            int len = r-l+1;
            maxLen = max(maxLen, len);
            r++;
        }
        return maxLen;
    }
};