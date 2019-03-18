#define N 20
typedef int element;
struct cell {
	element data;
	int priority;
	struct cell *next;
};

typedef  struct {
	struct cell *front;
} pqueue;