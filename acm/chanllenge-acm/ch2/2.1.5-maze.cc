#include <utility>
#include <cstdio>
#include <queue>

using namespace std;
const int INF = 100000000;
const int MAX_N = 1000, MAX_M = 1000;

typedef pair<int, int> P;

// 起点和终点坐标
int sx, sy, gx, gy;

// 移动方向
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int i, j, k, N, M;

// 迷宫地图
char maze[MAX_N][MAX_M];

// 最短距离
int d[MAX_N][MAX_M];

int main() {
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++) {
        scanf("%s", maze[i]);
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            // 找出起点和终点
            if (maze[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (maze[i][j] == 'G') {
                gx = i;
                gy = j;
            }
            // 初始化最短距离
            d[i][j] = INF;
        }
    }
    d[sx][sy] = 0;

    queue<P> que;
    que.push(P(sx, sy));
    while (que.size()) {
        P p = que.front();
        que.pop();

        // 找到终点
        if (p.first == gx && p.second == gy) {
            break;
        }
        for (i = 0; i < 4; i++) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#' &&
                    d[nx][ny] == INF) {
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    printf("%d\n", d[gx][gy]);

    return 0;
}
