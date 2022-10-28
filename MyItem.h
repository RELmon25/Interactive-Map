#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <fcntl.h>

using namespace std;

class MyItem {
    private:
        string name;
    public:
        MyItem(string _name){ name = _name; };
};