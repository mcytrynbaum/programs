#include <stdio.h> 


void print_pnt(int *pnt, int count)
{
    int i = 0;

    for(i = 0; i < count; i++) {
        printf("here we go %d \n", pnt[i]);
    }
    printf("done \n");
}



int main(int argc, char *argv[])
{
    //create two super awesome arrays 
    int ages[] = {23, 48, 12, 89, 2};

    //get the size of our array
    int count = sizeof(ages)/sizeof(int);

    int *pnt = ages;

    print_pnt(pnt, count);

    return 0;
}




