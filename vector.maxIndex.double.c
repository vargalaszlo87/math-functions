// max value's index of (double) vector
int maxIndex(double *a, double n) {
  double temp = a[0];
  int i = -1, j = 0;
  while (++i < n) {
    if (a[i] > temp)
      temp = a[i],
      j = i;
	}
	return j;
}

// usage: int index = max(vector, 18);
