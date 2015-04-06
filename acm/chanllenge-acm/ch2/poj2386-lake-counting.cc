#include <cstdio>
const int MAX_N = 101;
const int MAX_M = 101;
int i, j, ans, N, M;
char map[MAX_N][MAX_M];

void dfs(int x, int y) {
    int dx, dy;
    map[x][y] = '.';
    for (dx = -1; dx <= 1; dx++) {
        for (dy = -1; dy <= 1; dy++) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < N && ny >= 0 && ny < M &&map[nx][ny] == 'W') {
                dfs(nx, ny);
            }
        }
    }
    return;
}
int main() {
    ans = 0;
    scanf("%d%d", &N, &M);
    for (i = 0; i < N; i++) {
        scanf("%s", map[i]);
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            if (map[i][j] == 'W') {
                dfs(i, j);
                ans++;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
