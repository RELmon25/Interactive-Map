#include <map>
#include <string>
#include <vector>
#include "MyMap.h"

using namespace std;

class Menu{
    private:
        MyMap* mapa;
        vector<MyMap*> options;
    public:
    Menu(MyMap* _mapa){ setMap(_mapa); }
    void setMap(MyMap* _mapa){
        options.clear();
        mapa = _mapa;
        options = (*mapa).submapas;
    }
    bool Display(){
        (*mapa).ShowMap();
        cout<<"\n\n\e[34m\t\t\t\t\t- Menu -\n";
        for(int i=0; i<options.size();i++){
            cout<<"\t\t\t\t("<<i+1<<") -> "<<(*options[i]).name<<"\n";
        }
        if(!(*mapa).isorphan()){ 
            options.push_back((*mapa).padre);
            cout<<"\t\t\t\t("<<options.size()<<") <- "<<(*options.front()).name<<"\n";
        }
        cout<<"\t\t\t\t("<<options.size()+1<<") Return to Main Menu\n\t\t\t\t_";
        int x;
        cin>>x;
        while(x<=0||x>options.size()+1){
            cout<<"\tComando invalido\n";
            cin>>x;
        }
        if(x == options.size()+2) return false;
        else{
            setMap(options[x-1]);
        }
    }
    ~Menu(){}
    const Menu& operator=(const Menu &other){
        this->mapa = other.mapa;
        this->options = other.options;
        return *this; 
    }
};