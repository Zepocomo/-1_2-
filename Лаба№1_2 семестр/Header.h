#pragma once
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
const int str_len = BUFSIZ;

struct stack
{
    char* ptr;
    stack* adr;
};
enum { end, file_read, file_to_stack, printStack, destroyStack, purge, number_Stack};

int menu();
int File_read(const char*);
stack* File_to_stack(char*);
void PrintStack(stack*);
void Number_Stack(stack*);
void push(stack*&, char*);
int DestroyStack(stack*&);
void Purge(stack*&);
int Nodes_count(stack*);
void Reverse_stack(stack*&);

