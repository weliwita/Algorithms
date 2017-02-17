
// type def here so you won't need to write struct all over. if not you always have to use 
// struct stack k, struct stack g etc...
typedef struct {
    int *elems;
    int logicalLen;
    int allocLen;
} Stack;

void StackNew(Stack *s);
void StackDispose(Stack *s);
void StackPush(Stack *s, int value);
int StackPop(Stack *s);


