#include <stdio.h> 
#include <stdlib.h> 

#define getpch(type) (type*)malloc(SIZE) 


int CPUTIME[3] = {2, 4, 8};
int cpu_count = 0;
int cpu_time = 0;
int SIZE;

struct pcb {
    char name[10]; 
    char state; 
    int itime; // 进入时间
    int ntime; 
    int rtime; 
    int times; // 记录已经使用了几个时间片
    struct pcb* next; 
};

typedef struct pcb PCB; 
PCB *wait, *ready1, *ready2, *ready3, *p, *tail1, *tail2, *tail3; 

// 添加到等待队列
void add()
{
    p->next = wait->next;
    wait->next = p;
}

void queue()
{ 
    if (ready1 == NULL) { // 如果第一就绪队列为空，把p插入队首
        p->next = NULL;
        ready1  = p;
        tail1   = p;
    } else { // 否则根据p已经运行的时间片，决定把它插入到哪一个队列
        switch (p->times) {
            case 0: // 第一次运行，插入到第二队列中去
                p->next = ready2;
                ready2 = p;
                tail1->next = ready2;
                break;
            case 1: case 2: // 第二次或之后运行，插入到第三队列中去
                p->next = ready3;
                ready3 = p;
                tail2->next = ready3;
                break;
            default:
                break;
        }
    }
} 

// 检查等待队列中有没有进程已经就绪
void check_ready()
{
    PCB *p, *q;
    p = wait;
    
    while (p->next != NULL) {
        if (p->next->itime == cpu_time) { // 
            // 用q来暂时存储这个结点，避免对p进行直接操作
            q = p->next;

            // 从等待队列删去这个结点
            p->next = q->next;

            // 把这个结点插入到第一就绪队列队尾
            q->next = tail1->next;
            tail1->next = q;
            tail1 = q;

            // 如果是队尾元素了，结束循环
            if (p->next == NULL) {
                break;
            }
        }
        p = p->next;
    }
}

void input()
{ 
    int i,num; 
    printf("\n 请输入进程个数?"); 
    scanf("%d", &num); 
    for(i = 0; i < num; i++) { 
        printf("\n 进程号No.%d:\n",i); 
        p = getpch(PCB); 

        printf("\n 进程名:"); 
        scanf("%s",p->name); 
        printf("\n 进程进入时间:"); 
        scanf("%d",&p->itime); 
        printf("\n 进程运行时间:"); 
        scanf("%d",&p->ntime); 
        printf("\n"); 

        p->rtime=0;
        p->times = 0; 
        p->state='w'; 
        p->next = NULL; 
        add();
        p = NULL;
    } 
} 

void disp(PCB * pr)
{ 
    printf("\n qname \t state \t itime \t ndtime \t runtime \n"); 
    printf("|%s\t",pr->name); 
    printf("|%c\t",pr->state); 
    printf("|%d\t",pr->itime); 
    printf("|%d\t",pr->ntime); 
    printf("|%d\t",pr->rtime); 
    printf("\n"); 
} 
 
 
void check()
{ 
    PCB *pr, *pw; 
    printf("\n **** 当前正在运行的进程是:");
    if (p != NULL) {
        printf("%s", p->name);
        disp(p); 
    } else {
        printf("NULL\n");
    }

    pr = ready1->next; 
    printf("\n **** 当前就绪队列状态为:\n");
    while(pr != NULL) { 
        disp(pr); 
        pr=pr->next; 
    }

    pw = wait->next;
    printf("\n **** 当前等待队列状态为:\n");
    while(pw != NULL) { 
        disp(pw); 
        pw = pw->next; 
    }
} 

void destroy()
{ 
    printf("\n 进程 [%s] 已完成.\n",p->name); 
    free(p); 
} 

void running()
{ 
    (p->rtime)++; 
    cpu_count++;
    if (p->rtime == p->ntime) { // 任务完成
        cpu_count = 0;
        destroy();
    } else if (cpu_count == CPUTIME[p->times]) { // 用完时间片了
        cpu_count = 0;
        if (ready1 == NULL) { // 如果已经是最后一个了
            ready1 = p;
        } else {
            tail1->next = p;
            tail1 = p;
        }
    } else { // 任务没完成，时间片也还没用完
        p->next = ready1;
        ready1 = p;
    }
} 
void main()
{ 
    char ch; 
    SIZE = sizeof (struct pcb);
    // 初始化头结点
    wait = getpch(PCB);
    ready1 = getpch(PCB);
    ready2 = getpch(PCB);
    ready3 = getpch(PCB);
    tail1 = ready1;
    tail2 = ready2;
    tail3 = ready3;
    input(); 

    
    while(wait != NULL) { // 只要还有进程在等待就继续
        ch = getchar(); 
        cpu_time++; 

        printf("\n The executed cpu_time:%d \n",cpu_time); 
        check(); 
        check_ready();
        if (ready1->next == NULL) { // 如果当前没有就绪的进程就跳过
            continue;
        }

        p = ready1->next; 
        ready1->next = p->next; 
        p->next = NULL; 
        p->state = 'R'; 
        running(); 
        printf("\n 按任意键继续......"); 
        ch = getchar(); 
    } 
    printf("\n\n 进程已经完成.\n"); 
    ch=getchar(); 
} 
