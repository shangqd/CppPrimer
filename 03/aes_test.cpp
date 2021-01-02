#include <wmmintrin.h>
#include <stdio.h>

//g++ aes_test.cpp -std=c++11 -msse2 -maes -o test

void print128_num(__m128i var_)
{
    u_int16_t *val = (u_int16_t*)&var_; 
    printf("Numerical: %i %i %i %i %i %i %i %i \n",  
             val[0], val[1], val[2], val[3], 
             val[4], val[5], val[6], val[7]);
}

int main()
{
    __m128i a;
    __m128i res;
    __m128i key;
    u_int64_t *p1 = (u_int64_t*)&a;
    u_int64_t *p2 = (u_int64_t*)&key;
    *p1 = 0x8899AABBCCDDEEFF;
    *(p1+1) = 0x0123456789ABCDEF;
    *p2 = 0x0022446688AACCEE;
    *(p2+1) = 0x1133557799BBDDFF;

    res = _mm_aesenc_si128(a, key);

    print128_num(res);
}