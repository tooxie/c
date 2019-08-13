/*
 * Given the triangle of consecutive odd numbers:
 *              1
 *           3     5
 *        7     9    11
 *    13    15    17    19
 * 21    23    25    27    29
 * ...
 *
 * Calculate the row sums of this triangle from the row index (starting at index 1) e.g.:
 *
 * rowSumOddNumbers(1); // 1                      ->  1 / 1 =  1 = 1^0
 * rowSumOddNumbers(2); // 3 + 5 = 8              ->  8 / 2 =  4 = 2^1
 * rowSumOddNumbers(3); // 7 + 9 + 11 = 27        -> 27 / 3 =  9 = 3^2
 * rowSumOddNumbers(4); // 13 + 15 + 17 + 19 = 64 -> 64 / 4 = 16 = 4^3
 *
 */
#include <inttypes.h>

uint64_t rowSumOddNumbers(uint32_t n)
{
    return powl(n, 2) * n;
}
