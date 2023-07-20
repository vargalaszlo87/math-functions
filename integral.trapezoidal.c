double integralTrapezoidal(double (*f)(double), double a, double b, int n) {
	int i = 0;
	double 
		step = (b-a)/n,
		out = f(a) + f(b);
	while (++i < n)
		out += 2 * f(a + i * step);
	return out *= step/2;
}