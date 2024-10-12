#include <iostream>
#include <stdexcept>
#include "TVector.h"

template <class T>
class TMatrix{
    int len;//length of vector of vectors = number of rows, so len = rows
    int columns;
    TVector<T> *arr;
    public:
    int getRows(){
        return this->len;
    }
    int getColumns(){
        return this->columns;
    }
    TVector<T>& operator[](int index){
        if(index>=this->len){
            throw std::out_of_range("");
        }
        return this->arr[index];
    }
    TMatrix(int rows=10,int columns=10){
        this->len = rows;
        this->columns = columns;
        this->arr = new TVector<T>[rows];
        for(int i=0;i<rows;i++){
            (this->arr[i]=TVector<T>(columns));
        }
    }
    TMatrix(const TMatrix<T>& matrixToCopy){
        this->len=matrixToCopy.len;
        this->columns = matrixToCopy.columns;
        this->arr = new TVector<T>[this->len];
        for(int i=0;i<this->len;i++){
            this->arr[i] = matrixToCopy.arr[i];
        }
    }
    ~TMatrix(){
        delete[] arr;
    }
    TMatrix<T>& operator=(const TMatrix<T>& matrixB){
        if(&matrixB==this){
            return *this;
        }
        if((this->len!=matrixB.len)||(this->columns!=matrixB.columns)){
            throw std::out_of_range("");
        }
        for(int i=0;i<this->len;i++){
            this->arr[i] = matrixB.arr[i];
        }
        return *this;
    }
    TMatrix<T> operator+=(const TMatrix<T>& matrixB){
        if((this->len!=matrixB.len)||(this->columns!=matrixB.columns)){
            throw std::out_of_range("");
        }
        for(int i=0;i<this->len;i++){
            this->arr[i] += matrixB.arr[i];
        }
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, TMatrix<T> matrix) {
        for(int i=0;i<matrix.getRows();i++){
            os << matrix[i] << "\n";
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, TMatrix<T>& matrix) {
        for (int i=0;i<matrix.getRows();i++) {
            for(int j=0;j<matrix.getColumns();j++)
            is >> matrix[i][j];
        }
        return is;
    }
};
