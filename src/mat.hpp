#ifndef VGFX_MATRIX
#define VGFX_MATRIX

#include<initializer_list>


/**
 * @brief Class holding a 4x4 Matrix 
 */
class Mat4{
    public:
        /**
         * @brief A class holding a row from a Mat4 class
         */
        class MRow{
            friend class Mat4;
            public:
                /**
                 * @brief Index into this row to get the value at the column with 
                 * the given index
                 * 
                 * @param idx The column index to get the value of 
                 * @return The retrieved value
                 */
                float& operator[](int idx);
            private:
                Mat4& parent;
                int thisIdx;

                /**
                 * @brief Construct a new MRow object correspondng to the given 
                 * row at the given index within the given Mat4. 
                 * 
                 * @param parent The Mat4 this MRow is a component of
                 * @param idx The index of the Row this class corresponds to
                 */
                MRow(Mat4& parent, int idx): parent(parent), thisIdx(idx) {}
        };

        /**
         * @brief Construct a new Mat4 object with the given contents. 
         * Contents should be provided as a list of 4, 4 entry long rows. With the top row 
         * in the 0 index, the second to the top row in the 1 index ...
         * 
         * @param initList Two dimension list containing the contents of the Matrix
         */
        Mat4(std::initializer_list<std::initializer_list<float>> initList);

        /**
         * @brief Construct a new Mat 4 object. -- Default Constructor will be the identity Matrix
         * 
         */
        Mat4();

        /**
         * @brief Copy constructor create a new Mat4 with the same entries as another
         * 
         * @param m The Matrix to copy to create a new one
         */
        Mat4(const Mat4& m);

        /**
         * @brief Add Override. Add this Mat4 and m together and return the sum
         * 
         * @param m The matrix to add to this one
         * @return The sum of this Matrix and m
         */
        Mat4 operator+(const Mat4& m) const;

        /**
         * @brief += Override. Add this Mat4 and m together and set this matrix to the sum
         * 
         * @param m The matrix to add to this one
         * @return The sum of this Matrix and m
         */
        Mat4 operator+=(const Mat4& m);

        /**
         * @brief - Override. Subtract m from this Mat4 and return the difference.
         * 
         * @param m The matrix to subtract from this mat4
         * @return The difference of this matrix and m
         */
        Mat4 operator-(const Mat4& m) const;

        /**
         * @brief -= Override. Subtract m from this Mat4 and set this matrix to the result.
         * 
         * @param m The matrix to subtract from this mat4
         * @return The difference of this matrix and m
         */
        Mat4 operator-=(const Mat4& m);


        /**
         * @brief * Override. Multiply this matrix by a scalar value
         * 
         * @param s The scalar to multiply this mat4 by.
         * @return This Mat4 scaled by the value s
         */
        Mat4 operator*(const float& s) const;

        /**
         * @brief * Override.Multiply this matrix by a scalar value 
         * and set this Matrix to the result.
         * 
         * @param  s The scalar to multiply this mat4 by.
         * @return This Mat4 scaled by the value s
         */
        Mat4 operator*=(const float& m);

        /**
         * @brief * Override. Multiply this matrix by m in that order.
         * 
         * @param m The matrix to multiply this mat4 by.
         * @return The product of this mat4 and m
         */
        Mat4 operator*(const Mat4& m) const;

        /**
         * @brief * Override. Multiply this matrix by m in that order and set this Matrix to the result.
         * 
         * @param m The matrix to multiply this Mat4 by.
         * @return The product of this Mat4 and m
         */
        Mat4 operator*=(const Mat4& m);

        /**
         * @brief Find and return the transpose of this Matrix.
         * 
         * @return The transpose of this Matrix
         */
        Mat4 transpose() const;

        /**
         * @brief Find the tranpose of this Matrix set it to the result and then return it.  
         * 
         * @return The tranpose of this matrix
         */
        Mat4 transposeThis();

        /**
         * @brief Find and return the inverse of this Matrix
         * 
         * @return The inverse of this Matrix
         */
        Mat4 inverse() const;

        /**
         * @brief Find the inverse of this Matrix set it to the result and then return it.  
         * 
         * @return The inverse of this matrix
         */
        Mat4 inverseThis();

        /**
         * @brief Index into this Matrix to get the contents of the row at the 
         * given index. 
         * 
         * @param idx The row of the matrix to retrieve the contents of
         * @return MRow holding the corresponding row   
         */
        MRow operator[](int idx);

    private:
        float backingArr[16];



};

#endif