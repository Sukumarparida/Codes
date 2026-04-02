class Solution {
public:
int n;
int m;
int t[501][501][3];
    int slove(vector<vector<int>>& coins,int i ,int j ,int neu){
        if(i == m-1 && j ==n-1){
            if(coins[i][j] <0 && neu >0){
                return 0;
            }
            return coins[i][j];
        }
        if(i>=m || j>=n){
            return INT_MIN;
        }

        if(t[i][j][neu] != INT_MIN){
            return t[i][j][neu];
        }
        int take =coins[i][j] + max(slove(coins , i ,j+1 , neu) , slove(coins , i+1 , j ,neu));

        int skip =INT_MIN;
        if(coins[i][j] <0 && neu >0){
            int skipdown = slove(coins , i+1 ,j,neu-1);
            int skipright =slove(coins ,i,j+1,neu -1 );

            skip =max(skipdown , skipright);
        }
        return t[i][j][neu]=max(take,skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
         m=coins.size();
         n=coins[0].size();
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                for(int k=0;k<3;k++){
                    t[i][j][k] =INT_MIN;
                }
            }
        }
        return slove(coins,0,0,2);
    }
};