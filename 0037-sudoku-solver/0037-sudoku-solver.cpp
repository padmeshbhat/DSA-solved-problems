class Solution {
public:
bool is_safe(vector<vector<char>>& board,int row,int col,char dig){
    for(int i=0;i<9;i++){
        if(board[i][col]==dig){
            return false;
        }
    }
    for(int j=0;j<9;j++){
        if(board[row][j]==dig){
            return false;
        }
    }
    int sr=(row/3)*3;
    int sc=(col/3)*3;
    for(int i=sr;i<=sr+2;i++){
        for(int j=sc;j<=sc+2;j++){
            if(board[i][j]==dig){
                return false;
            }
        }
    }
    return true;

}
bool solve(vector<vector<char>>& board){
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            if(board[row][col]=='.'){
                for(char dig='1';dig<='9';dig++){
                    if(is_safe(board,row,col,dig)){
                        board[row][col]=dig;
                        if(solve(board)){
                            return true;
                        }
                        board[row][col]='.';
                    }
                }
                return false;

            }
        }
    }
    return true;
}





void solveSudoku(vector<vector<char>>& board) {
    solve(board);
        
    }
};