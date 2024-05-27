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


Vec4 Vec4::operator*(const float& s) const{
    return Vec4(x * s, y * s, z * s, w * s);
}


Vec4 Vec4::operator*=(const float& s){
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


Vec3 Vec3::operator*(const double& s) const{
    return Vec3(x * s, y * s, z * s);
}


Vec3 Vec3::operator*=(const double& s){
    return *this = *this * s;
}

bool Vec3::operator==(const Vec3& v){
    return x == v.x && y == v.y && z == v.z;
}


bool Vec3::operator!=(const Vec3& v){
     return !(*this == v);
}


float Vec3::magitude(){
    return sqrt((x * x) + (y * y) + (z * z));
}


Vec3 operator*(const float& s, const Vec3& v){
    return Vec3(v.x * s, v.y * s, v.z * s);
}

std::ostream& operator<<(std::ostream& o, const Vec3& v){
    // Output Vec3
    o << "{" << v.x << ", " << v.y << ", " << v.z << "}";
    return o;
}