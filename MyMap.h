#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <fcntl.h>
#include <map>
#include "MyException.h"

using namespace std;

class MyMap{
    public:
        string name;
        vector<string> submaps;
        vector<string> supermaps;
        int maximo;
        int ubicacion;
        int item;
/*
        MyMap();
        MyMap(string _name);
        void setName(string s);
        void ShowMap();
        const MyMap& operator=(const MyMap &other);
        void menu();
        void addSub(string);
        void addSup(string);
};

MyMap::MyMap(){ name = "default"; item = -1; maximo = 0; ubicacion = 0; }

MyMap::MyMap(string _name){
    name = _name;
    item = -1;
    maximo = 0;
    ubicacion = 0;
}

void MyMap::setName(string s){
    name = s;
}

const MyMap& MyMap::operator=(const MyMap &other){
    this->name = other.name;
    this->submaps = other.submaps;
    this->supermaps = other.submaps;
    this->maximo = other.maximo;
    this->ubicacion = other.ubicacion;
    this->item = other.item;
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

void MyMap::menu(){
    cout<<"\n\n\e[34m\t\t\t\t\t- Menu -\n";
    for(int i=1;i<=maximo;i++){
        cout<<"\t\t\t\t("<<i<<") \n";
    }
    for(int i=0;i<submaps.size();i++){
        cout<<"\t\t\t\t("<<i+1<<") "<<submaps[i]<<"\n";
    }
    for(int i=0;i<supermaps.size();i++){
        cout<<"\t\t\t\t("<<i+1+submaps.size()<<") "<<supermaps[i]<<"\n";
    }
    cout<<"\t\t\t\t("<<submaps.size()+supermaps.size()+maximo+1<<") Menu Inicial\n";
}

void MyMap::addSub(string s){
    this->submaps.push_back(s);
}
void MyMap::addSup(string s){
    this->supermaps.push_back(s);
}
*/
    MyMap(){ name = "default"; item = -1; maximo = 0; ubicacion = 0; }

    MyMap(string _name){
        name = _name;
        item = -1;
        maximo = 0;
        ubicacion = 0;
    }

    void setName(string s){
        name = s;
    }

    const MyMap& operator=(const MyMap &other){
        this->name = other.name;
        this->submaps = other.submaps;
        this->supermaps = other.submaps;
        this->maximo = other.maximo;
        this->ubicacion = other.ubicacion;
        this->item = other.item;
        return *this; 
    }


    void ShowMap(){
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

    void menu(){
        cout<<"\n\n\e[34m\t\t\t\t\t- Menu -\n";
        for(int i=1;i<=maximo;i++){
            cout<<"\t\t\t\t("<<i<<") \n";
        }
        for(int i=0;i<submaps.size();i++){
            cout<<"\t\t\t\t("<<i+1+maximo<<") "<<submaps[i]<<"\n";
        }
        for(int i=0;i<supermaps.size();i++){
            cout<<"\t\t\t\t("<<i+1+submaps.size()+maximo<<") "<<supermaps[i]<<"\n";
        }
        cout<<"\t\t\t\t("<<submaps.size()+supermaps.size()+maximo+1<<") Menu Inicial\n";
    }

    void addSub(string s){
        this->submaps.push_back(s);
    }
    void addSup(string s){
        this->supermaps.push_back(s);
    }
};
