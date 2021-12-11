#include <iostream>

using namespace std;

#include "GraphGenerator.h"
#include "GraphGenerator.cpp"
#include "GraphOperator.h"
#include "GraphOperator.cpp"
#include <fstream>
#include <sstream>

int main(int argc,char* argv[])//int argc,char* argv[]
{
    
    GraphGenerator avl;

    GraphOperator op;


    ifstream inFile1;
    inFile1.open( argv[1] );

    string line;
    string num1;
    string num2;
    
    while ( getline(inFile1,line) )
    {
        /* stringstream linestream(line);
        while(linestream.good()){
            getline(linestream, num1, ',');
            getline(linestream, num2, ',');
        }
        int number1 = stoi(num1);
        int number2 = stoi(num2);

        avl.InsertEdge(number1,number2); */

        cout<<line<<"\n";
    }
    inFile1.close();

    avl.InsertEdge(1,2);
    avl.InsertEdge(3,2);

    avl.InOrder(avl.getHead());

    cout<<"\n";

    avl.PreOrder(avl.getHead());

    cout<<"\n";

    cout<<"Components: \n";

    op.PrintConnectedComponents(avl);

    cout<<"Is Acyclic: \n";
    
    op.PrintIsAcyclic(avl);
    
    return 0;
}