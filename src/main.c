#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include "version.h"
#include "gtk/app.h"

void help(void) __attribute__ ((noreturn));
void usage(void) __attribute__ ((noreturn));
void version(void) __attribute__ ((noreturn));

void help(void){
	//     |0/60     |10/70    |20/80    |30       |40       |50       |60
	//      123456789012345678901234567890123456789012345678901234567890
	printf("Usage: libreforge [OPTION...]\n\n");
	printf("Options:\n");
	printf("  -h, --help                 print this help text\n");
	printf("  -V, --version              print version information\n");
	exit(EXIT_SUCCESS);
}

void usage(void){
	//     |0/60     |10/70    |20/80    |30       |40       |50       |60
	//      123456789012345678901234567890123456789012345678901234567890
	printf("Usage: libreforge [-hV] [--help] [--verbose]\n");
	exit(EXIT_FAILURE);
}

void version(void){
	//     |0/60     |10/70    |20/80    |30       |40       |50       |60
	//      123456789012345678901234567890123456789012345678901234567890
	printf("%s\n", VERSION);
	printf("%s\n", COPYRIGHT);
	printf("%s\n", LICENSE);
	exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]){
	int opt;
	char *optstr = "hV";
	struct option longopts[] = {
		{ "help", no_argument, NULL, 'h' },
		{ "version", no_argument, NULL, 'V' },
		{ NULL, no_argument, NULL, 0 }
	};
	while ((opt = getopt_long(argc, argv, optstr, longopts, NULL)) != -1){
		switch (opt) {
		case 'h':
			help();
		case 'V':
			version();
		default:
			usage();
		}
	}
	app_init(argc, argv);
	return EXIT_SUCCESS;
}
