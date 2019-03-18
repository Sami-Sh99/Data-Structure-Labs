#include "Queue.h"

extern void create_system(systemQ t);
extern void display(systemQ t);
extern int add(systemQ t, process e, element priority);
extern int deletePri(systemQ t);
extern int nb_elements(queue Q);
extern void exchange(element p1,element p2,systemQ t);