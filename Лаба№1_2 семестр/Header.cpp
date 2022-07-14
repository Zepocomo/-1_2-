#include "Header.h"

int menu() {
 
    printf("%s", "\t\t__MENU__\n");
    printf("%d - %s", file_read ,"\tShow file\n");
    printf("%d - %s", file_to_stack , "\tconvert File to stack\n");
    printf("%d - %s", printStack , "\tPrint Stack\n");
    printf("%d - %s", destroyStack , "\tDestroy Stack\n");
    printf("%d - %s", purge , "\tPrint and Destroy Stack\n");
    printf("%d - %s", number_Stack, "\tNumber Stack\n");
    printf("%d - %s", end , "\texit\n");
    puts("get choise: ");
    char num[5];
    gets_s(num);
    return atoi(num);
}
int File_read(const char* file_name)
{
    FILE* fp;
  
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", file_name);
        return(0);
    }
    char str[str_len + 1];
    fgets(str, str_len, fp);
    while (!feof(fp))
    {
        printf("%s", str);
        fgets(str, str_len, fp);
    }
    fclose(fp);
	return 1;
}
void push(stack*& node, char* a)
{
    stack* prev = new stack;
    prev->ptr = new char[strlen(a) + 1];
    strcpy(prev->ptr, a);
    prev->adr = node;
    node = prev;

    //stack* prev = node; //prev � node �������� �� ������� �����
    //node = new stack; //�������� �������� ����� �� ����� �������
    //node->ptr = a; //����� ������������ ������� ������ ��������
    //node->adr = prev; //��'������� ������ �������� �� �����
    ////node ����� �� ���� ������� ����� � ����������� � main()
}
/*void push2(reverse_stack*& node2, char* a2)
{
    reverse_stack* prev2 = new reverse_stack;
    prev2->ptr2 = new char[strlen(a2) + 1];
    strcpy(prev2->ptr2, a2);
    prev2->adr2 = node2;
    node2 = prev2;

    //stack* prev = node; //prev � node �������� �� ������� �����
    //node = new stack; //�������� �������� ����� �� ����� �������
    //node->ptr = a; //����� ������������ ������� ������ ��������
    //node->adr = prev; //��'������� ������ �������� �� �����
    ////node ����� �� ���� ������� ����� � ����������� � main()
}*/
stack* File_to_stack(char* file_name)
{
    FILE* fp;
    fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", file_name);
        return(0);
    }
    char str[str_len + 1];
    stack* next = NULL;
    fgets(str, str_len, fp);
    //char a;
    while (!feof(fp))
    {
        push(next, str);
        fgets(str, str_len, fp);
    } 
    fclose(fp);
    printf("%s\n","file was converted to stack");
    return next;
    //printf(head);
}
void PrintStack(stack* node) //���� �����
{
   // char str1[str_len + 1];
   // reverse_stack* next2 = NULL;
    if (!node)
    {
        perror("Stack is empty");
    }
    while (node) //���� ������� ����� ���Ӫ 
    {
        printf("%s" , node->ptr); //���� ������������ �������
        node = node->adr; //������� �� ���������� ��������
       // push2(next2, str1);
    }   
}
void Number_Stack(stack* node) {
    int i = Nodes_count(node);
    if (!i)
    {
        return;
    }
    char* text;
    while (node)
    {
            text = new char[strlen(node->ptr) + (int)log10(i) + 5];
            itoa(i, text, 10);
            strcat(text, " : ");
            strcat(text, node->ptr);
            delete[] node->ptr;
            node->ptr = text;
            node = node->adr;
            i--;
    }
    //int i = 1;
    //while (node) //���� ������� ����� ���Ӫ 
    //{
    //    printf("%d %s %s", i, ":", node->ptr); //���� ������������ �������
    //    node = node->adr; //������� �� ���������� ��������
    //    i++;
    //}
}
int DestroyStack(stack*& node) 
{
    if(!node){ 
        printf("%s", "\nNothing to Delete!\n");
        return 0;
    }
    
    stack* top; 
    while (node) 
    {
        top = node->adr;
        delete node; 
        node = top;
    }
    printf("%s", "\nStack deleted\n");
    return 1;
}
void Purge(stack*& node)
{
    if (!node)
    {
        perror("Stack is empty");
    }
    stack* next;
    while (node) //���� ������� ����� ���Ӫ 
    {
        printf("%s", node->ptr); //���� ������������ �������
        next = node->adr; //������� �� ���������� ��������
        delete node;
        node = next;
    }
    printf("\nend of Stack\n");

}
int Nodes_count(stack* top)
{
    int k = 0;
    while (top)
    {
        k++;
        top = top->adr;
    }
    return k;
}
void Reverse_stack(stack*& node)
{
    stack* new_head = 0;
    
    for (stack* pos = node; pos;)
    {
        //������ � ������ ������ ������
        stack* save_next = pos->adr;
        pos->adr = new_head;
        new_head = pos;
        pos = save_next;
    }

    node = new_head;
}
//<windows.h>
// <fstream>
// handle
//find_firs_name
//find_next

