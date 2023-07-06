
// min value of vector
// -
int min(int *a, int n) {
	int temp = a[0], i = 0;
	while (++i < n)
		temp = (a[i] < temp) ? a[i] : temp;
	return temp;
}

// GCD with recursive Euclidean
// algorithm between two numbers
int gcd(int a, int b) {
	return (b == 0) ? a : gcd(b, a%b);
}

// GCD with recursive Euclidean
// algorithm for vector 
int gcdVector(int *a, int n) {
	int *temp = (int*)calloc(n-1, sizeof(int)), j;
	for (j = 0 ; j < n-1 ; j++) 
		temp[j] = abs(gcd(a[0],a[j+1]));	
	return min(temp, n-1);
}

// matrix simplification with
// GCD algorithm 
void matrixSimplification(int ***a, int n, int m) {
	int i, j, temp;
	for (i = 0 ; i < n ; i++) {
		temp = gcdVector(a[0][i],m);
		if (temp > 1)
			for (j = 0 ; j < m ; j++)
				a[0][i][j] /= temp;
	}
}

// use it: matrixSimplification(&matrix, N, M);