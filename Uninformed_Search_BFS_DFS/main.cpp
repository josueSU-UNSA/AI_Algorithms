#include<iostream>


//File to use mi class Graph 
#include "Graph.h"
#include<vector>
using namespace std;




int main(){
    string dptos[17]={"PUN","CUZ","AYA","TRUJ","AQP","APUR","ICA","LIM","CAJ","MDD","TUMB","PUC","UCA","CHI","SMP","CALL","TAC"};
    int vals[17]={200,80,800,40,100,400,2000,30,50,90,150,300,500,1200,5000,15,140};
    
    Graph treeRoutes;

    int nodesNumb=sizeof(dptos)/sizeof(dptos[0]);
    for (int i=0;i<nodesNumb;i++){
        treeRoutes.insert(dptos[i],vals[i]);
    }

    treeRoutes.BFS(treeRoutes.m_pRoot,"CALL");

    



    // treeRoutes.DFS(treeRoutes.m_pRoot,"TAC");
    

    string vocales[10]={"F","D","K","B","E","G","L","A","C","H"};
    int indeces[10]={2000,600,5000,300,700,3000,10000,50,400,2500};

    // Graph exampleDFS;
    // for(int i=0;i<10;i++){
        // exampleDFS.insert(vocales[i],indeces[i]);
    // }
// 
    // exampleDFS.DFS(exampleDFS.m_pRoot,"H");
    treeRoutes.DFS(treeRoutes.m_pRoot,"TAC");

    return 0;
}