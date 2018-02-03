#include <libspe2.h>

#include "PthreadClass.h";


#ifndef __CELL_ABSTRACT_CLASS__
#define __CELL_ABSTRACT_CLASS__


class CellAbstractAlgorithm : public PthreadClass {

	private:
		spe_program_handle_t *spe_program;
		unsigned int spe_numbers;

	public:
		CellAbstractAlgorithm (spe_program_handle_t *spe_program , int spe_numbers);
		~CellAbstractAlgorithm();

	protected:
		spe_context_ptr_t context [20];								//Assume we have at max 20 SPEs.
		void kernel(int thread_id);
		virtual void run_ppu_algorithm()=0;
		void WriteSpePropertiesToMailbox();
		int get_spe_numbers();
};


#endif
