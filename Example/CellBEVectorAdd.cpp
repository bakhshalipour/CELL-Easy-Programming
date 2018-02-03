#include <libspe2.h>
#include <stdio.h>

#include "CellBEVectorAdd.h";

CellBEVectorAdd :: CellBEVectorAdd(int *vector1, int *vector2, int vector_size, spe_program_handle_t *spe_program , int spe_numbers)
	:CellAbstractAlgorithm(spe_program, spe_numbers)
{
	this->vector1 = vector1;
	this->vector2 = vector2;
	this->vector_size = vector_size;
}

CellBEVectorAdd :: ~CellBEVectorAdd()
{
	//Destruct
}

int* CellBEVectorAdd :: vector_add()
{
	return resultVector;
}

void CellBEVectorAdd :: run_ppu_algorithm()
{
	this->WriteSpePropertiesToMailbox();

	unsigned int vector1_address = (unsigned int) vector1;
	for (int i = 0; i < get_spe_numbers(); i++)
		spe_in_mbox_write(context [i], &vector1_address, 1, SPE_MBOX_ALL_BLOCKING);

	unsigned int vector2_address = (unsigned int) vector2;
	for (int i = 0; i < get_spe_numbers(); i++)
		spe_in_mbox_write(context [i], &vector2_address, 1, SPE_MBOX_ALL_BLOCKING);

	unsigned int resultVector_address = (unsigned int) resultVector;
	for (int i = 0; i < get_spe_numbers(); i++)
		spe_in_mbox_write(context [i], &resultVector_address, 1, SPE_MBOX_ALL_BLOCKING);

	unsigned int vector_size_value = (unsigned int) vector_size;
	for (int i = 0; i < get_spe_numbers(); i++)
		spe_in_mbox_write(context [i], &vector_size_value, 1, SPE_MBOX_ALL_BLOCKING);
}
