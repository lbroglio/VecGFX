#include <cmath>

#include <cppunit/TestCase.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>

#include "../lib/vgfx.hpp"
#include "../lib/util.hpp"



using namespace VecGFX;

class VecGFXTests : public CppUnit::TestCase{
    public:

        // VEC4 TESTS

        /**
         * @brief Test that finding the dot product works for two Vec4 type vectors
         */
        void testDotProductVec4(){
            std::cout << "testDotProductVec4:\n";

            // Create two Vectors to test with
            Vec4 v1(2, 3, 4, 5);
            Vec4 v2(5, 4, 3, 2);

            // Calculate dot product of the Vectors 
            float dotProd = v1.dot(v2);

            // Assert that the dot product is as expected
            std::cout << "\tExpected: 44.0 : Actual: " << dotProd << "\n";
            CPPUNIT_ASSERT_EQUAL(44.0f, dotProd);

            

            // Create two Vectors to test decimal values
            Vec4 v1f(1.5, 1.5, 1.5, 1.5);
            Vec4 v2f(2, 2, 2, 2);

            // Calculate dot product of the Vectors 
            dotProd = v1f.dot(v2f);

            // Assert that the dot product is as expected
            std::cout << "\tExpected: 12.0 : Actual: " << dotProd << "\n";
            CPPUNIT_ASSERT(compareWithEpsilon(12.0, dotProd));

        }

        /**
         * @brief Test that the + operator works for two Vec4 type vectors
         */
        void testPlusVec4(){
            std::cout << "testPlusVec4:\n";

            // Vector to use as expected
            Vec4 EXPECT(10, 10, 10 ,10);

            // Create two Vectors to test with
            Vec4 v1(4, 3, 9, 2);
            Vec4 v2(6, 7, 1, 8);

            // Calculate sum of the Vectors 
            Vec4 sum = v1 + v2;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << sum << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, sum);

            

            // Create two Vectors to test decimal values
            Vec4 v1f(2.5, 7, 5.5, 1.5);
            Vec4 v2f(7.5, 3, 4.5, 8.5);

