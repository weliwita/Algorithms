
// type def here so you won't need to write struct all over. if not you always have to use 
// struct stack k, struct stack g etc...
typedef struct {
    void *elems;
    int elemSize;
    int logicalLen;
    int allocLen;
} Stack;

void StackNew(Stack *s, int elemSize);
void StackDispose(Stack *s);
void StackPush(Stack *s, void *elemAddr);
void StackPop(Stack *s, void *elemAddr);


