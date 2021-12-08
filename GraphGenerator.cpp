#include <iostream>
#include <string>
#include <vector>
#include "GraphGenerator.h"
#include <algorithm>

using namespace std;

GraphGenerator::GraphGenerator(){

}

void GraphGenerator::InsertVertex(int v1, AvlNode * & t){
    if(t = nullptr){
        Node* n = new Node();
        n->data = v1;
        n->next = nullptr;
        t = new AvlNode{n, nullptr, nullptr};
    }
    else if(v1 < t->head->data){
        InsertVertex(v1, t->left);
    }
    else if(v1 > t->head->data){
        InsertVertex(v1, t->right);
    }

    balance(t);


}

void GraphGenerator::InsertEdge(int v1, int v2){
    AvlNode *vertex1 = Lookup(v1);
    AvlNode *vertex2 = Lookup(v2);

    if(vertex1 == nullptr){
        InsertVertex(v1, mainHead);
        AvlNode *vertex1 = Lookup(v1);
    }
    else if(vertex2 == nullptr){
        InsertVertex(v2, mainHead);
        AvlNode *vertex2 = Lookup(v2);
    }

    Node *first = new Node();
    first->data = v1;
    first->next = nullptr;
    vertex2->tail->next = first;

    Node *second = new Node();
    second->data = v2;
    second->next = nullptr;
    vertex1->tail->next = second;

}

AvlNode* GraphGenerator::Lookup(int v1){

}

void GraphGenerator::InOrder(){

}

void GraphGenerator::PreOrder(){

}

void GraphGenerator::balance(AvlNode* & t){
    if(t == nullptr){
        return;
    }

    if(getHeight(t->left) - getHeight(t->right) > 1){
        if(getHeight(t->left->left) >= getHeight(t->left->right)){
            rightRotation(t);
        }
        else{
            leftRightDoubleRotation(t);
        }
    }
    else if(getHeight(t->right) - getHeight(t->left) > 1){
        if(getHeight(t->right->right) >= getHeight(t->right->left)){
            leftRotation(t);
        }
        else{
            rightLeftDoubleRotation(t);
        }
    }

    t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
}

void GraphGenerator::rightRotation(AvlNode * & k2){
    AvlNode *k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(getHeight(k2->left),getHeight(k2->right)) + 1;
    k1->height = max(getHeight(k1->left),k2->height) + 1;
    k2 = k1;
}

void GraphGenerator::leftRotation(AvlNode * k1){
    AvlNode *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(getHeight(k1->left),getHeight(k1->right)) + 1;
    k2->height = max(getHeight(k2->right),k1->height) + 1;
    k1 = k2;
}

void GraphGenerator::leftRightDoubleRotation(AvlNode * k3){
    leftRotation(k3->left);
    rightRotation(k3);
}

void GraphGenerator::rightLeftDoubleRotation(AvlNode * k1){
    rightRotation(k1->right);
    leftRotation(k1);
}



