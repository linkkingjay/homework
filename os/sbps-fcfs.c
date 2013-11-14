#include<stdio.h>
#include<stdlib.h>

#define getjcb (JCB*)malloc(SIZE);
int SIZE;
int CPU_TIME = 0;
typedef enum {w, r, f} State;
struct jcb {
    char name[10];
    State state;
    int itime; // 到达时间
    int stime; // 开始服务时间
    int ntime; // 所需运行时间

    int rtime; // 运行时间
    int ftime; // 完成时间
    struct jcb *next;
};
typedef struct jcb JCB;
JCB *wait, *ready, *p;

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
    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        p = getjcb;

        scanf("%s", p->name);
        scanf("%d", &p->itime);
        scanf("%d", &p->ntime);

        p->state = w;
        p->stime = 0;
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
            q = pw->next;
            pw->next = q->next;
            
            while (pr->next != NULL) {
                pr = pr->next;
            }
            q->next = NULL;
            pr->next = q;

            continue;
        }
        pw = pw->next;
    }
}
void destroy()
{
    p->ftime = CPU_TIME;
    p->stime = CPU_TIME - p->ntime + 1;
    printf("|%s\t", p->name);
    printf("|%d\t\t", p->stime);
    printf("|%d\t\t", p->ftime);
    printf("|%d\t\t", p->ftime - p->itime);
    printf("\n");
    free(p);
    p = NULL;
}

void run()
{
    (p->rtime)++;
    if (p->rtime == p->ntime) {
        destroy();
    } else {
        p->next = ready->next;
        ready->next = p;
    }
}
void test()
{
    JCB *pw = wait->next;
    JCB *pr = ready->next;
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
}
int main()
{
    SIZE = sizeof(JCB);
    wait = getjcb;
    ready = getjcb;
    wait->next = NULL;
    ready->next = NULL;
    input();

    printf("\n\n 进程 \t 开始时刻 \t 完成时刻 \t 周转时间 \t 带权周转时间\n");
    while (wait->next != NULL || ready->next != NULL) {
        CPU_TIME++;
        check_ready();
        if (ready->next != NULL) {
            p = ready->next;
            ready->next = p->next;
            p->next = NULL;
            p->state = r;
            run();
        }
    }

    return 0;
}
