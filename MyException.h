#include<iostream>

using namespace std;

class MyException: public exception{
    public: 
        virtual const char* what() const throw(){
            return "Damaged or missing files... :(\n";
        }
};