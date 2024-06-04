#include"vec.hpp"
#include "util.hpp"
#include<cmath>




namespace VecGFX{

    float Vec4::dot(const Vec4& v){
        return (x * v.x) + (y * v.y) + (z * v.z) + (w * v.w);
    }

    Vec4 Vec4::operator+(const Vec4& v) const{
        return Vec4(x + v.x, y + v.y, z + v.z, w + v.w);
    }

        
    Vec4 Vec4::operator+=(const Vec4& v){
        return *this = *this + v;
    }

        
    Vec4 Vec4::operator-(const Vec4& v) const{
        return Vec4(x - v.x, y - v.y, z - v.z, w - v.w);
    }


    Vec4 Vec4::operator-=(const Vec4& v){
        return *this = *this - v;
    }


    Vec4 Vec4::operator*(const float& s) const{
        return Vec4(x * s, y * s, z * s, w * s);
    }


    Vec4 Vec4::operator*=(const float& s){
        return *this = *this * s;
    }

    bool Vec4::operator==(const Vec4& v) const{
        return compareWithEpsilon(x, v.x) && compareWithEpsilon(y, v.y) 
            && compareWithEpsilon(z , v.z) && compareWithEpsilon(w, v.w);
    }


    bool Vec4::operator!=(const Vec4& v){
        return !(*this == v);
    }

    Vec4 Vec4::operator=(const Vec4& v){
        // Set values of this Vec4
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
        this->w = v.w;

        // Return this Vec4
        return *this;
    }

    Vec4 Vec4::transform(const Mat4& m){
        return (*this = m * *this);
    }

    float Vec4::magitude(){
        return sqrt((x * x) + (y * y) + (z * z) + (w * w));
    }


    Vec4 operator*(const float& s, const Vec4& v){
        return Vec4(v.x * s, v.y * s, v.z * s, v.w * s);
    }

    Vec4 operator*(const Mat4& m, const Vec4& v){
        // Vec4 to store product
        Vec4 ret;

        // Perform matrix multiplication with the vector treated as a 4x1 matrix
        for(int row=0; row < 4; row++){
            float indexVal = 0;
            for(int i=0; i < 4; i++){
                int offset = (row * 4) + i;
                indexVal += (m[row][i] * v.backingArr[i]);
            }
            ret.backingArr[row] = indexVal;
        }

        return ret;
    }


    std::ostream& operator<<(std::ostream& o, const Vec4& v){
        // Output Vec4
        o << "{" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << "}";
        return o;
    }


    float Vec3::dot(const Vec3& v){
        return (x * v.x) + (y * v.y) + (z * v.z);
    }

    Vec3 Vec3::operator+(const Vec3& v) const{
        return Vec3(x + v.x, y + v.y, z + v.z);
    }

        
    Vec3 Vec3::operator+=(const Vec3& v){
        return *this = *this + v;
    }

        
    Vec3 Vec3::operator-(const Vec3& v) const{
        return Vec3(x - v.x, y - v.y, z - v.z);
    }


    Vec3 Vec3::operator-=(const Vec3& v){
        return *this = *this - v;
    }


    Vec3 Vec3::operator*(const float& s) const{
        return Vec3(x * s, y * s, z * s);
    }


    Vec3 Vec3::operator*=(const float& s){
        return *this = *this * s;
    }

    Vec3 Vec3::operator*(const Vec3& v) const{
        float crossX = (this->y * v.z) - (this->z * v.y);
        float crossY = (this->z * v.x) - (this->x * v.z);
        float crossZ = (this->x * v.y) - (this->y * v.x);

        return Vec3(crossX, crossY, crossZ);
    }

    Vec3 Vec3::operator*=(const Vec3& v){
        return (*this = *this * v);
    }


    bool Vec3::operator==(const Vec3& v) const{
        return compareWithEpsilon(x, v.x) && compareWithEpsilon(y, v.y) 
            && compareWithEpsilon(z , v.z);
    }


    bool Vec3::operator!=(const Vec3& v){
        return !(*this == v);
    }

    Vec3 Vec3::operator=(const Vec3& v){
        // Set values of this Vec3
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;

        // Return this Vec3
        return *this;
    }

    float Vec3::magitude(){
        return sqrt((x * x) + (y * y) + (z * z));
    }

    Vec3 Vec3::transform(const Mat3& m){
        return (*this = m * *this);
    }

    Vec3 operator*(const float& s, const Vec3& v){
        return Vec3(v.x * s, v.y * s, v.z * s);
    }

    Vec3 operator*(const Mat3& m, const Vec3& v){
        // Vec4 to store product
        Vec3 ret;

        // Perform matrix multiplication with the vector treated as a 4x1 matrix
        for(int row=0; row < 3; row++){
            float indexVal = 0;
            for(int i=0; i < 3; i++){
                int offset = (row * 3) + i;
                indexVal += (m[row][i] * v.backingArr[i]);
            }
            ret.backingArr[row] = indexVal;
        }

        return ret;
    }

    std::ostream& operator<<(std::ostream& o, const Vec3& v){
        // Output Vec3
        o << "{" << v.x << ", " << v.y << ", " << v.z << "}";
        return o;
    }

}