#include <stdio.h>
#include <stdlib.h>

#define InitSize 100
typedef int ElemType;

typedef struct{
            int Length, MaxSize;
            ElemType *data;
 } SeqList;


int InitList(SeqList &L){
    L.data = (ElemType *)malloc(sizeof(ElemType)*InitSize);
    L.MaxSize = InitSize;
    return 0;
}



int main(){
    SeqList L;
    InitList(&L);
    

}