#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int> q;
    q.push_back(10);
    q.push_back(11);
    q.push_back(12);

    vector<int> v;
    for (int i = 0; i < 5; i++)
	v.push_back(i);

    vector<int>::iterator it = v.begin() + 1;
    it = v.begin() + 3;
    v.insert(it, 3, -1);
    it = v.begin() + 4;
    v.erase(it);
    it = v.begin() + 1;
    v.erase(it, it + 4);
    v.clear();
    return 0;
}
