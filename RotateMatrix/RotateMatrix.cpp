#include <iostream>

void RotateMatrix(int** matrix, int n, int degree) {
	degree%= 360;
	for (int a = 0; a < degree / 90; a++) {
		for (int i = 0; i < n / 2; i++) {
			for (int j = i; j < n - i - 1; j++) {
				int temp = matrix[i][j];

				/*matrix[i][j] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = temp;*/

				matrix[i][j] = matrix[n - j - 1][i];
				matrix[n - j - 1][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = temp;


			}
		}
	}

}
void printMatrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
};
int** CreateMatrix(int n) {
	int** matrix;
	matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			matrix[i][j] = i * n + j + 1;
		}
	}
	return matrix;
}
int main()
{
	int n = 5;
	int** matrix = CreateMatrix(n);
	printMatrix(matrix, n);
	RotateMatrix(matrix, n, 1890);
	std::cout << "After rotate" << std::endl;
	printMatrix(matrix, n);
}