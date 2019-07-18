/*
 **************************************************************************************
 *       Filename:  Scopy.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2019-01-18 14:04:18
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, const char *argv[]) {
    string s;
    ifstream in("1.txt");
    ofstream out("1.txt.bk");
    while(getline(in, s)) {
        cout << s << endl;
        out << s << "\n";
    }
    return 0;
}

/********************************** END **********************************************/

