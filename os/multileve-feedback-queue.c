#include <stdio.h> 
#include <stdlib.h> 

#define getpch(type) (type*)malloc(SIZE) 


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
PCB *wait, *ready1, *ready2, *ready3, *p;

// 添加到等待队列
void add()
{
    PCB *pw = wait;
    if (pw->next == NULL) {
        pw->next = p;
    } else {
        while (pw->next != NULL) {
            if (pw->next->itime >= p->itime) {
                p->next = pw->next;
                pw->next = p;
                break;
            }
            pw = pw->next;
        }
        // 遍历到队尾了
        if (pw->next == NULL) {
            pw->next = p;
        }
    }
}


// 检查等待队列中有没有进程已经就绪
void check_ready()
{
    PCB *pw, *q, *cur, *tmp;
    pw = wait;
    
    while (pw->next != NULL) {
        if (pw->next->itime == cpu_time) { // 
            // 用q来暂时存储这个结点，避免对pw进行直接操作
            q = pw->next;

            // 从等待队列删去这个结点
            pw->next = q->next;

            // 如果这时候正在执行的进程不是在第一队列，则应该出现抢占CPU
            cur = ready1->next;
            if (cur == NULL) {
                // 把正在执行的进程调到当前队列的队尾
                if ((cur = ready2->next) != NULL) { // 在第二队列
                    cpu_count = 0;
                    tmp = ready2;
                    ready2->next = cur->next;

                    while(tmp->next != NULL) {
                        tmp = tmp->next;
                    }
                    cur->state = 'R';
                    cur->next = NULL;
                    tmp->next = cur;
                } else if ((cur = ready3->next) != NULL) { // 在第三队列
                    cpu_count = 0;
                    tmp = ready3;
                    ready3->next = cur->next;

                    while(tmp->next != NULL) {
                        tmp = tmp->next;
                    }
                    cur->state = 'R';
                    cur->next = NULL;
                    tmp->next = cur;
                }
            }
            // 把这个结点插入到第一就绪队列队尾
            tmp = ready1;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            q->next = NULL;
            tmp->next = q;

            continue;
        }
        pw = pw->next;
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
        p->state='W'; 
        p->next = NULL; 
        add();
        p = NULL;
    }
} 

void disp(PCB * pr)
{ 
    printf("\n qname \t state \t itime \t ntime \t rtime \t times\n"); 
    printf("|%s\t",pr->name); 
    printf("|%c\t",pr->state); 
    printf("|%d\t",pr->itime); 
    printf("|%d\t",pr->ntime); 
    printf("|%d\t",pr->rtime); 
    printf("|%d\t",pr->times); 
    printf("\n"); 
} 
 
 
void check()
{ 
    PCB *pr1, *pr2, *pr3, *pw; 
    printf("\n **** 当前正在运行的进程是:");
    if (p != NULL) {
        printf("%s", p->name);
        disp(p); 
    } else {
        printf("NULL\n");
    }

    pr1 = ready1->next; 
    if (p != NULL && p == pr1) {
        pr1 = pr1->next;
    }
    printf("\n **** 当前就绪队列1状态为:\n");
    while(pr1 != NULL) { 
        disp(pr1);
        pr1 = pr1->next; 
    }

    pr2 = ready2->next; 
    if (p != NULL && p == pr2) {
        pr2 = pr2->next;
    }
    printf("\n **** 当前就绪队列2状态为:\n");
    while(pr2 != NULL) { 
        disp(pr2);
        pr2 = pr2->next; 
    }

    pr3 = ready3->next; 
    if (p != NULL && p == pr1) {
        pr3 = pr3->next;
    }
    printf("\n **** 当前就绪队列3状态为:\n");
    while(pr3 != NULL) { 
        disp(pr3);
        pr3 = pr3->next; 
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
    p = NULL;
} 

void running()
{ 
    PCB *tmp;
    (p->rtime)++; 
    cpu_count++;
    if (p->rtime == p->ntime) { // 任务完成
        cpu_count = 0;
        destroy();
    } else if (cpu_count == (2 << p->times)) { // 用完时间片了，掉到下一队列。
        cpu_count = 0;
        p->state = 'R';
        p->times++;
        p->next = NULL;
        printf("\n%d\n\n", p->times);
        if (p->times == 1) {
            tmp = ready2;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = p;
        } else {
            tmp = ready3;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = p;
        }
    } else { // 任务没完成，时间片也还没用完
        if (p->times == 0) {
            p->next = ready1->next;
            ready1->next = p;
        } else if (p->times == 1) {
            p->next = ready2->next;
            ready2->next = p;
        } else {
            p->next = ready3->next;
            ready3->next = p;
        }
    }
} 
void main()
{ 
    char ch; 
    PCB *ready;
    SIZE = sizeof (struct pcb);
    // 初始化头结点
    wait        = getpch(PCB);
    ready1      = getpch(PCB);
    ready2      = getpch(PCB);
    ready3      = getpch(PCB);
    wait->next  = NULL;
    ready1->next = NULL;
    ready2->next = NULL;
    ready3->next = NULL;
    input(); 

    
    while(wait->next != NULL || ready1->next != NULL || ready2->next != NULL
            || ready3->next != NULL) { // 只要还有进程在等待就继续
        ch = getchar(); 
        cpu_time++; 

        printf("\n The executed cpu_time:%d \n",cpu_time); 
        check_ready();

        ready = NULL;
        if (ready1->next != NULL) {
            ready = ready1;
        } else if (ready2->next != NULL) {
            ready = ready2;
        } else if (ready3->next != NULL) {
            ready = ready3;
        }
        if (ready != NULL) {
            p = ready->next;
            ready->next = p->next;
            p->next = NULL; 
            p->state = 'R'; 
            running(); 
        }
        check();

        printf("\n 按任意键继续......"); 
        ch = getchar(); 
    } 
    printf("\n\n 进程已经完成.\n"); 
    ch=getchar(); 
} 
