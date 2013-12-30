#include <iostream>
using namespace std;

char maze[510][510];
int flag[510][510];
int n, m, k;
void dfs(int x, int y) {
    flag[x][y] = 1;
    if (x - 1 >= 0 && maze[x - 1][y] == '.' && flag[x - 1][y] == 0) dfs(x - 1, y);
    if (x + 1 < n && maze[x + 1][y] == '.' && flag[x + 1][y] == 0) dfs(x + 1, y);
    if (y - 1 >= 0 && maze[x][y - 1] == '.' && flag[x][y - 1] == 0) dfs(x, y - 1);
    if (y + 1 < m && maze[x][y + 1] == '.' && flag[x][y + 1] == 0) dfs(x, y + 1);
    if (k > 0) {
        k--;
        maze[x][y] = 'X';
    }
}
int main()
{
    char t;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            flag[i][j] = 0;
            maze[i][j] = '#';
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> maze[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '.') {
                dfs(i, j);
            }
        }
    }
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << maze[i][j];
        cout << endl;
    }

    return 0;
}
