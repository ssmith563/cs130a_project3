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

    avl.InsertEdge(1,2);
    avl.InsertEdge(2,3);

    avl.PreOrder(avl.getHead());
    
    return 0;
}