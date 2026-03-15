//A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);

    int left = 0;
    int right = strlen(str) - 1;
    char temp;

    while(left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }

    printf("%s", str);

    return 0;
}