/*
 **************************************************************************************
 *       Filename:  HelloString.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2019-01-18 13:51:34
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char *argv[]) {
    string s1, s2;
    string s3 = "Hello World,";
    string s5("I am");
    s2 = "Today";
    s1 = s3 + " " + s5;
    s1+= "8";
    cout << s1 + s2 + "!" << endl;
    return 0;
}

/********************************** END **********************************************/

