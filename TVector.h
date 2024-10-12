#include <iostream>
#include <stdexcept>

template <class T>
class TVector{
    T* arr;
    int len;
    public:
    const int getLength() const {
        return this->len;
    }
    T& operator[](int index){
        if(index>=this->len){
            throw std::out_of_range("");
        }
        return this->arr[index];
    }
    const T& operator[](int index) const {
        if(index>=this->len){
            throw std::out_of_range("");
        }
        return this->arr[index];
    }
    TVector(int l=0){//important change, not more l=1 by default, so its possible to create TVector without allocationg memory
        this->len = l;
        if(l!=0){
            this->arr = new T[this->len];
        } else {
            this->arr = nullptr;
        }
    }
    TVector(const TVector<T>& vectorToCopy){
        this->len = vectorToCopy.len;
        this->arr = new T[this->len];
        for(int i=0;i<this->len;i++){
            this->arr[i] = vectorToCopy.arr[i];
        }
    }
    ~TVector(){
        delete[] this->arr;
    }
    void setLength(int newLen){
        T* newArr = new T[newLen];
        int minLen = newLen;
        if(minLen>this->len){
            minLen=this->len;
        }
        for(int i=0;i<minLen;i++){
            newArr[i] = this->arr[i];
        }
        this->len=newLen;
        T* tempPtr=this->arr;
        this->arr = newArr;
        delete[] tempPtr;
    }
    TVector<T>& operator=(const TVector<T>& vectorB){
        if(&vectorB==this){
            return *this;
        }
        if(this->len!=vectorB.len){
            this->len=vectorB.len;
            delete[] this->arr;
            this->arr = new T[this->len];
        }
        for(int i=0;i<this->len;i++){
            this->arr[i] = vectorB.arr[i];
        }
        return *this;
    }
    TVector<T> operator+=(const TVector<T>& vectorB){
        if(this->len!=(vectorB.len)){
            throw std::out_of_range("");
        }
        for(int i=0;i<this->len;i++){
            this->arr[i] += vectorB.arr[i];
        }
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, TVector<T> vector) {
        for(int i=0;i<vector.getLength();i++){
            os << vector[i] << " ";
        }
        return os;
    }
    friend std::istream& operator>>(std::istream& is, TVector<T>& vector) {
        int length;
        is >> length;
        vector.setLength(length);
        for (int i = 0; i < length; i++) {
            is >> vector[i];
        }
        return is;
    }
};
