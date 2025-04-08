#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int BYTE_LEN = 20;

int exponent(int a, int b);
char* int_to_byte(int a, char* byte);
int byte_to_int(char* byte);
int logical_and(int a, int b);
int logical_or(int a, int b);
int logical_xor(int a, int b);
int maximum_and_under_threshold(int n, int k);
int maximum_or_under_threshold(int n, int k);
int maximum_xor_under_threshold(int n, int k);

int exponent(int a, int b)
{
    int output = a;
    if (b == 0)
    {
        return 1;
    }
    for (int i = 1 ; i < b ; i++){
        output *= a;
    }
    return output;
}

char* int_to_byte(int a, char* byte)
{
    for (int i = 0; i < BYTE_LEN; i++)
    {
        if (a % 2 == 1)
        {
            byte[BYTE_LEN-1 - i] = '1';
        }
        else
        {
            byte[BYTE_LEN-1 - i] = '0';
        }
        a = a/2;
    }
    byte[BYTE_LEN] = '\0';
    return byte;
}

int byte_to_int(char* byte)
{
    int output = 0;
    for (int i = 0; i < BYTE_LEN; i++)
    {
        if (byte[i] == '1')
        {
            output += exponent(2,(BYTE_LEN-1 - i));
        }
    }
    return output;
}

int logical_and(int a, int b)
{
    char aByte[BYTE_LEN+1];
    char bByte[BYTE_LEN+1];
    int_to_byte(a, aByte);
    int_to_byte(b, bByte);

    for (int i = 0 ; i < BYTE_LEN ; i++)
    {
        if (aByte[i] == '1' && bByte[i] != '1')
        {
            aByte[i] = '0';
        }
    }

    return byte_to_int(aByte);
}

int logical_or(int a, int b)
{
    char aByte[BYTE_LEN+1];
    char bByte[BYTE_LEN+1];
    int_to_byte(a, aByte);
    int_to_byte(b, bByte);
    for (int i = 0 ; i < BYTE_LEN ; i++)
    {
        if (bByte[i] == '1')
        {
            aByte[i] = '1';
        }
    }
    return byte_to_int(aByte);
}

int logical_xor(int a, int b)
{
    char aByte[BYTE_LEN+1];
    char bByte[BYTE_LEN+1];
    int_to_byte(a, aByte);
    int_to_byte(b, bByte);
    for (int i = 0 ; i < BYTE_LEN ; i++)
    {
        if ((bByte[i] == '1' && aByte[i] == '0') || (aByte[i] == '1' && bByte[i] == '0'))
        {
            aByte[i] = '1';
        }
        else
        {
            aByte[i] = '0';
        }
    }

    return byte_to_int(aByte);
}

int maximum_and_under_threshold(int n, int k)
{
    int max = 0;
    int andResult;
    for (int i = 1 ; i < n ; i++)
    {
        for (int j = i+1 ; j <= n ; j++)
        {
            andResult = logical_and(i,j);
            if (andResult > max && andResult < k)
            {
                max = andResult;
            }
        }
    }

    return max;
}

int maximum_or_under_threshold(int n, int k)
{
    int max = 0;
    int orResult;
    for (int i = 1 ; i < n ; i++)
    {
        for (int j = i+1 ; j <= n ; j++)
        {
            orResult = logical_or(i,j);
            if (orResult > max && orResult < k)
            {
                max = orResult;
            }
        }
    }

    return max;
}

int maximum_xor_under_threshold(int n, int k)
{
    int max = 0;
    int xorResult;
    for (int i = 1 ; i < n ; i++)
    {
        for (int j = i+1 ; j <= n ; j++)
        {
            xorResult = logical_xor(i,j);
            if (xorResult > max && xorResult < k)
            {
                max = xorResult;
            }
        }
    }

    return max;
}

int main()
{
    char byte[BYTE_LEN+1];
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d\n", maximum_and_under_threshold(n,k));
    printf("%d\n", maximum_or_under_threshold(n,k));
    printf("%d\n", maximum_xor_under_threshold(n,k));
    return 0;
}

