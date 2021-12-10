#ifndef GRAPHOPERATOR_H
#define GRAPHOPERATOR_H

#include "GraphGenerator.h"
#include <string>

class GraphOperator
{

    public:

    bool IsAclyclic(GraphGenerator graph);

    void ConnectedComponents(GraphGenerator graph);

    void DFS(GraphGenerator graph, AvlNode* pointNode, int* a, int* d, int* visited, int time);

};

#endif