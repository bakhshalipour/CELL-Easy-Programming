#include <libspe2.h>
#include <stdio.h>

#include "CellAbstractAlgorithm.h";
#include "PthreadClass.h";

CellAbstractAlgorithm :: CellAbstractAlgorithm(spe_program_handle_t *spe_program , int spe_numbers)
	:PthreadClass(1 + spe_numbers)
{
	this->spe_program = spe_program;
	this->spe_numbers = spe_numbers;
	unsigned int i;
	for (i = 0; i < spe_numbers; i++)
	{
		context [i] = spe_context_create (0, NULL);
		spe_program_load (context [i], this->spe_program);
	}
}

CellAbstractAlgorithm :: ~CellAbstractAlgorithm()
{
	unsigned int i;
	for (i = 0; i < this->get_thread_numbers() - 1; i++)
		spe_context_destroy (context [i]);
}

void CellAbstractAlgorithm :: kernel (int thread_id)
{
	unsigned int entry = SPE_DEFAULT_ENTRY;
	if (thread_id == 0)	
		run_ppu_algorithm();
	else
		spe_context_run(context [thread_id - 1], &entry, 0, NULL, NULL, NULL);
}


void CellAbstractAlgorithm :: WriteSpePropertiesToMailbox()
{
	unsigned int i;
	for (i = 0; i < spe_numbers; i++)
	{
		spe_in_mbox_write(context[i], &i, 1, SPE_MBOX_ALL_BLOCKING);			//Write SPE's identifier to first inbound of mail box.
		spe_in_mbox_write(context[i], &spe_numbers, 1, SPE_MBOX_ALL_BLOCKING);	//Write number if active SPEs to second inbound of mail box.
	}
}

int CellAbstractAlgorithm :: get_spe_numbers()
{
	return spe_numbers;
}

