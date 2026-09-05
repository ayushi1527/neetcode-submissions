class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l =0, r= 0;
        int cnt = 0;
        vector<int>seen(255,-1);
        while(r<n){
            if(seen[s[r]] != -1){
                if(seen[s[r]] >= l){
                    l = seen[s[r]] + 1;
                }
            }
            seen[s[r]] = r;
            cnt = max(cnt, r-l+1);
            r++;
        }
        return cnt;
    }
};
