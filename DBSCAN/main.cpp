#include<iostream>
#include<cmath>

#include<utility>
#include<vector>

#include<assert.h>

#include<fstream>
using namespace std;
//DBSCAN algorithm
//function DBSCAN(X(set of points), eps(radius) , minpts(min number points near) )
//  for each unvisited
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

//We store 100 points
const int nPoints=100;

bool fillVector(std::vector<std::pair<double,double>> &vectorToFill){
    std::ifstream filePoints;
            
    filePoints.open("points.txt");
    if(!(filePoints.is_open())){
        std::cout<<"The file of points couldn't be opened"<<std::endl;
        return false;
    }

    int count=0;

    // std::cout<<"Starting the print of points"<<std::endl<<std::endl;
            
    //Iteramos linea por linea , cada linea consta de coordenadas
    // X e Y
    std::string coordinateDouble="";
    while(!(filePoints.eof())){
                
        char sign;
        filePoints>>sign;


        if(sign=='\n' )continue;
        
        if(sign=='[')continue;
        if(sign==','){

            //here insert in the first point
            
            // std::cout<<"FIRST"<<std::endl;
            // std::cout<< coordinateDouble<<" -> ";

            vectorToFill[count].first=std::stod(coordinateDouble);
            
            coordinateDouble="";
        }

        else if(sign==']'){

            //here insert in the second point
            
            //this->mPoints[count].second=std::stod(coordinateDouble);
                    
                    

            //Here we display the X and Y points
            //std::cout<< this->mPoints[count].first<<" , "<<this->mPoints[count].second<<std::endl;
            
            // std::cout<<"SECOND"<<std::endl;
                
            if(coordinateDouble!=""){ 
                        

                // std::cout<< coordinateDouble<<std::endl;
                // std::cout<<"FINISHEd"<<std::endl;
                vectorToFill[count].second=std::stod(coordinateDouble);

                count++;
                    
            }
                    
            coordinateDouble="";
                    
            //count++;

        }

        else {
            coordinateDouble+=sign;
        }

                
        }


        filePoints.close();

        return true;
}


void printVector(std::vector<std::pair<double,double>> vectorToPrint){
    for (int i=0;i<vectorToPrint.size();i++){
        cout<<i+1<<". "<<"("<<vectorToPrint[i].first<<", "<<vectorToPrint[i].second<<")"<<endl;
    }
    cout<<endl;
}

void printPoint(std::pair<double,double> point){
    
    cout<<"("<<point.first<<", "<<point.second<<")"<<endl;
    
    
}



//THIS WORKS WELL
double euclidianDistance(std::pair<double,double>point1,std::pair<double,double>point2){
    return std::pow(std::pow((point1.first-point2.first),2)+std::pow((point1.second-point2.second),2)   ,0.5);
}




//Function which get us the all neighbors of a point
//This means the all points what are returned are
//the enougly close to be considered as a neighbour 

//THIS WORKS WELL
std::vector<std::pair<double,double>> getNeighbors(std::vector<std::pair<double,double>> allPoints,std::pair<double,double> x,double epsilon){
    
    std::vector<std::pair<double,double>> neighbors;

    for(int i=0;i<allPoints.size();i++){
        //Si el punto dentro esta en el radio de epsilon del punto x
        //es vecino
        if(euclidianDistance(allPoints[i],x)<=epsilon && euclidianDistance(allPoints[i],x)!=0 ){
            neighbors.push_back(allPoints[i]);
            

        }

    }

    return neighbors;
    

    
}


void DBSCAN(std::vector<std::pair<double,double>> X, double epsilon,int minPts){
    
    //vector of visited points
    std::vector<bool> visited(X.size(),false);

    for(int i=0;i<X.size();i++){
        //this means the point is not visited
        if(!(visited[i])){
            
            visited[i]=true;//Mark x as visited
            

        }
    }





}








//OJO CUANDO ES CLASIFICADO COMO RUIDO SIMPLEMENTE
//NO ENTRA EN NINGUN CLUSTER 
//ES UN RUIDO ALGO Q NO DEBERIA SER CONSIDERADO
int main(){
    
    
    //******************Create the vector wich store the all points****************
    //*********************************************************************************
    std::vector<std::pair<double,double>>vectorPoints(nPoints);

    //*********************************************************************************
    //*********************************************************************************
    
    
    //******************Definition of parameters as epsilon and minPts****************
    //*********************************************************************************
    const double epsilon= 0.75;
    const int minPts=2;


    cout<<"Parámetros"<<endl; 
    cout<<"epsilon "<<epsilon<<endl;
    cout<<"minPts "<<minPts<<endl;

    //*********************************************************************************
    //*********************************************************************************

    //******************Filling the vector of points****************
    //*********************************************************************************
    if(fillVector(vectorPoints)){
        printVector(vectorPoints);
    }
    else{
        cout<<"The vector couldn't be filled"<<endl;
    }
    //*********************************************************************************
    //*********************************************************************************



    //***********************HERE WE TESTED  NEIGHBORS**************************
    //*********************************************************************************

    cout<<"Everything is ok"<<endl;
    
    //*********************************************************************************
    //*********************************************************************************

    return 0;
}