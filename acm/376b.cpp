#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int s[10010];
int main()
{
    int n, m, a, b, count, sum;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++)
            s[i] = 0;

        for (int i = 0; i < m; i++) {
            cin >> a >> b >> count;
            s[a] -= count;
            s[b] += count;
        }

        sum = 0;
        for (int i = 1; i <= n; i++)
            if (s[i] > 0)
                sum += s[i];

        cout << sum << endl;
    }
    return 0;
}
