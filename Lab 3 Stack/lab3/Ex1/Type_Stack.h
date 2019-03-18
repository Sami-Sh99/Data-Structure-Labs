#define N 20

typedef int element1;
typedef struct cell {
	element1 data;
	struct cell * next;
} *list;


typedef list element;

typedef struct  {
	element data[N]; 
	int top;
} stack;
