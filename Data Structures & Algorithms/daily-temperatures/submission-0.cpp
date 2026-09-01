class Solution {
public:
    vector<int> nextGreaterIndex(vector<int> &temperatures){
        int n = temperatures.size();
        stack<pair<int,int>>st;
        vector<int> ans(n,-1);
        int i = n-1;
        st.push({-1,-1});
        while(i>=0){
            while(!st.empty() && st.top().first <= temperatures[i]){
                st.pop();
            }
            if(!st.empty() && st.top().first > temperatures[i]){
                ans[i] = st.top().second;
            }
            st.push({temperatures[i], i});
            i--;
        }
        return ans;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      int n = temperatures.size();
      vector<int> nextWarm = nextGreaterIndex(temperatures);
      vector<int> ans(n);
      for(int i = 0; i<n ; i++){
        if(nextWarm[i] == -1){
            ans[i] = 0;
        }
        else{
            ans[i] = nextWarm[i] - i;
        }
      }
      return ans;
    }
};
