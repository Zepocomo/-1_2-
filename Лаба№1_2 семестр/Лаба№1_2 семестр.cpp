#include "Header.h"
//#include "Header.cpp"
//#include <iostream>



int main() {
    int choice = 0;
    char fname[] = "file.txt";
    stack* FTS = File_to_stack(fname);
    puts("FIRSTLY, PLEASE CHOOSE FILE(YOU CAN CHANGE IT AT ANY TIME YOU WANT)");
    stack* head = NULL;
    while (((choice = menu()) != end)) 
    {
        switch (choice) 
        {
        case file_read: File_read(fname); break;
        case file_to_stack: File_to_stack(fname); break;
        case printStack:Reverse_stack(FTS); PrintStack(FTS); break;
        case number_Stack: Number_Stack(FTS); break;
        case destroyStack: DestroyStack(FTS); break;
        case purge: Reverse_stack(FTS); Purge(FTS); break;
        default: "ERROR CHOICE"; break;
        }
        printf("%c", '\n');
    }
    return 1;
}



    //PrintStack(FTS);
    //Number_Stack(FTS);
    //PrintStack(FTS);
    //Purge(FTS);
    // PrintStack(FTS);
   // Number_Stack(FTS);
    //DestroyStack(FTS);

  /*  printf("%s", "\t\t__MENU__\n");
    printf("%s", "\tShow file\n");
    printf("%s", "\tconvert File to stack\n");
    printf("%s", "\tPrint Stack\n");
    printf("%s", "\tDestroy Stack\n");
    printf("%s", "\texit\n");


    int choise;
    while (choise != 5) {
        switch (choise)
        {
        case 1: 
       
        File_read(fname);
        case 2:
            File_to_stack(fname);
        case 3:
            PrintStack(FTS);
        case 4:
            DestroyStack(FTS);
        case 5:
            break;
        default:
            printf("%s", "Enter smth from menu");
            break;
        }
    }
}*/
   /* STACK* head, * q;
    char a;
    head = NULL; 
    //printf("Enter a string to reverse:\n");
    do 
    {
        a = getchar(); 
        q = new STACK; //створення нового вузла стеку
        q->ch = puts(str);
        //q->ch = a; //заповнення нового вузла
        q->next = head; //включення нового вузла у стек
        head = q; //head знову вказує на вершину стеку
        std::cout << head->ch;
    } while (fgets(str, 60, fp) != NULL);

    fclose(fp);
    return(0);
}*/

