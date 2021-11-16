#include "bits/stdc++.h"
using namespace std;

/* The operators |, &, and ~ act on individual bits in parallel. They can be used only on integer types. a | b does an independent OR operation of each bit of a with the corresponding bit of b to generate that bit of the result.

The operators ||, &&, and ! act on each entire operand as a single true/false value. Any data type can be used that implicitly converts to bool. Many data types, including float implicitly convert to bool with an implied !=0 operation. */

/* property about left shift operator ( << )
if we assume that the leading y bits are 0, then x << y is equivalent to x * 2^y
similarly x >> y is equivalent to floor (x/2^y) */

/* bitwise not operator ( ~ )   
inverts all the bits
if we have n bits then the maximum no we can have is 2^n - 1 ( ex for 3 bits max no is 7 which is 111)
if we have 32 bits max no we can have is 2^32 -1 which is 4,29,49,67,295 which is 111.....111 (32 one's)
for unsigned integers:
so if x is 1 (000....001) then ~x is 111....110 so it is 2^32 - 1 - 1 which is 4,29,49,67,294
if x is 5 (000....0101) then ~x is 111....1010 which is 2^32 - 1 - 5 which is 4,29,49,67,290 */

// for signed integers:
/*
we use 31 bits to represent the no and the leading one bit to represent if it's positive or negative - 0 if it's positive and 1 if it is negative
so ~ of a positive no is going to be a negative integer 
*/

int getBit (int n, int pos) {
    // if we want to know which digit is at a given position in a binary number
    // we can create a number with 1 at the given position (using left shift operator)
    // suppose we want to know which digit is at pos 2 in the number n = 0101 (start indexing from right from 0)
    // then we create another number 0100 using left shift operator on 1 (0001) by 2
    // then take logical and (&) of given number and our number
    // so in the result digits at all other places would be 0  (result = 0100)
    // if result is 0 then the digit was 0 at the required position otherwise it was 1
    // if n & (n << i) != 0 then bit is 1   (i is the position)

    return (n & (1<<pos)) != 0;
}

int setBit(int n, int pos) {
    // if we want to set bit (1) at a particular position
    // ex if we want to convert 0101 to 0111 then we will set bit at pos 1
    // again we will create a number with bit at required pos and return or with our number

    return (n | (1<<pos));
}

int clearBit (int n, int pos) {
    // create 1<<pos, negate it, take and with n
    return n & (~(1<<pos));
}

int updateBit (int n, int pos, int value) {
    // update bit is clearBit + setBit with given value (0 or 1)
    //clearBit
    int mask = ~(1<<pos);
    n = n & mask;
    // setBit (0 or 1)
    return (n | (value<<pos));
}

/* right most bit (1) is called the right most set bit
   if binary no is 10110 then bit at index 1 is called right most set bit or rsb
   00010 is mask of rsb which can be obtained by & of n and 2's compliment of n 
   n is 10110 so 1's compliment is n' = 01001 so 2's compliment is n'+1 = 01010 = n"
   and mask is n & n" which is 00010*/

bool powOf2 (int n) {
    /*if n = 6 = 0110 then n-1 = 5 can be written by flipping the right most set bit (1) and the digits before it
    so 5 can be written as 0101
    similarly 8 = 1000 so n-1 = 7 = 0111
    if we take & of n and n-1 then the answer has same bits as n except the rightmost set bit
    0110 & 0101 =  0100
    if n is a power of 2 then n & n-1 would be 0 using the above logic
    1000 & 0111 = 0000 */

    // return !(n & n-1);  this doesn't cover the corner case where n is 0
    return (n && !(n & n-1));
}

int noOf1 (int n) {
    /* we have to calculate no of 1 in binary representation of n
    n & n-1 has same bits as n except rightmost set bit 
    that is it has one less 1 than n
    we then change value of n with n & n-1 and continue till n is a power of 2 since then n & n-1 is 0
    the no of times we do this is the no of 1 in n */

    int count = 0;
    while (n) {
        n = (n & n-1);
        count++;
    }
    return count;
}

void subSets (int arr[], int n) {
    /* we can print subsets using bit manip
    if there are 3 elements in a array then there are 2^n-1 sub sets
    write no from 0 to n-1 in their binary representation
    if there is 1 at pos of element, print it else skip
    ex: arr = {a, b, c}
    _       000     0
    c       001     1
    b       010     2
    b c     011     3
    a       100     4
    a c     101     5
    a b     110     6
    a b c   111     7
    check if bit is present using the get bit method discussed above
    */

    for (int i=0; i < (1<<n); i++) {        // i<<n is 2^n
        for (int j=0; j<n; j++) {
            if (i & (1<<j))
                cout << arr[j] << " ";
        }
        cout << endl;
    }        
}

