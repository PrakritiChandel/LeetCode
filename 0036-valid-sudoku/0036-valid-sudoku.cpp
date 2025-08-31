class Solution {
public:
    bool validSub(vector<vector<char>>& board, int sr, int er, int sc, int ec) {
        unordered_set<char> st;
        for(int row = sr; row<=er; row++) {
            for(int col = sc; col <= ec; col++) {
                char ch = board[row][col];
                if(ch == '.') continue;
                if(st.count(ch)) return false;
                st.insert(ch);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        //row
        for(int i=0;i<9;i++){
            unordered_set<int> st;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                if(st.count(board[i][j])) return false;
                st.insert(board[i][j]);
            }
        }

        // col
        for(int i=0;i<9;i++){
            unordered_set<int> st;
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') continue;
                if(st.count(board[j][i])) return false;
                st.insert(board[j][i]);
            }
        }

        //validate ech 3*3 box
        for(int sr = 0; sr < 9; sr+=3) {
            int er = sr+2;
            for(int sc = 0; sc < 9; sc+=3) {
                int ec = sc+2;
                if(!validSub(board, sr, er, sc, ec))
                    return false;
            }
        }
        
        return true;
    }
};