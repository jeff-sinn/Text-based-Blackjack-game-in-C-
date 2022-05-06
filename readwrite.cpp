//readwrite.cpp

#include <fstream>
#include <iostream>
#include "readwrite.h"

using namespace std;

int readinfile(){
    int token;
    char filename[30] = "token.txt";
    ifstream fin;
    fin.open(filename);
    if (fin.fail()){
        cout << "Error in the file opening" << endl;
        exit(1);
    }
    fin >> token;
    fin.close();
    return token;
}

void writetofile(int token, int result){
    if (result == 1){
        token += 1;
        cout << "gain 1 token" << endl;
    }
    else if (result == 0){
        token -= 1;
        cout << "lose 1 token" << endl;
    }
    else{
    }
    if (token < 3){
        token = 20;
        cout << "token reset to 20 since token is lower than 3" << endl;
    }
    ofstream fout;
    fout.open("token.txt");
    if (fout.fail()){
        cout << "Error in the file opening!" << endl;
        exit(1);
    }
    fout << token << endl;
    fout.close();

}
