#include <iostream>
#include <deque>
using namespace std;

typedef deque<int> INTDEQUE;

// 从前向后显示deque队列的全部元素
void put_deque(INTDEQUE deque, char *name)
{
    INTDEQUE::iterator pdeque;
    cout << "The contents of " << name << " : ";
    for (pdeque = deque.begin(); pdeque != deque.end(); pdeque++)
	cout << *pdeque << " ";
    cout << endl;
}

int main()
{
    INTDEQUE deq1;
    INTDEQUE deq2(10, 6);
    INTDEQUE::iterator i;
    
    put_deque(deq1, "deq1");
    put_deque(deq2, "deq2");

    deq1.push_back(2);
    deq1.push_back(4);
    cout << "deq1.push_back(2) and deq1.push_back(4):" << endl;
    put_deque(deq1, "deq1");

    deq1.push_front(5);
    deq1.push_front(7);
    cout << "deq1.push_front(5) and deq1.push_front(7):" << endl;
    put_deque(deq1, "deq1");
}
