
#include <iostream>
#include <string>
#include "GraphOperator.h"
#include <list>


using namespace std;

GraphOperator::GraphOperator(){

}

void GraphOperator::PrintConnectedComponents(GraphGenerator graph){
    int* arr = ConnectedComponents(graph);
    for(int i = 0; i < graph.getTotalNodes(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int* GraphOperator::ConnectedComponents(GraphGenerator graph){
    int* componentArr = new int[graph.getTotalNodes()];

    componentArr = {0};
    int componentNum = 1;

    for(int i = 0; i < graph.getTotalNodes(); i++){
        if(componentArr[i] == 0){
            AvlNode* avlPointer = graph.Lookup(i+1);
            BFS(graph, avlPointer, componentNum, componentArr);
            componentNum++;
        }
    }

    return componentArr;
}

void GraphOperator::BFS(GraphGenerator graph, AvlNode* avlNodePointer, int component, int* componentArr){
    //Node* pointer = avlNodePointer->head->next;

    int* visited = new int[graph.getTotalNodes()];
    visited = {0};

    list<int> queue;
    queue.push_back(avlNodePointer->head->data);

    visited[avlNodePointer->head->data -1] = 1;
    componentArr[avlNodePointer->head->data -1] = component;

    int s;

    /* while(pointer != nullptr){


        pointer = pointer->next;
    } */


    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (Node* pointer = graph.Lookup(s)->head->next; pointer != nullptr; pointer = pointer->next)
        {
            if (visited[pointer->data -1] == 0)
            {
                visited[pointer->data -1] = 1;
                componentArr[pointer->data -1] = component;
                queue.push_back(pointer->data);
            }
        }
    }
}

bool GraphOperator::IsAclyclic(GraphGenerator graph){
    int visited[graph.getTotalNodes()];
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
