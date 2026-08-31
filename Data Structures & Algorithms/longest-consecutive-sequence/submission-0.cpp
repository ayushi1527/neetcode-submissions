class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     unordered_set<int>seen;
     int ans = 0;
     for(int x : nums){
        seen.insert(x);
     }
     for(int x : nums){
        if(seen.find(x) != seen.end() && seen.find(x-1) == seen.end()){
            int curr = x;
            int count = 0;
            while(seen.find(curr) != seen.end()){
                count++;
                curr++;
            }
            ans = max(ans, count);
        }
     }
     return ans;
    }
};
