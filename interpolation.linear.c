double interpolationLinear(double x[], double y[], double x0, int n) {
	int i = 0;
	while (i < n) {
		if (x0 <= x[i])
			break;	
		i++;
	}
	return y[i-1]+((x0-x[i-1])*(y[i]-y[i-1]))/(x[i]-x[i-1]);
}

/*  
	// usage:
	double x[] = {1,3,5,7,9,11,13};
	double y[] = {1.5,1.7,1.9,2.2,2.6,3.1,4.8};
	double x0 = 7.2;
	double result = interpolationLinear(x,y,x0,7);
*/	

