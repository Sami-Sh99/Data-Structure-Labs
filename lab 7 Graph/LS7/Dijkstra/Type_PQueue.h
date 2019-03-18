#define N 20
typedef int element;
typedef struct cell {
	element data;
	int priority;
	struct cell *next;
}node;

typedef  struct {
	struct cell *front;
} pqueue;