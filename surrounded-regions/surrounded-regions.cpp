/* Key is to do DFS from the outer ring 'O' rather than starting from each 'O' and checking if it reaches outer edge(Optimization)*/
class Solution {
public:
    void ReachableFromEdge(int row,int col,vector<vector<char>>& board){
        if(row<0||row>=board.size()||col<0||col>=board[0].size()){
            return;
        }
        if(board[row][col]=='X'||board[row][col]=='#'){
            return;
        }
        board[row][col]='#';
        ReachableFromEdge(row+1,col,board);
        ReachableFromEdge(row,col-1,board);
        ReachableFromEdge(row-1,col,board);
        ReachableFromEdge(row,col+1,board);

    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        //Spiral Matrix outer layer traversal
        int left=0,right=m-1,top=0,bottom=n-1;
        for(int i=left;i<=right;i++){            
            if(board[0][i]=='O'){
                ReachableFromEdge(0,i,board);
            }

        }
        top++;
        for(int i=top;i<=bottom;i++){
             if(board[i][m-1]=='O'){
                ReachableFromEdge(i,m-1,board);
            }
        }
        right--;
        for(int i=right;i>=left;i--){
            if(board[n-1][i]=='O'){
                ReachableFromEdge(n-1,i,board);
            }
        }
        bottom--;
        for(int i=bottom;i>=top;i--){
            if(board[i][0]=='O'){
                ReachableFromEdge(i,0,board);
            }
        }
        
        //Restore values after DFS change.
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};