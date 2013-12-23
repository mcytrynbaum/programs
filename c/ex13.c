#include <stdio.h> 

int main(int argc, char *argv[])
{
    if(argc !=2) {
        printf("you suck \n");
        return 1;
    }

    int i = 0;
    for(i = 0; argv[1][i] != '\0'; i++) {
        char letter = argv[1][i];

        switch(letter) {
            case 'a':
            case 'A':
                printf("it was an a \n");
                break;

            case 'e':
            case 'E':
                printf("it was an e \n");
                break;

            default: 
                printf("no dice \n");

            }
    }
    return 0;
}
