
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N (10)
typedef struct {
    int frontA;
    int endA;
    int dataA[100];
    int frontB;
    int endB;
    int dataB[100];
} MyStack;

//! leetcode 225
MyStack* myStackCreate() {
    MyStack* new = calloc(1, sizeof(MyStack));
    return new;
}

static void pushA(MyStack *obj, int x)
{
    int index = (obj->frontA + 1);
    if (index == 100)
        return;
    obj->dataA[obj->frontA] = x;
    obj->frontA = (obj->frontA + 1)%100;
}

static int popA(MyStack *obj)
{
    if (obj->frontA == obj->endA)
        return -1;
    int index = obj->endA;
    obj->endA = (obj->endA + 1) % 100;
    return obj->dataA[index];
}

static void pushB(MyStack *obj, int x)
{
    int index = (obj->frontB + 1);
    if (index == 100)
        return;
    obj->dataB[obj->frontB] = x;
    obj->frontB = (obj->frontB + 1)%100;
}

static int popB(MyStack *obj)
{
    if (obj->frontB == obj->endB)
        return -1;
    int index = obj->endB;
    obj->endB = (obj->endB + 1)%100;
    return obj->dataB[index];
}

void myStackPush(MyStack* obj, int x) 
{
    pushA(obj, x);
}

int myStackPop(MyStack* obj) 
{
    int index = obj->frontA - 1;
    int data = 0;
    while(obj->endA < index) {
        pushB(obj, popA(obj));
    }
    data = popA(obj);
    //! push back 

    while(obj->endB != obj->frontB) {
        pushA(obj, popB(obj));
    }
    return data;
}
int myStackTop(MyStack* obj) 
{
  int index = obj->frontA;
  return obj->dataA[index - 1];
}

bool myStackEmpty(MyStack* obj) {
  return obj->frontA == obj->endA;
}

void myStackFree(MyStack* obj) {
    if (obj)
        free(obj);
}

