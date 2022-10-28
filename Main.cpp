#include <iostream>
#include <windows.h> 
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <set>
#include <cstdlib>
#include "MyLib.h"
#include <thread>

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

map<string,MyMap*> mapDirectory;

int main(){
    HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode;
    GetConsoleMode( handleOut, &consoleMode);
    consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    consoleMode |= DISABLE_NEWLINE_AUTO_RETURN;
    SetConsoleMode( handleOut, consoleMode);

    preparar();
    itemManagement();
    
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
                target = randomItem();
                play(Mustreron);
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

void ganaste(){
    collectionSet.insert(target.first);
    MyMap felicidades("Felicidades");
    felicidades.ShowMap();
    cout<<"\n"<<itemtostring<<"\n";
    system("PAUSE");
    return;
}

void preparar(){
    mapDirectory.insert({"Mustreron",&Mustreron});
    mapDirectory.insert({"Stokemere",&Stokemere});
    mapDirectory.insert({"WitchTower",&WitchTower});
    mapDirectory.insert({"Observatory",&Observatory});
    mapDirectory.insert({"PotionsLab",&PotionsLab});
    mapDirectory.insert({"PumpkinGarden",&PumpkinGarden});
    mapDirectory.insert({"DarkForest",&DarkForest});
    mapDirectory.insert({"AppleField",&AppleField});
    mapDirectory.insert({"MagicWaterfall",&MagicWaterfall});
    mapDirectory.insert({"GrimMegalith",&GrimMegalith});
    mapDirectory.insert({"Village",&Village});
    mapDirectory.insert({"Scaffold",&Scaffold});
    mapDirectory.insert({"WaterWell",&WaterWell});
    mapDirectory.insert({"Graveyard",&Graveyard});
    mapDirectory.insert({"Aeria",&Aeria});
    mapDirectory.insert({"Garden",&Garden});
    mapDirectory.insert({"Fountain",&Fountain});
    mapDirectory.insert({"Flowers",&Flowers});
    mapDirectory.insert({"Castle",&Castle});
    mapDirectory.insert({"Tower",&Tower});
    mapDirectory.insert({"ThroneRoom",&ThroneRoom});
    mapDirectory.insert({"Ballroom",&Ballroom});
    mapDirectory.insert({"Shibotsu",&Shibotsu});
    mapDirectory.insert({"Temple",&Temple});
    mapDirectory.insert({"Altar",&Altar});
    mapDirectory.insert({"Backyard",&Backyard});
    mapDirectory.insert({"Skyscraper",&Skyscraper});
    mapDirectory.insert({"WC",&WC});
    mapDirectory.insert({"Laboratory",&Laboratory});
    mapDirectory.insert({"IT_Office",&IT_Office});
    relations();
    return;
}

void relations(){
    Mustreron.addSub("Stokemere");
    Mustreron.addSub("Aeria");
    Mustreron.addSub("Shibotsu");
    Stokemere.addSup("Mustreron");
    Aeria.addSup("Mustreron");
    Shibotsu.addSup("Mustreron");

    Stokemere.addSub("WitchTower");
    Stokemere.addSub("DarkForest");
    Stokemere.addSub("Village");
    WitchTower.addSup("Stokemere");
    DarkForest.addSup("Stokemere");
    Village.addSup("Stokemere");

    WitchTower.addSub("Observatory");
    WitchTower.addSub("PotionsLab");
    WitchTower.addSub("PumpkinGarden");
    Observatory.addSup("WitchTower");
    PotionsLab.addSup("WitchTower");
    PumpkinGarden.addSup("WitchTower");

    DarkForest.addSub("AppleField");
    DarkForest.addSub("MagicWaterfall");
    DarkForest.addSub("GrimMegalith");
    AppleField.addSup("DarkForest");
    MagicWaterfall.addSup("DarkForest");
    GrimMegalith.addSup("DarkForest");

    Village.addSub("Scaffold");
    Village.addSub("WaterWell");
    Village.addSub("Graveyard");
    Scaffold.addSup("Village");
    WaterWell.addSup("Village");
    Graveyard.addSup("Village");

    Aeria.addSub("Garden");
    Aeria.addSub("Castle");
    Aeria.addSub("Fountain");
    Garden.addSup("Aeria");
    Castle.addSup("Aeria");
    Fountain.addSup("Aeria");

    Garden.addSub("Fountain");
    Garden.addSub("Flowers");
    Fountain.addSup("Garden");
    Flowers.addSup("Garden");

    Castle.addSub("Tower");
    Castle.addSub("ThroneRoom");
    Castle.addSub("Ballroom");
    Tower.addSup("Castle");
    ThroneRoom.addSup("Castle");
    Ballroom.addSup("Castle");

    Shibotsu.addSub("Temple");
    Shibotsu.addSub("Skyscraper"); 
    Temple.addSup("Shibotsu");
    Skyscraper.addSup("Shibotsu");

    Temple.addSub("Altar");
    Temple.addSub("Backyard");
    Altar.addSup("Temple");
    Backyard.addSup("Temple");

    Skyscraper.addSub("WC");
    Skyscraper.addSub("Laboratory");
    Skyscraper.addSub("IT_Office");
    WC.addSup("Skyscraper");
    Laboratory.addSup("Skyscraper");
    IT_Office.addSup("Skyscraper");
    return;
}

pair<int,string> randomItem(){
    string s = "";
    int x;
    do{
        x = rand() % 20+1;
    }while(collectionSet.count(x)>0);
    s = itemtostring(x);
    pair<int,string> p = {x,s};
    return p;
}

string itemtostring(int x){
    string s;
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
    return s;
}

void itemManagement(){
    ifstream file;
    string mapa, entero;
    int x;
    file.open("ItemUbication.txt",ios::in);
    try{
        while(!file.eof()){
            getline(file, mapa);
            getline(file,entero);
            x = stoi(entero);
            (*mapDirectory[mapa]).item = x;
            getline(file,entero);
            x = stoi(entero);
            (*mapDirectory[mapa]).ubicacion = x;
            getline(file,entero);
            x = stoi(entero);
            (*mapDirectory[mapa]).maximo = x;
        }
        file.close();
    }
    catch(MyException &e){
        cout<<e.what()<<endl;
    }
}

void play(MyMap visualmap){
    system("CLS");
    cout<<"\e[0mfind this item to add to your collection...\n"<<target.second<<"\n";
    visualmap.ShowMap();
    visualmap.menu();
    int x;
    cin>>x;
    while(x<=0||x>(visualmap.maximo+visualmap.submaps.size()+visualmap.submaps.size()+1)){
        cout<<"\tComando invalido\n\t\t\t\t_";
        cin>>x;
    }
    if(x==visualmap.maximo+visualmap.submaps.size()+visualmap.submaps.size()+1) return;
    if(visualmap.submaps.size()==0){
        if(x == visualmap.ubicacion){
            if(target.first == visualmap.item) ganaste();
            else{
                 cout<<"\n"<<itemtostring(visualmap.item)<<"\n\tNo es lo que estas buscando...\n";
                 cin.ignore();
                 cin.ignore();
            }
        }
        else cout<<"\n\tNo hay nada aqui, intenta otra vez...\n";
    }
    else{
        if(x>visualmap.submaps.size()) play(*mapDirectory[visualmap.supermaps[0]]);
        else play(*mapDirectory[visualmap.submaps[x-1]]);
    }
    return;
}
