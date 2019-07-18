/*
 **************************************************************************************
 *       Filename:  Reference.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2019-01-21 15:40:32
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#include <iostream>
using namespace std;
int main(int argc, const char *argv[]) {
    int a = 10;
    int& r = a;
    cout << "a addr: " << &a << endl;
    cout << "r content: " << &r << endl;
    cout << "r : " << r << endl;
    return 0;
}

/********************************** END **********************************************/

