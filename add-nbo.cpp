#include <stdio.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


uint32_t readTerm(char* fileName) {
	FILE* fp = fopen(fileName, "rb");
	if (fp == nullptr) {
		printf("Check your file:  %s", fileName);
		exit(EXIT_FAILURE);
	}

	uint32_t n;
	fread(&n, 1, sizeof(n), fp);
	n = ntohl(n);
	fclose(fp);
	return n;
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("syntax error: add-nbo <file1> <file2>");
		exit(EXIT_FAILURE);
	}

	uint32_t n1 = readTerm(argv[1]);
	uint32_t n2 = readTerm(argv[2]);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1 + n2, n1 + n2);
}

