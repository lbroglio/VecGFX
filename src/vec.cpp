#include"vec.hpp"
#include<cmath>

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


Vec4 Vec4::operator*(const double& s) const{
    return Vec4(x * s, y * s, z * s, w * s);
}


Vec4 Vec4::operator*=(const double& s){
    return *this = *this * s;
}

bool Vec4::operator==(const Vec4& v){
    return x == v.x && y == v.y && z == v.z && w == v.w;
}


bool Vec4::operator!=(const Vec4& v){
     return !(*this == v);
}


float Vec4::magitude(){
    return sqrt((x * x) + (y * y) + (z * z) + (w * w));
}


Vec4 operator*(const double& s, const Vec4& v){
    return Vec4(v.x * s, v.y * s, v.z * s, v.w * s);
}