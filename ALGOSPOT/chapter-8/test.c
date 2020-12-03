#include <stdint.h>
#include <stdio.h>


#define ARM_MODE_BIT_USR    0x10
#define ARM_MODE_BIT_FIQ    0x11
#define ARM_MODE_BIT_IRQ    0x12
#define ARM_MODE_BIT_SVC    0x13
#define ARM_MODE_BIT_ABT    0x17
#define ARM_MODE_BIT_UND    0x1B
#define ARM_MODE_BIT_SYS    0x1F
#define ARM_MODE_BIT_MON    0x16


#define INST_ADDR_START     0x0
#define USRSYS_STACK_START  0x00100000
#define SVC_STACK_START     0x00300000
#define IRQ_STACK_START     0x00400000
#define FIQ_STACK_START     0x00500000
#define ABT_STACK_START     0x00600000
#define UND_STACK_START     0x00700000
#define TASK_STACK_START    0x00800000
#define GLOBAL_STACK_START  0x04800000
#define DALLOC_STACK_START  0x04900000

#define INST_MEM_SIZE       (USRSYS_STACK_START - INST_ADDR_START)
#define USRSYS_STACK_SIZE   (SVC_STACK_START - USRSYS_STACK_START)
#define SVC_STACK_SIZE      (IRQ_STACK_START - SVC_STACK_START)
#define IRQ_STACK_SIZE      (FIQ_STACK_START - IRQ_STACK_START)
#define FIQ_STACK_SIZE      (ABT_STACK_START - FIQ_STACK_START)
#define ABT_STACK_SIZE      (UND_STACK_START - ABT_STACK_START)
#define UND_STACK_SIZE      (TASK_STACK_START - UND_STACK_START)
#define TASK_STACK_SIZE     (GLOBAL_STACK_START - TASK_STACK_START)
#define DALLOC_MEM_SIZE     (55 * 1024 * 1024)

#define USRSYS_STACK_TOP    (USRSYS_STACK_START + USRSYS_STACK_SIZE - 4)
#define SVC_STACK_TOP       (SVC_STACK_START + SVC_STACK_SIZE - 4)
#define IRQ_STACK_TOP       (IRQ_STACK_START + IRQ_STACK_SIZE - 4)
#define FIQ_STACK_TOP       (FIQ_STACK_START + FIQ_STACK_SIZE - 4)
#define ABT_STACK_TOP       (ABT_STACK_START + ABT_STACK_SIZE - 4)
#define UND_STACK_TOP       (UND_STACK_START + UND_STACK_SIZE - 4)


#define NOT_ENOUGH_TASK_NUM 0xFFFFFFFF
#define USR_TASK_STACK_SIZE 0x100000
#define MAX_TASK_NUM        (TASK_STACK_SIZE / USR_TASK_STACK_SIZE)



typedef void (*KernelTaskFunc_t)(void);
void Kernel_task_init(void);
void usertask01(void);
uint32_t Kernel_task_create(KernelTaskFunc_t startFunc);

typedef union UARTDR_t
{
    uint32_t all;
    struct {
        uint32_t DATA:8;    // 7:0
        uint32_t FE:1;      // 8
        uint32_t PE:1;      // 9
        uint32_t BE:1;      // 10
        uint32_t OE:1;      // 11
        uint32_t reserved:20;
    } bits;
} UARTDR_t;

typedef union UARTRSR_t
{
    uint32_t all;
    struct {
        uint32_t FE:1;      // 0
        uint32_t PE:1;      // 1
        uint32_t BE:1;      // 2
        uint32_t OE:1;      // 3
        uint32_t reserved:28;
    } bits;
} UARTRSR_t;

typedef union UARTFR_t
{
    uint32_t all;
    struct {
        uint32_t CTS:1;     // 0
        uint32_t DSR:1;    // 1
        uint32_t DCD:1;     // 2
        uint32_t BUSY:1;    // 3
        uint32_t RXFE:1;    // 4
        uint32_t TXFF:1;    // 5
        uint32_t RXFF:1;    // 6
        uint32_t TXFE:1;    // 7
        uint32_t RI:1;      // 8
        uint32_t reserved:23;
    } bits;
} UARTFR_t;

typedef union UARTILPR_t
{
    uint32_t all;
    struct {
        uint32_t ILPDVSR:8; // 7:0
        uint32_t reserved:24;
    } bits;
} UARTILPR_t;

