#include <stdio.h>

int main()
{
    int hex;
    scanf("%x", &hex);

    // 32位有符号整型
    int signedInt = (int)hex;
    printf("%d\n", signedInt);

    // 32位无符号整型
    unsigned int unsignedInt = (unsigned int)hex;
    printf("%u\n", unsignedInt);

    // 32位浮点型（小数形式）
    float decimalFloat = *(float *)&hex;
    printf("%.6f\n", decimalFloat);

    // 32位浮点型（科学记数法）
    float scientificFloat = *(float *)&hex;
    printf("%.3e\n", scientificFloat);

    return 0;
}