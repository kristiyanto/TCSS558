/*
 ============================================================================
 Name        : server.c
 Author      : Kevin Anderson <k3a@uw.edu> & Daniel Kristiyanto <danielkr@uw.edu>
 Version     : 2015.01.10
 Description : TCSS558 Project 1
 ============================================================================
 */

#ifndef SERVER_H
#include "server.h"
#endif

int getTimeStamp(char * output);




int main(void) {

	test_log();

}


int test_log()
{
	for(int i = 0; i < 100; i++)
	{
		log_write("localhost", (i*4), "Message Sent", "I'm ignoring it");
	}

	printf("Log Completed, check the file \"%s\"" ,S_LOGFILE);

}

int test_kv()
{
	// CONSTRUCT A NEW LIST
	kv * my_list = kv_new();

	// FILL THE LIST WITH SOME NEW KEYS
	for (int i = 0; i < 16; i++)
		kv_put(my_list, i*2, i * i);

	// DISPLAY WHAT IS IN THE CURRENT LIST
	kv_print(my_list);

	// TEST DELETE, PUT AND GET
	printf("===========================\n");
	printf("Removing the value from 10\n\n");

	kv_del(my_list, 10);
	kv_put(my_list, 10, -100);
	kv_print(my_list);
	int err; //ERROR FOR GET NEEDS FINALIZED.
	printf("And now getting what is in 14: [%d]", kv_get(my_list, 14, &err));

}
