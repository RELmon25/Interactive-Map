/*
#include <locale>
#include <codecvt>
#include <fstream>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <windows.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;


#define _O_U16TEXT 0x00020000
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#define DISABLE_NEWLINE_AUTO_RETURN 0x0008
*/

/*
void escritura(string nombre){
    wofstream archivo;
    wstring text;

    archivo.open(nombre,ios::app);

    if(archivo.fail()){
        cout<<"El archivo no se puede abrir"<<endl;
    }

    fflush(stdin);

    text = L"\x22d2\x22d3\nHOLA";

    archivo<<text<<endl;

    archivo.close();

    return;
}
*/

/*

vector<string> vec;

void escritura(string nombre){
    ofstream archivo;
    string text;

    archivo.open(nombre,ios::app);

    if(archivo.fail()){
        cout<<"El archivo no se puede abrir"<<endl;
    }

    fflush(stdin);

    text = "\\e[38;2;25;180;185mHOLA\\n";

    archivo<<text<<endl;

    archivo.close();

    return;
}

void lectura(string nombre){
    ifstream archivo;
    string text;

    archivo.open(nombre,ios::in);

    while(!archivo.eof()){
        getline(archivo, text);
        vec.push_back(text);
    }

    archivo.close();

    return;
}
*/

/*
#include <iostream>
#include <sstream>
#include <fstream>
#include <codecvt>

std::wstring readFile(const char* filename)
{
    std::cout<<"Ok\n";
    std::wifstream wif(filename);
    wif.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t>));
    std::wstringstream wss;
    wss << wif.rdbuf();
    return wss.str();
}
*/

/*

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <codecvt>
#include <sstream>

using namespace std;

void lectura(wstring nombre){
    wifstream archivo;
    wstring text;

    archivo.open(nombre,ios::in);

    while(!archivo.eof()){
        getline(archivo, text);
        wcout<<text<<"\n";
    }

    archivo.close();

    return;
}

int main()
{
    /*
    const std::locale utf8_locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
    wofstream f(L"sample.txt");
    f.imbue(utf8_locale);
    f << L"\u263b我是美国人。我叫马克。" << endl;
    */
   /*
    HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode;
    GetConsoleMode( handleOut, &consoleMode);
    consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    consoleMode |= DISABLE_NEWLINE_AUTO_RETURN;
    SetConsoleMode( handleOut, consoleMode);
    _setmode(_fileno(stdout), _O_U16TEXT);
    */

    //escritura("HolaMundo");
    /*
    lectura("HolaMundo");
    for(int i=0;i<vec.size();i++){
        for(int j=0; j<vec[i].size(); j++)
        cout<<vec[i][j];
    }
    */
   /*
    wstring nom = L"Experimento.txt";
    lectura(nom);
    */
//}

/*

#include <fstream>
#include <codecvt>
#include <iostream>
#include <clocale>
#ifdef _WIN32
#include <fcntl.h>
#include <io.h>
#endif
#define _O_WTEXT 0x10000
int main()
{
    std::ifstream f("test.txt");
    std::wbuffer_convert<std::codecvt_utf8<wchar_t>> conv(f.rdbuf());
    std::wistream wf(&conv);

#ifdef _WIN32
    _setmode(_fileno(stdout), _O_WTEXT);
#else
    std::setlocale(LC_ALL, "");
#endif 
    for(wchar_t c; wf.get(c); )
        std::wcout << "Processed character " << c << '\n';
}
*/

/*

#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <cstdlib>

int main()
{
    std::wifstream wif("test.txt");
    wif.imbue(std::locale("zh_CN.UTF-8"));

    std::wcout.imbue(std::locale("zh_CN.UTF-8"));
    std::wcout << wif.rdbuf();
}
*/

#include <bits/stdc++.h>
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

#define _O_U16TEXT 0x00020000
#define _O_U8TEXT 0x00040000

using namespace std;

/*
void lectura(string nombre){
    //_setmode(_fileno(stdout), _O_U16TEXT);
    wifstream archivo;
    wstring text;

    archivo.open(nombre,wifstream::in);

    while(!archivo.eof()){
        archivo>>text;
        wcout<<text<<"\n";
        wprintf(L"%s\n",text.c_str());
        wprintf(L"%ls\n",text.c_str());
    }

    archivo.close();

    return;
}
*/

//MEDIANAMENTE FUNCIONAL

void ShowMap(string name){
    wifstream file;
    wstring text;
    file.open(name+".txt",wifstream::in);
    if(file.fail()){
        cout<<"El mapa "<<name<<" no se puede abrir";
        return;
    }
    while(!file.eof()){
        getline(file, text);
        if(text == L"\\n") wcout<<endl;
        else{
            wcout<<"\e["<<text<<"m";
            getline(file, text);
            wcout<<text<<"\e[0m";
        }
    }
    file.close();
    return;
}



int main(){
    //_setmode(_fileno(stdout), _O_U16TEXT);
    //_setmode(_fileno(stdout), _O_U8TEXT);
    
    /*
    //IT WORKS!! :)
    wstring ws= L"\x22d2\x22d3\x22d2\x22d3\x22d2\x22d3";
    wcout<<ws<<endl;
    wcout<<ws<<"\n";
    wprintf(L"%s\n",ws);
    wprintf(L"%ls\n",ws);
    wprintf(L"%s\n",ws.c_str());
    wprintf(L"%ls\n",ws.c_str());
    */
   /*
   //Failure :(
   wstring ws;
   getline(wcin, ws);
   wcout<<ws;
   */

   //lectura("test.txt");

   //Failure
   /*
    wchar_t wch = 0x002;  // the delimiter
	wchar_t wbuf[256];      // the Unicode buffer
	fstream f;
	f.open(L"test.txt", ios::in | ios::binary);
	if(!f) { _RPT0(0, "Unable to open file for reading.\n"); }
    else{
        wchar_t wBuffer[128];
        wf.rdbuf()->pubsetbuf(wBuffer, (streamsize)128);
        f.getline( &wbuf, 256, 0x0002);
        f.close();
        wcout<<wbuf;
    }
    */
   //Failure
   /*
    wchar_t wch = '\xE2\x8B\x92';
    wcout<<wch<<endl;
    wch = '0xE80xAE0x92';
    wcout<<wch<<endl;
    */

   cout<<sizeof(wchar_t);
   cout<<sizeof(char);
}