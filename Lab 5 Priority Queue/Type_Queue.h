#define N 5
#define M 10
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef int element;
typedef element process;
typedef struct 
{
	element data[M]; /* queue content */
	int front, rear;
} queue;

typedef queue systemQ[N];		
