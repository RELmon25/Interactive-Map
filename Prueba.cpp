/*#include <iostream>
#include <locale>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    wcin.imbue(locale("en_US.UTF-8"));
    wcout.imbue(locale("en_US.UTF-8"));

    wstring s;
    wstring t(L" la Polynésie française");

    wcin >> s;
    wcout << s << t << endl;
    return 0;
}
*/
#include <iostream>
#include <windows.h> 
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <fstream>
#include "MyException.h"

#define _O_U16TEXT 0x00020000
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#define DISABLE_NEWLINE_AUTO_RETURN 0x0008

using namespace std;

void ShowMap(string name){
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

int main(){
    HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode;
    GetConsoleMode( handleOut, &consoleMode);
    consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    consoleMode |= DISABLE_NEWLINE_AUTO_RETURN;
    SetConsoleMode( handleOut, consoleMode);
    //_setmode(_fileno(stdout), _O_U16TEXT);

    ///MAPA

    //top edge
    /*
    wprintf(L"\e[0m\x231c\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x23ba\x231d\n");
    wprintf(L"\e[0m\x23b8\e[38;2;5;220;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[0m\x23b9\n");
    wprintf(L"\e[0m\x23b8\e[38;2;10;210;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[38;5;64m\x2a53\e[38;2;10;210;185m\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[0m\x23b9\n");
    wprintf(L"\e[0m\x23b8\e[38;2;15;200;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[38;5;34m\x2a53\e[38;2;15;200;185m\x22d3\x22d2\e[38;5;64m\x2a53\x2a53\x2a53\e[38;2;15;200;185m\x22d2\x22d3\e[38;5;34m\x2a53\e[38;2;15;200;185m\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\e[38;5;214m\x25b2\e[38;2;15;200;185m\x22d2\x22d3\x22d2\x22d3\e[38;5;90m\x2375\x2375\x2375\e[38;2;15;200;185m\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[0m\x23b9\n");
    wprintf(L"\e[0m\x23b8\e[38;2;20;190;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\e[38;5;34m\x2a53\x2a53\x2a53\e[38;5;64m\x2a53\x2a53\x2a53\x2a53\x2a53\e[38;5;34m\x2a53\x2a53\x2a53\e[38;2;20;190;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\e[38;5;203m\x2588\e[38;2;20;190;185m\x22d2\x22d3\e[38;5;90m\x2375\x2375\e[38;2;20;190;185m\x22d2\x22d3\x22d2\e[38;5;90m\x2375\x2375\e[38;2;20;190;185m\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[0m\x23b9\n");
    wprintf(L"\e[0m\x23b8\e[38;2;25;180;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[38;5;34m\x2a53\x2a53\x2a53\e[38;5;97m\x25b2\e[38;5;34m\x2a53\e[38;5;64m\x2a53\x2a53\x2a53\e[38;5;34m\x2a53\x2a53\x2a53\x2a53\x2a53\e[38;2;25;180;185m\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[38;5;90m\x2375\x2375\e[38;2;25;180;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\e[38;5;90m\x2375\x2375\e[38;2;25;180;185m\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[0m\x23b9\n");
    wprintf(L"\e[0m\x23b8\e[38;2;30;170;185m\x22d2\x22d3\x22d2\x22d3\x22d2\e[38;5;34m\x2a53\x2a53\x2a53\x2a53\e[38;5;97m\x2588\e[38;5;34m\x2a53\x2a53\e[38;2;30;170;185m\x22d2\e[38;5;34m\x2a53\x2a53\x2a53\x2a53\x2a53\x2a53\x2a53\e[38;2;30;170;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[38;5;90m\x2375\x2375\e[38;2;30;170;185m\x22d2\x22d3\x22d2\e[38;5;214m\x2691\e[38;2;30;170;185m\x22d2\e[38;5;203m\x25b2\e[38;2;30;170;185m\x22d3\e[38;5;214m\x2691\e[38;2;30;170;185m\x22d2\x22d3\x22d2\e[38;5;90m\x2375\x2375\e[38;2;30;170;185m\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[0m\x23b9\n");
    wprintf(L"\e[0m\x23b8\e[38;2;35;160;185m\x22d2\x22d3\x22d2\x22d3\e[38;5;34m\x2a53\x2a53\x2a53\x2a53\x2a53\e[38;5;97m\x2588\e[38;5;34m\x2a53\x2a53\x2a53\e[38;2;35;160;185m\x22d3\e[38;5;34m\x2a53\x2a53\x2a53\x2a53\x2a53\x2a53\x2a53\e[38;2;35;160;185m\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\e[38;5;90m\x2375\x2375\e[38;2;35;160;185m\x22d3\x22d2\x22d3\x22d2\e[38;5;203m\x2587\x2584\x2588\x2584\x2587\e[38;2;35;160;185m\x22d2\x22d3\x22d2\x22d3\e[38;5;90m\x2375\x2375\e[38;2;35;160;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[0m\x23b9\n");
    wprintf(L"\e[0m\x23b8\e[38;2;40;150;185m\x22d2\x22d3\x22d2\e[38;5;64m\x2a69\x2a69\x2a69\x2a69\x2a69\x2a69\x2a69\x2a69\x2a69\x2a69\x2a69\e[38;2;40;150;185m\x22d2\x22d3\e[38;5;64m\x2a69\x2a69\x2a69\x2a69\x2a69\x2a69\e[38;2;40;150;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[38;5;90m\x2375\x2375\e[38;2;40;150;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\e[38;5;90m\x2375\x2375\e[38;2;40;150;185m\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[0m\x23b9\n");
    wprintf(L"\e[0m\x23b8\e[38;2;45;140;185m\x22d2\x22d3\x22d2\x22d3\x22d2\e[38;5;64m\x2a69\x2a69\x2a69\x2a69\x2a69\x2a69\x2a69\e[38;5;130m\x23CF\e[38;5;64m\x2a69\x2a69\e[38;2;45;140;185m\x22d3\x22d2\x22d3\e[38;5;64m\x2a69\x2a69\x2a69\e[38;2;45;140;185m\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[38;5;90m\x2375\x2375\e[38;2;45;140;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\e[38;5;90m\x2375\x2375\e[38;2;45;140;185m\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[0m\x23b9\n");
    wprintf(L"\e[0m\x23b8\e[38;2;50;130;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\e[38;5;64m\x2a69\x2a69\x2a69\x2a69\e[38;5;130m\x23CF\e[38;5;64m\x2a69\x2a69\e[38;5;130m\x23CF\e[38;5;64m\x2a69\e[38;2;50;130;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[38;5;90m\x2375\x2375\e[38;2;50;130;185m\x22d2\x22d3\x22d2\e[38;5;90m\x2375\x2375\e[38;2;50;130;185m\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[0m\x23b9\n");
    wprintf(L"\e[0m\x23b8\e[38;2;55;120;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\e[38;5;64m\x2a69\x2a69\x2a69\x2a69\x2a69\x2a69\x2a69\x2a69\x2a69\e[38;2;55;120;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[38;5;90m\x2375\x2375\x2375\e[38;2;55;120;185m\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[0m\x23b9\n");
    wprintf(L"\e[0m\x23b8\e[38;2;60;110;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[0m\x23b9\n");
    wprintf(L"\e[0m\x23b8\e[38;2;65;100;185m\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3\e[0m\x23b9\n");
    //bottom edge
    wprintf(L"\e[0m\x231e\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x23bd\x231f\n");
    return 0;
    */
   string s;
   cin>>s;
   ShowMap(s);
}


///OBJETOS

/*
    //gold fish
    wprintf(L"\e[93m>\x00B0)))\x5F61\e[0m");
    wprintf(L"\n\n");

    //gun
    wprintf(L"\e[90m\x2584\xFE3B\x253B\x2533\x2550\x4E00\e[0m");
    wprintf(L"\n\n");

    //blood dager
    wprintf(L"\e[91m\x25AC\x25AC|\x2550\x2550\x2550\x2550\x25B9\e[0m");
    wprintf(L"\n\n");

    //Crown
    wprintf(L"\e[93m\x25E3\x25B2\x25ED\x25B3\x25FF\n\x203E\x203E\x203E\x203E\x203E\e[0m");
    wprintf(L"\n\n");

    //Magic Wand
    wprintf(L"\e[35m\x2605 \xFF65\xFF61\xFF65\n \x2572\e[0m");
    wprintf(L"\n\n");

    //love letter
    wprintf(L"\e[0m|\x27CD\e[91m\x2661\e[0m\x27CB\x23B9\e[0m");
    wprintf(L"\n\n");


    //Macha tea
    wprintf(L"\e[38;5;210m \x23b5 \e[92m[\x030f_]\xff8c\n\e[38;5;94m\x203E\x203E\x203E\x203E\x203E\x203E\x203E\e[0m");
    wprintf(L"\n\n");


    //Billiard balls
    wprintf(L"\e[0m  (8)\e[38;5;94m\x2572\n\e[91m(3)\e[94m(2)\e[38;5;94m\x2572\e[0m");
    wprintf(L"\n\n");
    

   //Robot Hand
   wprintf(L"\e[90m\x2550\x23e3\x2A74 \x26ac");
   wprintf(L"C\e[0m\n\n");
   */


///EJEMPLO

/*for(int i = 0; i<10; i++){
        //std::cout << "\x1b[38;2;" << 5*i <<";"<<255 -10 * i<<";220m"<<"Hola mundo"<<std::endl;
        wprintf(L"\e[0m\x1b[38;2;%d;%d;220mHola mundo\e[0m\n",5*i,255-10*i);
    }*/

    

/// INTENTOS DE IMPRESION
 /*
    wchar_t x[] = L"\e[38;2;25;180;185m\x22d2\x22d3\e[0m";
    wprintf(L"%ls", x);
    std::wstring st = L"SomeText";
    std::wcout << st;
    */
   /*
   cin>>name;
   ShowMap();
   */

    /*
    std::wstring wstr2;
    wstr2 = readFile("Experimento");
    std::wcout << wstr2;
    */

   /*
    std::wstring st = L"\e[38;2;25;180;185m\x22d2\x22d3\e[0m";
    //std::u16string st = L"\e[38;2;25;180;185m\x22d2\x22d3\e[0m";
    std::wcout << st;
    */
   /*std::wstring readFile(const char* filename)
{
    std::wifstream wif(filename);
    wif.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    std::wstringstream wss;
    wss << wif.rdbuf();
    return wss.str();
}
*/