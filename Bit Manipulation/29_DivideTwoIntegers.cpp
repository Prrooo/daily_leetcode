/*Question----------------------------------------------------------------------------------------------*/
/**/
/*Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.*/
/**/
/*The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.*/
/**/
/*Return the quotient after dividing dividend by divisor.*/
/**/
/*Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.*/
/**/
/**/
/**/
/*Example 1:*/
/**/
/*Input: dividend = 10, divisor = 3*/
/*Output: 3*/
/*Explanation: 10/3 = 3.33333.. which is truncated to 3.*/
/*Example 2:*/
/**/
/*Input: dividend = 7, divisor = -3*/
/*Output: -2*/
/*Explanation: 7/-3 = -2.33333.. which is truncated to -2.*/



/*solution -----------------------------------------------------------------------------------------*/
/**/
/*Divide using bit manipulation*/
/**/
/*Approach*/
/*First, we handle the special case wheredividendis equal todivisor. In this case, we return 1.*/
/*We initialize an unsigned integeransto store the result of the division.*/
/*We also initialize a variablesignto keep track of the sign of the result. If eitherdividendordivisoris negative,signis set to -1.*/
/*Next, we take the absolute values ofdividendanddivisor(since we'll be working with positive integers).*/
/*We enter a loop where we repeatedly subtract multiples ofdivisorfromdividenduntildividendbecomes less thandivisor.*/
/*Inside the loop:*/
/*We use a nested loop to find the largest power of 2 (denoted bycount) such thatd << (count + 1)is less than or equal ton.*/
/*We subtractd << countfromn.*/
/*We add1 << counttoans.*/
/*After the loop, we check if the result exceeds the maximum 32-bit signed integer value (i.e.,1 << 31). If it does and the sign is positive, we return the maximum integer value. Otherwise, we return the result with the appropriate sign.*/
/*Complexity*/
/*Time complexity: 0((log n)^2)*/
/*Both the while loops being O(log n)*/
/*Space complexity: 0(1)*/
/*Code*/

#include <bits/stdc++.h>
#include <climits>
using namespace std;

int divide(int divident, int divisor) {
  unsigned int ans = 0;
  int sign = 1;
  if (divident == divisor)
    return 1;
  if ((divident > 0 && divisor < 0) || (divident < 0 && divisor > 0)) {
    sign = -1;
  }
  unsigned int n = abs(divident), b = abs(divisor);
  while (n >= b) {
    int count = 0;
    while (n > b << (count + 1)) {
      count++;
    }
    ans += 1 << count;
    n -= b << count;
  }
  if (ans == (1 << 31) && sign == 1)
    return INT_MAX;
  return sign * ans;
}

int main() {
  int divident, divisor;
  cin >> divident >> divisor;
  cout << divide(divident, divisor);
  return 0;
}
