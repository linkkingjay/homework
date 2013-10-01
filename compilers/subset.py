# coding: utf-8

# 子集法
def subset(NFA):
    K = list()
    Sigma = list()
    f = list()
    S = closure(NFA['S'], NFA['f'])
    Z = list()

    DFA = {
            "K": K,
            "Sigma": Sigma,
            "f": f,
            "S": S,
            "Z": Z
            }
    K.append(S)
    for k in K:
        for s in NFA['Sigma']:
            m = move(k, s, NFA['f'])
            c = closure(m, NFA['f'])

            if c not in K:
                K.append(c)

            if s not in Sigma:
                Sigma.append(s)

            if [k, s, c] not in f:
                f.append([k, s, c])

    for k in K:
        flag = 1
        for nz in NFA['Z']:
            if nz not in k:
                flag = 0
                break

        if flag == 1:
            Z.append(k)

    return DFA

# 求状态集合I的闭包，是状态集I中的任何状态S经过任意条空弧而能到达的集合状态集合
def closure(I, f):
    ret = list()
    for s in I:
        # 把s本身添加到结果中去
        if s not in ret:
            ret.append(s)
        for i in f:
            if i[0] == s and i[1] == 'e':
                if i[2] not in ret:
                    ret.append(i[2])
                    if i[2] not in I:
                        I.append(i[2])
    ret.sort()
    return ret

# 状态集合T0的a弧转换，是状态集合I中那些可以从TO中的某一状态经过一条a弧而到达的
# 状态的全体
def move(T0, a, f):
    ret = list()
    for s in T0:
        for i in f:
            if i[0] == s and i[1] == a:
                if i[2] not in ret:
                    ret.append(i[2])

    ret.sort()
    return ret

def main():
    # 测试数据1
    NFA = {
            "K": range(1, 5),
            "Sigma": ['a','b'],
            "f": [[0,'a',0],[0,'a',3],[0,'b',0],[0,'b',1],[1,'b',2],[2,'a',2],
                  [2,'b',2],[3,'a',4],[4,'a',4],[4,'b',4]],
            "S": [0],
            "Z": [2,4]
            }
    # 测试数据2
    NFA1 = {
            "K": range(1, 11),
            "Sigma": ['a','b'],
            "f": [[0,'e',1],[0,'e',7],[1,'e',2],[1,'e',4],[2,'a',3],[3,'e',6],
                  [4,'b',5],[5,'e',6],[6,'e',1],[6,'e',7],[7,'a',8],[8,'b',9],
                  [9,'b',10]],
            "S": [0],
            "Z": [10]
            }
    c = closure(NFA1['S'], NFA1['f'])
    m = move(c, 'a', NFA1['f'])
    DFA = subset(NFA1)
    for (k, v) in DFA.items():
        if k != 'f':
            print k,':',v
        else:
            print 'f:'
            for i in v:
                print i

if __name__ == '__main__':
    main()
