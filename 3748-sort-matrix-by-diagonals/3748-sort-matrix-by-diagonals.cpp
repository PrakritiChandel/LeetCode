class Solution {
public:
    void sortDiagonal(int r, int c, vector<vector<int>> & grid, bool asc){
        vector<int> vec;
        int n=grid.size();
        int i=r;
        int j=c;

        while(i<n && j<n){
            vec.push_back(grid[i][j]);
            i++;
            j++;
        }

        if(asc){
            sort(begin(vec),end(vec));
        }
        else{
            sort(rbegin(vec),rend(vec));
        }

        i=r;
        j=c;

        for(int & val:vec){
            grid[i][j]=val;
            i++;
            j++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> vec;
        for(int r=0;r<n;r++){
            sortDiagonal(r,0,grid,false);
        }
        for(int c=1;c<n;c++){
            sortDiagonal(0,c,grid,true);
        }

        return grid;
    }
};