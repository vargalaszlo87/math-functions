// min value of int vector
int min(int *a, int n) {
	int temp = a[0], i = 0;
	while (++i < n)
		temp = (a[i] < temp) ? a[i] : temp;
	return temp;
}

// usage: int smallest = min(vector, 18);