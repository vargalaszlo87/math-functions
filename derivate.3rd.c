double derive3(double (*f)(double), double x0) {
	// 3rd derivative, central differential, points: 4, error O(h^2)	
	const double d = 1.0e-3;	
	double y22 = f(x0 + 2 * d);
	double y2 = f(x0 + d);	
	double y1 = f(x0 - d);		
	double y11 = f(x0 - 2 * d);
	return (y22 - 2 * y2 + 2 * y1 - y11)/(2 * pow(d, 3));
}