typedef struct stack {
	double *array;
	int size;
	int pointer;
} stack;

stack* create(int size) {
	stack* s = (stack*)malloc(sizeof(stack));
	s->size = size;
	s->pointer = -1;
	s->array = (double*)malloc(s->size * sizeof(double));
}

void push(stack* s, double item) {
	if (s->pointer < s->size-1) 
		s->array[++s->pointer] = item;
}

double pop(stack* s) {
	return (double)((s->pointer == -1 ) ? -1 : s->array[s->pointer--]);
}

/* usage:
stack* s = create(32);	
push(s,3.14);
double value = pop(s);
*/