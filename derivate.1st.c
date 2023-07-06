double derive(double (*f)(double), double x0) {
	// 1st derivative, central differential, points: 3, error O(h^2)
	const double d = 1.0e-6;
	double y1 = f(x0 - d);
	double y2 = f(x0 + d);
	return (y2 - y1)/(2 * d);
}