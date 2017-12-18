// Aleksey Yakovlev
//1.	Реализовать перевод из 10 в 2 систему счисления с использованием стека.
//2.	Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
//Например: (2+(2*2)) или [2/{5*(4+7)}]
//3.	*Создать функцию, копирующую односвязный список (то есть создает в памяти копию односвязного списка, без удаления первого списка).
//4.	*Реализовать алгоритм перевода из инфиксной записи арифметического выражения в постфиксную.
//5.	Реализовать очередь.
//1) с использованием массива;
//2) *с использованием односвязного списка;
//3) ***с использованием двусвязного списка


#include <stdio.h>
#define MaxN 1000
#define T char

struct TStack
{
    int N;            // Номер верхнего элемента
    T Data[MaxN];     // Данные
};
struct TStack Stack1;
struct TStack Stack2;

void push(struct TStack *Stack, T data)
{
    Stack->N++;
    (*Stack).Data[(*Stack).N] = data;
}

T pop(struct TStack *Stack)
{
    if (Stack->N != -1)
        return Stack->Data[Stack->N--];
}
void init(struct TStack *Stack)
{
    Stack->N = -1;
}

void checkLine(char *str, int len){
    char t;
    for (int i =0; i<len;i++){
        if(str[i]=='(') push(&Stack2,')');
        if(str[i]=='{') push(&Stack2,'}');
        if(str[i]=='[') push(&Stack2,']');
        if(str[i]==')' || str[i]=='}' || str[i]==']' ) {
            t=pop(&Stack2);
            if(t!=str[i]){
                printf("\nSymbol %c not found!",t);
                return;
            };
        }
    }
    if(Stack2.N>0){
        printf("\nSymbol %c not found!",Stack2.Data[1]);
        return;
    };
    printf("\nLine is correct");

}

int main() {

    //1.	Реализовать перевод из 10 в 2 систему счисления с использованием стека.
    printf("Enter a number\n");
    int n;

    scanf("%d",&n);
    intToBinary(n);
    printf("\nNumber %d in binary is ",n);
    while(Stack1.N != -1)  printf("%d", pop(&Stack1));
    printf("\n");

    //2.	Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.
    //Например: (2+(2*2)) или [2/{5*(4+7)}]
    printf("Enter a line with brackets\n");
    int len=20;
    char str[len];
    scanf("%s", str);
    checkLine(str,len);
    return 0;
}

void intToBinary(int num){
    init(&Stack1);
    while ((num/2)>=1){
        push(&Stack1,(char)num%2);
        num/=2;
    }
    push(&Stack1,(char)num%2);

}




