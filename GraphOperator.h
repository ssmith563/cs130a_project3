#ifndef GRAPHOPERATOR_H
#define GRAPHOPERATOR_H

#include "GraphGenerator.h"
#include <string>

class GraphOperator
{

    public:

    GraphOperator();

    void PrintConnectedComponents(GraphGenerator graph);

    int* ConnectedComponents(GraphGenerator graph);

    void BFS(GraphGenerator graph, AvlNode* avlNodePointer, int component, int* componentArr);

    void PrintIsAcyclic(GraphGenerator graph);

    bool IsAclyclic(GraphGenerator graph);

    void DFS(GraphGenerator graph, AvlNode* pointNode, int* a, int* d, int* visited, int time);
};

#endif
