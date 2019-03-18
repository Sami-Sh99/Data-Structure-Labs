#pragma once
#define N 20
typedef int element;
typedef struct {
	element data;
	int priority;
}process;
typedef struct {
	process data[N];
	int front, rear;
}queue;

