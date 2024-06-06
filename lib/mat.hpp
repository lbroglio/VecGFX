#ifndef VGFX_MATRIX
#define VGFX_MATRIX

#include<initializer_list>
#include<iostream>

namespace VecGFX{
    
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

                    /**
                     * @brief Index into this row to get the value at the column with 
                     * the given index
                     * 
                     * @param idx The column index to get the value of 
                     * @return The retrieved value
                     */
                    float const& operator[](int idx) const;
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
             * @brief A class holding a row from a const Mat4 class
             */
            class CMRow{
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

                    /**
                     * @brief Index into this row to get the value at the column with 
                     * the given index
                     * 
                     * @param idx The column index to get the value of 
                     * @return The retrieved value
                     */
                    float const& operator[](int idx) const;
                private:
                    const Mat4& parent;
                    int thisIdx;

                    /**
                     * @brief Construct a new MRow object correspondng to the given 
                     * row at the given index within the given Mat4. 
                     * 
                     * @param parent The Mat4 this MRow is a component of
                     * @param idx The index of the Row this class corresponds to
                     */
                    CMRow(const Mat4& parent, int idx): parent(parent), thisIdx(idx) {}
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
             * @brief -operator Override. Subtract m from this Mat4 and return the difference.
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
             * @brief * override. Multiply this matrix by a scalar value
             * 
             * @param s The scalar to multiply this mat4 by.
             * @return This Mat4 scaled by the value s
             */
            Mat4 operator*(const float& s) const;

            /**
             * @brief * override.Multiply this matrix by a scalar value 
             * and set this Matrix to the result.
             * 
             * @param  s The scalar to multiply this mat4 by.
             * @return This Mat4 scaled by the value s
             */
            Mat4 operator*=(const float& m);

            /**
             * @brief * override. Multiply this matrix by m in that order.
             * 
             * @param m The matrix to multiply this mat4 by.
             * @return The product of this mat4 and m
             */
            Mat4 operator*(const Mat4& m) const;

            /**
             * @brief * override. Multiply this matrix by m in that order and set this Matrix to the result.
             * 
             * @param m The matrix to multiply this Mat4 by.
             * @return The product of this Mat4 and m
             */
            Mat4 operator*=(const Mat4& m);

            /**
             * @brief == Override. Compare two matrices and return true if 
             * all of their components are the same.
             * 
             * @param m The matrix to compare this Mat4 to.
             * @return bool holding the truth value 
             * true: The two matrices are equal
             * false: The two matrices are not equal
             */
            bool operator==(const Mat4& m) const;

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
             * @brief Index into this Matrix to get the contents of the row at the 
             * given index. 
             * 
             * @param idx The row of the matrix to retrieve the contents of
             * @return MRow holding the corresponding row   
             */
            MRow operator[](int idx);

            /**
             * @brief Index into this Matrix to get the contents of the row at the 
             * given index. 
             * 
             * @param idx The row of the matrix to retrieve the contents of
             * @return MRow holding the corresponding row   
             */
            CMRow const operator[](int idx) const;

            /**
             * @brief Return the Mat4 as a standard array. Index for each element can be calculated with 
             * (row * 4) + column <br>
             * Allocates space for the array
             * 
             * @return Matrix as an array
             */
            float* asArray();

            /**
             * @brief Create a 3D transformation matrix for a rotation 30 degrees around
             * the x axis.
             * 
             * @param theta Number of degrees to rotate around the x axis
             * 
             * @return 3D transformation matrix for a rotation 30 degrees around
             * the x axis.
             */
            static Mat4 rotationX(float theta);

             /**
             * @brief Create a 3D transformation matrix for a rotation 30 degrees around
             * the y axis.
             * 
             * @param theta Number of degrees to rotate around the y axis
             * 
             * @return 3D transformation matrix for a rotation 30 degrees around
             * the y axis.
             */
            static Mat4 rotationY(float theta);

            /**
             * @brief Create a 3D transformation matrix for a rotation 30 degrees around
             * the z axis.
             * 
             * @param theta Number of degrees to rotate around the z axis
             * 
             * @return 3D transformation matrix for a rotation 30 degrees around
             * the z axis.
             */
            static Mat4 rotationZ(float theta);

