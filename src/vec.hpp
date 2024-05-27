#ifndef VGFX_VECTORS
#define VGFX_VECTORS

#include<iostream>

/**
 * @brief A class holding a 4D Vector 
 */
class Vec4 {
    public:
         /**
         * @brief x component of this Vector 
         */
        float x;

        /**
         * @brief y component of this Vector
         */
        float y; 

        /**
         * @brief z component of this Vector
         */
        float z;

        /**
         * @brief w component of this Vector
         */
        float w;

        /**
         * @brief Construct a new Vec4 object with a given x, y, z, and w components
         * 
         * @param x x component of the Vec4 to create
         * @param y y component of the Vec4 to create
         * @param z z component of the Vec4 to create
         * @param w w component of the Vec4 to create
         */
        Vec4(float x, float y, float z, float w): x(x), y(y), z(z), w(w) {}

        /**
         * @brief Construct a new Vec4 object -- Default constructor; sets all components to zero
         * 
         */
        Vec4(): x(0), y(0), z(0), w(0){}

        /**
         * @brief Calculate the dot product of this Vector with another 
         * 
         * @param v The Vector to take the dot product with
         * @return The dot product of this Vector and v 
         */
        float dot(const Vec4& v);

        /**
         * @brief Add operator override. Add together this Vector and v component wise (x1 + x2 ... )
         * 
         * @param v Vector to add to this one
         * @return New Vector with the sum 
         */
        Vec4 operator+(const Vec4& v) const;

        /**
         * @brief += override. Add together this Vector and v component wise (x1 +x2 ... ) 
         * and set this Vector to the sum
         * 
         * @param v Vector to add to this one
         * @return This Vector after the add operation
         */
        Vec4 operator+=(const Vec4& v);

        /**
         * @brief - override. Subtract v from this Vector component wise (x1 - x2 ... )
         * 
         * @param v Vector to subtract from this one
         * @return New Vector created from adding these together
         */
        Vec4 operator-(const Vec4& v) const;

        /**
         * @brief -= override. Subtract v from this Vector component wise (x1 - x2 ...  )
         * and set this Vector to the difference
         * 
         * @param v Vector to subtract from this one
         * @return This Vector after the operation
         */
        Vec4 operator-=(const Vec4& v);

        /**
         * @brief * override. Perform scalar multiplication on this Vec4
         * 
         * @param s Scalar to multiply the elements of this Vector by
         * @return New Vector created after scaling
         */
        Vec4 operator*(const float& s) const;

        /**
         * @brief *= override. Perform scalar multiplication on this Vector and 
         * set it to the result
         * 
         * @param s Scalar to multiply the elements of this Vector by
         * @return This Vector after the operation
         */
        Vec4 operator*=(const float& s);

        /**
         * @brief == override. Compare two Vectors and return true if 
         * all of their components are the same.
         * 
         * @param v Vector to compare to this one
         * 
         * @return bool holding the truth value 
         * true: The two Vectors are equal
         * false: The two Vectors are not equal
         */
        bool operator==(const Vec4& v);

        /**
         * @brief != override. Compare two Vectors and return true if they aren't equal.
         * 
         * @param v Vector to compare to this one
         * 
         * @return bool holding the truth value 
         * true: The two Vectors are not equal
         * false: The two Vectors are equal
         */
        bool operator!=(const Vec4& v);

        /**
         * @brief Calculate and return the magnitude of this Vector
         * 
         * @return Magnitude of this Vector 
         */
        float magitude();

     /**
     * @brief * override. Perform scalar multiplication on this Vec4
     * 
     * @param s Scalar to multiply the elements of this Vector by
     * @return New Vector created after scaling
     */
    friend Vec4 operator*(const double& s, const Vec4& v);

    /**
     * @brief Create a string representation of a Vec4 and pass it into an output stream
     * 
     * @param o output stream to print to
     * @param v Vec4 to print a string representation of
     * @return The output string after the Vec4's representation is printed
     */
    friend std::ostream& operator<<(std::ostream& o, const Vec4& v);

};

