double integralSimpson(double (*f)(double), double a, double b, int n) {
	int i = 0;
	double 
		step = (b-a)/n,
		out1 = f(a + step/2),
		out2 = 0;
	while (++i < n)
		out1 += f(a + step*i + step/2),
		out2 += f(a + step*i);
	return (step/6) * (f(a) + f(b) + 4*out1 + 2*out2);
}
