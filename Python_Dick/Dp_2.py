#在一段数组中能否找到给定数字的合
import numpy as np
arr = [3, 34, 4, 12, 5, 2]


def rec_subset(arr, i, s):
    if s == 0:
        return True
    elif i == 0:
        return arr[0] == s
    elif arr[i] > s:
        return rec_subset(arr, i - 1, s)
    else:
        A = rec_subset(arr, i - 1, s - arr[i])  #选
        B = rec_subset(arr, i - 1, s)  #不选
        return A or B


print(rec_subset(arr, len(arr) - 1, 9))


#用一个二维数组
def dp_subset(arr, s):
    subset = np.zeros((len(arr), s + 1), dtype=bool)  #表示保存的都是T,F
    subset[:, 0] = True  #  冒号表示所有行
    subset[0, :] = False
    subset[0:arr[0]] = True
    for i in range(1, len(arr)):
        for j in range(1, s + 1):
            if arr[i] > j:
                subset[i, s] = subset[i - 1, s]
            else:
                A = dp_subset(i - 1, s - arr[i])  #选
                B = dp_subset(i - 1, s)  #不选
                subset[i, s] = A or B
    r, c = subset.shape
    return subset[r - 1, c - 1]
