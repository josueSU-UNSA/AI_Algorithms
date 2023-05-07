#include<list>
#include<vector>
#include <algorithm>
#include <cassert>


//library to write a txt file
#include<fstream>

const std::string studentName="Josue Gabriel Sumare Uscca";

class Node{
    public:
        std::string name;
        int val;
        Node* m_pChild[2];
        int level;

        Node(std::string name,int val,int level=0){
            this->m_pChild[0]=this->m_pChild[1]=0;
            this->name=name;
            this->val=val;
            this->level=level;
        }
        bool hasChildren(){
            return (this->m_pChild[0] ||this->m_pChild[1]);
        }

        // Node** expand(){
        //     // if(!currentNode)return 0;
        //     if(!(this->hasChildren()))return 0;
            
        //     int countNN=0;
        //     for(int i=0;i<2;i++)
        //         if(this->m_pChild[i])countNN++;

        //     Node ** childsNotNull=new Node*[countNN];
        //     int indexNN=0;

        //     for(int i=0;i<countNN;i++)   
        //         if(this->m_pChild[i])childsNotNull[indexNN++]=this->m_pChild[i];
            
        //     return childsNotNull;
        // }
        std::vector<Node*> expand(){
            

            std::vector<Node*>childrenAvail;
            for(int i=0;i<2;i++) 
                if(this->m_pChild[i])childrenAvail.push_back(this->m_pChild[i]);

            return childrenAvail;
        
        }
};

class Graph{
    public:
        Node* m_pRoot;

        Graph(){
            this->m_pRoot=0;
        }
        void insert(Node* &pAux,std::string name,int value,int level){
            if(!pAux){
                pAux=new Node(name,value,level);
                return;    
            }
            else{
                // pAux=;

                insert(pAux->m_pChild[pAux->val<value],name,value,++level);
            }
            
            // else{
            //     Node *pAux=this->m_pRoot;
            //     Node *pAuxChild=this->m_pRoot;
            //     while(!pAuxChild){
            //         if()
            //     }
            //     pAux->m_pChild[pAux->val<pAuxChild->val]


            // }
        }

        void insert(std::string name,int value){
            insert(this->m_pRoot,name,value,0);
            
            // else{
            //     Node *pAux=this->m_pRoot;
            //     Node *pAuxChild=this->m_pRoot;
            //     while(!pAuxChild){
            //         if()
            //     }
            //     pAux->m_pChild[pAux->val<pAuxChild->val]


            // }
        }
        
        void printPreOrden(Node *pAux){
            if(!pAux)return;
            std::cout<<pAux->name<<" ";
            
            printPreOrden(pAux->m_pChild[0]);
            printPreOrden(pAux->m_pChild[1]);
        }
        void printPreOrden(){
            printPreOrden(this->m_pRoot);
        }

        

        void BFS(Node* start,std::string toFind){
            
            //******************Open file to write BFS**************************:
            std::ofstream bfsFile("BFS_steps.txt");
            assert(bfsFile.is_open());
            //******************************************************************:
            
            bfsFile<<"BFS - Nodo Seleccionado "<<toFind<<"\n";
            bfsFile<<studentName<<"\n"<<"\n";

            int stepNumber=1;
            if(start->name==toFind){
                bfsFile<<"Paso "<<stepNumber<<"\n";
                bfsFile<<start->name<<"->"<<start->name;
                bfsFile.close();
                return;
            }


            std::list<Node*>frontier;//frontier queue
            std::list<Node*>reached;

            frontier.push_back(start);
            reached.push_back(start);

            while(!(frontier.empty())){
                bfsFile<<"Paso "<<stepNumber++<<"\n";
                
                Node *nodeToExpand=frontier.front();

                //*******************printing Froniter**************************** 
                bfsFile<<"frontier = {";
                    for(Node* itFront:frontier){
                        bfsFile<<itFront->name<<" ";
                    }
                bfsFile<<"}"<<"\n";
                //****************************************************************
                
                frontier.pop_front();
                
                std::vector<Node *>childArr=nodeToExpand->expand();
                
                //*******************printing Reached**************************** 
                bfsFile<<"reached = {";
                for(Node* itReached:reached){
                    bfsFile<<itReached->name<<" ";
                    
                }
                bfsFile<<"}"<<"\n";
                //****************************************************************


                for(Node* child:childArr){
                    if(child->name==toFind){
                        bfsFile<<"------------------------------------------------------------------------------"<<"\n";

                        bfsFile<<"\n"<<nodeToExpand->name<<"->"<<child->name<<"\n";
                        bfsFile.close();
                        return;
                    }
                    auto it=std::find(reached.begin(), reached.end(), child);
                    if(it==reached.end()){
                        reached.push_back(child);
                        frontier.push_back(child);
                    }
                }
                bfsFile<<"------------------------------------------------------------------------------"<<"\n";
                // for ()
                
                
                
                

            }
            
            bfsFile<<"Failure";
            bfsFile.close();
            return;







        }
        // void printListNodes(){
        //     std::list<Node*>nodesList;//frontier queue
            
