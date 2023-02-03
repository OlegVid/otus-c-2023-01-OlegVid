#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pair{
	int value;
	struct pair* next;
} pair;

pair* make_pair(int value, pair* next);

pair* filter(pair* list, bool (*predicate)(int));
pair* map(pair* list, int (*modif)(int));
pair* inv_list(pair* list);

