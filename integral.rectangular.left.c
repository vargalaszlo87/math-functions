double integralRectangularLeft(double (*f)(double), double a, double b, int n) {
	double
		i = a,
		step = (b-a)/n,
		out = 0;
	while (i <= (b-step))
		out += f(i),
		i += step;
	return step * out;
}
