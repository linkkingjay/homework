# coding: utf-8

# 子集法
def subset(NFA):
    DFA = {}
    return DFA

# 求状态集合I的闭包，是状态集I中的任何状态S经过任意条空弧而能到达的集合状态集合
def closure(I, f):
    ret = list()
    for s in I:
        # 把s本身添加到结果中去
        try:
            ret.index(s)
        except:
            ret.append(s)
        for i in f:
            if i[0] == s and i[1] == 'ε':
                try:
                    ret.index(i[2])
                except:
                    ret.append(i[2])
                    I.append(i[2])
    ret.sort()
    return ret

# 状态集合T0的a弧转换，是状态集合I中那些可以从TO中的某一状态经过一条a弧而到达的状态
# 的全体
def move(T0, a, f):
    ret = list()
    for s in T0:
        for i in f:
            if i[0] == s and i[1] == a:
                try:
                    ret.index(i[2])
                except:
                    ret.append(i[2])

    ret.sort()
    return ret

def main():
    f = [[0,'ε',1],[0,'ε',7],[1,'ε',2],[1,'ε',4],[0,'b',1],[1,'b',2],[2,'a',2],[2,'b',2]
            ,[3,'a',4],[0,'ε',2]]
    NFA = {
            "K": [0,1,2,3,4],
            "Sigma": ['a','b'],
            "f": f,
            "S": [0],
            "Z": [2,4]
            }
    print move([0,2],'b',f)

if __name__ == '__main__':
    main()
