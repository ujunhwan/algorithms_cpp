#include <stdio.h>
typedef struct tcb {
    int a, b, c, d, e, f;
} tcb;

int main() {
    int num = 100;
    int *p = &num;
    printf("%d %d\n", num, *p);
    tcb* ptcb = (tcb*)p;
    ptcb->a = 111;
    ptcb->b = 222;
    ptcb->c = 3123;
    ptcb->d = 444;
    ptcb->e = 555;
    ptcb->f = 666;

    //////////////////////////////////////////////////////////

    printf("%p %p\n", p, ptcb); // 주소 동일

    printf("%d %d\n", *ptcb, *p);   // 111 333
    printf("%d %d\n", *p, *ptcb);   // 111 333

    printf("%d\n", *ptcb); // 73896
    printf("%d\n", *p);     // 111

}