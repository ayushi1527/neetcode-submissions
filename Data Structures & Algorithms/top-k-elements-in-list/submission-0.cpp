class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

      unordered_map<int,int>freq;
      for(int x : nums){
        freq[x]++;
      }  

      for(pair<int,int> entry : freq){
        pq.push({entry.second, entry.first});

        while(pq.size()>k){
            pq.pop();
        }
      }

      vector<int> ans;
      while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
      }
      return ans;
    }
};
