// 10814번 나이순 정렬
#include <cstdio>
typedef struct _person {
    int age;
    int order;
    char name[101];
} Person;
Person mem[100001];
Person ans[100001];
void merge (int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (mem[i].age < mem[j].age) {
            ans[k++] = mem[i++];
        } else if (mem[i].age > mem[j].age) {
            ans[k++] = mem[j++];
        } else {
            if (mem[i].order < mem[j].order) {
                ans[k++] = mem[i++];
            }
        }
    }
    if (i > mid) {
        for (int l = j; l <= right; l++) ans[k++] = mem[l];
    } else {
        for (int l = i; l <= mid; l++) ans[k++] = mem[l];
    }
    for (int l = left; l <= right; l++) mem[l] = ans[l];
}
void sort (int left, int right) {
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
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %s", &mem[i].age, mem[i].name);
        mem[i].order = i;
        getchar();
    }
    sort(0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d %s\n", mem[i].age, mem[i].name);
    }
}