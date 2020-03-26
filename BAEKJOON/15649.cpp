// 15649번 N과 M (1) 
#include <cstdio>
int n,m;
bool check[10];
int ans[10];
void func(int idx){
    if(idx == m){
        for(int i=0;i<m;i++)
            printf("%d ",ans[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        if(check[i]) continue;
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