#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <fcntl.h>
#include <map>
#include "MyItem.h"
#include "MyException.h"

using namespace std;

class MyMap{
    private:
        string name;
    public:
        vector<string> submaps;
        vector<string> supermaps;
        MyMap();
        MyMap(string _name);
        void setName(string s);
        void ShowMap();
        const MyMap& operator=(const MyMap &other);
};

MyMap::MyMap(){ name = "default"; }

MyMap::MyMap(string _name){
    name = _name;
}

void MyMap::setName(string s){
    name = s;
}

const MyMap& MyMap::operator=(const MyMap &other){
    this->name = other.name;
    this->submaps = other.submaps;
    this->supermaps = other.submaps;
    return *this; 
}

void MyMap::ShowMap(){
    try{
        ifstream file;
        string text;
        file.open(name+".txt",ios::in);
        while(!file.eof()){
            getline(file, text);
            if(text == "\\n") cout<<"\n";
            else{
                if(isdigit(text[0])) cout<<"\e["<<text<<"m";
                else cout<<text;
            }
        }
        file.close();
        return;
    }
    catch(MyException &e){
        cout<<e.what()<<endl;
    }
}