#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get(int arg){
    return arg;
}

int set(int age){
    return age < 0 ? 0: age;
}

struct Person{
    char name[16];
    int age;
    int (*get)(int);
    int (*set)(int);
};

struct Person* new(char* arg_name, int arg_age){
    struct Person* new_person = malloc(sizeof(struct Person));
    strcpy(new_person->name,arg_name);

    new_person->get = get;
    new_person->set = set;

    new_person->age = get(set(arg_age));
}

int main(){
    struct Person* Yun = new("yunseok",-1);
    printf("%s,%d\n",Yun->name,Yun->age);
}