// 2751번 수 정렬하기 2
#include <cstdio>
#define swap(x, y) { int t; t = x; x = y; y = t; }
static const int MAX = 1000000;
int n, a[MAX], d[MAX];
static inline void merge (int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) d[k++] = a[i++];
        else d[k++] = a[j++];
    }
    if (i > mid) {
        for (int l = j; l <= right; l++) d[k++] = a[l];
    } else {
         for (int l = i; l <= mid; l++) d[k++] = a[l];
    }
    for (int l = left; l <= right; l++) a[l] = d[l];
}
static inline void sort (int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        sort(left, mid);
        sort(mid+1, right);
        merge(left, mid, right);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(0, n-1);
    for (int i = 0; i < n; i++) printf("%d\n", a[i]);
    return 0;
}