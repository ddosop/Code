#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
 } CNode;

 
int main(){
    CNode start;
    int count = 0;
    start.val = 0;
    CNode *S = &start, *result = &start;
    printf("%d\n", result);
// 局部变量会被回收，只有申请后得以保存。
    for(int i=0; i<=10; i++){
        CNode *temp = malloc(sizeof(CNode));
        count += 1;
        temp->val = count;
        S->next = temp;
        S = temp;
        printf("%d, %d\n", S->val, result->val);
    }


    result = result->next;
    printf("result_id:%d, result_val:%d\n", result, result->val);
    printf("%d\n", NULL);


    return 0;
}