typedef union UARTIBRD_t
{
    uint32_t all;
    struct {
        uint32_t BAUDDIVINT:16; // 15:0
        uint32_t reserved:16;
    } bits;
} UARTIBRD_t;

typedef union UARTFBRD_t
{
    uint32_t all;
    struct {
        uint32_t BAUDDIVFRAC:6; // 5:0
        uint32_t reserved:26;
    } bits;
} UARTFBRD_t;

typedef union UARTLCR_H_t
{
    uint32_t all;
    struct {
        uint32_t BRK:1;     // 0
        uint32_t PEN:1;     // 1
        uint32_t EPS:1;     // 2
        uint32_t STP2:1;    // 3
        uint32_t FEN:1;     // 4
        uint32_t WLEN:2;    // 6:5
        uint32_t SPS:1;     // 7
        uint32_t reserved:24;
    } bits;
} UARTLCR_H_t;

typedef union UARTCR_t
{
    uint32_t all;
    struct {
        uint32_t UARTEN:1;      // 0
        uint32_t SIREN:1;       // 1
        uint32_t SIRLP:1;       // 2
        uint32_t Reserved1:4;   // 6:3
        uint32_t LBE:1;         // 7
        uint32_t TXE:1;         // 8
        uint32_t RXE:1;         // 9
        uint32_t DTR:1;         // 10
        uint32_t RTS:1;         // 11
        uint32_t Out1:1;        // 12
        uint32_t Out2:1;        // 13
        uint32_t RTSEn:1;       // 14
        uint32_t CTSEn:1;       // 15
        uint32_t reserved2:16;
    } bits;
} UARTCR_t;

typedef union UARTIFLS_t
{
    uint32_t all;
    struct {
        uint32_t TXIFLSEL:3;    // 2:0
        uint32_t RXIFLSEL:3;    // 5:3
        uint32_t reserved:26;
    } bits;
} UARTIFLS_t;

typedef union UARTIMSC_t
{
    uint32_t all;
    struct {
        uint32_t RIMIM:1;   // 0
        uint32_t CTSMIM:1;  // 1
        uint32_t DCDMIM:1;  // 2
        uint32_t DSRMIM:1;  // 3
        uint32_t RXIM:1;    // 4
        uint32_t TXIM:1;    // 5
        uint32_t RTIM:1;    // 6
        uint32_t FEIM:1;    // 7
        uint32_t PEIM:1;    // 8
        uint32_t BEIM:1;    // 9
        uint32_t OEIM:1;    // 10
        uint32_t reserved:21;
    } bits;
} UARTIMSC_t;

typedef union UARTRIS_t
{
    uint32_t all;
    struct {
        uint32_t RIRMIS:1;  // 0
        uint32_t CTSRMIS:1; // 1
        uint32_t DCDRMIS:1; // 2
        uint32_t DSRRMIS:1; // 3
        uint32_t RXRIS:1;   // 4
        uint32_t TXRIS:1;   // 5
        uint32_t RTRIS:1;   // 6
        uint32_t FERIS:1;   // 7
        uint32_t PERIS:1;   // 8
        uint32_t BERIS:1;   // 9
        uint32_t OERIS:1;   // 10
        uint32_t reserved:21;
    } bits;
} UARTRIS_t;

typedef union UARTMIS_t
{
    uint32_t all;
    struct {
        uint32_t RIMMIS:1;  // 0
        uint32_t CTSMMIS:1; // 1
        uint32_t DCDMMIS:1; // 2
        uint32_t DSRMMIS:1; // 3
        uint32_t RXMIS:1;   // 4
        uint32_t TXMIS:1;   // 5
        uint32_t RTMIS:1;   // 6
        uint32_t FEMIS:1;   // 7
        uint32_t PEMIS:1;   // 8
        uint32_t BEMIS:1;   // 9
        uint32_t OEMIS:1;   // 10
        uint32_t reserved:21;
    } bits;
} UARTMIS_t;

typedef union UARTICR_t
{
    uint32_t all;
    struct {
        uint32_t RIMIC:1;   // 0
        uint32_t CTSMIC:1;  // 1
        uint32_t DCDMIC:1;  // 2
        uint32_t DSRMIC:1;  // 3
        uint32_t RXIC:1;    // 4
        uint32_t TXIC:1;    // 5
        uint32_t RTIC:1;    // 6
        uint32_t FEIC:1;    // 7
        uint32_t PEIC:1;    // 8
        uint32_t BEIC:1;    // 9
        uint32_t OEIC:1;    // 10
        uint32_t reserved:21;
    } bits;
} UARTICR_t;

