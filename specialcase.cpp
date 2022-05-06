#include <iostream>
#include "specialcase.h"

using namespace std;

bool checkstraight(int x, int y, int z){ // check whether the desk have straight or not
    int arr[3] ={x,y,z};
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(arr[i]>arr[j]){
                int temp  =arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    if (arr[0] == 1 && arr[1] == 12 && arr[2] == 13){
        return true;
    }
    if (arr[2] == arr[0]+2 && arr[1] == arr[0]+1){
        return true;
    }
    return false;
}
bool checkflush(int x, int y, int z){ //check whether the desk have flush or not
    if(x == y && x == z){
        return true;
    }
    return false;
}
bool checkthreeofakind(int x,int y,int z){ //check whether the desk have three of a kind or not
    if (x == y && x == z){
        return true;
    }
    return false;
}
bool checkpairs(int x,int y){ // check whether the desk have pair or not
    if (x == y){
        return true;
    }
    return false;
}

bool checkpairsflush(int x,int y){ //check whether the desk have pairs flush or not
    if (x == y){
        return true;
    }
    return false;
}
