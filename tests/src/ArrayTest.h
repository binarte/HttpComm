/*
 * ArrayTest.h
 *
 *  Created on: 28 de jul de 2019
 *      Author: jack
 */

#ifndef ARRAYTEST_H_
#define ARRAYTEST_H_

#include <libhttpcomm/Array.h>
#include <stdio.h>

void testArray(){
	Array a;
	Array_initCustom(&a,sizeof(int),4);
	printf("Capacity is %i\n",a.capacity);
	Array_push(&a,int) = 12;
	Array_push(&a,int) = 23;
	Array_push(&a,int) = 34;
	Array_push(&a,int) = 45;
	printf("Capacity is %i\n",a.capacity);
	Array_push(&a,int) = 123;
	Array_push(&a,int) = 234;
	Array_push(&a,int) = 345;
	Array_push(&a,int) = 456;
	printf("Capacity is %i\n",a.capacity);
	Array_push(&a,int) = 4567;
	printf("Capacity is %i\n",a.capacity);

	for(int i = 0; i < a.count; i++) {
		printf("%i\t",Array_item(&a,int,i));
	}
	puts("");
	Array_pull(&a);
	printf("Capacity is %i\n",a.capacity);
	Array_pull(&a);
	Array_reduce(&a);
	printf("Capacity is %i\n",a.capacity);

	for(int i = 0; i < a.count; i++) {
		printf("%i\t",Array_item(&a,int,i));
	}
	puts("");

	Array_clear(&a);
}

#endif /* ARRAYTEST_H_ */
