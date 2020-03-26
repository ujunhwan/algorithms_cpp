// 10972번 다음 순열
#include <cstdio>
#include <vector>
using namespace std;
int n; 
vector <int> a(10000);
void swap(int *x, int *y){
    int * tmp;
    tmp = x;
    x = y;
    y = tmp;
}
bool func(){
    int i = n - 1;
    while(i > 0 && a[i] <= a[i-1]) i -= 1;
    if(i <= 0) return false;
    int j = n - 1;
    while(a[i-1] >= a[j]) j -= 1;
    swap(a[j], a[i-1]);
    j = n - 1;
    while(i < j){
        swap(a[i], a[j]);
        i += 1; j -= 1;
    }
    return true;
}
int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    if(!func()){
        printf("-1");
        return 0;
    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}