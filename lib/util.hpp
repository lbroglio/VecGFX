#ifndef VGFX_UTIL
#define VGFX_UTIL

/**
 * @brief Compare two floats with an epsilon value to allow for
 * deviations caused by floating point math.
 * 
 * @param a First float to compare
 * @param b Second float to compare
 * @param epsilon Maximum difference between the two floats
 * @return true The difference between the floats is less than epsilon
 * @return false The difference between the floats is more than epsilon
 */
bool compareWithEpsilon(float a, float b, float epsilon = 0.00001);

#endif