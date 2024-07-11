struct Stack {
    int size;
    int top;
    int *S;
};


void create(struct Stack *st, int size) {
    st->size = size;
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}


void push(struct Stack *st, int x) {
    if (st->top == st->size - 1) {
        printf("Stack is Overflow\n");
    } else {
        st->S[++st->top] = x;
    }
}


int pop(struct Stack *st) {
    int x = -1;
    if (st->top == -1) {
        printf("Stack is underflow\n");
    } else {
        x = st->S[st->top--];
    }
    return x;
}


int isEmpty(struct Stack st) {
    return st.top == -1;
}


void reverse(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
}

char* reverseParentheses(char* s) {
    int n = strlen(s);
    struct Stack st;
    create(&st,n);
    for(int i=0;i<n;i++){
        if(s[i]=='('){
            push(&st,i);
        }
        else if(s[i]==')'){
            int start =pop(&st);
            reverse(s+start+1,s+i-1);
        }
    }
    
    char *result=(char *)malloc((n+1)*sizeof(char));
    int index=0;
    for(int i=0;i<n;i++){
        if(s[i]!='(' && s[i]!=')'){
            result[index++]=s[i];
        }
    }
    result[index]='\0';
    return result;
}