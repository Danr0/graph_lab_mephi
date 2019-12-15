
#ifndef tests_H
#define tests_H

#include "algfloid.hpp"

void floidtests() {
    int N = 5;
    int ** Matrix;
    int i, j;
    Matrix = (int**)malloc(N * sizeof(int*));
    for (i = 0; i < N; i++)
        Matrix[i] = (int*)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++){
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
    cout << "\n\n \n Test matrix #1\n";
    printMatrix(Matrix, N);
    cout << "Floid alg: ";
    int* tmp1 = Floid(Matrix, N, 0, -1);
    for(i=0; i<N; i++)
        cout << " " << tmp1[i];
    if (tmp1[0]==0 && tmp1[1]==10 && tmp1[2]==20 && 
                tmp1[3]==40 && tmp1[4]==10)
        cout << "\nTest passed";
    else
        cout << "\nTest failed";
    

    

    N = 6;
    double ** Matrix2;
    Matrix2 = (double**)malloc(N * sizeof(double*));
    for (i = 0; i < N; i++)
        Matrix2[i] = (double*)malloc(N * sizeof(double));
    
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++){
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
    cout << "\n\n \n Test matrix #2\n";
    printMatrix(Matrix2, N);
    cout << "Floid alg: ";
    double* tmp2 = Floid(Matrix2, N, 0.0, -1.0);
    for(i=0; i<N; i++)
        cout << " " << tmp2[i];
    if (tmp2[0]==(double)0 && tmp2[1]==(double)10 && tmp2[2]==(double)20 && 
                tmp2[3]==(double)40 && tmp2[4]==(double)10 && tmp2[5]==(double)-1)
        cout << "\nTest passed";
    else
        cout << "\nTest failed";
        

    N = 6;
    float ** Matrix3;
    Matrix3 = (float**)malloc(N * sizeof(float*));
    for (i = 0; i < N; i++)
        Matrix3[i] = (float*)malloc(N * sizeof(float));
    
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++){
            Matrix3[i][j]=static_cast <float> (rand()) / static_cast <float> (RAND_MAX/100);
            if(i==j)
            Matrix3[i][j]=(float)(0);
        }
    cout << "\n\n \n Test random matrix #3\n";
    printMatrix(Matrix3, N);
    cout << "Floid alg: ";
    float* tmp3 = Floid(Matrix3, N, (float)(0), (float)(-1));
    for(i=0; i<N; i++)
        cout << " " << tmp3[i];
    cout << "\n ";

}
#endif 