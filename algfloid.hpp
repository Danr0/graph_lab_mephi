
#ifndef algfloid_H
#define algfloid_H
#include <iostream>

using namespace std;

template<typename T>
T* Floid(T** ary, int n, T nullel, T infel)
{
    T* tmp = (T*)malloc(n * sizeof(T));
    tmp[0] = nullel;
    for (int i = 1; i < n; i++) {
        tmp[i] = infel;
    }
    T l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(ary[i][j]!=infel && tmp[i]!=infel){
                l=ary[i][j]+tmp[i];
            }
            else
            {
                l=infel;
            }
            if((tmp[j] == infel && l != infel)||(tmp[j] != infel && l != infel && l<tmp[j]))
                tmp[j] = l;
        }
    }
    return tmp;
}

template<typename T>
void printMatrix(T** ary, int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ary[i][j] << " ";
        }
        cout << "\n";
    }
}
#endif