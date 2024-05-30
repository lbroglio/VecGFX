#include"mat.hpp"

namespace VecGFX{
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

    Mat4 Mat4::operator*(const float& s) const {
        // Matrix containing the scaled value
        Mat4 ret = Mat4();

        // Set all values of this matrix to the sum of the corresponding values
        for(int i=0; i < 16; i++){
            ret.backingArr[i] = backingArr[i] * s; 
        }

        return ret;
    }

    Mat4 Mat4::operator*=(const float& s){
        // Matrix containing the scaled value
        Mat4 ret = Mat4();

        // Set all values of this matrix to the sum of the corresponding values
        for(int i=0; i < 16; i++){
            ret.backingArr[i] = backingArr[i] * s; 
        }

        return (*this = *this * ret);
    }

    Mat4 Mat4::operator*(const Mat4& m) const {
        // Matrix to store the product
        Mat4 ret = Mat4();

        // Perform the matrix mutliplication
        int prodRow = 0;
        for(int row = 0; row < 4; row++){
            int prodCol = 0;
            for(int col = 0; col < 4; col++){
                // Hold the calculated sum of the products for this row
                float indexVal = 0;

                for(int rowIndex=0; rowIndex < 4; rowIndex++){
                    for(int colIndex=0; colIndex < 4; colIndex++){
                        indexVal += backingArr[rowIndex] + m.backingArr[colIndex];
                    }
                }
                prodCol++;
            }
            prodRow++;
        }

        return ret;
    }

    Mat4 Mat4::operator*=(const Mat4& m){
        return (*this = *this * m);
    }

    Mat4 Mat4::transpose() const {
        // Matrix to store the product
        Mat4 ret = Mat4();

        // Transpose the matrix
        for(int row = 0; row < 4; row++){
            for(int col = 0; col < 4; col++){
                // Calculate offsets in backing arrays
                int newOffset = (col * 4) + row;
                int origOffset = (row * 4) + col;

                ret.backingArr[newOffset] = backingArr[origOffset];
            }
        }

        return ret;
    }

    Mat4 Mat4::transposeThis(){
        return (*this = this->transpose());
    }

    Mat4::MRow Mat4::operator[](int idx){
        return MRow(*this, idx);
    }

    float& Mat4::MRow::operator[](int idx){
        int offset = (thisIdx * 4) + idx;
        return parent.backingArr[offset];
    }

    Mat4::CMRow const& Mat4::operator[](int idx) const{
        return CMRow(*this, idx);
    }

    float const& Mat4::CMRow::operator[](int idx) const {
        int offset = (thisIdx * 4) + idx;
        return parent.backingArr[offset];
    }

    float* Mat4::asArray(){
        // Allocate space for array
        float* matArray = new float[16];

        // Fill array from backing array
        for(int i=0; i < 16; i++){
            matArray[i] = backingArr[i];
        }

        return matArray;
    }

    Mat4 operator*(const float& s, const Mat4& m){
        // Matrix containing the scaled value
        Mat4 ret = Mat4();

        // Set all values of this matrix to the sum of the corresponding values
        for(int i=0; i < 16; i++){
            ret.backingArr[i] = m.backingArr[i] * s; 
        }

        return ret;
    }

    std::ostream& operator<<(std::ostream& o, const Mat4& m){
        // Output the formatted matrix
        o << m.backingArr[0] << ", " << m.backingArr[1] << ", " << m.backingArr[2] << ", " << m.backingArr[3] << "\n"
        << m.backingArr[4] << ", " << m.backingArr[5] << ", " << m.backingArr[6] << ", " << m.backingArr[7] << "\n"
        << m.backingArr[8] << ", " << m.backingArr[9] << ", " << m.backingArr[10] << ", " << m.backingArr[11] << "\n"
        << m.backingArr[12] << ", " << m.backingArr[13] << ", " << m.backingArr[14] << ", " << m.backingArr[15] << "\n";

        return o;
    }

    Mat3::Mat3(std::initializer_list<std::initializer_list<float>> initList){
        //Set the matrix to the provided values
        for(int i =0; i < 9; i++){
            // Find location of this index in the initList
            int row = i / 3;
            int col = i % 3;

            backingArr[i] = *((initList.begin() + row)->begin() + col);
        }
    }


