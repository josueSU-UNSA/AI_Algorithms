#include<list>
#include<iostream>

#include<string>
#include<list>
#include <algorithm>



#if !defined(ASEARCH_H)
#define A_SEARCH_H

bool compararNode(const Node& a, const Node& b);

class Node{
    public:
        Node *mFather;
        std::string mPuzzleArr;
        int mG;
        int mH;
        int mF;
        std::list<Node*> mChild;




    //Initial state:
    //[2,8,3,1,6,4,7, ,5]
    public:
        
        Node(std::string PuzzleArr,int G,int H){
            this->mPuzzleArr=PuzzleArr;
            this->mG=G;
            this->mH=H;
            this->mF=G+H;
            this->mFather=0;
        }
        
        void expand(){
            int posBlank=0;
            for (;posBlank<this->mPuzzleArr.size();posBlank++)
                if(this->mPuzzleArr[posBlank]==' ')break;

            std::string father;
            (this->mFather)?father=this->mFather->mPuzzleArr:father="";

            std::list<int> indexSwap;

            switch (posBlank)
            {
            case 0:
                indexSwap.push_back(1);
                indexSwap.push_back(3);
                
                break;
            case 1:
                indexSwap.push_back(0);
                indexSwap.push_back(2);
                indexSwap.push_back(4);
                

                break;
            case 2:
                indexSwap.push_back(1);
                indexSwap.push_back(5);

                break;
            
            case 3:
                indexSwap.push_back(0);
                indexSwap.push_back(4);
                indexSwap.push_back(6);
                

                break;
            case 4:
                indexSwap.push_back(1);
                indexSwap.push_back(3);
                indexSwap.push_back(5);
                indexSwap.push_back(7);


                break;
            case 5:
                indexSwap.push_back(2);
                indexSwap.push_back(4);
                indexSwap.push_back(8);


                break;
            
            case 6:
                indexSwap.push_back(3);
                indexSwap.push_back(7);
                break;
            case 7:
                
                indexSwap.push_back(4);
                indexSwap.push_back(6);
                indexSwap.push_back(8);
                break;
            case 8:
                
                indexSwap.push_back(5);
                indexSwap.push_back(7);
                break;
            default:
                break;
            }

            for (int it:indexSwap){
                std::string auxChildren=this->mFather->mPuzzleArr;
                std::swap(auxChildren[posBlank],auxChildren[it]);
                if(auxChildren!=father){
                    this->mChild.push_back(new Node(auxChildren,this->mG+1,0));
                }


            }
        
        }
        
        


};
bool compararNode(const Node& a, const Node& b) {
    return a.mF < b.mF;
}
// openList.sort(compararNode);

void A_Search(std::string ){

}
     
//class ASearch{
//    public:
//        std::string mInitialState;
//        std::string mFinalState;
//        
//        Node *mNodeInitialState;     
//
//
//    public:
//        ASearch(std::string initialState,std::string FinalState){
//            this->mNodeInitialState=0;
//            
//            this->mInitialState=initialState;
//            this->mFinalState=FinalState;
//        }
//        void printFS(){
//            for (int i=0;i<this->mFinalState.size();i++){
//                //for (int i=0;i<3;i++){
//                std::cout<<this->mFinalState[i]<<" ";
//                if(!((i+1)%3))std::cout<<std::endl;
//
//
//
//            }
//        }
//        
//        void expand(Node* nodeToExpand){
//            
//            
//
//
//        }
//
//};


#endif // MACRO



// Priority queue sort in ascendent of objects
// #include <iostream>
// #include <queue>
// 
// using namespace std;
// 
// class Objeto {
// public:
    // int valor;
    // Objeto(int v) : valor(v) {}
// };
// 
// struct compararObjetos {
    // bool operator()(const Objeto& a, const Objeto& b) const {
        // return a.valor > b.valor;
    // }
// };
// 
// int main() {
    // priority_queue<Objeto, vector<Objeto>, compararObjetos> q;
// 
    // q.push(Objeto(3));
    // q.push(Objeto(1));
    // q.push(Objeto(4));
    // q.push(Objeto(1));
    // q.push(Objeto(5));
// 
    // while (!q.empty())
    // {
        // cout << q.top().valor << " ";
        // q.pop();
    // }
// 
    // return 0;
// }
// 