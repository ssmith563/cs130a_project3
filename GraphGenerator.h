#ifndef GRAPHGENERATOR_H
#define GRAPHGENERATOR_H

#include <string>
#include <vector>


struct Node {
    int data;
    Node *next;
};


struct AvlNode{
    Node *head;
    Node *tail;
    AvlNode *left;
    AvlNode *right;
    int height;

    AvlNode(Node *ele, AvlNode *lt, AvlNode *rt, int h = 0){
        head = ele;
        left = lt;
        right = rt;
        height = h;
        tail = ele;
    }
};

int getHeight(AvlNode *t){
    if(t == nullptr){
        return -1;
    }
    else{
        return t->height;
    }
}

class GraphGenerator
{
    
    AvlNode *mainHead;

    public:

    GraphGenerator();

    void InsertVertex(int v1, AvlNode * & t);

    void InsertEdge(int v1, int v2);

    AvlNode* Lookup(int v1);

    void InOrder();

    void PreOrder();

    void balance(AvlNode* & t);

    void rightRotation(AvlNode * & k2);

    void leftRotation(AvlNode * k1);

    void leftRightDoubleRotation(AvlNode * k3);

    void rightLeftDoubleRotation(AvlNode * k1);

    
};

#endif


