#include <iostream>
//#include "ASearch.h"
using namespace std;

int main(){
    
    //ASearch rompecabeza("2831647 5","123 84765");
    //rompecabeza.printFS();
    string swapCharExample="123456789 ";
    cout<<"BEFORE"<<endl;
    for(char it:swapCharExample){
        if(it==' '){
            cout<<"B";
            continue;
        }


        cout<<it;
    }
    cout<<endl;
    swap(swapCharExample[1],swapCharExample[swapCharExample.size()-1]);
    cout<<"AFTER"<<endl;
    for(char it:swapCharExample){
        if(it==' '){
            cout<<"B";
            continue;
        }
        cout<<it;

    }
    cout<<endl;
    return 0;
}