class SubrectangleQueries 
{
public:
    vector<vector<int>> result,sub;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        result=rectangle;
    }
    
    // use a vector to store the previously updated values
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        sub.push_back({row1,col1,row2,col2,newValue});
    }
    
    // search through the vector backwards to get the latest updated value.
    int getValue(int row, int col) {
        for(int i=sub.size()-1;i>=0;i--){
            if(sub[i][0]<=row&&sub[i][1]<=col&&row<=sub[i][2]&&col<=sub[i][3]){
                return sub[i][4];
            }
        }
        return result[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */