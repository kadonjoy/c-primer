/*
 **************************************************************************************
 *       Filename:  DisplayASCII.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2019-01-21 13:43:14
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */
#include <iostream>
using namespace std;
int main(int argc, const char *argv[]) {
    for (int i = 0; i<128; i++) {
        if(i!=26)
            cout << "ASCII code: " << char(i) << " " << i << endl;
    }
    return 0;
}



/********************************** END **********************************************/

