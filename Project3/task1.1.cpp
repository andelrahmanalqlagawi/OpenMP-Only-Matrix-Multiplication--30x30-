//just comment the the other part that you dont want to test
//task1.1 omp
#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
	int mtx[30][30], mul[30][30];


	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
		{
			mtx[i][j] = i + j;
		}
	double start = omp_get_wtime();

#pragma omp parallel for
	for (int i = 0; i < 30; i++)
		for (int j = 0; j < 30; j++)
		{
			mul[i][j] = 0;
			for (int k = 0; k < 30; k++)
				mul[i][j] += mtx[i][k] * mtx[k][j];
		}
	double end = omp_get_wtime();


	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			cout << mul[i][j] << " ";

		}
		cout << endl;
	}
	double time = (end - start) * 1000000;
	cout << "the time taken is: \t" << time << "\t in microsecond" << endl;
	system("pause");
	return 0;
}

