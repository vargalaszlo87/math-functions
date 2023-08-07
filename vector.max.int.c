// max value of int vector
int max(int *a, int n) {
	int temp = a[0], i = 0;
	while (++i < n)
		temp = (a[i] > temp) ? a[i] : temp;
	return temp;
}

// usage: int largest = max(vector, 18);