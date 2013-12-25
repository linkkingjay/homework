#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int number[20] = {29, 23, 20, 22, 17, 15, 26, 51, 19, 12, 35, 40};

    make_heap(&number[0], &number[12]);
    for (int i = 0; i < 12; i++)
	cout << number[i] << " ";
    cout << endl;

    make_heap(&number[0], &number[12], cmp);
    for (int i = 0; i < 12; i++)
	cout << number[i] << " ";
    cout << endl;

    number[12] = 8;
    push_heap(&number[0], &number[13], cmp);
    for (int i = 0; i < 13; i++)
	cout << number[i] << " ";
    cout << endl;

    sort_heap(&number[0], &number[13], cmp);
    for (int i = 0; i < 13; i++)
	cout << number[i] << " ";
    cout << endl;

    return 0;
}
