class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedStr = "";
        for(auto word : strs){
            int n = word.length();
            string len = to_string(n);
            encodedStr = encodedStr+len+"/:"+word;
        }
        return encodedStr;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0;
        int n =s.size();
        while(i<n){
            int j = i;
            while(s[j] != '/'){
                j++;
            }
            int len = stoi(s.substr(i, j-i));
            j+=2;
            strs.push_back(s.substr(j, len));
            i = j+len;
        }
        return strs;
    }
};
