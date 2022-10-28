/*
#include <iostream>
#include <windows.h> 
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <wchar.h>
#include <fcntl.h>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <codecvt>
#include <string>
#include <vector>
*/

#include <iostream>
#include <windows.h> 
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <set>
#include <cstdlib>
#include "MyLib.h"

using namespace std;

#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#define DISABLE_NEWLINE_AUTO_RETURN 0x0008

set<int> collectionSet;
pair<int,string> target;
string questionMark = " .----------------.\n | .--------------. |\n | |    ______    | |\n | |   / _ __ `.  | |\n | |  |_/____) |  | |\n | |    /  ___.'  | |\n | |    |_|       | |\n | |    (_)       | |\n | |              | |\n | '--------------' |\n  '----------------' \n";
MyMap Mustreron("Mustreron");
MyMap Stokemere("Stokemere");
MyMap WitchTower("WitchTower");
MyMap Observatory("Observatory");
MyMap PotionsLab("PotionsLab");
MyMap PumpkinGarden("PumpkinGarden");
MyMap DarkForest("DarkForest");
MyMap AppleField("AppleField");
MyMap MagicWaterfall("MagicWaterfall");
MyMap GrimMegalith("GrimMegalith");
MyMap Village("Village");
MyMap Scaffold("Scaffold");
MyMap WaterWell("WaterWell");
MyMap Graveyard("Graveyard");
MyMap Aeria("Aeria");
MyMap Garden("Garden");
MyMap Fountain("Fountain");
MyMap Flowers("Flowers");
MyMap Castle("Castle");
MyMap Tower("Tower");
MyMap ThroneRoom("ThroneRoom");
MyMap Ballroom("Ballroom");
MyMap Shibotsu("Shibotsu");
MyMap Temple("Temple");
MyMap Altar("Altar");
MyMap Backyard("Backyard");
MyMap Skyscraper("Skyscraper");
MyMap WC("WC");
MyMap Laboratory("Laboratory");
MyMap IT_Office("IT_Office");

int main(){
    HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode;
    GetConsoleMode( handleOut, &consoleMode);
    consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    consoleMode |= DISABLE_NEWLINE_AUTO_RETURN;
    SetConsoleMode( handleOut, consoleMode);
    
    MyMap tittle("Tittle");
    string username;
    int x;
    while(true){
        system ("CLS");
        cout<<"\n\n\n";
        tittle.ShowMap();
        cout<<"\n\n\e[34m\t\t\t\t\tType your username: \n\t\t\t\t\t_";
        cin>>username;
        setCollection(username);
        do{
            system ("CLS");
            tittle.ShowMap();
            cout<<"\n\n\e[34m\t\t\t\t\t- Menu -\n";
            cout<<"\t\t\t\t(1) PLAY\n\t\t\t\t(2) Collection\n\t\t\t\t(3) Logout\n\t\t\t\t_";
            cin>>x;
            while(x<=0||x>3){ 
                cout<<"\tComando invalido\n\t\t\t\t_";
                cin>>x;
            }
            system ("CLS");
            if(x==2){ 
                showCollection();
                cout<<"\e[34mPress Enter to return to Main Menu_";
                cin.ignore();
                cin.ignore();
            }
            if(x==1){
                play();
            }
        } while(x!=3);
    }
}

void createProfile(string username){
    ofstream file;
    file.open(username+".txt",ios::app);
    file<<0;
    file.close();
    setCollection(username);
    return;
}

void setCollection(string username){
    ifstream file;
    string text;
    file.open(username+".txt",ios::in);
    if(file.fail()){
        createProfile(username);
        return;
    }
    collectionSet.clear();
    while(!file.eof()){
        getline(file, text);
        collectionSet.insert(stoi(text));
    }
    file.close();
}

void showCollection(){
    ifstream file;
    string text;
    file.open("Collection.txt",ios::in);
    try{
        for(int i=1;i<=19;i++){
            getline(file, text);
            int x = stoi(text);
            if(collectionSet.count(i)>0){
                for(int j=0;j<x;j++){
                    getline(file, text);
                    cout<<"\e[0m"<<text<<"\n";
                }
            }
            else{
                for(int j=0;j<x;j++) getline(file, text);
                cout<<"\e[0m"<<questionMark;
            }
            cout<<"\n";
        }
        file.close();
    }
    catch(MyException &e){
        cout<<e.what()<<endl;
    }
}

void play(){
    target = randomItem();
    cout<<"Target item\n"<<target.second<<"\n";
    int x;
    cin>>x;
    do{
        Mustreron.ShowMap();
        cout<<"\n\n\e[34m\t\t\t\t\t- Menu -\n";
        cout<<"\t\t\t\t(1) Stokemere\n\t\t\t\t(2) Aeria\n\t\t\t\t(3) Shibotsu\n\t\t\t\t(4) Main Menu\n\t\t\t\t_";
        if(x==4) return;
        if(x==1){
            do{
                system("CLS");
                cout<<"Target item\n"<<target.second<<"\n";
                Stokemere.ShowMap();
                cout<<"\n\n\e[34m\t\t\t\t\t- Menu -\n";
                cout<<"\t\t\t\t(1) WitchTower\n\t\t\t\t(2) DarkForest\n\t\t\t\t(3) Village\n\t\t\t\t(4) Mustreron\n\t\t\t\t(5) Main Menu\n\t\t\t\t_";
                if(x==4) break;
                if(x==5) return;
                if(x==1){
                    do{
                        system("CLS");
                        cout<<"Target item\n"<<target.second<<"\n";
                        WitchTower.ShowMap();
                        cout<<"\n\n\e[34m\t\t\t\t\t- Menu -\n";
                        cout<<"\t\t\t\t(1) Observatory\n\t\t\t\t(2) PotionsLab\n\t\t\t\t(3) Village\n\t\t\t\t(4) Main Menu\n\t\t\t\t_";
                        if(x==4) break;
                        if(x==5) return;
                    }while(x<=0||x>=5);
                }
            }while(x<=0||x>=5);
        }
    }while(x<=0||x>=5)
}

pair<int,string> randomItem(){
    string s = "";
    int x;
    do{
        x = rand() % 20+1;
    }while(collectionSet.count(x)>0);
    ifstream file;
    string text;
    file.open("Collection.txt",ios::in);
    try{
        for(int i=1;i<x;i++){
            getline(file, text);
            int x = stoi(text);
            for(int j=0;j<x;j++) getline(file, text);
        }
        getline(file, text);
        int x = stoi(text);
        for(int j=0;j<x;j++){
            getline(file, text);
            s+=text;
            s+="\n";
        }
        file.close();
    }
    catch(MyException &e){
        cout<<e.what()<<endl;
    }
    pair<int,string> p = {x,s};
    return p;
}