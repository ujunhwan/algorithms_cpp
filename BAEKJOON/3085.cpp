// 3085번 사탕 게임
#include <cstdio>
#define max(a,b) a > b ? a : b
#define swap(a,b) {char tmp = a; a = b; b = tmp;}
int n;
char ch[51][51];
int rowCheck(int row){
    if(row >= n+1) return 0;
    int ret = 0;
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(ch[row][i] == ch[row][i+1]){
            cnt += 1;
            ret = max(cnt, ret);
        }
        else{
            ret = max(cnt, ret);
            cnt = 1;
        }
    }
    return ret;
}
int colCheck(int column){
    if(column >= n+1) return 0;
    int ret = 0;
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(ch[i][column] == ch[i+1][column]){
            cnt += 1;
            ret = max(cnt, ret);
        }
        else{
            ret = max(cnt, ret);
            cnt = 1;
        }
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf(" %c",&ch[i][j]);
        }
        getchar();
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ch[i][j] != ch[i+1][j]){
                swap(ch[i][j], ch[i+1][j]);
                ans = max(colCheck(j), ans);
                ans = max(rowCheck(i), ans);
                ans = max(rowCheck(i+1), ans);
                swap(ch[i][j], ch[i+1][j]);
            }
            if(ch[i][j] != ch[i][j+1]){
                swap(ch[i][j], ch[i][j+1]);
                ans = max(rowCheck(i), ans);
                ans = max(colCheck(j), ans);
                ans = max(colCheck(j+1), ans);
                swap(ch[i][j], ch[i][j+1]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans = max(rowCheck(i), ans);
        ans = max(colCheck(i), ans);
    }
    printf("%d\n", ans);
    return 0;
}