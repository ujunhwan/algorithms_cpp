// 15651번 N과 M (3) 
#include <cstdio>
int n, m;
int ans[10];
void func(int idx){
    if(idx == m){
        for(int i=0;i<m;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++){
        ans[idx] = i;
        func(idx + 1);
    }
}
int main(){
    scanf("%d %d", &n, &m);
    func(0);
}
