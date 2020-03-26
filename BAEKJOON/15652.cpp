// 15652번 N과 M (4) 
#include <cstdio>
int n, m;
int ans[10];
void func(int idx, int selected){
    if(selected == m){
        for(int i=1;i<=n;i++){
            for(int j=0;j<ans[i];j++)
                printf("%d ", i);
        }
        printf("\n");
        return;
    }
    if(idx > n) return;
    for(int j=m-selected;j>=1;j--){
        ans[idx] = j;
        func(idx + 1, selected + j);
    }
    ans[idx] = 0;
    func(idx + 1, selected);
}
int main(){
    scanf("%d %d", &n, &m);
    func(1, 0);
}