        //     Node *pAux=this->m_pRoot;
        //     while(pAux){
        //         nodesList.push_back(pAux);
        //         pAux=pAux->m_pChild[0];
        //     }
        //     for(auto it:nodesList){
        //         std::cout<<it->name<<"->";
        //     }
        //     std::cout<<"\n";
            

        // }
        void BFS(std::string start,std::string toFind){
            

        }
        void DFS(Node* start,std::string toFind){
            
            //******************Open file to write BFS**************************:
            std::ofstream dfsFile("DFS_steps.txt");
            assert(dfsFile.is_open());
            //******************************************************************:
            
            dfsFile<<"DFS - Nodo Seleccionado "<<toFind<<"\n";
            dfsFile<<studentName<<"\n"<<"\n";

            int stepNumber=1;
            if(start->name==toFind){
                dfsFile<<"Paso "<<stepNumber<<"\n";
                dfsFile<<start->name;
                dfsFile.close();
                return;
            }


            std::list<Node*>frontier;//frontier queue
            std::list<Node*>reached;

            frontier.push_back(start);
            reached.push_back(start);

            while(!(frontier.empty())){
                dfsFile<<"Paso "<<stepNumber++<<"\n";
                
                Node *nodeToExpand=frontier.front();
                std::vector<Node *>childArr=nodeToExpand->expand();
                

                //*******************printing Froniter**************************** 
                dfsFile<<"frontier = {";
                    for(Node* itFront:frontier){
                        dfsFile<<itFront->name<<"("<<(-1*itFront->level)<<") ";
                    }
                dfsFile<<"}"<<"\n";
                //****************************************************************
                frontier.pop_front();
                //*******************printing Reached**************************** 
                dfsFile<<"reached = {";
                for(Node* itReached:reached){
                    dfsFile<<itReached->name<<"("<<(-1*itReached->level)<<") ";
                    
                }
                dfsFile<<"}"<<"\n";
                //****************************************************************
                dfsFile<<"------------------------------------------------------------------------------"<<"\n";

                //IF PROBLEM IS GOAL
                if(nodeToExpand->name==toFind){

                    dfsFile<<"Paso "<<stepNumber++<<"\n";

                    //*******************printing Froniter**************************** 
                    dfsFile<<"frontier = {";
                    for(Node* itFront:frontier){
                        dfsFile<<itFront->name<<"("<<(-1*itFront->level)<<") ";
                    }
                    dfsFile<<"}"<<"\n";
                    //****************************************************************
                    frontier.pop_front();
                    //*******************printing Reached**************************** 
                    dfsFile<<"reached = {";
                    for(Node* itReached:reached){
                        dfsFile<<itReached->name<<"("<<(-1*itReached->level)<<") ";

                    }
                    dfsFile<<"}"<<"\n";






                    dfsFile<<nodeToExpand->name<<"\n";
                    dfsFile<<"------------------------------------------------------------------------------"<<"\n";
                    dfsFile.close();
                    return;
                }

                auto it=std::find(reached.begin(), reached.end(), nodeToExpand);
                if(it==reached.end()){
                    reached.push_back(nodeToExpand);
                }

                // for (std::list<Node*>::reverse_iterator child = childArr.rbegin(); child != childArr.rend(); child++)
                // for(Node* child:childArr){
                for (auto child = childArr.rbegin(); child != childArr.rend(); child++){
                    auto itChild=std::find(reached.begin(), reached.end(), (*child));
                    if(itChild==reached.end()){
                        frontier.push_front(*child);
                    }
                    // if((*child)->name==toFind){

                    //     dfsFile<<nodeToExpand->name<<"->"<<(*child)->name<<"\n";
                    //     dfsFile<<"------------------------------------------------------------------------------"<<"\n";

                    //     dfsFile.close();
                    //     return;
                    // }
                    // auto it=std::find(reached.begin(), reached.end(), child);
                    // if(it==reached.end()){
                    //     reached.push_back(*child);
                    //     frontier.push_back(*child);
                    // }
                }
                // for ()
                
                
                
                

            }
            
            dfsFile<<"Failure";
            dfsFile.close();
            return;







        }
};