            /**
             * @brief Create a 3D transformation matrix for a translation with the given 
             * x, y, and z amounts.
             * 
             * @param xShift Amount to translate in the x direction
             * @param yShift Amount to translate in the y direction
             * @param zShift Amount to translate in the z direction
             * 
             * @return 3D transformation matrix for a translation. 
             */
            static Mat4 translation(float xShift, float yShift, float zShift);

            /**
             * @brief Create a 3D transformation matrix for scaling with the given 
             * x, y, and z scaling factors.
             * 
             * @param xFactor Amount to scale in the x direction
             * @param yFactor Amount to scale in the y direction
             * @param zFactor Amount to scale in the z direction
             * 
             * @return 3D transformation matrix for scaling 
             */
            static Mat4 scale(float xFactor, float yFactor, float zFactor);


        private:
            float backingArr[16];

        /**
         * @brief * override. Perform scalar multiplication on this Vec3
         * 
         * @param s Scalar to multiply the elements of this Vector by
         * @return New Vector created after scaling
         */
        friend Mat4 operator*(const float& s, const Mat4& m);

        /**
         * @brief Create a string representation of a Mat4 and pass it into an output stream
         * 
         * @param o output stream to print to
         * @param v Mat4 to print a string representation of
         * @return The output string after the Mat4's representation is printed
         */
        friend std::ostream& operator<<(std::ostream& o, const Mat4& m);

    };

    /**
     * @brief Class holding a 3x3 Matrix 
     */
    class Mat3{
        public:
            /**
             * @brief A class holding a row from a Mat3 class
             */
            class MRow{
                friend class Mat3;
                public:
                    /**
                     * @brief Index into this row to get the value at the column with 
                     * the given index
                     * 
                     * @param idx The column index to get the value of 
                     * @return The retrieved value
                     */
                    float& operator[](int idx);

                    /**
                     * @brief Index into this row to get the value at the column with 
                     * the given index
                     * 
                     * @param idx The column index to get the value of 
                     * @return The retrieved value
                     */
                    float const& operator[](int index) const;
                private:
                    Mat3& parent;
                    int thisIdx;

                    /**
                     * @brief Construct a new MRow object correspondng to the given 
                     * row at the given index within the given Mat4. 
                     * 
                     * @param parent The Mat3 this MRow is a component of
                     * @param idx The index of the Row this class corresponds to
                     */
                    MRow(Mat3& parent, int idx): parent(parent), thisIdx(idx) {}
            };

            /**
             * @brief A class holding a row from a const Mat3 class
             */
            class CMRow{
                friend class Mat3;
                public:
                    /**
                     * @brief Index into this row to get the value at the column with 
                     * the given index
                     * 
                     * @param idx The column index to get the value of 
                     * @return The retrieved value
                     */
                    float& operator[](int idx);

                    /**
                     * @brief Index into this row to get the value at the column with 
                     * the given index
                     * 
                     * @param idx The column index to get the value of 
                     * @return The retrieved value
                     */
                    float const& operator[](int idx) const;
                private:
                    const Mat3& parent;
                    int thisIdx;

                    /**
                     * @brief Construct a new MRow object correspondng to the given 
                     * row at the given index within the given Mat4. 
                     * 
                     * @param parent The Mat4 this MRow is a component of
                     * @param idx The index of the Row this class corresponds to
                     */
                    CMRow(const Mat3& parent, int idx): parent(parent), thisIdx(idx) {}
            };

            /**
             * @brief Construct a new Mat3 object with the given contents. 
             * Contents should be provided as a list of 3, 3 entry long rows. With the top row 
             * in the 0 index, the second to the top row in the 1 index ...
             * 
             * @param initList Two dimension list containing the contents of the Matrix
             */
            Mat3(std::initializer_list<std::initializer_list<float>> initList);

            /**
             * @brief Construct a new Mat3 object. -- Default Constructor will be the identity Matrix
             * 
             */
            Mat3();

