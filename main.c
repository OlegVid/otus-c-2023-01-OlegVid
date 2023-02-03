#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct pair{
	int value;
	struct pair* next;
} pair;

static pair* make_pair(int value, pair* next){
	pair* result = malloc(sizeof(pair));
	result->value = value;
	result->next = next;
	return result;
}

static pair* filter(pair* list, pair* result, bool (*predicate)(int)){
	if (!list)
		return result;
	return filter(list->next, predicate(list->value) ? make_pair(list->value,result): result, predicate);
}
static bool is_even(int x){
	return (x % 2) == 0;
}

static pair* map(pair* list, pair* result, int (*modif)(int)){
	if (!list)
		return result;
	return map(list->next, make_pair(modif(list->value),result),modif);
}

static pair* inv_list(pair* list, pair* result){
	if (!list)
		return result;
	return inv_list(list->next, make_pair(list->value,result));
}

static int modifier(int inp_value){
	return inp_value * 5;
}

static void print_list(pair *list){
	for (pair* p = list; p ; p = p->next){
		printf("value = %d \n", p->value);
	}
	printf("---------------------\n");
}

int main (void){
	pair* list = &(pair){4, &(pair){8, &(pair){17, &(pair){33, NULL}}}};	
	pair* filtered = inv_list(filter(list, NULL, is_even),NULL);
	pair* mapped =  inv_list(map(list, NULL, modifier),NULL); 
	print_list(list);
	print_list(filtered);
	print_list(mapped);

	return 0;
}


		
