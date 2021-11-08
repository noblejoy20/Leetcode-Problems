public class Solution {
    public string Tictactoe(int[][] moves) {
        int[,] mat = new int[3,3];
        int[] row = new int[3];
        int[] col = new int[3];
        int leftdiag = 0;
        int rightdiag = 0;
        int count=0;
        foreach(var move in moves){
            if(count%2==1){
                mat[move[0],move[1]]+=-1;
                row[move[0]]+=-1;
                col[move[1]]+=-1;
                if(Math.Abs(row[move[0]])==3) return "B";
                if(Math.Abs(col[move[1]])==3) return "B";
                if(move[0]==move[1]){
                    leftdiag+=-1;
                    if(Math.Abs(leftdiag)==3){
                        return "B";
                    }

                }
                if(move[0]+move[1]==2){
                   rightdiag+=-1;
                   if(Math.Abs(rightdiag)==3){
                       return "B";
                    }                       
                }
            }else{
                mat[move[0],move[1]]+=1 ;
                row[move[0]]+=1;
                col[move[1]]+=1;
                if(Math.Abs(row[move[0]])==3) return "A";
                if(Math.Abs(col[move[1]])==3) return "A";
                if(move[0]==move[1]){
                    leftdiag+=1;
                    if(Math.Abs(leftdiag)==3){
                        return "A";
                    }

                }
               if(move[0]+move[1]==2){
                   rightdiag+=1;
                   if(Math.Abs(rightdiag)==3){
                       return "A";
                   }                       
               }
            }
            count++;
            
        }
        if(count!=9) return "Pending";
        return "Draw";
    }
}