            // Calculate dot product of the Vectors 
            sum = v1f + v2f;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << sum << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, sum);

        }

        /**
         * @brief Test that the += operator works for two Vec4 type vectors
         */
        void testPlusEqualsVec4(){
            std::cout << "testPlusEqualsVec4:\n";

            // Vector to use as expected
            Vec4 EXPECT(10, 10, 10 ,10);

            // Create two Vectors to test with
            Vec4 v1(4, 3, 9, 2);
            Vec4 v2(6, 7, 1, 8);

            // Calculate sum of the Vectors 
            v1 += v2;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v1 << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v1);

            

            // Create two Vectors to test decimal values
            Vec4 v1f(2.5, 7, 5.5, 1.5);
            Vec4 v2f(7.5, 3, 4.5, 8.5);

            // Calculate dot product of the Vectors 
            v1f += v2f;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v1f << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v1f);

        }

        /**
         * @brief Test that the - operator works for two Vec4 type vectors
         */
        void testMinusVec4(){
            std::cout << "testMinusVec4:\n";

            // Vector to use as expected
            Vec4 EXPECT;

            // Create two Vectors to test with
            Vec4 v1(5, 10, 1, 4);
            Vec4 v2(5, 10, 1, 4);

            // Calculate difference of the Vectors 
            Vec4 diff = v1 - v2;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << diff << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, diff);

            // Create two Vectors to test decimal values
            Vec4 v1f(5.5, 100.1, 0.3, 12.5);
            Vec4 v2f(5.5, 100.1, 0.3, 12.5);

            // Calculate sum of the Vectors 
            diff = v1f - v2f;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << diff << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, diff);

        }

         /**
         * @brief Test that the - operator works for two Vec4 type vectors
         */
        void testMinusEqualsVec4(){
            std::cout << "testMinusEqualsVec4:\n";

            // Vector to use as expected
            Vec4 EXPECT(5, 12, 6, 4);

            // Create two Vectors to test with
            Vec4 v1(6, 20, 8, 14);
            Vec4 v2(1, 8, 2, 10);

            // Calculate difference of the Vectors 
            v1 -= v2;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v1 << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v1);

            // Create two Vectors to test decimal values
            Vec4 v1f(6.5, 112, 6, 5.7);
            Vec4 v2f(1.5, 100, 0, 1.7);

             // Calculate difference of the Vectors 
            v1f -= v2f;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v1f << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v1f);

        }

        /**
         * @brief Test that the * operator works for a Vec4 and a float
         */
        void testScalarVec4(){
            std::cout << "testScalarVec4:\n";

            // Vector to use as expected
            Vec4 EXPECT(10, 12, 6, 4);

            // Create two Vectors to test with
            Vec4 v(5, 6, 3, 2);

            // Calculate difference of the Vectors 
            Vec4 prod = 2 * v;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << prod << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, prod);

            // Create two Vectors to test decimal values
            EXPECT = Vec4(5, 11, 12, 13);
            Vec4 vf(2.5, 5.5, 6, 6.5);

             // Calculate difference of the Vectors 
            prod = vf * 2;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << prod << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, prod);
        }

        /**
         * @brief Test that the *= operator works for a Vec4 and a float
         */
        void testScalarEqualsVec4(){
            std::cout << "testScalarEqualsVec4:\n";

            // Vector to use as expected
            Vec4 EXPECT(10, 12, 6, 4);

            // Create two Vectors to test with
            Vec4 v(5, 6, 3, 2);

            // Calculate difference of the Vectors 
            v *= 2;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v);

            // Create two Vectors to test decimal values
            EXPECT = Vec4(5, 11, 12, 13);
            Vec4 vf(2.5, 5.5, 6, 6.5);

             // Calculate difference of the Vectors 
             vf *= 2;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << vf << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, vf);
        }

         /**
         * @brief Test that the != operator works for two Vec4 type vectors
         */
        void testNotEqualsVec4(){
            std::cout << "testNotEqualsVec4:\n";

            // Create two Vectors to test with
            Vec4 v1(2, 2.5, 2, 2);
            Vec4 v2(1, 2, 1, 1);

            // Assert that the result is as expected
            std::cout << "\tExpected: 1"  << " : Actual: " << (v1 != v2) << "\n";
            CPPUNIT_ASSERT(v1 != v2);

            // Create two Vectors to test decimal values
            Vec4 v1f(6.5, 100.1, 6, 3);
            Vec4 v2f(6.5, 100.1, 6, 3);

            // Assert that the result is as expected
            std::cout << "\tExpected: 0" << " : Actual: " << (v1f != v2f) << "\n";
            CPPUNIT_ASSERT(!(v1f != v2f));

        }

        /**
         * @brief Test that the = operator works for Vec4 type vectors
         */
        void testSetVec4(){
            std::cout << "tesSetVec4:\n";

            // Create Vectors to test with
            Vec4 EXPECT(1, 2, 3, 4);
            Vec4 v;
            v = EXPECT;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v);
        }

        /**
         * @brief Test that the magnitude method works for Vec4 type vectors
         */
        void testMagnitudeVec4(){
            std::cout << "testMagnitudeVec4:\n";

            // Create Vectors to test with
            float EXPECT = 8;
            Vec4 v(4, 4, 4, 4);

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v.magitude() << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v.magitude());
        }

        /**
         * @brief Test that the * operator works for Mat4 and Vec4
         */
        void testTransformOperatorVec4(){
            std::cout << "testTransformOperatorVec4:\n";

            // Create Vectors to test with
            Vec4 EXPECT(6, 6, 6, 2);
            Vec4 v(2, 2, 2, 2);
            Mat4 m({{1, 0, 0, 2},
                    {0, 1, 0, 2},
                    {0, 0, 1, 2},
                    {0, 0, 0, 1},
                });
            
            Vec4 res = m * v;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << res << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, res);
        }

        /**
         * @brief Test that the transform method works for a Vec4
         */
        void testTransformVec4(){
            std::cout << "testTransformVec4:\n";

            // Create Vectors to test with
            Vec4 EXPECT(6, 6, 6, 2);
            Vec4 v(2, 2, 2, 2);
            Mat4 m({{1, 0, 0, 2},
                    {0, 1, 0, 2},
                    {0, 0, 1, 2},
                    {0, 0, 0, 1},
                });
            
           v.transform(m);

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v);
        }

       // VEC3 TESTS

        /**
         * @brief Test that finding the dot product works for two Vec3 type vectors
         */
        void testDotProductVec3(){
            std::cout << "testDotProductVec3:\n";

            // Create two Vectors to test with
            Vec3 v1(2, 3, 4);
            Vec3 v2(5, 4, 3);

            // Calculate dot product of the Vectors 
            float dotProd = v1.dot(v2);

            // Assert that the dot product is as expected
            std::cout << "\tExpected: 34.0 : Actual: " << dotProd << "\n";
            CPPUNIT_ASSERT_EQUAL(34.0f, dotProd);

            

            // Create two Vectors to test decimal values
            Vec3 v1f(1.5, 1.5, 1.5);
            Vec3 v2f(2, 2, 2);

            // Calculate dot product of the Vectors 
            dotProd = v1f.dot(v2f);

            // Assert that the dot product is as expected
            std::cout << "\tExpected: 9.0 : Actual: " << dotProd << "\n";
            CPPUNIT_ASSERT(compareWithEpsilon(9.0, dotProd));

        }

        /**
         * @brief Test that the + operator works for two Vec3 type vectors
         */
        void testPlusVec3(){
            std::cout << "testPlusVec3:\n";

            // Vector to use as expected
            Vec3 EXPECT(10, 10, 10);

            // Create two Vectors to test with
            Vec3 v1(4, 3, 9);
            Vec3 v2(6, 7, 1);

            // Calculate sum of the Vectors 
            Vec3 sum = v1 + v2;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << sum << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, sum);

            

            // Create two Vectors to test decimal values
            Vec3 v1f(2.5, 7, 5.5);
            Vec3 v2f(7.5, 3, 4.5);

            // Calculate dot product of the Vectors 
            sum = v1f + v2f;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << sum << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, sum);

        }

        /**
         * @brief Test that the += operator works for two Vec3 type vectors
         */
        void testPlusEqualsVec3(){
            std::cout << "testPlusEqualsVec3:\n";

            // Vector to use as expected
            Vec3 EXPECT(10, 10, 10);

            // Create two Vectors to test with
            Vec3 v1(4, 3, 9);
            Vec3 v2(6, 7, 1);

            // Calculate sum of the Vectors 
            v1 += v2;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v1 << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v1);

            

            // Create two Vectors to test decimal values
            Vec3 v1f(2.5, 7, 5.5);
            Vec3 v2f(7.5, 3, 4.5);

            // Calculate dot product of the Vectors 
            v1f += v2f;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v1f << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v1f);

        }

        /**
         * @brief Test that the - operator works for two Vec3 type vectors
         */
        void testMinusVec3(){
            std::cout << "testMinusVec3:\n";

            // Vector to use as expected
            Vec3 EXPECT;

            // Create two Vectors to test with
            Vec3 v1(5, 10, 1);
            Vec3 v2(5, 10, 1);

            // Calculate difference of the Vectors 
            Vec3 diff = v1 - v2;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << diff << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, diff);

            // Create two Vectors to test decimal values
            Vec3 v1f(5.5, 100.1, 0.3);
            Vec3 v2f(5.5, 100.1, 0.3);

            // Calculate sum of the Vectors 
            diff = v1f - v2f;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << diff << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, diff);

        }

         /**
         * @brief Test that the - operator works for two Vec3 type vectors
         */
        void testMinusEqualsVec3(){
            std::cout << "testMinusEqualsVec3:\n";

            // Vector to use as expected
            Vec3 EXPECT(5, 12, 6);

            // Create two Vectors to test with
            Vec3 v1(6, 20, 8);
            Vec3 v2(1, 8, 2);

            // Calculate difference of the Vectors 
            v1 -= v2;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v1 << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v1);

            // Create two Vectors to test decimal values
            Vec3 v1f(6.5, 112, 6);
            Vec3 v2f(1.5, 100, 0);

             // Calculate difference of the Vectors 
            v1f -= v2f;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v1f << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v1f);

        }

        /**
         * @brief Test that the * operator works for a Vec3 and a float
         */
        void testScalarVec3(){
            std::cout << "testScalarVec3:\n";

            // Vector to use as expected
            Vec3 EXPECT(10, 12, 6);

            // Create two Vectors to test with
            Vec3 v(5, 6, 3);

            // Calculate difference of the Vectors 
            Vec3 prod = 2 * v;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << prod << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, prod);

            // Create two Vectors to test decimal values
            EXPECT = Vec3(5, 11, 12);
            Vec3 vf(2.5, 5.5, 6);

             // Calculate difference of the Vectors 
            prod = vf * 2;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << prod << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, prod);
        }

        /**
         * @brief Test that the *= operator works for a Vec3 and a float
         */
        void testScalarEqualsVec3(){
            std::cout << "testScalarEqualsVec3:\n";

            // Vector to use as expected
            Vec3 EXPECT(10, 12, 6);

            // Create two Vectors to test with
            Vec3 v(5, 6, 3);

            // Calculate difference of the Vectors 
            v *= 2;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v);

            // Create two Vectors to test decimal values
            EXPECT = Vec3(5, 11, 12);
            Vec3 vf(2.5, 5.5, 6);

             // Calculate difference of the Vectors 
             vf *= 2;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << vf << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, vf);
        }

         /**
         * @brief Test that the != operator works for two Vec3 type vectors
         */
        void testNotEqualsVec3(){
            std::cout << "testNotEqualsVec3:\n";

            // Create two Vectors to test with
            Vec3 v1(2, 2.5, 2);
            Vec3 v2(1, 2, 1);

            // Assert that the result is as expected
            std::cout << "\tExpected: 1"  << " : Actual: " << (v1 != v2) << "\n";
            CPPUNIT_ASSERT(v1 != v2);

            // Create two Vectors to test decimal values
            Vec3 v1f(6.5, 100.1, 6);
            Vec3 v2f(6.5, 100.1, 6);

            // Assert that the result is as expected
            std::cout << "\tExpected: 0" << " : Actual: " << (v1f != v2f) << "\n";
            CPPUNIT_ASSERT(!(v1f != v2f));

        }

        /**
         * @brief Test that the = operator works for Vec3 type vectors
         */
        void testSetVec3(){
            std::cout << "tesSetVec3:\n";

            // Create Vectors to test with
            Vec3 EXPECT(1, 2, 3);
            Vec3 v;
            v = EXPECT;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v);
        }

        /**
         * @brief Test that the magnitude method works for Vec3 type vectors
         */
        void testMagnitudeVec3(){
            std::cout << "testMagnitudeVec3:\n";

            // Create Vectors to test with
            float EXPECT = 4 * sqrt(3);
            Vec3 v(4, 4, 4);

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v.magitude() << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v.magitude());
        }

        /**
         * @brief Test that the * operator works for Mat3 and Vec3
         */
        void testTransformOperatorVec3(){
            std::cout << "testTransformOperatorVec3:\n";

            // Create Vectors to test with
            Vec3 EXPECT(6, 6, 0);
            Vec3 v(2, 2, 2);
            Mat3 m({{1, 0, 2},
                    {0, 1, 2},
                    {0, 0, 0}
                });
            
            Vec3 res = m * v;

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << res << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, res);
        }

        /**
         * @brief Test that the transform method works for a Vec3
         */
        void testTransformVec3(){
            std::cout << "testTransformVec3:\n";

            // Create Vectors to test with
            Vec3 EXPECT(6, 6, 0);
            Vec3 v(2, 2, 2);
            Mat3 m({{1, 0, 2},
                    {0, 1, 2},
                    {0, 0, 0}
                });
            
           v.transform(m);

            // Assert that the result is as expected
            std::cout << "\tExpected: " << EXPECT << " : Actual: " << v << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, v);
        }
        
        // MAT4 TESTS

        /**
         * @brief Test that the + operator works for Mat4 type matrices
         * 
         */
        void testAddMat4(){
            std::cout << "testAddMat4:\n";

            // Matrix to compare against
            Mat4 EXPECT({
                {5, 5, 5, 5},
                {5, 5, 5, 5},
                {5, 5, 5, 5},
                {5, 5, 5, 5},
            });

            // Matrices to add together
            Mat4 m1({
                {2, 3, 3, 2},
                {1.5, 5, 2.4, 5},
                {1.5, 5, 5, 4},
                {2, 3, 3, 2},
            });

            Mat4 m2({
                {3, 2, 2, 3},
                {3.5, 0, 2.6, 0},
                {3.5, 0, 0, 1},
                {3, 2, 2, 3},
            });

            Mat4 sumMat = m1 + m2;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << sumMat << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, sumMat);
        }

        /**
         * @brief Test that the += operator works for Mat4 type matrices
         * 
         */
        void testAddEqualsMat4(){
            std::cout << "testAddEqualsMat4:\n";

            // Matrix to compare against
            Mat4 EXPECT({
                {5, 5, 5, 5},
                {5, 5, 5, 5},
                {5, 5, 5, 5},
                {5, 5, 5, 5},
            });

            // Matrices to add together
            Mat4 m1({
                {2, 3, 3, 2},
                {1.5, 5, 2.4, 5},
                {1.5, 5, 5, 4},
                {2, 3, 3, 2},
            });

            Mat4 m2({
                {3, 2, 2, 3},
                {3.5, 0, 2.6, 0},
                {3.5, 0, 0, 1},
                {3, 2, 2, 3},
            });

           m1 += m2;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << m1 << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, m1);
        }

        /**
         * @brief Test that the - operator works for Mat4 type matrices
         * 
         */
        void testMinusMat4(){
            std::cout << "testMinusMat4:\n";

            // Matrix to compare against
            Mat4 EXPECT({
                {-1, -1, -1, -1},
                {-1, -1, -1, -1},
                {-1, -1, -1, -1},
                {-1, -1, -1, -1},
            });

            // Matrices to add together
            Mat4 m1({
                {2, 3, 3, 2},
                {1.5, 5, 2.4, 5},
                {1.5, 5, 5, 4},
                {2, 3, 3, 2},
            });

            Mat4 m2({
                {3, 4, 4, 3},
                {2.5, 6, 3.4, 6},
                {2.5, 6, 6, 5},
                {3, 4, 4, 3},
            });

            Mat4 diffMat = m1 - m2;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << diffMat << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, diffMat);
        }
        

        /**
         * @brief Test that the -= operator works for Mat4 type matrices
         * 
         */
        void testMinusEqualsMat4(){
            std::cout << "testMinusEqualsMat4:\n";

            // Matrix to compare against
            Mat4 EXPECT({
                {-1, -1, -1, -1},
                {-1, -1, -1, -1},
                {-1, -1, -1, -1},
                {-1, -1, -1, -1},
            });

            // Matrices to add together
            Mat4 m1({
                {2, 3, 3, 2},
                {1.5, 5, 2.4, 5},
                {1.5, 5, 5, 4},
                {2, 3, 3, 2},
            });

            Mat4 m2({
                {3, 4, 4, 3},
                {2.5, 6, 3.4, 6},
                {2.5, 6, 6, 5},
                {3, 4, 4, 3},
            });

            m1 -= m2;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << m1 << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, m1);
        }

        /**
         * @brief Test that the *= operator works for a Mat4 and a float
         * 
         */
        void testScaleEqualsMat4(){
            std::cout << "testScaleEqualsMat4:\n";

            // Matrix to compare against
            Mat4 EXPECT({
                {10, 10, 10, 3},
                {3, 10, 10, 10},
                {4, 4, 4, 4},
                {4, 4, 4, 4},
            });

            // Matrices to add together
            Mat4 m({
                {5, 5, 5, 1.5},
                {1.5, 5, 5, 5},
                {2, 2, 2, 2},
                {2, 2, 2, 2},
            });

            m *= 2;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << m << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, m);
        }

        /**
         * @brief Test that the * operator works for a Mat4 and a float
         * 
         */
        void testScaleMat4(){
            std::cout << "testScaleMat4:\n";

            // Matrix to compare against
            Mat4 EXPECT({
                {10, 10, 10, 3},
                {3, 10, 10, 10},
                {4, 4, 4, 4},
                {4, 4, 4, 4},
            });

            // Matrices to add together
            Mat4 m({
                {5, 5, 5, 1.5},
                {1.5, 5, 5, 5},
                {2, 2, 2, 2},
                {2, 2, 2, 2},
            });

            Mat4 prod = 2 * m;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << prod << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, prod);
        }

        /**
         * @brief Test that the * operator works for Mat4 type matrices
         * 
         */
        void testMultMat4(){
            std::cout << "testMultMat4:\n";

            // Matrix to compare against
            Mat4 EXPECT({
                {57, 69.5, 69.5, 57},
                {50, 62.5, 62.5, 58.75},
                {27, 32, 32, 27},
                {27, 32, 32, 27},
            });

            // Matrices to add together
            Mat4 m1({
                {5, 5, 5, 1.5},
                {1.5, 5, 5, 5},
                {2, 2, 2, 2},
                {2, 2, 2, 2},
            });

            Mat4 m2({
                {5, 5, 5, 2.5},
                {2.5, 5, 5, 5},
                {3, 3, 3, 3},
                {3, 3, 3, 3},
            });

            Mat4 prod = m1 * m2;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << prod << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, prod);
        }

        /**
         * @brief Test that the *= operator works for Mat4 type matrices
         * 
         */
        void testMultEqualsMat4(){
            std::cout << "testMultEqualsMat4:\n";

            // Matrix to compare against
            Mat4 EXPECT({
                {57, 69.5, 69.5, 57},
                {50, 62.5, 62.5, 58.75},
                {27, 32, 32, 27},
                {27, 32, 32, 27},
            });

            // Matrices to add together
            Mat4 m1({
                {5, 5, 5, 1.5},
                {1.5, 5, 5, 5},
                {2, 2, 2, 2},
                {2, 2, 2, 2},
            });

            Mat4 m2({
                {5, 5, 5, 2.5},
                {2.5, 5, 5, 5},
                {3, 3, 3, 3},
                {3, 3, 3, 3},
            });

            m1 *= m2;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << m1 << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, m1);
        }

        /**
         * @brief Test that the transpose method works for Mat4 type matrices
         * 
         */
        void testTransposeMat4(){
            std::cout << "testTransposeMat4:\n";

            // Matrix to compare against
            Mat4 EXPECT({
                {2, 5, 1, 3},
                {3, 6, 1, 3},
                {3, 6, 1, 3},
                {1.5, 2.5, 3.5, 4.5},
            });

            // Matrices to add together
            Mat4 m({
                {2, 3, 3, 1.5},
                {5, 6, 6, 2.5},
                {1, 1, 1, 3.5},
                {3, 3, 3, 4.5},
            });

            Mat4 res = m.transpose();

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << res << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, res);
        }

        /**
         * @brief Test that the transposeThis method works for Mat4 type matrices
         * 
         */
        void testTransposeThisMat4(){
            std::cout << "testTransposeThisMat4:\n";

            // Matrix to compare against
            Mat4 EXPECT({
                {2, 5, 1, 3},
                {3, 6, 1, 3},
                {3, 6, 1, 3},
                {1.5, 2.5, 3.5, 4.5},
            });

            // Matrices to add together
            Mat4 m({
                {2, 3, 3, 1.5},
                {5, 6, 6, 2.5},
                {1, 1, 1, 3.5},
                {3, 3, 3, 4.5},
            });

            m.transposeThis();

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << m << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, m);
        }

        /**
         * @brief Test that the [][] operator works for Mat4 type matrix
         * 
         */
        void testIndexMat4(){
            std::cout << "testIndexMat4:\n";
            
            // Matrices to add together
            Mat4 m({
                {2, 3, 3, 1.5},
                {5, 6, 6, 2.5},
                {1, 1, 1, 3.5},
                {3, 3, 3, 4.5},
            });

            // Assert that the matrix indexes are as expected
            std::cout << "\tExpected: " << 1.5 << " : Actual: " << m[0][3] << "\n";
            CPPUNIT_ASSERT(compareWithEpsilon(1.5, m[0][3]));

            std::cout << "\tExpected: " << 2 << " : Actual: " << m[0][0] << "\n";
            CPPUNIT_ASSERT(compareWithEpsilon(2, m[0][0]));

            std::cout << "\tExpected: " << 3 << " : Actual: " << m[3][2] << "\n";
            CPPUNIT_ASSERT(compareWithEpsilon(3, m[3][2]));
        }

        /**
         * @brief Test that the [][] operator works for setting values in a Mat4 type matrix
         * 
         */
        void testSetIndexMat4(){
            std::cout << "testSetIndexMat4:\n";
            
            // Matrices to add together
            Mat4 m({
                {2, 3, 3, 1.5},
                {5, 6, 6, 2.5},
                {1, 1, 1, 3.5},
                {3, 3, 3, 4.5},
            });

            m[2][2] = 8.8;

            // Assert that the matrix indexes are as expected
            std::cout << "\tExpected: " << 8.8 << " : Actual: " << m[2][2] << "\n";
            CPPUNIT_ASSERT(compareWithEpsilon(8.8, m[2][2]));

        }

        /**
         * @brief Test that the asArray method works for a Mat4 type matrix
         * 
         */
        void testAsArrayMat4(){
            std::cout << "testAsArrayMat4:\n";
            
            // Expected value
            float EXPECTED[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

            // Matrices to add together
            Mat4 m({
                {0, 1, 2, 3},
                {4, 5, 6, 7},
                {8, 9, 10, 11},
                {12, 13, 14, 15},
            });

            // Assert that the values match expected
            std::cout << "\tExpected: {";

            int i = 0;
            for(i =0; i < 16; i++){
                std::cout << EXPECTED[i] << ", ";
            }
             std::cout << "}\n\tActual: {";
            for(i =0; i < 16; i++){
                int xIdx = i / 4;
                int yIdx = i % 4;

                std::cout << m[xIdx][yIdx] << ", ";
            }
            std::cout << "}\n";

            for(i =0; i < 16; i++){
                int xIdx = i / 4;
                int yIdx = i % 4;

                CPPUNIT_ASSERT(compareWithEpsilon(EXPECTED[i], m[xIdx][yIdx]));

            }
        }

        /**
         * @brief Test that the rotationX function works
         * 
         */
        void testRotationX(){
            std::cout << "testRotationX:\n";

            // Matrix to compare against
            Mat4 EXPECT({
                {1, 0, 0, 0},
                {0, 0.707107, -0.707107, 0},
                {0, 0.707107, 0.707107, 0},
                {0, 0, 0, 1},
            });

            // Rotation matrix
            Mat4 m = Mat4::rotationX(45);


            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << m << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, m);
        }

        /**
         * @brief Test that the rotationY function works
         * 
         */
        void testRotationY(){
            std::cout << "testRotationY:\n";

            // Matrix to compare against
            Mat4 EXPECT({
                {0.707107, 0, 0.707107, 0},
                {0, 1, 0, 0},
                {-0.707107, 0, 0.707107, 0},
                {0, 0, 0, 1},
            });

            // Rotation matrix
            Mat4 m = Mat4::rotationY(45);


            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << m << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, m);
        }

        /**
         * @brief Test that the rotationZ function works
         * 
         */
        void testRotationZ(){
            std::cout << "testRotationZ:\n";

            // Matrix to compare against
            Mat4 EXPECT({
                {0.707107, -0.707107, 0, 0 },
                {0.707107, 0.707107, 0, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 1},
            });

            // Rotation matrix
            Mat4 m = Mat4::rotationZ(45);


            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << m << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, m);
        }

        /**
         * @brief Test that the translation function works
         * 
         */
        void testTranslation(){
            std::cout << "testTranslation:\n";

            // Matrix to compare against
            Mat4 EXPECT({
                {1, 0, 0, 3 },
                {0, 1, 0, 4},
                {0, 0, 1, 5},
                {0, 0, 0, 1},
            });

            // Rotation matrix
            Mat4 m = Mat4::translation(3, 4, 5);


            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << m << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, m);
        }

        /**
         * @brief Test that the scale function works
         * 
         */
        void testScale(){
            std::cout << "testScale:\n";

            // Matrix to compare against
            Mat4 EXPECT({
                {3, 0, 0, 0},
                {0, 4, 0, 0},
                {0, 0, 5, 0},
                {0, 0, 0, 1},
            });

            // Rotation matrix
            Mat4 m = Mat4::scale(3, 4, 5);


            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << m << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, m);
        }

        // MAT3 TESTS

        /**
         * @brief Test that the + operator works for Mat3 type matrices
         * 
         */
        void testAddMat3(){
            std::cout << "testAddMat3:\n";

            // Matrix to compare against
            Mat3 EXPECT({
                {5, 5, 5},
                {5, 5, 5},
                {5, 5, 5},
            });

            // Matrices to add together
            Mat3 m1({
                {2, 3, 3},
                {1.5, 5, 2.4},
                {1.5, 5, 5},
            });

            Mat3 m2({
                {3, 2, 2},
                {3.5, 0, 2.6},
                {3.5, 0, 0},
            });

            Mat3 sumMat = m1 + m2;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << sumMat << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, sumMat);
        }

        /**
         * @brief Test that the += operator works for Mat3 type matrices
         * 
         */
        void testAddEqualsMat3(){
            std::cout << "testAddEqualsMat3:\n";

            // Matrix to compare against
            Mat3 EXPECT({
                {5, 5, 5},
                {5, 5, 5},
                {5, 5, 5},
            });

            // Matrices to add together
            Mat3 m1({
                {2, 3, 3},
                {1.5, 5, 2.4},
                {1.5, 5, 5},
            });

            Mat3 m2({
                {3, 2, 2},
                {3.5, 0, 2.6},
                {3.5, 0, 0},
            });

           m1 += m2;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << m1 << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, m1);
        }

        /**
         * @brief Test that the - operator works for Mat3 type matrices
         * 
         */
        void testMinusMat3(){
            std::cout << "testMinusMat3:\n";

            // Matrix to compare against
            Mat3 EXPECT({
                {-1, -1, -1},
                {-1, -1, -1},
                {-1, -1, -1},
            });

            // Matrices to add together
            Mat3 m1({
                {2, 3, 3},
                {1.5, 5, 2.4},
                {1.5, 5, 5},
            });

            Mat3 m2({
                {3, 4, 4},
                {2.5, 6, 3.4},
                {2.5, 6, 6},
            });

            Mat3 diffMat = m1 - m2;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << diffMat << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, diffMat);
        }
        

        /**
         * @brief Test that the -= operator works for Mat3 type matrices
         * 
         */
        void testMinusEqualsMat3(){
            std::cout << "testMinusEqualsMat3:\n";

            // Matrix to compare against
            Mat3 EXPECT({
                {-1, -1, -1},
                {-1, -1, -1},
                {-1, -1, -1},
            });

            // Matrices to add together
            Mat3 m1({
                {2, 3, 3},
                {1.5, 5, 2.4},
                {1.5, 5, 5},
            });

            Mat3 m2({
                {3, 4, 4},
                {2.5, 6, 3.4},
                {2.5, 6, 6},
            });

            m1 -= m2;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << m1 << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, m1);
        }

        /**
         * @brief Test that the *= operator works for a Mat4 and a float
         * 
         */
        void testScaleEqualsMat3(){
            std::cout << "testScaleEqualsMat3:\n";

            // Matrix to compare against
            Mat3 EXPECT({
                {10, 10, 10},
                {3, 10, 10},
                {4, 4, 4},
            });

            // Matrices to add together
            Mat3 m({
                {5, 5, 5},
                {1.5, 5, 5},
                {2, 2, 2},
            });

            m *= 2;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << m << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, m);
        }

        /**
         * @brief Test that the * operator works for a Mat3 and a float
         * 
         */
        void testScaleMat3(){
            std::cout << "testScaleMat3:\n";

            // Matrix to compare against
            Mat3 EXPECT({
                {10, 10, 10},
                {3, 10, 10},
                {4, 4, 4},
            });

            // Matrices to add together
            Mat3 m({
                {5, 5, 5},
                {1.5, 5, 5},
                {2, 2, 2},
            });

            Mat3 prod = 2 * m;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << prod << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, prod);
        }

        /**
         * @brief Test that the * operator works for Mat3 type matrices
         * 
         */
        void testMultMat3(){
            std::cout << "testMultMat3:\n";

            // Matrix to compare against
            Mat3 EXPECT({
                {42, 54.5, 42},
                {35, 47.5, 43.75},
                {21, 26, 21},
            });

            // Matrices to multiply together
            Mat3 m1({
                {5, 5, 1.5},
                {1.5, 5, 5},
                {2, 2, 2},

            });

            Mat3 m2({
                {5, 5, 2.5},
                {2.5, 5, 5},
                {3, 3, 3},
            });

            Mat3 prod = m1 * m2;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << prod << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, prod);
        }

        /**
         * @brief Test that the *= operator works for Mat3 type matrices
         * 
         */
        void testMultEqualsMat3(){
            std::cout << "testMultEqualsMat3:\n";

            // Matrix to compare against
            Mat3 EXPECT({
                {42, 54.5, 42},
                {35, 47.5, 43.75},
                {21, 26, 21},
            });

            // Matrices to multiply together
            Mat3 m1({
                {5, 5, 1.5},
                {1.5, 5, 5},
                {2, 2, 2},

            });

            Mat3 m2({
                {5, 5, 2.5},
                {2.5, 5, 5},
                {3, 3, 3},
            });

            m1 *= m2;

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << m1 << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, m1);
        }

        /**
         * @brief Test that the transpose method works for Mat3 type matrices
         * 
         */
        void testTransposeMat3(){
            std::cout << "testTransposeMat3:\n";

            // Matrix to compare against
            Mat3 EXPECT({
                {2, 5, 1},
                {3, 6, 1},
                {1.5, 2.5, 3.5},
            });

            // Matrices to add together
            Mat3 m({
                {2, 3, 1.5},
                {5, 6, 2.5},
                {1, 1, 3.5},
            });

            Mat3 res = m.transpose();

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << res << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, res);
        }

        /**
         * @brief Test that the transposeThis method works for Mat3 type matrices
         * 
         */
        void testTransposeThisMat3(){
            std::cout << "testTransposeThisMat3:\n";

            // Matrix to compare against
            Mat3 EXPECT({
                {2, 5, 1},
                {3, 6, 1},
                {1.5, 2.5, 3.5},
            });

            // Matrices to add together
            Mat3 m({
                {2, 3, 1.5},
                {5, 6, 2.5},
                {1, 1, 3.5},
            });

            m.transposeThis();

            // Assert that the result is as expected
            std::cout << "Expected: \n" << EXPECT << "Actual: \n" << m << "\n";
            CPPUNIT_ASSERT_EQUAL(EXPECT, m);
        }

        /**
         * @brief Test that the [][] operator works for Mat3 type matrix
         * 
         */
        void testIndexMat3(){
            std::cout << "testIndexMat3:\n";
            
            // Matrices to add together
            Mat3 m({
                {2, 3, 1.5},
                {5, 6, 2.5},
                {1, 1, 3.5},
            });

            // Assert that the matrix indexes are as expected
            std::cout << "\tExpected: " << 1.5 << " : Actual: " << m[0][2] << "\n";
            CPPUNIT_ASSERT(compareWithEpsilon(1.5, m[0][2]));

            std::cout << "\tExpected: " << 2 << " : Actual: " << m[0][0] << "\n";
            CPPUNIT_ASSERT(compareWithEpsilon(2, m[0][0]));

            std::cout << "\tExpected: " << 4 << " : Actual: " << m[1][0] << "\n";
            CPPUNIT_ASSERT(compareWithEpsilon(5, m[1][0]));
        }

        /**
         * @brief Test that the [][] operator works for setting values in a Mat3 type matrix
         * 
         */
        void testSetIndexMat3(){
            std::cout << "testSetIndexMat3:\n";
            
            // Matrices to add together
            Mat3 m({
                {2, 3, 3},
                {5, 6, 6},
                {1, 1, 1},
            });

            m[2][2] = 8.8;

            // Assert that the matrix indexes are as expected
            std::cout << "\tExpected: " << 8.8 << " : Actual: " << m[2][2] << "\n";
            CPPUNIT_ASSERT(compareWithEpsilon(8.8, m[2][2]));

        }

        /**
         * @brief Test that the asArray method works for a Mat3 type matrix
         * 
         */
        void testAsArrayMat3(){
            std::cout << "testAsArrayMat3:\n";
            
            // Expected value
            float EXPECTED[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};

            // Matrices to add together
            Mat3 m({
                {0, 1, 2},
                {3, 4, 5},
                {6, 7, 8},
            });

            // Assert that the values match expected
            std::cout << "\tExpected: {";

            int i = 0;
            for(i =0; i < 9; i++){
                std::cout << EXPECTED[i] << ", ";
            }
             std::cout << "}\n\tActual: {";
            for(i =0; i < 9; i++){
                int xIdx = i / 3;
                int yIdx = i % 3;

                std::cout << m[xIdx][yIdx] << ", ";
            }
            std::cout << "}\n";

            for(i =0; i < 9; i++){
                int xIdx = i / 3;
                int yIdx = i % 3;

                CPPUNIT_ASSERT(compareWithEpsilon(EXPECTED[i], m[xIdx][yIdx]));

            }
        }
        
        /**
         * @brief Build and return the a Test Suit consisting of all this classes tests
         */
        CPPUNIT_NS::Test* suite(){
            CPPUNIT_NS::TestSuite* testSuite = new CPPUNIT_NS::TestSuite ("VecGFXTests");
            
            // add the tests
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testDotProductVec4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testPlusVec4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testPlusEqualsVec4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testMinusVec4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testMinusEqualsVec4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testScalarVec4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testScalarEqualsVec4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testNotEqualsVec4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testSetVec4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testMagnitudeVec4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testTransformOperatorVec4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testTransformVec4));
            
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testDotProductVec3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testPlusVec3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testPlusEqualsVec3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testMinusVec3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testMinusEqualsVec3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testScalarVec3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testScalarEqualsVec3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testNotEqualsVec3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testSetVec3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testMagnitudeVec3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testTransformOperatorVec3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testTransformVec3));

            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testAddMat4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testAddEqualsMat4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testMinusMat4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testMinusEqualsMat4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testMultMat4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testMultEqualsMat4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testScaleMat4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testScaleEqualsMat4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testTransposeMat4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testTransposeThisMat4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testIndexMat4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testSetIndexMat4));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testAsArrayMat4));

            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testRotationX));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testRotationY));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testRotationZ));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testTranslation));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testScale));

            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testAddMat3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testAddEqualsMat3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testMinusMat3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testMinusEqualsMat3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testMultMat3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testMultEqualsMat3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testScaleMat3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testScaleEqualsMat3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testTransposeMat3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testTransposeThisMat3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testIndexMat3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testSetIndexMat3));
            testSuite->addTest (new CPPUNIT_NS::TestCaller ("testConstructor", &VecGFXTests::testAsArrayMat3));

            return testSuite;
        }
};

// Main -- Run tests
int main (int argc, char* argv[]) {
    // Create Test
    VecGFXTests tests;

    // Create Test Runner
    CPPUNIT_NS::TestRunner runner;

    // Create test controller
    CPPUNIT_NS::TestResult controller;

    //--- Add a listener that colllects test result
    CPPUNIT_NS::TestResultCollector result;
    controller.addListener( &result );     

    // Run tests
    runner.addTest(tests.suite());
    runner.run(controller, "");

    std::cout << "Test Result: " << (result.wasSuccessful() ? "Passed" : "Failed") << std::endl;
    return result.wasSuccessful() ? 0 : 1;
}