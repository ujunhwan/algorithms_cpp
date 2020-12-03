#include <iostream>
using namespace std;
typedef struct KernelTaskContext_t
{
    uint32_t spsr;
    uint32_t r0_r12[13];
    uint32_t pc;
} KernelTaskContext_t;

typedef struct KernelTcb_t
{
    uint32_t sp;
    uint8_t* stack_base;
} KernelTcb_t;

int main() {
    KernelTcb_t sTask_list[1001];
    int* aa;
    int b = 100;
    aa = &b;
    uint32_t cc = 101;
    sTask_list[0].stack_base = (uint8_t*)aa;
    sTask_list[0].sp = 1010;
    KernelTcb_t* new_tcb = &sTask_list[0];
    cout << "1" << '\n';
    KernelTaskContext_t* ctx = (KernelTaskContext_t*)new_tcb->sp;
    cout << "2" << '\n';
    cout << new_tcb->sp << '\n';   // 1010
    printf("%p\n", new_tcb->sp);
    cout << "ctx " << ctx << '\n';
    //ctx->pc = cc;
    //ctx->spsr = b; 
    printf("asdf\n");
    printf("%d\n", ctx->pc);

    return 0;
}