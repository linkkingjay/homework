#include<stdio.h>
#include<stdlib.h>

#define getjcb (JCB*)malloc(SIZE);
int SIZE;
int CPU_TIME = 0;
int memory, tape;
typedef enum {w, r, f} State;
struct jcb {
    char name[10];
    State state;
    int itime; // 到达时间
    int ntime; // 所需运行时间

    int stime; // 开始服务时间
    int rtime; // 运行时间
    int ftime; // 完成时间

    int m_count; // 所需内存
    int t_count; // 所需磁带机
    struct jcb *next;
};
typedef struct jcb JCB;
JCB *wait, *ready, *running, *p;

void add()
{
    JCB *pw = wait;
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
        if (pw->next == NULL) {
            pw->next = p;
        }
    }
}
void input()
{
    int i, num;
    printf("\n 请输入作业个数？");
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        printf("\n 作业号No.%d:\n", i);
        p = getjcb;

        printf("\n 作业名:");
        scanf("%s", p->name);
        printf("\n 作业进入时间:");
        scanf("%d", &p->itime);
        printf("\n 作业所需运行时间:");
        scanf("%d", &p->ntime);
        printf("\n 作业所需内存数量:");
        scanf("%d", &p->m_count);
        printf("\n 作业所需磁带机数量:");
        scanf("%d", &p->t_count);

        p->state = w;
        p->rtime = 0;
        p->ftime = 0;
        p->next = NULL;
        add();
    }
}

void check_ready()
{
    JCB *pw, *pr, *q;
    pw = wait;
    pr = ready;
    while (pw->next != NULL) {
        if (pw->next->itime == CPU_TIME) {
            // q为可以进入就绪队列的作业
            q = pw->next;
            pw->next = q->next;
            
            // 按所需服务时间排序，插入到合适位置
            while (pr->next != NULL) {
                if (pr->next->ntime > q->ntime) {
                    q->next = pr->next;
                    pr->next = q;
                    break;
                }
                pr = pr->next;
            }
            if (pr->next == NULL) {
                q->next = NULL;
                pr->next = q;
            }

            continue;
        }
        pw = pw->next;
    }
}

void destroy(JCB *p)
{
    // 释放资源
    memory += p->m_count;
    tape += p->t_count;

    p->ftime = CPU_TIME;
    p->stime = CPU_TIME - p->ntime + 1;
    printf("|%s\t", p->name);
    printf("|%d\t\t", p->stime);
    printf("|%d\t\t", p->ftime);
    printf("|%d\t\t", p->ftime - p->itime);
    printf("|%.2f\t\t", (float)(p->ftime - p->itime) / p->ntime);
    printf("\n");
}

void run()
{
    JCB *prun = running;
    while (prun->next != NULL) {
        (prun->next->rtime)++;
        if (prun->next->rtime == prun->next->ntime) {
            destroy(prun->next);
            prun->next = prun->next->next;
        } else {
            prun = prun->next;
        }
    }
}
void test()
{
    JCB *pw, *pr, *prun;

    pw = wait->next;
    pr = ready->next;
    prun = running->next;

    printf("\n==============\n");
    printf("CPUTIME:%d\n", CPU_TIME);

    printf("\nwait queue:\n");
    while (pw != NULL) {
        printf("%s\n", pw->name);
        pw = pw->next;
    }

    printf("\nready queue:\n");
    while (pr != NULL) {
        printf("%s\n", pr->name);
        pr = pr->next;
    }

    printf("\nrunning queue:\n");
    while (prun != NULL) {
        printf("%s\n", prun->name);
        prun = prun->next;
    }
}
int main()
{
    JCB *pr, *tmp;
    SIZE = sizeof(JCB);

    memory = 100;
    tape = 5;

    wait          = getjcb;
    ready         = getjcb;
    running       = getjcb;
    wait->next    = NULL;
    ready->next   = NULL;
    running->next = NULL;
    input();

    printf("\n\n 进程 \t 开始时刻 \t 完成时刻 \t 周转时间 \t 带权周转时间\n");
    while (wait->next != NULL || ready->next != NULL || running->next != NULL) {
        CPU_TIME++;
        check_ready();

        // 从就绪队列中按顺序查找可以分配资源的作业插入运行队列队尾
        pr = ready;
        while (pr->next != NULL) {
            // 能够分配资源的
            if (pr->next->m_count <= memory && pr->next->t_count <= tape) {
                tmp = pr->next;
                pr->next = tmp->next;

                memory -= tmp->m_count;
                tape -= tmp->t_count;
                tmp->next = running->next;
                running->next = tmp;
            } else {
                pr = pr->next;
            }
        }
        if (running->next != NULL) {
            run();
        }
    }

    return 0;
}
