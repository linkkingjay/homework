# coding: utf-8
# 蛮力法求凸包

# 根据给出的两个点获得一条直线的方程：ax+by=c
def get_line(x1, y1, x2, y2):
    a = y2 - y1
    b = x1 - x2
    c = x1 * y2 - y1 * x2
    return {'a':a, 'b':b, 'c':c}

def convex_hull(points):
    n = len(points)
    result = list() 
    for i in range(0, n):
        for j in range(i + 1, n):
        # 每两个点获取一条直线
            p1 = points[i]
            p2 = points[j]
            line = get_line(p1[0], p1[1], p2[0], p2[1]) 
            side = list() 
            # side用来存放其他点在这条直线的哪一边
            on = list()
            # on用来存放在这条直线上的点

            for k in range(0, n):
                p = points[k]
                # val = ax + by，判断其跟c的大小关系，确定在直线的哪一边
                val = line['a'] * p[0] + line['b'] * p[1]
                if val < line['c']:
                    side.append(-1)
                elif val > line['c']:
                    side.append(1)
                elif val == line['c']:
                    on.append(p)

            ret = True
            if len(side) > 0:
                t = side[0]
                for f in side[1:]:
                    if t != f:
                        ret = False
                        break

            # 判断在直线上的点是否在这两个点构成的线段的两端
            for op in on:
                if (op[0] > p1[0] and op[0] > p2[0]) or (op[0] < p1[0] and op[0] < p2[0]) \
                or (op[1] > p1[1] and op[1] > p2[1]) or (op[1] < p1[1] and op[1] < p2[1]) :
                    ret = False
                    break

            # 如果符合条件，就添加到结果中去
            if ret == True:
                try: 
                    result.index(points[i])
                except:
                    result.append(points[i])

                try: 
                    result.index(points[j])
                except:
                    result.append(points[j])

    result.sort()
    return result
# end of convex_hull

def main():
    points = list()
    for i in range(-5, 6):
        for j in range(-5, 6):
            points.append([i,j])
    t= convex_hull(points)
    print t

if __name__ == '__main__':
    main()
