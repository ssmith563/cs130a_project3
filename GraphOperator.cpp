
#include <iostream>
#include <string>
#include "GraphOperator.h"
#include <list>


using namespace std;

GraphOperator::GraphOperator(){

}

void GraphOperator::PrintConnectedComponents(GraphGenerator graph){
    int* arr = ConnectedComponents(graph);

    int max = arr[0];
    

    for(int k = 1; k < graph.getTotalNodes(); k++){
        if (arr[k] > max){
            max = arr[k];
        }
    }

    

    for(int j = 1; j <= max; j++){
        for(int i = 0; i < graph.getTotalNodes(); i++){
            if(arr[i] == j){
                cout<<i+1<<" ";
            }
        }
        cout<<"\n";
    }


    
}

int* GraphOperator::ConnectedComponents(GraphGenerator graph){
    int* componentArr = new int[graph.getTotalNodes()];
    
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

    list<int> queue;
    queue.push_back(avlNodePointer->head->data);
    componentArr[avlNodePointer->head->data -1] = component;

    int s;

    while(!queue.empty())
    {
  
        s = queue.front();
        queue.pop_front();

        Node* pointer = graph.Lookup(s)->head->next;
        while (pointer != NULL)
        {
            if(componentArr[pointer->data -1] == 0)
            {
                componentArr[pointer->data -1] = component;
                queue.push_back(pointer->data);
            }
            pointer=pointer->next;
        }
    }
}

void GraphOperator::PrintIsAcyclic(GraphGenerator graph){
    if(IsAclyclic(graph)){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
    }
}

bool GraphOperator::IsAclyclic(GraphGenerator graph){
    int* visited = new int[graph.getTotalNodes()];
    //int visited[graph.getTotalNodes()];
    int a[graph.getTotalNodes()];
    int d[graph.getTotalNodes()];
    int time = 0;

    int* arr = ConnectedComponents(graph);
    int max = arr[0];
    for(int k = 1; k < graph.getTotalNodes(); k++){
        if (arr[k] > max){
            max = arr[k];
        }
    }

    AvlNode* pred = nullptr;
    bool* cycle =new bool(false);

   

    for(int j = 1; j <= max; j++){
        for(int i = 0; i < graph.getTotalNodes(); i++){
            if(arr[i] == j){
                DFS(graph, graph.Lookup(i+1), visited, pred, cycle);
                break;
            }
        }
    }

    

    return *cycle;
}

void GraphOperator::DFS(GraphGenerator graph, AvlNode* pointNode, int* visited, AvlNode* pred, bool* &cycle){
    visited[pointNode->head->data -1] = 1;
    //a[pointNode->head->data -1] = time++;
    //bool cycle = false;

    Node* pointer = pointNode->head->next;
    
    
    while(pointer != nullptr){
        if(visited[pointer->data -1] == 0){
            DFS(graph, graph.Lookup(pointer->data), visited, pointNode, cycle);
        }
        else if(pred != nullptr && pointer->data != pred->head->data){
            *cycle = true;
        }

        pointer = pointer->next;
    }

    //d[pointNode->head->data -1] = time++;
}

