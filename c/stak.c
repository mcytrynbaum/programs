#include <stdio.h> 
#include <string.h> 
#include <errno.h> 
#include <stdlib.h> 
#include <assert.h>

#define ROWS 100

//time to write a stack 
//give it a defined number of rows to start 

struct Line {
    int x; 
    int y;
};

//may need to modify this to contain a pointer instead
struct Database {
    struct Line lines[ROWS];
};

struct Stk {
    struct Database *db;
    int size;
};

//need to make this clean up data structures
void die(const char *die_string) 
{
    if(errno) {
        perror(die_string);
    } else {
        printf("ERROR: %s \n", die_string);
    }

    exit(1);
}

//Need a function for initializing the stack 
void stk_initial(struct Stk *stk) 
{
    int i = 0;
    for(i = 0; i < ROWS; i++) {

        struct Line *lp = malloc(sizeof(struct Line));
       
        lp->x = 0;
        lp->y = 0;

        stk->db->lines[i] = *lp;

    }

}

//returns a pointer to a newly created stack 
struct Stk *stk_create()
{
    struct Stk *stk = malloc(sizeof(struct Stk));
    if(!stk) die("memory problem creating stk");

    stk->db = malloc(sizeof(struct Database));
    if(!stk->db) die("memory problem, exiting");

    stk->size = 0; 

    stk_initial(stk);

    return stk;
}


void stk_push(int x, int y, struct Stk *stk) 
{
    int n = stk->size;

    if(n == ROWS) {
        die("Out of room");
    }
    
    struct Line *ln = &stk->db->lines[n];

    ln->x = x;
    ln->y = y; 

    stk->size += 1; 

}

void stk_pop(struct Stk *stk) 
{

    int n = stk->size;
    if(n == 0) {
        die("Nothing on the stack to pop");
    }

    struct Line *ln = &stk->db->lines[n-1];

    ln->x = 0;
    ln->y = 0;
    stk->size -= 1; 

}

void stk_print(struct Stk *stk)
{
    int i;
    int n = stk->size;

    printf("Stack currently has %d entries: \n", n);
    for(i = 0; i < n; i++) {

        //find a way to do without this pointer 
        struct Line *ln = &stk->db->lines[i];
        int x = ln->x;
        int y = ln->y; 

        printf("row %d ----- x = %d, y = %d. \n", i + 1, x, y);
    }
}

int main(int argc, char *argv[]) 
{
    struct Stk *stk = stk_create();

    stk_push(1,1,stk);
    stk_push(2,2,stk);
    stk_push(3,3,stk);
    stk_pop(stk);

    stk_print(stk);

    return 0;
}








