#include <iostream>
#include <stdexcept>
#include "TMatrix.h"

int main(){
    TMatrix<double> matrixA(4,6),streamTestMatrix(2,3);
    std::cout << "matrixA =\n" << matrixA << "\n";
    for(int i=0;i<matrixA.getRows();i++){
        for(int j=0;j<matrixA.getColumns();j++){
            matrixA[i][j] = i;
        }
    }
    std::cout << "matrixA =\n" << matrixA << "\n";
    TMatrix<double> matrixB(4,6);
    std::cout << "matrixB before assignment =\n" << matrixB << "\n";
    matrixB=matrixA;
    std::cout << "matrixB after matrixB=matrixA =\n" << matrixB << "\n";
    for(int i=0;i<matrixB.getRows();i++){
        for(int j=0;j<matrixB.getColumns();j++){
            matrixB[i][j] = j;
        }
    }
    std::cout << "matrixB =\n" << matrixB << "\n";
    //matrixB=streamTestMatrix;
    matrixA+=matrixB;
    std::cout << "matrixA =\n" << matrixA << "\n";
    std::cin >> streamTestMatrix;
    std::cout << "matrixFromStream = \n" << streamTestMatrix;
    return 0;
}
