#include "stdio.h" 
#include <stdlib.h> 

#define getpch(type) (type*)malloc(sizeof(type)) 
#define CPUTIME 4

int current_cpu = 0;

struct pcb {
    char name[10]; 
    char state; 
    int super; 
    int ntime; 
    int rtime; 
    struct pcb* link; 
}*ready=NULL, *p, *tail; 

typedef struct pcb PCB; 

void add()
{ 
    if (ready == NULL) { // 如果就绪队列为空，把p插入队首
        p->link = NULL;
        ready   = p;
        tail    = p;
    } else { // 否则把p插入队尾，更新队尾指针
        tail->link = p;
        tail = p;
    }
} 

void input()
{ 
    int i,num; 
    printf("\n 请输入进程号?"); 
    scanf("%d",&num); 
    for(i=0;i<num;i++) { 
        printf("\n 进程号No.%d:\n",i); 
        p=getpch(PCB); 
        printf("\n 进程名:"); 
        scanf("%s",p->name); 
        /*printf("\n 进程优先数:"); */
        /*scanf("%d",&p->super); */
        p->super = 0;
        printf("\n 进程运行时间:"); 
        scanf("%d",&p->ntime); 
        printf("\n"); 
        p->rtime=0;p->state='w'; 
        p->link=NULL; 
        add();
    } 
} 

int space() 
{ 
    int l=0; PCB* pr=ready; 
    while(pr!=NULL) { 
        l++; 
        pr=pr->link; 
    } 
    return(l); 
} 

void disp(PCB * pr)
{ 
    printf("\n qname \t state \t super \t ndtime \t runtime \n"); 
    printf("|%s\t",pr->name); 
    printf("|%c\t",pr->state); 
    printf("|%d\t",pr->super); 
    printf("|%d\t",pr->ntime); 
    printf("|%d\t",pr->rtime); 
    printf("\n"); 
} 
 
 
void check()
{ 
    PCB* pr; 
    printf("\n **** 当前正在运行的进程是:%s",p->name);
    disp(p); 
    pr=ready; 
    printf("\n **** 当前就绪队列状态为:\n");
    while(pr!=NULL) { 
        disp(pr); 
        pr=pr->link; 
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
    current_cpu++;
    if (p->rtime == p->ntime) { // 任务完成
        current_cpu = 0;
        destroy();
    } else if (current_cpu == CPUTIME) { // 用完时间片了
        current_cpu = 0;
        if (ready == NULL) { // 如果已经是最后一个了
            ready = p;
        } else {
            tail->link = p;
            tail = p;
        }
    } else { // 任务没完成，时间片也还没用完
        p->link = ready;
        ready = p;
    }
} 
void main()
{ 
    int len,number=0; 
    char ch; 
    input(); 
    len=space(); 
    while((len!=0)&&(ready!=NULL)) { 
        ch=getchar(); 
        number++; 
        printf("\n The execute number:%d \n",number); 
        p=ready; 
        ready=p->link; 
        p->link=NULL; 
        p->state='R'; 
        check(); 
        running(); 
        printf("\n 按任意键继续......"); 
        ch=getchar(); 
    } 
    printf("\n\n 进程已经完成.\n"); 
    ch=getchar(); 
} 
