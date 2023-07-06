double derive2(double (*f)(double), double x0) {
	// 2nd derivative, central differential, points: 3, error O(h^2)
	const double d = 1.0e-6;
	double y0 = f(x0);
	double y1 = f(x0 - d);
	double y2 = f(x0 + d);	
	return (y2 - 2*y0 + y1)/(pow(d,2));
}