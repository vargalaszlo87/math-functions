double integralRectangularRight(double (*f)(double), double a, double b, int n) {
	double
		i = a,
		step = (b-a)/n,
		out = 0;
	while (i <= (b-step))
		out += f(i+step),
		i += step;
	return step * out;
}