    Mat3::Mat3(){
        *this = Mat3({
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0},
        {0.0, 0.0, 0.0}
        });
    }

    Mat3::Mat3(const Mat3& m){
        *this = Mat3({
        {m.backingArr[0], m.backingArr[1], m.backingArr[2],},
        {m.backingArr[3], m.backingArr[4], m.backingArr[5],},
        {m.backingArr[6], m.backingArr[7], m.backingArr[8] }
        });
    }

    Mat3 Mat3::operator+(const Mat3& m) const{
        // Matrix to hold the sum
        Mat3 ret = Mat3();

        // Set all values of this matrix to the sum of the corresponding values
        for(int i=0; i < 9; i++){
            ret.backingArr[i] = backingArr[i] + m.backingArr[i]; 
        }

        return ret;
    }

    Mat3 Mat3::operator+=(const Mat3& m){
        return (*this = *this + m);
    }

    Mat3 Mat3::operator-(const Mat3& m) const{
        // Matrix to hold the difference
        Mat3 ret = Mat3();

        // Set all values of this matrix to the sum of the corresponding values
        for(int i=0; i < 9; i++){
            ret.backingArr[i] = backingArr[i] - m.backingArr[i]; 
        }

        return ret;
    }

    Mat3 Mat3::operator-=(const Mat3& m){
        return (*this = *this - m);
    }

    Mat3 Mat3::operator*(const float& s) const {
        // Matrix containing the scaled value
        Mat3 ret = Mat3();

        // Set all values of this matrix to the sum of the corresponding values
        for(int i=0; i < 9; i++){
            ret.backingArr[i] = backingArr[i] * s; 
        }

        return ret;
    }

    Mat3 Mat3::operator*=(const float& s){
        // Matrix containing the scaled value
        Mat3 ret = Mat3();

        // Set all values of this matrix to the sum of the corresponding values
        for(int i=0; i < 9; i++){
            ret.backingArr[i] = backingArr[i] * s; 
        }

        return (*this = *this * ret);
    }

    Mat3 Mat3::operator*(const Mat3& m) const {
        // Matrix to store the product
        Mat3 ret = Mat3();

        // Perform the matrix mutliplication
        int prodRow = 0;
        for(int row = 0; row < 3; row++){
            int prodCol = 0;
            for(int col = 0; col < 3; col++){
                // Hold the calculated sum of the products for this row
                float indexVal = 0;

                for(int rowIndex=0; rowIndex < 3; rowIndex++){
                    for(int colIndex=0; colIndex < 3; colIndex++){
                        indexVal += backingArr[rowIndex] + m.backingArr[colIndex];
                    }
                }
                prodCol++;
            }
            prodRow++;
        }

        return ret;
    }

    Mat3 Mat3::operator*=(const Mat3& m){
        return (*this = *this * m);
    }

    Mat3 Mat3::transpose() const {
        // Matrix to store the product
        Mat3 ret = Mat3();

        // Transpose the matrix
        for(int row = 0; row < 3; row++){
            for(int col = 0; col < 3; col++){
                // Calculate offsets in backing arrays
                int newOffset = (col * 3) + row;
                int origOffset = (row * 3) + col;

                ret.backingArr[newOffset] = backingArr[origOffset];
            }
        }

        return ret;
    }

    Mat3 Mat3::transposeThis(){
        return (*this = this->transpose());
    }

    Mat3::MRow Mat3::operator[](int idx){
        return MRow(*this, idx);
    }

    float& Mat3::MRow::operator[](int idx){
        int offset = (thisIdx * 3) + idx;
        return parent.backingArr[offset];
    }

    float& Mat3::MRow::operator[](int idx){
        int offset = (thisIdx * 3) + idx;
        return parent.backingArr[offset];
    }
    
    Mat3::CMRow const& Mat3::operator[](int idx) const{
        return CMRow(*this, idx);
    }

    float const& Mat3::CMRow::operator[](int idx) const{
        int offset = (thisIdx * 3) + idx;
        return parent.backingArr[offset];
    }

    float* Mat3::asArray(){
        // Allocate space for array
        float* matArray = new float[9];

        // Fill array from backing array
        for(int i=0; i < 9; i++){
            matArray[i] = backingArr[i];
        }

        return matArray;
    }

    Mat3 operator*(const float& s, const Mat3& m){
        // Matrix containing the scaled value
        Mat3 ret = Mat3();

        // Set all values of this matrix to the sum of the corresponding values
        for(int i=0; i < 9; i++){
            ret.backingArr[i] = m.backingArr[i] * s; 
        }

        return ret;
    }

    std::ostream& operator<<(std::ostream& o, const Mat3& m){
        // Output the formatted matrix
        o << m.backingArr[0] << ", " << m.backingArr[1] << ", " << m.backingArr[2] << ", \n "
        << m.backingArr[3] << ", " << m.backingArr[4] << ", " << m.backingArr[5] << ", \n"
        << m.backingArr[6] << ", " << m.backingArr[7] << ", " << m.backingArr[8] << ", \n";

        return o;
    }

}