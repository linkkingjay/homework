#include <iostream>
using namespace std;

int abs (int x) {
    if (x < 0)
        return -x;
    else
        return x;
}
int main()
{
    int a, b, t;
    int aw, d, bw;
    while (cin >> a >> b) {
        aw = d = bw = 0;
        for (int i = 1; i <= 6; i++) {
            t = abs(a - i) - abs(b - i);
            if (t < 0)
                aw++;
            else if (t == 0)
                d++;
            else
                bw++;
        }
        cout << aw << " " <<  d << " " << bw << endl;
    }

    return 0;
}
