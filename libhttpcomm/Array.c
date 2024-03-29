/*
 * BufferedArray.c
 *
 *  Created on: 5 de jul de 2019
 *      Author: jack
 */

#include "Array.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void Array_initCustom(Array *a, size_t itemSize, unsigned short chunkSize) {
	a->capacity = 0;
	a->count = 0;
	a->data = NULL;
	a->itemSize = itemSize;
	a->chunkSize = chunkSize;
}
unsigned short Array_clear(Array *a) {
	if (a->count == 0) {
		return 0;
	}
	unsigned short out = a->count;
	free(a->data);
	a->capacity = 0;
	a->count = 0;
	a->data = NULL;
	return out;
}
void* Array_pushVoid(Array *a, unsigned short *out_idx) {
	if (a->count >= a->capacity) {
		a->capacity = ((a->count / a->chunkSize) + 1) * a->chunkSize;
		void *old = a->data;
		a->data = malloc(a->itemSize * a->capacity);
		if (old != NULL) {
			memcpy(a->data, old, a->itemSize * a->count);
			free(old);
		}
	}
	void *out = a->data + (a->itemSize * a->count);
	a->count++;
	return out;
}
void* Array_itemVoid(Array *a, unsigned short idx) {
	if (idx >= a->count){
		return NULL;
	}
	return a->data + (a->itemSize * idx);
}

unsigned short Array_pull(Array *a){
	if (a->count == 0){
		return 0;
	}
	a->count--;
	return a->count+1;
}

unsigned short Array_reduce(Array* a){
	unsigned short ret;
	if (a->count == 0 || a->data == NULL){
		ret = a->capacity;
		Array_clear(a);
		return ret;
	}
	unsigned short newcap = ((a->count / a->chunkSize) + 1) * a->chunkSize;
	if (newcap >= a->capacity){
		return 0;
	}

	ret = a->capacity - newcap;

	void *old = a->data;
	a->capacity = newcap;
	a->data = malloc(a->itemSize * a->capacity);
	memcpy(a->data, old, a->itemSize * a->count);
	free(old);

	return ret;
}
