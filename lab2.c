#include <stdio.h>

unsigned long interleave(unsigned int i1, unsigned int i2)
{
	int i;
	unsigned long res = 0;
	unsigned char *p1 = (unsigned char *) &i1;
	unsigned char *p2 = (unsigned char *) &i2;
	unsigned char *pres = (unsigned char *) &res;

	for(i = 0; i < sizeof(i1); i++){
		pres[2*i] = p1[i];
		pres[2*i+1] = p2[i];
	}
	return res;
}

void print_raw_bytes(char *start, unsigned int len)
{
	int i;
	unsigned char *start1 = (unsigned char *) start;
	for(i = 0; i < len; i++){
		printf("%p: %x\n", &start[i], start[i]);
	}
}

unsigned int count_ones(unsigned int n){
	int i = 0 ;
	unsigned int count = 0;
	for(i = 0; i < sizeof(n) * 8; i++){
		if( (n >> i) & 1 != 0 ){
			count++;
		}
	}
	return count;
}

int main(int argc, char *argv[])
{
	unsigned int i1 = 0x12345678;
	unsigned int i2 = 0xdeadbeef;
	printf("0x%x, 0x%x -> 0x%lx\n", i1, i2, interleave(i1, i2));
	printf("%d\n", count_ones(5));
	printf("%d\n", count_ones(i1));
	print_raw_bytes((char *) &i1, sizeof(i1));
	print_raw_bytes((char *) &i2, sizeof(i2));
	printf("%lx\n", interleave(i1, i2));
	printf("count = %u\n", count_ones(i2));
	return 0;
}

