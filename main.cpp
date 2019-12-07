#include <iostream>
#include <iomanip>

using namespace std;

template<typename T>
void Floid(T** ary, int n, T nullel, T infel)
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
                //cout << " h" << l;
            }
            else
            {
                l=infel;
            }
            if((tmp[j] == infel && l != infel)||(tmp[j] != infel && l != infel && l<tmp[j]))
                tmp[j] = l;   
        }
        //for (int i = 0; i < n; i++) 
        //cout << tmp[i] << " ";
        //cout <<"\n";
    }
    for (int i = 0; i < n; i++) 
        cout << tmp[i] << " ";
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

int main() {
    /*
    int ary[6][6] = {{0,7,9,-1,-1,-1},{7,0,10,15,-1,-1},{9,10,0,11,-1,2}
                    ,{-1,15,11,0,6,-1},{-1,-1,-1,6,0,9},{-1,-1,2,-1,9,0}};
    int tmp[6] = {0,-1,-1,-1,-1,-1};
    int l;  
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if(ary[i][j]!=-1){
                l=ary[i][j]+tmp[i];
            }
            else
            {
                l=-1;
            }
            if((tmp[j] == -1 && l != -1)||(tmp[j] != -1 && l != -1 && l<tmp[j]))
                tmp[j] = l;   
        }
    }
    for (int i = 0; i < 6; i++) 
        cout << tmp[i] << " ";

    */
    int N = 5;
    int ** Matrix;
    int i, j;
    Matrix = (int**)malloc(N * sizeof(int*));
    for (i = 0; i < N; i++)
        Matrix[i] = (int*)malloc(N * sizeof(int));
    
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++){
            //cin >> Matrix[i][j];
            Matrix[i][j]=-1;
            if(i==j)
            Matrix[i][j]=0;
        }
    Matrix[0][1] = 10;
    Matrix[0][2] = 30;
    Matrix[0][3] = 50;
    Matrix[0][4] = 10;
    Matrix[2][4] = 10;
    Matrix[3][1] = 40;
    Matrix[3][2] = 20;
    Matrix[4][0] = 10;
    Matrix[4][2] = 10;
    Matrix[4][3] = 30;
    cout << "\n";
    printMatrix(Matrix, N);
    Floid(Matrix, N, 0, -1);

    N = 6;
    double ** Matrix2;
    Matrix2 = (double**)malloc(N * sizeof(double*));
    for (i = 0; i < N; i++)
        Matrix2[i] = (double*)malloc(N * sizeof(double));
    
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++){
            //cin >> Matrix[i][j];
            Matrix2[i][j]=-1;
            if(i==j)
            Matrix2[i][j]=0;
        }
    Matrix2[0][1] = 10;
    Matrix2[0][2] = 30;
    Matrix2[0][3] = 50;
    Matrix2[0][4] = 10;
    Matrix2[2][4] = 10;
    Matrix2[3][1] = 40;
    Matrix2[3][2] = 20;
    Matrix2[4][0] = 10;
    Matrix2[4][2] = 10;
    Matrix2[4][3] = 30;
    cout << "\n";
    printMatrix(Matrix2, N);
    Floid(Matrix2, N, 0.0, -1.0);

    N = 6;
    float ** Matrix3;
    Matrix3 = (float**)malloc(N * sizeof(float*));
    for (i = 0; i < N; i++)
        Matrix3[i] = (float*)malloc(N * sizeof(float));
    
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++){
            //cin >> Matrix[i][j];
            Matrix3[i][j]=static_cast <float> (rand()) / static_cast <float> (RAND_MAX/100);
            if(i==j)
            Matrix3[i][j]=(float)(0);
        }
    cout << "\n";
    printMatrix(Matrix3, N);
    Floid(Matrix3, N, (float)(0), (float)(-1));

}