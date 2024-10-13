#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <map>
#include <math.h>
#include <vector>
#include <ctime>
#include <random>
using namespace std;

class OS
{
    // Core Data Structures
private:
    char M[300][4]; // Main Memory
    char R[4];      // General Purpose Register
    char IR[4];     // Instruction Register
    int IC;         // Instruction Counter
    int VA;         // Virtual Address
    int RA;         // Real Address
    bool C;         // Toggle Variable
    int PTR;        // Page Table Register
    int TTC;        // Total Time Counter
    int LLC;        // Line Limit Counter

    // Process Control Block
    struct PCB
    {
        int TTL, TLL, JOBID;
    } pcb;
    /*
    TTL : TOTAL TIME LIMIT
    TLL : TOTAL LINE LIMIT
    */

    // Interrupts
    short SI;
    short TI; // Time
    short PI; // Program

    // Error Messages Coding
    map<int, string> ERRORMSGS{
        {0, "NO ERROR"}, // Make changes in the time or line in the $AMJ accordingly if necessary or maybe GD and LR
        {1, "OUT OF DATA"}, // ( $DTA Lines < GD number)
        {2, "LINE LIMIT EXCEEDED"}, // Make changes in the $AMJ
        {3, "TIME LIMIT EXCEEDED"}, // Make changes in the $AMJ
        {4, "OPERATION CODE ERROR"}, //Make changes in the card apart from GD, LR, SR, PD, BT
        {5, "OPERAND ERROR"}, // Make changes in the card where number != [0,99]
        {6, "INVALID PAGE FAULT"}, // After GD put LR but not with the same operand number
    };

    // Non-Core Data Structures
public:
    char buffer[40];
    string line;
    ifstream finput;
    ofstream foutput;
    bool program_card_flag;
    int Frame;
    vector<int> framearray;
    int ptr_counter;
    bool flag_Exe_end;
    int count_program_cards;

    // Constructor
    OS(string input_file, string output_file)
    {
        finput.open(input_file, ios::in);
        foutput.open(output_file, ios::out);
        line.reserve(40);
    }

    // Core Functions
    void INITIALIZATION();
    void LOAD();
    int ALLOCATE();
    void STARTEXE();
    void EXECUTE();
    void ADDRESSMAP_IC();
    void ADDRESSMAP_VA();
    void MOS();
    void READ();
    void WRITE();
    void TERMINATE(short);
    void TERMINATE(short, short);
    void SIMULATION();

    // Non Core Functions
    void init();
    void printmemory();
    void clearbuffer();
    void copytobuffer();
    void storedata();
    void extractjobdetails();
    void init_page_table();
    void update_page_table_program();
    void update_page_table_data();
};
