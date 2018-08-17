/*
 ============================================================================
 Name        : RemoteControlCar.c
 Author      : yogi
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "dbgPrint.h"

int main(int argc, const char *argv) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	dbg_print(PRINT_LEVEL_WARNING,"lock report");



	return EXIT_SUCCESS;
}
