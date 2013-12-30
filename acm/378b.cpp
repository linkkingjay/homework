#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

vector <int> a, b;
int ra[100010], rb[100010];
int main()
{
    int n, t;
    vector <int>::iterator it;
    cin >> n;
    memset(ra, 0, sizeof(ra));
    memset(rb, 0, sizeof(rb));

    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
        cin >> t;
        b.push_back(t);
    }

    for (int i = 0, ia = 0, ib = 0; i < n; i++) {
        if (a[ia] < b[ib]) {
            ra[ia++] = 1;
        } else {
            rb[ib++] = 1;
        }
    }

    for (int i = 0; i < n / 2; i++)
        cout << 1;
    for (int i = n / 2; i < n; i++)
        if (ra[i] == 1)
            cout << 1;
        else
            cout << 0;
    cout << endl;

    for (int i = 0; i < n / 2; i++)
        cout << 1;
    for (int i = n / 2; i < n; i++)
        if (rb[i] == 1)
            cout << 1;
        else
            cout << 0;
    cout << endl;

    return 0;
}
