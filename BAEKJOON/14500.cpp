// 14500번 테트로미노
#include <cstdio>
#include <vector>
#define max(x, y) x > y ? x : y
int n, m;
int a[501][501];
int main(){
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d", &a[i][j]);
        }
        getchar();
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i + 2 <= n && j + 1 <= m){
                int tmp = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+2][j+1];
                ans = max(tmp, ans);
            }
            if(i + 2 <= n && j <= m && j > 1){
                int tmp = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+2][j-1];
                ans = max(tmp, ans);
            }
            if(i + 1 <= n && j + 2 <= m){
                int tmp = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j];
                ans = max(tmp, ans);
            }
            if(i + 1 <= n && j + 2 <= m){
                int tmp = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+2];
                ans = max(tmp, ans);
            }
            if(i + 2 <= n && j + 1 <= m){
                int tmp = a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+2][j+1];
                ans = max(tmp, ans);
            }
            if(i + 2 <= n && j + 1 <= m){
                int tmp = a[i][j] + a[i][j+1] + a[i+1][j] + a[i+2][j];
                ans = max(tmp, ans);
            }
            if(i + 1 <= n && j <= m && j > 2){
                int tmp = a[i][j] + a[i+1][j] + a[i+1][j-1] + a[i+1][j-2]; 
                ans = max(tmp, ans);
            }
            if(i + 1 <= n && j + 2 <= m){
                int tmp = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+1][j+2];
                ans = max(tmp, ans);
            }
            if(i + 2 <= n && j + 1 <= m){
                int tmp = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+2][j+1];
                ans = max(tmp, ans);
            }
            if(i + 2 <= n && j > 1){
                int tmp = a[i][j] + a[i+1][j] + a[i+1][j-1] + a[i+2][j-1];
                ans = max(tmp, ans);
            }
            if(i + 1 <= n && j > 2){
                int tmp = a[i][j] + a[i][j-1] + a[i+1][j-1] + a[i+1][j-2];
                ans = max(tmp, ans);
            }
            if(i + 1 <= n && j + 2 <= m){
                int tmp = a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+1][j+2];
                ans = max(tmp, ans);
            }
            if(j + 2 <= m && i > 1){
                int tmp = a[i][j] + a[i][j+1] + a[i-1][j+1] + a[i][j+2];
                ans = max(tmp, ans);
            }
            if(i + 2 <= n && j + 1 <= m){
                int tmp = a[i][j] + a[i+1][j] + a[i+1][j+1] + a[i+2][j];
                ans = max(tmp, ans);
            }
            if(i > 1 && i + 1 <= n && j + 1 <= m){
                int tmp = a[i][j] + a[i][j+1] + a[i-1][j+1] + a[i+1][j+1];
                ans = max(tmp, ans);
            }
            if(i + 1 <= n && j + 2 <= m){
                int tmp = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+1];
                ans = max(tmp, ans);
            }
            if(i + 1 <= n && j + 1 <= m){
                int tmp = a[i][j] + a[i][j+1] + a[i+1][j+1] + a[i+1][j];
                ans = max(tmp, ans);
            }
            if(i + 3 <= n){
                int tmp = a[i][j] + a[i+1][j] + a[i+2][j] + a[i+3][j];
                ans = max(tmp, ans);
            }
            if(j + 3 <= m){
                int tmp = a[i][j] + a[i][j+1] + a[i][j+2] + a[i][j+3];
                ans = max(tmp, ans);
            }
        }
    }  
    printf("%d\n", ans);
    return 0;
}

