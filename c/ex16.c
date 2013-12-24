#include <stdio.h> 
#include <assert.h> 
#include <stdlib.h> 
#include <string.h> 

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight) 
{
    struct Person *who = malloc(sizeof(struct Person));
    //check to see that memory is good
    assert(who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void Person_destroy(struct Person *who)
{
    assert(who != NULL);

    free(who->name);
    free(who);
}

void Person_print(struct Person *who)
{
    printf("Name: %s \n", who->name);
    printf("\t Age: %d \n", who->age);
    printf("\t Height: %d \n", who->height);
    printf("\t Weight: %d \n", who->weight);
}

int main(int argc, char *argv[])
{
    //make two people structures
    struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
    struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

    printf("joe is at memory location %p \n", joe);
    printf("frank is at location %p \n", frank);

    //make everyone age 20 years
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    //destroy to clean up memory
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}