int uniqueElement (int arr[], int n) {
    // find the only unique element in the arr, all other elements repeat atleast once
    /*for (int i = 0; i < n; i++) {
    xorsum = xorsum ^ arr[i];
    }

    Let's dry run this for arr[] = {1, 2, 3, 4, 1, 2, 3}:
    what we can write:
    xorsum = 0 ^ 1;
    xorsum = 0 ^ 1 ^ 2;
    .
    .
    .
    xorsum = 0 ^ 1 ^ 2 ^ 3 ^ 4 ^ 1 ^ 2 ^ 3;
    By Commutative Property -
    xorsum = 0 ^ (1 ^ 1) ^ (2 ^ 2) ^ (3 ^ 3) ^ 4;
    xorsum = 0 ^ 0 ^ 0 ^ 0 ^ 4;
    xorsum = 4;
    and boom! That's the answer*/

    int xorSum = 0;
    for (int i=0; i<n; i++) 
        xorSum = xorSum^arr[i];

    return xorSum;
}

void twoUniqueElements (int arr[], int n) {
    /* all elements repeat atleast once except two, we have to print those two
    if we take xor of all the elements then we will get xor of the two non repeating elements
    ex if arr[] = {36, 50, 24, 56, 36, 24, 42, 50}
    here 56 and 42 are non repeating elements so xor of arr = 56^42 = 18
        56 = 1 1 1 0 0 0
        42 = 1 0 1 0 1 0
    42^56  = 0 1 0 0 1 0 = 18
    it means wherever there is a bit in the xor, 42(x) and 57(y) have diff bits
    in the original array, odd no of elements have bit at index 1 and 4 that's why result has a bit at index 1 and 4
    if we separate those elements who have bit at index 1 and those who don't have bit have index 1, 
    42 and 56 will fall in diff groups since they both cannot have the same bit at index 1
    therefore in both of these groups, only 1 elements is non repeating and rest are repeating so we can 
    find the non repeating element by taking xor */
    // let x and y be the 2 non repeating elements

    int xXORy = 0;
    for (int i=0; i<n; i++) 
        xXORy = xXORy^arr[i];
    // we now have xor of the two non repeating elements

    // now to check which numbers have a bit at index 1 (or at the index where the right most set bit is) when need mask of right most set bit (rsbm)     
    int rsbm = xXORy & -xXORy;
    int x = 0, y = 0;  // two non repeating elements
    for (int i=0; i<n; i++) {
        if ((arr[i] & rsbm) == 0)
            x = x^arr[i];
        else    
            y = y^arr[i];
    }
    cout << x << " " << y << endl;
}

int oneUniqueOtherThree (int arr[] ,int n) {
    /* In an array all elements repeat thrice except one which appears only once
    if we count the number of bits at a particular index then it will be 3*(no of elements which appeat thrice) + 1 if the unique element also has a bit at that index
    so if take the modulo of no of bits at each index we will get the binary representation of unique element */
    int bitArr[64];
    int answer = 0;
    for (int i=0; i<64; i++) {
        int sum = 0;
        for (int j=0; j<n; j++) {
            if (getBit(arr[j], i))
                sum++;
        }
        sum = sum%3;
        answer = updateBit(answer, i, sum);
    }
    return answer;
}

int main () {
    // cout << getBit(5, 2) << endl;         //1
    // cout << setBit(5, 1) << endl;         //7
    // cout << clearBit(13, 2) << endl;      // 9
    // cout << updateBit(5, 1, 1) << endl;   // 7
    //cout << boolalpha << powOf2(8) << " " << powOf2(0) << endl;
    //cout << noOf1(19) << endl;
    // int arr[] = {1, 2, 3, 4};
    // subSets(arr, 4);
    // int arr[] = {1, 2, 3, 4, 3, 2, 1};
    // cout << uniqueElement(arr, 7) << endl;      // 4
    // int arr[] = {1, 2, 3, 4, 5, 3, 2, 1};
    // twoUniqueElements(arr, 8);

    int arr[] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 3};
    cout << oneUniqueOtherThree(arr, 10) << endl;
}