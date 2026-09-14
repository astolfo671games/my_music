#include <stdio.h>
#include <stdlib.h>

#define SONGNAME argv[1]
#define SAMPLERATE atoi(argv[2])
#define LENGTH atoi(argv[3])
#define HEADER_1 "RIFF\xff\xff\xff\xffWAVEfmt\x20\x10\x00\x00\x00\x01\x00\x01\x00"
#define HEADER_2 "\x01\x00\x08\x00\x64\x61ta\xff\xff\xff\xff"

void get_header(int samplerate){
	for(int i = 0; i < sizeof(HEADER_1) - 1; i++) putchar(HEADER_1[i]);
	char* sr = (char*)(&samplerate);
	for(int i = 0; i < sizeof(int); i++) putchar(sr[i]);
	for(int i = 0; i < sizeof(int); i++) putchar(sr[i]);
	for(int i = 0; i < sizeof(HEADER_2) - 1; i++) putchar(HEADER_2[i]);
}

int main(int argc, char** argv){
	get_header(SAMPLERATE);
	for(long long t = 0; t < LENGTH; t++) putchar((long long)(t&t>>8));
	return 0;
}
