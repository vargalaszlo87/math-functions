typedef struct RK4Variables {
	float
		t0,
		t,
		y0,
		y,
		h,
		k[4];
	int step;
} RK4Variables;

float eq(float t, float y) {
	return pow(y,2)-y*sin(t)+cos(t);
}

void rk4(struct RK4Variables *r, float (*f)(float, float)) {
	int i = -1;
	r->h = (r->t-r->t0)/r->step;
	while (++i < r->step) {
		r->k[0] = f(r->t0, r->y0);
		r->k[1] = f(r->t0 + r->h/2, r->y0 + r->k[0]*r->h/2);
		r->k[2] = f(r->t0 + r->h/2, r->y0 + r->k[1]*r->h/2);
		r->k[3] = f(r->t0 + r->h, r->y0 + r->k[2]*r->h);			
		#ifdef DEBUG
			printf ("t0: %f\ty0: %f\ty: %f\n",r->t0, r->y0, r->y);
		#endif
		r->y = r->y0 + r->h/6 * (r->k[0] + 2 * r->k[1] + 2 * r->k[2] + r->k[3]);
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
	struct RK4Variables os;
	os.t0 = 0;
	os.y0 = 0;
	os.t = 3.1;
	os.step = 10000;
	rk4(&os, &eq);
	
	printf ("Result: y(%lf) = %lf",os.t,os.y);

*/
