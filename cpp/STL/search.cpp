#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a[9] = {3, 6, 1, 6, 2, 6, 0, 9, 8};
    vector<int> v1(a, a + 9);
    vector<int>::iterator result1, result2;

    result1 = find(v1.begin(), v1.end(), 0);
    result2 = find(v1.begin(), v1.end(), 7);
    cout << result1 - v1.begin() << endl;
    cout << result2 - v1.end() << endl;

    int b[6] = {6, 2, 6, 0, 9, 8};
    vector<int> v2(a + 2, a + 8);
    vector<int> v3(b, b + 6);

    result1 = search(v1.begin(), v1.end(), v2.begin(), v2.end());
    cout << *result1 << endl;

    result1 = search(v1.begin(), v1.end(), v3.begin(), v3.end());
    cout << *result1 << endl;

    vector<int> v4(a, a + 9);
    int i = count(v4.begin(), v4.end(), 6);
    cout << "there are " << i << " memebers in v4 equal to 6" << endl;

    return 0;
}
