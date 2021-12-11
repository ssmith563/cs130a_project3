
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
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
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

