#include <stdio.h>
#include <libspe2.h>

#include "CellBEVectorAdd.h";

#define SPE_NUMBERS		8

int main()
{
	extern spe_program_handle sum_spu;

	int vector1 [256];
	int vector2 [256];
	int* result_vector;
	int vector_size = 256;

	for (int i = 0; i < vector_size; i++)
	{
		vector1[i] = 2 * i;
		vector2[i] = 2 * i;
	}

	CellBEVectorAdd CELLBEVectorAddObject0 (vector1, vector2, vector_size, &sum_spu, SPE_NUMBERS);	

	CELLBEVectorAddObject0.run();

	result_vector = CELLBEVectorAddObject0.vector_add();

	for (int i = 0; i < vector_size; i++)
		printf("%d\n", result_vector [i]);

	return 0;
}