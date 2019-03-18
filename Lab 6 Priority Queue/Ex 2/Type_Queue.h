

typedef int element;
typedef struct cell {
	element data;
	int priority;
	struct cell*next;
}process;

typedef struct {
	process*front, *rear;
}queue;