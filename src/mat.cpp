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

}

Mat4 Mat4::operator+(const Mat4& m) const{
    Mat4()
}

Mat4 operator+=(const Mat4& m);

Mat4 operator-(const Mat4& m) const;

Mat4 operator-=(const Mat4& m);

Mat4 operator*(const Mat4& m);

Mat4 operator*=(const Mat4& m);

Mat4 transpose() const;

Mat4 transposeThis();

Mat4 inverse();

Mat4 inverseThis();