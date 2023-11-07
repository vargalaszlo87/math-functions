typedef struct EulerVariables {
	float
		t0,
		t,
		y0,
		y,
		h;
	int step;
} EulerVariables;

void euler(struct EulerVariables *e, float (*f)(float, float)) {
	int i = -1;
	e->h = (e->t - e->t0)/e->step;
    while(++i < e->step) {
        e->y = e->y0 + e->h * f(e->t0,e->y0);        
        e->y0 = e->y;       
        e->t0 += e->h;
		#ifdef DEBUG
			printf ("t0: %f\ty0: %f\ty: %f\n",e->t0, e->y0, e->y);
		#endif        
    }
}

/*

usage:

Add this header:
	include <math.h>

Write your equation:
	float eq(float t, float y) {
		return pow(y,2)-y*sin(t)+cos(t);
	}

For example add into your main function:
	struct EulerVariables es;
	es.t0 = 0;
	es.y0 = 0;
	es.t = 3.1;
	es.step = 10000;		
	euler(&es, &eq);
	
	printf ("Result: y(%lf) = %lf",es.t,es.y);	

*/
