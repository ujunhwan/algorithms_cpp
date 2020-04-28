// 11650번 좌표 정렬하기
#include <cstdio>
#define swap(a, b) { int t; t = a; a = b; b = t; }
int n, x[100001], y[100001];
int xd[100001], yd[100001];
static inline void merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (x[i] < x[j]) {
            xd[k] = x[i];
            yd[k++] = y[i++];
        } else if (x[i] > x[j]) {
            xd[k] = x[j];
            yd[k++] = y[j++];
        } else {
            if (y[i] < y[j]) {
                xd[k] = x[i];
                yd[k++] = y[i++];
            } else {
                xd[k] = x[j];
                yd[k++] = y[j++];
            }
        }
    }
    if (i > mid) {
        for (int l = j; l <= right; l++) {
            xd[k] = x[l];
            yd[k++] = y[l];
        }
    } else {
        for (int l = i; l <= mid; l++) {
            xd[k] = x[l];
            yd[k++] = y[l];
        }
    }
    for (int l = left; l <= right; l++) {
        x[l] = xd[l]; 
        y[l] = yd[l];
    }
}
static inline void sort(int left, int right) {
    int mid;
    if (left >= right) return;
    else {
        mid = (left + right) / 2;
        sort(left, mid);
        sort(mid + 1, right);
        merge(left, mid, right);
    }
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    sort(0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", x[i], y[i]);
    }
    return 0;
}