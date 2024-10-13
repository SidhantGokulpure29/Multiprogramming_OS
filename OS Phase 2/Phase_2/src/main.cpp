#include "Core_Function.cpp"

int main()
{
    string in = "..\\Input\\phase2_input.txt";
    string out = "..\\Output\\phase2_output.txt";
//
//    string in = "..\\Input\\input.txt";
//    string out = "..\\Output\\output.txt";

    OS NewOS(in,out);
    NewOS.LOAD();

    return 0;
}

