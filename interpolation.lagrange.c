double interpolationLagrange(double x[], double y[], double x0, int n) {
	double out = 0, p;	
	int i = 0, j;
		while (++i < n) {
			p = 1, j = 0;
			while (++j < n) 
				if (i != j)
					p *= (x0-x[j])/(x[i]-x[j]);
			out += (p*y[i]);
		}
	return out;		
}

/*  
	// usage:
	double x[] = {1,3,5,7,9,11,13};
	double y[] = {1.5,1.7,1.9,2.2,2.6,3.1,4.8};
	double x0 = 7.2;
	double result = interpolationLagrange(x,y,x0,7);
*/	

