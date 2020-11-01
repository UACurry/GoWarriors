#include <stdio.h>
#include <stdlib.h>

//二叉搜索树
//必须是一颗二叉树  根 > 左 根 < 右
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

//这个结构可以把树写的更加完整一点
typedef struct
{
    //访问这颗树的话  访问根结点就行
    Node *root;
} Tree;

void preorder(Node *node)
{
    if (node != NULL)
    {
        printf("%d\n", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(Node *node)
{
    if (node != NULL)
    {

        inorder(node->left);
        printf("%d\n", node->data);
        inorder(node->right);
    }
}

void insert(Tree *tree, int value)
{
    //先把value打包成node
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    if (tree->root == NULL)
    {
        tree->root = node;
    }
    else
    {
        Node *temp = tree->root; //当前这个进来的数值需要比较的数字  一开始等于树的根
        while (temp != NULL)
        {
            //插入到左边的情况
            if (value < temp->data)
            {
                if (temp->left == NULL)
                {
                    temp->left = node; //value 已经打包成node了
                    return;
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            //插入到右边的情况
            {
                if (temp->right == NULL)
                {
                    temp->right = node; //value已经打包成node了
                    return;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
}

int get_high(Node *node)
{
    //递归的出口
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        int left_high = get_high(node->left);
        int right_high = get_high(node->right);
        int max = left_high;
        if (right_high > max)
        {
            max = right_high;
        }
        return max + 1; //加上根结点
    }
}

int get_max(Node *node)
{
    //假设只有正数
    if (node == NULL)
    {
        //空结点
        return -1;
    }
    else
    {
        int left_max = get_max(node->left);   //左子树的最大值
        int right_max = get_max(node->right); //同理
        int root = node->data;                //根结点
        int max = left_max;
        if (right_max > max)
        {
            max = right_max;
        }
        if (root > max)
        {
            max = root;
        }
        return max;
    }
}

int main()
{

    int arr[7] = {4, 5, 7, 2, 1, 3, 6};

    Tree tree;
    tree.root = NULL;

    int i;
    for (i = 0; i < 7; i++)
    {
        insert(&tree, arr[i]);
    }
    //preorder(tree.root);
    inorder(tree.root);

    int h;
    h = get_high(tree.root);
    printf("树高为:%d\n", h);

    int max;
    max = get_max(tree.root);
    printf("最大值%d\n", max);
    system("pause");
    return 0;
}