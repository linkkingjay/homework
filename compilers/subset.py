# coding: utf-8

# 子集法
def subset(NFA):
    DFA = {}
    return DFA

# 求状态集合I的闭包，是状态集I中的任何状态S经过任意条空弧而能到达的集合状态集合
# todo:删除重复添加状态
def closure(I, f):
    ret = list()
    for s in I:
        for i in f:
            if i[0] == s and i[1] == 'null':
                ret.append(i[2])
                I.append(i[2])
    return ret

# 状态集合I的a弧转换，是状态集合I中那些可以从I中的某一状态经过一条a弧而到达的状态
# 的全体
def move(T0, a, f):
    ret = list()
    return ret

def main():
    f = [[0,'a',0],[0,'a',3],[0,'b',1],[0,'b',1],[1,'b',2],[2,'a',2],[2,'null',1]
            ,[1,'null',0]]
    NFA = {
            "K": [0,1,2,3,4],
            "Sigma": ['a','b'],
            "f": f,
            "S": [0],
            "Z": [2,4]
            }
    print subset(NFA)

if __name__ == '__main__':
    main()