/**
 * @brief Class holding a 3D Vector
 * 
 */
class Vec3{
    public:
        /**
        * @brief x component of this Vector 
        */
        float x;

        /**
        * @brief y component of this Vector
        */
        float y; 

        /**
        * @brief z component of this Vector
        */
        float z;

        /**
         * @brief Construct a new Vec3 object with a given x, y, and zcomponents
         * 
         * @param x x component of the Vec3 to create
         * @param y y component of the Vec3 to create
         * @param z z component of the Vec3 to create
         */
        Vec3(float x, float y, float z): x(x), y(y), z(z){}

        /**
         * @brief Construct a new Vec4 object -- Default constructor; sets all components to zero
         * 
         */
        Vec3(): x(0), y(0), z(0){}

        /**
         * @brief Calculate the dot product of this Vector with another 
         * 
         * @param v The Vector to take the dot product with
         * @return The dot product of this Vector and v 
         */
        float dot(const Vec3& v);

        /**
         * @brief + operator override. Add together this Vector and v component wise (x1 + x2 ... )
         * 
         * @param v Vector to add to this one
         * @return New Vector with the sum 
         */
        Vec3 operator+(const Vec3& v) const;

        /**
         * @brief += override. Add together this Vector and v component wise (x1 +x2 ... ) 
         * and set this Vector to the sum
         * 
         * @param v Vector to add to this one
         * @return This Vector after the add operation
         */
        Vec3 operator+=(const Vec3& v);

        /**
         * @brief - override. Subtract v from this Vector component wise (x1 - x2 ... )
         * 
         * @param v Vector to subtract from this one
         * @return New Vector created from adding these together
         */
        Vec3 operator-(const Vec3& v) const;

        /**
         * @brief -= override. Subtract v from this Vector component wise (x1 - x2 ...  )
         * and set this Vector to the difference
         * 
         * @param v Vector to subtract from this one
         * @return This Vector after the operation
         */
        Vec3 operator-=(const Vec3& v);

        /**
         * @brief * override. Perform scalar multiplication on this Vec4
         * 
         * @param s Scalar to multiply the elements of this Vector by
         * @return New Vector created after scaling
         */
        Vec3 operator*(const double& s) const;

        /**
         * @brief *= override. Perform scalar multiplication on this Vector and 
         * set it to the result
         * 
         * @param s Scalar to multiply the elements of this Vector by
         * @return This Vector after the operation
         */
        Vec3 operator*=(const double& s);

        /**
         * @brief == override. Compare two Vectors and return true if 
         * all of their components are the same.
         * 
         * @param v Vector to compare to this one
         * 
         * @return bool holding the truth value 
         * true: The two Vectors are equal
         * false: The two Vectors are not equal
         */
        bool operator==(const Vec3& v);

        /**
         * @brief != override. Compare two Vectors and return true if they aren't equal.
         * 
         * @param v Vector to compare to this one
         * 
         * @return bool holding the truth value 
         * true: The two Vectors are not equal
         * false: The two Vectors are equal
         */
        bool operator!=(const Vec3& v);

        /**
         * @brief Calculate and return the magnitude of this Vector
         * 
         * @return Magnitude of this Vector 
         */
        float magitude();

     /**
     * @brief * override. Perform scalar multiplication on this Vec3
     * 
     * @param s Scalar to multiply the elements of this Vector by
     * @return New Vector created after scaling
     */
    friend Vec3 operator*(const double& s, const Vec3& v);

    /**
     * @brief Create a string representation of a Vec3 and pass it into an output stream
     * 
     * @param o output stream to print to
     * @param v Vec3 to print a string representation of
     * @return The output string after the Vec3's representation is printed
     */
    friend std::ostream& operator<<(std::ostream& o, const Vec3& v);
};



#endif