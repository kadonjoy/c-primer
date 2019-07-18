/*
 **************************************************************************************
 *       Filename:  Pointers.cpp
 *    Description:   source file
 *
 *        Version:  1.0
 *        Created:  2019-01-21 15:21:53
 *
 *       Revision:  initial draft;
 **************************************************************************************
 */
#include <iostream>
using namespace std;

int a, b, c, d;

void func(void) {
    cout << "call func" << endl;
}
int main(int argc, const char *argv[]) {
    int i, j, k;
    cout << "func() address: " << (void *)&func << endl;
    cout << "main() address: " << (void *)&main << endl;
    cout << "a address: " << &a << endl;
    cout << "b address: " << &b << endl;
    cout << "c address: " << &c << endl;
    cout << "d address: " << &d << endl;
    cout << "i address: " << &i << endl;
    cout << "j address: " << &j << endl;
    cout << "k address: " << &k << endl;
    return 0;
}

/********************************** END **********************************************/

