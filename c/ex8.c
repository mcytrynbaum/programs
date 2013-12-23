#include <stdio.h> 

int main(int argc, char *argv[])
{
    int areas[] = {10,12,13,14,20};
    char name[] = "Zed";
    char full_name[] = {
        'Z', 'e', 'd', '\0'
    };

    //warning: here is a warning
    
    printf("the size of an int %lu \n", sizeof(int));
    printf("the size of areas (int[]) %lu \n", sizeof(areas));
    printf("the number of ints in areas: %lu \n", sizeof(areas)/sizeof(int));
    printf("the first area is %d the 2nd %d. \n", areas[0], areas[1]);
    printf("the size of a char: %lu \n", sizeof(char));
    printf("the size of name (char[]) %lu \n", sizeof(name));
    printf("the number of chars: %lu \n", sizeof(name)/sizeof(char));
    printf("the size of full_name (char[]); %lu \n", sizeof(full_name));
    printf("the number of chars %lu \n", sizeof(full_name)/sizeof(char));

    areas[0] = 13;
    printf("here we modify the first area to 13 %d \n.", areas[0]);

    name[0] = 'M';
    printf("here we modify the first char to m: %c \n", name[0]);

    return 0;
}


