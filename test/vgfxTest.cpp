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