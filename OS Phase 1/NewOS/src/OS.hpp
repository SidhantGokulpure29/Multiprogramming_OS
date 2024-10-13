#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class OS
{
    // Core Data Structures
private:
    char M[100][4]; //memory
    char R[4]; //general purpose reg
    char IR[4];
    short IC; //instruction counter reg
    bool C; //toggle
    signed char SI; //master mode

    // Non-Core Data Structures
public:
    int memory_used;
    int address;
    char buffer[40];
    string line;
    ifstream finput;
    ofstream foutput;
    bool flag;

    //Constructor
    OS(string input_file,string output_file)
    {
        finput.open(input_file, ios::in);
        foutput.open(output_file, ios::out);
        line.reserve(40);
        LOAD();
    }

    // Core Functions
    void LOAD();
    void STARTEXE();
    void EXECUTE();
    void MOS();
    void READ();
    void WRITE();
    void TERMINATE();

    // Non Core Functions
    void init();
    void printmemory();
    void clearbuffer();
    void extractaddress();
    void storedata();
};

