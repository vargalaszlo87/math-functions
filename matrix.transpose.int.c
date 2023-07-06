// transpose of matrix
// (only quadratic)
void matrixTranspose(int ***a, int n, int m) {
	int i, j, **temp;
	temp = (int**)malloc(sizeof(int*) * n);
	while (++i < m) 
		temp[i] = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < n; i++) 
        for (j = 0; j < m; j++)	
        	temp[i][j] = a[0][j][i];
	for (i = 0; i < n; i++) 
        for (j = 0; j < m; j++)	
			a[0][i][j] = temp[i][j];	
}

// uset it: matrixTranspose(&matrix, N, M);