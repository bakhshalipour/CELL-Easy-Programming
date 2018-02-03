#include <stdio.h>

#include "CellAbstractAlgorithm.h";

#ifndef __CELL_BE_VECTOR_ADD__
#define __CELL_BE_VECTOR_ADD__

class CellBEVectorAdd : public CellAbstractAlgorithm {

	private:
		int* vector1 __attribute__((aligned(128)));
		int* vector2 __attribute__((aligned(128)));
		int* resultVector __attribute__((aligned(128)));
		int vector_size;
		

	public:
		CellBEVectorAdd (int *vector1, int *vector2, int vector_size, spe_program_handle_t *spe_program , int spe_numbers);
		~CellBEVectorAdd();
		int* vector_add(); // return value of this method is result of (vector1 + vector2)
		
	protected:
		void run_ppu_algorithm();
};


#endif
