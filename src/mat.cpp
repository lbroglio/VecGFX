#include"mat.hpp"


Mat4::Mat4(std::initializer_list<std::initializer_list<float>> initList){
    //Set the matrix to the provided values
    for(int i =0; i < 16; i++){
        // Find location of this index in the initList
        int row = i / 4;
        int col = i % 4;

        backingArr[i] = *((initList.begin() + row)->begin() + col);
    }
}


Mat4::Mat4(){
    *this = Mat4({
    {1.0, 0.0, 0.0, 0.0},
    {0.0, 1.0, 0.0, 0.0},
    {0.0, 0.0, 1.0, 0.0},
    {0.0, 0.0, 0.0, 1.0}
    });
}

Mat4::Mat4(const Mat4& m){
    *this = Mat4({
    {m.backingArr[0], m.backingArr[1], m.backingArr[2], m.backingArr[3]},
    {m.backingArr[4], m.backingArr[5], m.backingArr[6], m.backingArr[7]},
    {m.backingArr[8], m.backingArr[9], m.backingArr[10], m.backingArr[11]},
    {m.backingArr[12], m.backingArr[13], m.backingArr[14], m.backingArr[15]}
    });
}

Mat4 Mat4::operator+(const Mat4& m) const{
    // Matrix to hold the sum
    Mat4 ret = Mat4();

    // Set all values of this matrix to the sum of the corresponding values
    for(int i=0; i < 16; i++){
        ret.backingArr[i] = backingArr[i] + m.backingArr[i]; 
    }

    return ret;
}

Mat4 Mat4::operator+=(const Mat4& m){
    return (*this = *this + m);
}

Mat4 Mat4::operator-(const Mat4& m) const{
    // Matrix to hold the difference
    Mat4 ret = Mat4();

    // Set all values of this matrix to the sum of the corresponding values
    for(int i=0; i < 16; i++){
        ret.backingArr[i] = backingArr[i] - m.backingArr[i]; 
    }

    return ret;
}

Mat4 Mat4::operator-=(const Mat4& m){
    return (*this = *this - m);
}

Mat4 operator*(const float& s){
    // Matrix containing the scaled value
    Mat4 ret = Mat4();

    // Set all values of this matrix to the sum of the corresponding values
    for(int i=0; i < 16; i++){
        ret.backingArr[i] = backingArr[i] - m.backingArr[i]; 
    }

    return ret;
}

Mat4 operator*=(const float& s){

}

Mat4 operator*(const Mat4& m);

Mat4 operator*=(const Mat4& m);

Mat4 transpose() const;

Mat4 transposeThis();

Mat4 inverse();

Mat4 inverseThis();

Mat4::MRow Mat4::operator[](int idx){
    return MRow(*this, idx);
}

float& Mat4::MRow::operator[](int idx){
    int offset = (thisIdx * 4) + idx;
    return parent.backingArr[offset];
}