#include <iostream>
#include <string>
#include <vector>
#include "GraphGenerator.h"
#include <algorithm>

using namespace std;

GraphGenerator::GraphGenerator(){
    mainHead = nullptr;
}

void GraphGenerator::InsertVertex(int v1, AvlNode * & t){
    if(t == nullptr){
        Node* n = new Node();
        n->data = v1;
        n->next = nullptr;
        t = new AvlNode{n, nullptr, nullptr};//maybe make reference to n
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
    AvlNode *vertex2 = Lookup(v2); //good here for 1 and 2 rounds

    if(vertex1 == nullptr){
        InsertVertex(v1, mainHead);
        vertex1 = Lookup(v1); //works
    }
    if(vertex2 == nullptr){
        InsertVertex(v2, mainHead);
        vertex2 = Lookup(v2); //sets 3 to 0
    }

    cout<<mainHead<<" ";

    Node *first = new Node();
    first->data = v1;
    first->next = nullptr;
    vertex2->tail->next = first; //seg fault (maybe add &) vertex 2 = 0
    vertex2->tail = first;

    Node *second = new Node();
    second->data = v2;
    second->next = nullptr;
    vertex1->tail->next = second;
    vertex1->tail = second;

}

AvlNode* GraphGenerator::Lookup(int v1){
    AvlNode* current = mainHead;
    while(current != nullptr){
        if(current->head->data == v1){
            return current;
        }
        else if(current->head->data > v1){
            current = current->left;//switched left and right
        }
        else{
            current = current->right;//switched left and right
        }
    }
    return current;

}

void GraphGenerator::InOrder(AvlNode* root){
    if(root != nullptr){
        PreOrder(root->left);
        cout<<root->head->data<<" ";
        PreOrder(root->right);
    }
}

void GraphGenerator::PreOrder(AvlNode* root){
    if(root != nullptr){
        cout<<root->head->data<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void GraphGenerator::balance(AvlNode* & t){
    if(t == nullptr){
        return;
    }

    if(getHeight(t->left) - getHeight(t->right) > 1){
        if(getHeight(t->left->left) >= getHeight(t->left->right)){
            //if(t == mainHead){//changes mainhead
            //    mainHead = t->left;
            //}
            rightRotation(t);
        }
        else{
            //if(t == mainHead){//changes mainhead
            //    mainHead = t->left->right;
            //}
            leftRightDoubleRotation(t);
        }
    }
    else if(getHeight(t->right) - getHeight(t->left) > 1){//Balancing for first time
        if(getHeight(t->right->right) >= getHeight(t->right->left)){
            //if(t == mainHead){//changes mainhead REACHES HERE FINE
            //    mainHead = t->right;//SWITCHES BOTH MAINHEAD AND T
            //}
            leftRotation(t);
        }
        else{
            //if(t == mainHead){//changes mainhead
            //    mainHead = t->right->left;
            //}
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

void GraphGenerator::leftRotation(AvlNode * & k1){
    AvlNode *k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1->height = max(getHeight(k1->left),getHeight(k1->right)) + 1;
    k2->height = max(getHeight(k2->right),k1->height) + 1;
    k1 = k2;
    
}

void GraphGenerator::leftRightDoubleRotation(AvlNode * & k3){
    leftRotation(k3->left);
    rightRotation(k3);
}

void GraphGenerator::rightLeftDoubleRotation(AvlNode * & k1){
    rightRotation(k1->right);
    leftRotation(k1);
}

AvlNode* GraphGenerator::getHead(){
    return mainHead;
}



