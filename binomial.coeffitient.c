unsigned long int binomialCoeffitient(int n, int k) {
	return (k == 0 || k == n) ? 1 : binomialCoeffitient(n - 1, k - 1) + binomialCoeffitient(n - 1, k);
}
