#include<cstring>
#include<vector>
#include<iostream>
using namespace std;

int ar[10] = {12, 45, 234, 64, 12, 35, 63, 23, 12, 55};
char* str = "Hello World";

int main()
{
    vector <int> vec1(ar, ar + 10); // first=ar, last=ar+10, 不包括ar+10
    vector <char> vec2(str, str + strlen(str));

    cout << "vec1:" << endl;
    for (int i = 0; i < vec1.size(); i++)
	cout << vec1[i];
    cout << endl;

    cout << "vec2:" << endl;
    for (int i = 0; i < vec2.size(); i++)
	cout << vec2[i];
    cout << endl;

    return 0;
}
