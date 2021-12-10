
#include <iostream>
#include <string>
#include "GraphOperator.h"


using namespace std;

bool GraphOperator::IsAclyclic(GraphGenerator graph){
    int visited[graph.getTotalNodes()]= {0};
    int a[graph.getTotalNodes()];
    int d[graph.getTotalNodes()];
    int time = 0;

    DFS(graph, graph.getHead(), a, d, visited, time);

    for(int i = 0; i < graph.getTotalNodes(); i++){
        cout<<visited[i]<<" ";
    }
    cout<<"\n";

    for(int i = 0; i < graph.getTotalNodes(); i++){
        if(visited[i] > 2){
            return true;
        }
    }

    

    return false;
}

void GraphOperator::DFS(GraphGenerator graph, AvlNode* pointNode, int* a, int* d, int* visited, int time){
    visited[pointNode->head->data -1] = 1;
    a[pointNode->head->data -1] = time++;
    //bool cycle = false;

    Node* pointer = pointNode->head->next;
    while(pointer != nullptr){
        if(visited[pointer->data -1] == 0){
            DFS(graph, graph.Lookup(pointer->data), a, d, visited, time);
        }
        else{
            visited[pointer->data -1]++;
        }

        pointer = pointer->next;
    }

    d[pointNode->head->data -1] = time++;
}

void GraphOperator::ConnectedComponents(GraphGenerator graph){

}
