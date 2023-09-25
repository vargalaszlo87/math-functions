typedef struct stack {
	double *array;
	int size;
	int pointer;
};

struct stack* create(int size) {
	struct stack* s = (struct stack*)malloc(sizeof(struct stack));
	s->size = size;
	s->pointer = -1;
	s->array = (double*)malloc(s->size * sizeof(double));
}

void push(struct stack* s, double item) {
	if (s->pointer < s->size-1) 
		s->array[++s->pointer] = item;
}

double pop(struct stack* s) {
	return (double)((s->pointer == -1 ) ? -1 : s->array[s->pointer--]);
}

/* usage:
struct stack* s = create(32);	
push(s,3.14);
double value = pop(s);
*/