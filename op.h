typedef enum table {
        D_OP_TRASH, // should write in console NEWBIE_VM__OP_TRASH
        UH_MAGIC_HEADER,
        OP_PUSH_IN_COMMON, // pushing value in common stack
        STACK_READ, // reads value after OP_PUSH_IN_COMMON
        STACK_CLEAR, // clears cmn_stack
        D_STACK_LOG, // prints stack value
        /* Actually just error things*/
        ERR_UNDEFINED_OPCODE
} opcode;

#define NEWBIE_VM__OP_TRASH "actually, just a string\n"

opcode vm_sioc(char * string); // converts string in opcode