            /**
             * @brief Copy constructor create a new Mat4 with the same entries as another
             * 
             * @param m The Matrix to copy to create a new one
             */
            Mat3(const Mat3& m);

            /**
             * @brief +operator override. Add this Mat3 and m together and return the sum
             * 
             * @param m The matrix to add to this one
             * @return The sum of this Matrix and m
             */
            Mat3 operator+(const Mat3& m) const;

            /**
             * @brief += Override. Add this Mat3 and m together and set this matrix to the sum
             * 
             * @param m The matrix to add to this one
             * @return The sum of this Matrix and m
             */
            Mat3 operator+=(const Mat3& m);

            /**
             * @brief -operator override. Subtract m from this Mat3 and return the difference.
             * 
             * @param m The matrix to subtract from this Mat3
             * @return The difference of this matrix and m
             */
            Mat3 operator-(const Mat3& m) const;

            /**
             * @brief -= Override. Subtract m from this Mat3 and set this matrix to the result.
             * 
             * @param m The matrix to subtract from this Mat3
             * @return The difference of this matrix and m
             */
            Mat3 operator-=(const Mat3& m);


            /**
             * @brief * override. Multiply this matrix by a scalar value
             * 
             * @param s The scalar to multiply this Mat3 by.
             * @return This Mat3 scaled by the value s
             */
            Mat3 operator*(const float& s) const;

            /**
             * @brief * override.Multiply this matrix by a scalar value 
             * and set this Matrix to the result.
             * 
             * @param  s The scalar to multiply this Mat3 by.
             * @return This Mat3 scaled by the value s
             */
            Mat3 operator*=(const float& m);

             /**
             * @brief == Override. Compare two matrices and return true if 
             * all of their components are the same.
             * 
             * @param m The matrix to compare this Mat4 to.
             * @return bool holding the truth value 
             * true: The two matrices are equal
             * false: The two matrices are not equal
             */
            bool operator==(const Mat3& m) const;

            /**
             * @brief * override. Multiply this matrix by m in that order.
             * 
             * @param m The matrix to multiply this Mat3 by.
             * @return The product of this Mat3 and m
             */
            Mat3 operator*(const Mat3& m) const;

            /**
             * @brief * override. Multiply this matrix by m in that order and set this Matrix to the result.
             * 
             * @param m The matrix to multiply this Mat3 by.
             * @return The product of this Mat3 and m
             */
            Mat3 operator*=(const Mat3& m);

            /**
             * @brief Find and return the transpose of this Matrix.
             * 
             * @return The transpose of this Matrix
             */
            Mat3 transpose() const;

            /**
             * @brief Find the tranpose of this Matrix set it to the result and then return it.  
             * 
             * @return The tranpose of this matrix
             */
            Mat3 transposeThis();

            /**
             * @brief Index into this Matrix to get the contents of the row at the 
             * given index. 
             * 
             * @param idx The row of the matrix to retrieve the contents of
             * @return MRow holding the corresponding row   
             */
            MRow operator[](int idx);

            /**
             * @brief Index into this Matrix to get the contents of the row at the 
             * given index. 
             * 
             * @param idx The row of the matrix to retrieve the contents of
             * @return MRow holding the corresponding row   
             */
            CMRow const operator[](int idx) const;

            /**
             * @brief Return the Mat3 as a standard array. Index for each element can be calculated with 
             * (row * 3) + column <br>
             * Allocates space for the array
             * 
             * @return Matrix as an array
             */
            float* asArray();

        private:
            float backingArr[9];

        /**
         * @brief * override. Perform scalar multiplication on this Vec3
         * 
         * @param s Scalar to multiply the elements of this Vector by
         * @return New Vector created after scaling
         */
        friend Mat3 operator*(const float& s, const Mat3& m);

        /**
         * @brief Create a string representation of a Mat3 and pass it into an output stream
         * 
         * @param o output stream to print to
         * @param v Mat3 to print a string representation of
         * @return The output string after the Mat3's representation is printed
         */
        friend std::ostream& operator<<(std::ostream& o, const Mat3& m);

    };
}

#endif