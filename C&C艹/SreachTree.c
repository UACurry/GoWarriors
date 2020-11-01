#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int v;//结点基本信息
    struct TreeNode *Left;
    struct TreeNode *Right;
    int flag;//用来判别序列是不是跟树一致，被访问过就为1，反之为0
}*Tree;