#include <stdio.h>

int main(int argc, char *argv[]) 
{
    //print out each string in argv

    int i = 0;
    while(i < argc) {
        printf("here is your arg number %d: %s \n", i, argv[i]);
        i++;
    }

    //time to make my own string
    char *mystring[] = {"here", "there"};
    int num = 2;

    i = 0;
    while(i < num) {
        printf("element %d is %s \n", i, mystring[i]);
        i++;
    }

    return 0;
}

