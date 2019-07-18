/*
 **************************************************************************************
 *       Filename:  iostream-example-cin.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2019-01-18 13:42:48
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */
#include <iostream>
using namespace std;
int main(int argc, const char *argv[]) {
    int number;
    cout << "Please input one int number: " << endl;
    cin >> number;
    cout << "number octal: 0" << oct << number << endl;
    cout << "number hex: 0x" << hex << number << endl;

    return 0;
}


/********************************** END **********************************************/

