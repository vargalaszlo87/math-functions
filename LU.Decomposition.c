#define TINY 1.0e-20

void LUdecomposition(float **a, int n, int *index, float *d) {	
	int i, j, k, iMax;
	float
		big,
		dum,
		sum,
		temp;
	float *vv = (float*)calloc(n, sizeof(float));
	if (vv == NULL) {
		fprintf (stderr, "Memory allocation error.");
		return;		
	}
	i = -1;
	while (++i < n) 
		vv[i] = 1;
	/* */
	*d = 1;
	i = -1;
	big = 0.0; 
	while (++i < n) {
		j = -1;
		while (++j < n)
			if ((temp = fabs(a[i][j])) > big)
				big = temp;
		if (big == 0.0) {
			fprintf (stderr, "Singular matrix in routine.");
			return;			
		}
		vv[i] = 1.0/big;
	}
	j = -1;
	while (++j < n) {
		i = -1;
		while (++i < j) {
			sum = a[i][j];
			k = -1;
			while (++k < i)
				sum -= a[i][k] * a[k][j];
			a[i][j] = sum;
		}
		big = 0.0;
		i = j;
		while (i<n) {
			sum = a[i][j];
			k = -1;
			while (++k < j) 
				sum -= a[i][k] * a[k][j];	
			a[i][j] = sum;
			if ((dum = vv[i]*fabs(sum)) >= big) {
				big = dum;
				iMax = i;
			}	
			i++;
		}
		if (j != iMax) {
			k = -1;
			while (++k < n) {
				dum = a[iMax][k];
				a[iMax][k] = a[j][k];
				a[j][k] = dum;
			}
			*d = -(*d);
			vv[iMax] = vv[j];
		}
		index[j] = iMax;
		if (a[j][j] == 0.0)
			a[j][j] = TINY;
		if (j != n) {
			dum = 1.0 /a[j][j];
			i = j; // +1
			while (i < n) 
				a[i][j] *= dum;
		}	
	}	
	free(vv);
	vv = NULL;
}
