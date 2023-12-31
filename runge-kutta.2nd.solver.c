typedef struct RK2Variables {
	float
		t0,
		t,
		y0,
		y,
		h,
		k[2];
	int step;
} RK2Variables;

void rk2(struct RK2Variables *r, float (*f)(float, float)) {
	int i = -1;
	r->h = (r->t-r->t0)/r->step;
	while (++i < r->step) {
		r->k[0] = r->h * f(r->t0, r->y0);
		r->k[1] = r->h * f(r->t0 + r->h/2, r->y0 + r->k[0]/2);	
		#ifdef DEBUG
			printf ("t0: %f\ty0: %f\ty: %f\n",r->t0, r->y0, r->y);
		#endif
		r->y = r->y0 + r->k[1];
		r->t0 += r->h;
		r->y0 = r->y;
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
	struct RK2Variables os;
	os.t0 = 0;
	os.y0 = 0;
	os.t = 3.1;
	os.step = 10000;
	rk2(&os, &eq);
	
	printf ("Result: y(%lf) = %lf",os.t,os.y);

*/