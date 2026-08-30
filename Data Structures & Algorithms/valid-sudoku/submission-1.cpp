class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,vector<pair<pair<int,int>,int>>> pos;
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i<n; i++){
            for(int j =0; j<m ; j++){
                if(board[i][j] == '.'){
                    continue;
                }
                char num = board[i][j];
                int boxIndex = (i/3)*3 + (j/3);
                for(auto p : pos[num]){

                    int prevRow = p.first.first;
                    int prevCol = p.first.second;
                    int prevBox = p.second;

                    if(i == prevRow ||
                       j == prevCol ||
                       boxIndex == prevBox){
                        return false;
                    }
                }

                pos[num].push_back({{i,j}, boxIndex});
            }
        }
        return true;
    }
};
