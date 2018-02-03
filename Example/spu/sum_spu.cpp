#include <stdio.h>
#include <spu_mfcio.h>

#define BUFFER_ENTRIES	32
#define BUFFER_SIZE		BUFFER_ENTRIES * sizeof(int)

int X [BUFFER_ENTRIES] __attribute__((aligned(128)));
int Y [BUFFER_ENTRIES] __attribute__((aligned(128)));
int Z [BUFFER_ENTRIES] __attribute__((aligned(128)));


int main(unsigned long long speid, unsigned long long argp, unsigned long long envp)
{
	unsigned int spu_id = spu_read_in_mbox();
	unsigned int spe_numbers = spu_read_in_mbox();
	unsigned vector1_address = spu_read_in_mbox();
	unsigned vector2_address = spu_read_in_mbox();
	unsigned resultVector_address = spu_read_in_mbox();
	unsigned vector_size_value = spu_read_in_mbox();

	int tag;
	tag = mfc_tag_reserve();
	int tag_mask = 1 << tag;
	unsigned int offset = spu_id * BUFFER_SIZE;

	mfc_get(X, vector1_address + offset, BUFFER_SIZE, tag, 0, 0);
	mfc_write_tag_mask(tag_mask);
	mfc_read_tag_status_all();

	mfc_get(Y, vector2_address + offset, BUFFER_SIZE, tag, 0, 0);
	mfc_read_tag_status_all();

	int i;
	for (i = 0; i < BUFFER_ENTRIES; i++)
	{
		Z [i] = X [i] + Y [i];
		printf("SPU %d:\t%d --> %d\n",spu_id, i, Z[i]);
	}

	mfc_put(Z, resultVector_address + offset, BUFFER_SIZE, tag, 0, 0);
	mfc_read_tag_status_all();


	return 0;
}
