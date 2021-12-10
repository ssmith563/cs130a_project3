#include <iostream>

using namespace std;

#include "GraphGenerator.h"
#include "GraphGenerator.cpp"
#include "GraphOperator.h"
#include "GraphOperator.cpp"
#include <fstream>

int main(int argc,char* argv[])//int argc,char* argv[]
{

    GraphGenerator avl;

    /* avl.InsertEdge(8,10);
    avl.InsertEdge(3,4);
    avl.InsertEdge(1,9);
    avl.InsertEdge(3,2);
    avl.InsertEdge(7,6);
    avl.InsertEdge(10,6);
    avl.InsertEdge(6,5);
    avl.InsertEdge(9,2);
    avl.InsertEdge(2,4);
    avl.InsertEdge(10,5);
    avl.InsertEdge(1,2);
    avl.InsertEdge(7,8); */

    avl.InsertEdge(1,2);
    avl.InsertEdge(2,3);
    avl.InsertEdge(3,4);
    //avl.InsertEdge(4,2);

    avl.PreOrder(avl.getHead());

    cout<<"\n";

    avl.InOrder(avl.getHead());

    cout<<"\n";

    GraphOperator op;

    cout<<op.IsAclyclic(avl);
    
    return 0;
}