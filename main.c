#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SAMPLERATE atoi(argv[2])
#define LENGTH atoi(argv[3])
#define HEADER_1 "RIFF\xff\xff\xff\xffWAVEfmt\x20\x10\x00\x00\x00\x01\x00\x01\x00"
#define HEADER_2 "\x01\x00\x08\x00\x64\x61ta\xff\xff\xff\xff"

void get_header(int32_t samplerate){
	for(int32_t i = 0; i < sizeof(HEADER_1) - 1; i++) putchar(HEADER_1[i]);
	char* sr = (char*)(&samplerate);
	for(int32_t i = 0; i < sizeof(int32_t); i++) putchar(sr[i]);
	for(int32_t i = 0; i < sizeof(int32_t); i++) putchar(sr[i]);
	for(int32_t i = 0; i < sizeof(HEADER_2) - 1; i++) putchar(HEADER_2[i]);
}

int main(int argc, char** argv){
	get_header(SAMPLERATE);
	for(int64_t t = 0; t < LENGTH; t++) putchar((int64_t)(t&t>>8));
	return 0;
}
