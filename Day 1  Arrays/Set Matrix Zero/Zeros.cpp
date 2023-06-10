#include <bits/stdc++.h>
using namespace std;
//Time Complexity : O O((N*M)*(N + M)) + O(N*M) ~= O(N^3)
/*
Where N is No. of Rows and M is No. of Col
*/
void markRow(vector<vector<int>> &matrix, int n, int m, int i){
    for(int j=0;j<m;j++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}
void markCol(vector<vector<int>> &matrix, int n, int m, int j){
    for(int i=0;i<n;i++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0){
                markRow(matrix,n,m,i);
                markCol(matrix,n,m,j);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}
int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> ans =  zeroMatrix(matrix,n,m);

    for(auto it : ans){
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}