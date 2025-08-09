#include "op.h"
#include <string.h>

opcode vm_sioc(char *string){
    if(strcmp(string, "newbie-vm:imvalid") == 0){
        return UH_MAGIC_HEADER;
    }
    if(strcmp(string, "D_OP_TRASH") == 0){
        return D_OP_TRASH;
    }
    if (strcmp(string, "OP_PUSH") == 0){
        return STACK_READ;
    }
    if (strcmp(string, "OP_CLEAR_CMN") == 0){
        return STACK_CLEAR;
    }
    if (strcmp(string, "D_STACK_LOG") == 0){
        return D_STACK_LOG;
    }
    else{
        return ERR_UNDEFINED_OPCODE;
    }
}