typedef union UARTDMACR_t
{
    uint32_t all;
    struct {
        uint32_t RXDMAE:1;  // 0
        uint32_t TXDMAE:1;  // 1
        uint32_t DMAONERR:1;// 2
        uint32_t reserved:29;
    } bits;
} UARTDMACR_t;

typedef struct PL011_t
{
    UARTDR_t    uartdr;         //0x000
    UARTRSR_t   uartrsr;        //0x004
    uint32_t    reserved0[4];   //0x008-0x014
    UARTFR_t    uartfr;         //0x018
    uint32_t    reserved1;      //0x01C
    UARTILPR_t  uartilpr;       //0x020
    UARTIBRD_t  uartibrd;       //0x024
    UARTFBRD_t  uartfbrd;       //0x028
    UARTLCR_H_t uartlcr_h;      //0x02C
    UARTCR_t    uartcr;         //0x030
    UARTIFLS_t  uartifls;       //0x034
    UARTIMSC_t  uartimsc;       //0x038
    UARTRIS_t   uartris;        //0x03C
    UARTMIS_t   uartmis;        //0x040
    UARTICR_t   uarticr;        //0x044
    UARTDMACR_t uartdmacr;      //0x048
} PL011_t;

#define UART_BASE_ADDRESS0       0x10009010
#define UART_INTERRUPT0          44

typedef void (*FP)(void);

int ret = 0;


void hello() {
    printf("hello\n");
}

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

static KernelTcb_t  sTask_list[MAX_TASK_NUM];
static KernelTcb_t* sCurrent_tcb;
static KernelTcb_t* sNext_tcb;

static uint32_t     sAllocated_tcb_index;
static uint32_t     sCurrent_tcb_index;

static KernelTcb_t  sTask_list[MAX_TASK_NUM];
static uint32_t     sAllocated_tcb_index;
void Kernel_task_init(void)
{
    sAllocated_tcb_index = 0;
    sCurrent_tcb_index = 0;

    for(uint32_t i = 0; i < MAX_TASK_NUM; i++)
    {
        sTask_list[i].stack_base = (uint8_t*)(TASK_STACK_START + (i * USR_TASK_STACK_SIZE));
        sTask_list[i].sp = (uint32_t)sTask_list[i].stack_base + USR_TASK_STACK_SIZE - 4;

        sTask_list[i].sp -= sizeof(KernelTaskContext_t);
        KernelTaskContext_t* ctx = (KernelTaskContext_t*)sTask_list[i].sp;
        ctx->pc = 0;
        ctx->spsr = ARM_MODE_BIT_SYS;
    }
}

uint32_t Kernel_task_create(KernelTaskFunc_t startFunc)
{
    KernelTcb_t* new_tcb = &sTask_list[sAllocated_tcb_index++];

    if(sAllocated_tcb_index > MAX_TASK_NUM)
    {
        return NOT_ENOUGH_TASK_NUM;
    }

    KernelTaskContext_t* ctx = (KernelTaskContext_t*)new_tcb->sp;
    printf("%u\n", ctx);
    printf("%x\n", new_tcb->sp);
    ctx->pc = (uint32_t)startFunc;

    return (sAllocated_tcb_index - 1);
}

void usertask01()
{
    printf("usertask01\n");
}

int main() {
    Kernel_task_init();
    FP fp = usertask01;
    Kernel_task_create(usertask01);
    
   /*
    PL011_t* Uart = (PL011_t*)UART_BASE_ADDRESS0;
    printf("%x\n", Uart);
    printf("%x\n", &Uart->uartdr);
    printf("%x\n", &Uart->uartrsr);
    printf("%x\n", &Uart->uartfr);
    printf("%x\n", &Uart->uartilpr);
    printf("***\n");
    printf("%p\n", &Uart->uartfr.all);
    printf("%d\n", Uart->uartfr.bits.CTS);
    */
   /*
    int *a;
    int num = 10;
    a = &num;
    printf("%p\n", a);

    int *b = a;
    hello(b);

    int c = *a;
    hello(&c);

    printf("%d\n", *a);
    */
}