//哈夫曼树 就是把两个最小的合并，形成一个新的二叉树
//二叉树的权值等于原来两个权值的和
//哈夫曼编码，要求没有二义性，所以所有的编码都要在叶结点上面
      
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int Weight;
    struct TreeNode *Left;
    struct TreeNode *Right;
}*HuffmanTree;

HuffmanTree Huffman(MinHeap H){

}