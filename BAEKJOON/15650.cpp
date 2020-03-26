// 15650번 N과 M (2) 
#include <cstdio>
int n,m;
bool check[10];
int ans[10];
void func(int idx){
    if(idx == m){
        for(int j=0;j<m;j++){
            printf("%d ", ans[j]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(check[i]) continue;
        if(idx == 0) ans[idx] = i;
        else if(ans[idx - 1] >= i) continue;
        ans[idx] = i;
        check[i] = true;
        func(idx + 1);
        check[i] = false;
    }
}
int main(){
    scanf("%d %d", &n, &m);
    func(0);
    return 0;
}