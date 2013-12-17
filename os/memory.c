struct memory {    //分区链
    int size;        //分区大小 
    int state;        //分区状态，1:已分配，0:未分配
    int address;    //起址
    struct memory *prior;    //指向上一个分区
    struct memory *next;        //指向下一个分区
}*mbegin=NULL;
struct job{        //作业链
    int num;        //作业编号
    int need;        //请求内存的大小 
    int address;    //作业已分配到的内存块的起址 
    struct job *next;    //指向下一个作业
}*jbegin=NULL;
 
int getmemory(int b,int c)    //申请内存，b:作业编号，c:申请的内存的大小 
{
    JOB *jp,*jtemp;
    MEMORY *mp,*mnew = NULL,*mpnext = NULL;
    jp = getpch(JOB);    //为作业创建控制块jp
    jp->num = b;
    jp->need = c; 
    jp->next = NULL; 
    mp = mbegin;
    while( mp!=NULL )    /*寻找合适内存分区块，找到则mp指向该内存块，否则
    {                      mp==NULL*/    
        if( mp->size >=c && mp->state == 0 ) 
            break;
        mp = mp->next;
    }
    if( mp==NULL )    /*mp==NULL表示没有合适的分区块存在，输出相应提示信
    {                 息并返回。*/
           printf("找不到合适的内存分区!\n");
           return 0;
    } 
     jp->address = mp->address;    //作业分配到的内存起址等于该内存块的起址 
    if( mp->size == jp->need )   //分区大小正好等于申请空间的情况
    {
        mp->state = 1; 
    } 
    else        //分区大小大于申请空间的情况
    {//创建新内存分区，大小为（原空闲分区大小-申请空间）
        mnew = getpch(MEMORY);    
        mnew->next = NULL;
        mnew->prior = NULL; 
        mnew->size = mp->size - c;
        mnew->address = mp->address + c;
        mnew->state = 0;
        mp->size = c;
        mp->state = 1; 
        if( mp->next==NULL )    //实现将新分区插到mp后面 
        {
            mp->next = mnew;
            mnew->prior = mp;
        }
        else 
        {                    
            mpnext = mp->next; 
            mpnext->prior = mnew;
            mnew->next = mpnext;
            mnew->prior = mp;
            mp->next = mnew;
        }
    }     
    if( jbegin==NULL )//以下操作将新的作业插入作业队列队尾
        jbegin=jp;
    else
    {
        jtemp=jbegin;
        while( jtemp->next != NULL )
        {
            jtemp = jtemp->next;
        }     
        jtemp->next = jp;
    }    
     printf("作业%d申请%dKB，内存分区情况：\n",b,c);
} 
 
int freememory(int b)    //释放内存，b:作业编号 
{
    int c;
    JOB *jp=NULL;
    MEMORY *mp,*mtemp=NULL; 
    jp=jbegin;
    while( jp!=NULL )    //从作业队列中查找该作业
    {
        if( jp->num == b )
            break;
        jp = jp->next;
    }
    if(jp==NULL)    //找不到该作业时提示并返回
    {
        printf("该作业不存在!\n");
        return 0;    
    }
    mp=mbegin;
    while( mp!=NULL )    //查找为该作业分配的内存块
    {
        if( mp->address == jp->address )
             break;
        mp = mp->next; 
    } 
    c = mp->size;    //记录释放空间大小
    /*开始回收该内存块操作*/
    mtemp = mp->prior;
    if( mp->prior != NULL && mtemp->state == 0 )    /*查看前一个内存块是否空 
    {                                                  闲，是则向前合并*/
        mtemp->size += mp->size; 
        mp->next->prior = mtemp; 
        mtemp->next = mp->next;
        free(mp);
        mp=mtemp;     
    }
    mtemp = mp->next;
　　//查看后一个内存块是否空闲，是则将后一个内存块向前合并
    if( mp->next != NULL && mtemp->state == 0 )        
    {
        mp->size += mtemp->size;
        if( mtemp->next == NULL ) 
            mp->next = NULL;
        else
        {
            mtemp->next->prior = mp;
            mp->next = mtemp->next;
            free(mtemp);
        }
    } 
    mp->state = 0;
    printf("作业%d释放%dKB，内存分区情况：\n",b,c);
}
