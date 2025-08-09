/*
   Honestly, you could just write raw commands straight away — how’s that not basically Python? :D
   - Ametero
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "op.h"

#define NEWBIE_VM__CODE_MAX_LENGTH 125000 // Maximun code (file) length

int main(int argc, char *argv[]){
    if(argv[1] == NULL){
        printf("Newbie-vm v0.5\nThe example of TextOpcodes-based VM\n\nMaded for... wha?\nGood luck, traveler!\n\nRepo: https://github.com/Ameterius/newbie-vm\n");
        exit(0);
    }
    FILE *src; // file pointer
    src = fopen(argv[1], "r");
    if(src == NULL){
        printf("[err] [file] failed to open file\n");
        fclose(src);
        exit(1);
    }
    char magic_header[20]; // refer to wiki
    printf("[mapping] checking magic header\n"); // 17 symbols
    while (fgets(magic_header, 18, src) != NULL){
        fclose(src);
        if(strcmp(magic_header, "newbie-vm:imvalid") != 0){
            printf("[err] [mapping] file %s incorrect\n", argv[1]);
            exit(1);
        }
    }
    printf("[mapping] creating SiOC instance\n");
    src = fopen(argv[1], "r");
    char btm[NEWBIE_VM__CODE_MAX_LENGTH];
    printf("[mapping] creating common stack\n");
    int cmn_stack;
    printf("============================\n\n");
    while(fgets(btm, NEWBIE_VM__CODE_MAX_LENGTH, src) != NULL){
        btm[strcspn(btm, "\n\r")] = '\0';
        if (strlen(btm) == 0) continue;
        int op_counter;
        op_counter = vm_sioc(btm);
        //printf("[debug] file op: %s | op: %i\n\n", btm, op_counter);
        switch (op_counter) {
            case D_OP_TRASH:
                printf(NEWBIE_VM__OP_TRASH);
                break;
            case ERR_UNDEFINED_OPCODE:
                printf("[runtime] Program (%s) tried to execute undefined OpCode (disired op: %i | file op: %s)\n", argv[1], op_counter, btm);
               // return 1;
                break;
            case UH_MAGIC_HEADER:
                break;
            case STACK_READ:
                fgets(btm, NEWBIE_VM__CODE_MAX_LENGTH, src);
                cmn_stack = atoi(btm);
                break;
            case STACK_CLEAR:
                cmn_stack = 0;
                break;
            case D_STACK_LOG:
                printf("%i\n", cmn_stack);
                break;
            default:
                printf("[runtime] unhooked error\n [runtime] op: %i | file op: %s\n", op_counter, btm);
              //  return 1;
                break;
        }
    }
    fclose(src);
     

}