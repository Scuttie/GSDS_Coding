#include <stdio.h>
#include <stdlib.h>

typedef struct LLNode {
    int val;
    struct LLNode *prv, *nxt;
} LLNode; //�ڿ� �ٿ���typedef�� �����ϰ� �Ѱ�

void print_linked_list (LLNode *head) {
    LLNode *cur = head;
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->nxt;
    }
    printf("\n");
}

//(a) doubly linked list�� head�� �޾� ������������ ����
//value�� ġȯ�ص� �ǳ�? value�� swap �ذ��� ����
void sort_list (LLNode *head){
    LLNode *cur = head;
    while (cur){
        LLNode *anchor_cur = cur;
        while (cur -> prv){
            if (cur -> val < cur -> prv -> val){
                int n = cur -> val;
                cur -> val = cur -> prv -> val;
                cur -> prv -> val = n;
                cur = cur -> prv;
            } else{
                break;
            }
        }
        cur = anchor_cur -> nxt;
    }
}

//(b) ���� ���� DLL�� �Է¹޾� ������������ ����
void sort_each_list (LLNode *head[100], int N){
    for (int i = 0; i < N; i++){
        sort_list(head[i]);  //head[i] ��ü�� pointer
    }
}
//���� �迭 ��ü�� ���̸� ���ϰ� �ʹٸ�  int length = sizeof(head) / sizeof(head[0]); �� ���� size�� �̿��ؼ� ���� �� �ִ�.


//(c) ���� ���� DLL�� �Է¹޾� ������������ ���ĵ� �ϳ��� DLL�� �����.
//�������� ���Ŀ� �Լ�
void decrease_sort_list (LLNode *head){
    LLNode *cur = head;
    while (cur){
        LLNode *anchor_cur = cur;
        while (cur -> prv){
            if (cur -> val > cur -> prv -> val){
                int n = cur -> val;
                cur -> val = cur -> prv -> val;
                cur -> prv -> val = n;
                cur = cur -> prv;
            } else{
                break;
            }
        }
        cur = anchor_cur -> nxt;
    }
}

LLNode* merge_sorted_lists(LLNode *head[100], int N){
    for (int i = 0; i < N-1; i++){ //���� �����ؼ� �ϳ��� ����� ��ü sort
        
        LLNode *cur = head[i];
        while (cur -> nxt){
            cur = cur -> nxt;
        }
        cur -> nxt = head[i+1];
        head[i+1] -> prv = cur;
    }
    decrease_sort_list(head[0]);
    return head[0];
}


int main () {
 LLNode *node11 = (LLNode *) malloc(sizeof(LLNode));
 LLNode *node12 = (LLNode *) malloc(sizeof(LLNode));
 LLNode *node13 = (LLNode *) malloc(sizeof(LLNode));
 node11->val = 3; node11->nxt = node12, node11->prv = NULL;
 node12->val = 1; node12->nxt = node13, node12->prv = node11;
 node13->val = 5; node13->nxt = NULL, node13->prv = node12;
 LLNode *list1 = node11;
 LLNode *node21 = (LLNode *) malloc(sizeof(LLNode));
 LLNode *node22 = (LLNode *) malloc(sizeof(LLNode));
 LLNode *node23 = (LLNode *) malloc(sizeof(LLNode));
 LLNode *node24 = (LLNode *) malloc(sizeof(LLNode));
 LLNode *node25 = (LLNode *) malloc(sizeof(LLNode));
 node21->val = 2; node21->nxt = node22, node21->prv = NULL;
 node22->val = 8; node22->nxt = node23, node22->prv = node21;
 node23->val = 6; node23->nxt = node24, node23->prv = node22;
 node24->val = 1; node24->nxt = node25, node24->prv = node23;
 node25->val = 1; node25->nxt = NULL, node25->prv = node24;
 LLNode *list2 = node21;
 LLNode *node31 = (LLNode *) malloc(sizeof(LLNode));
 LLNode *node32 = (LLNode *) malloc(sizeof(LLNode));
 LLNode *node33 = (LLNode *) malloc(sizeof(LLNode));
 LLNode *node34 = (LLNode *) malloc(sizeof(LLNode));
 node31->val = 7; node31->nxt = node32, node31->prv = NULL;
 node32->val = 2; node32->nxt = node33, node32->prv= node31;
 node33->val = 7; node33->nxt = node34, node33->prv= node32;
 node34->val = 4; node34->nxt = NULL, node34->prv = node33;
 LLNode *list3 = node31;
 print_linked_list(list1);
 print_linked_list(list2);
 print_linked_list(list3);
 sort_list(list1);
 print_linked_list(list1);

 LLNode *lists[100];
 lists[0] = list1;
 lists[1] = list2;
 lists[2] = list3;
 sort_each_list(lists, 3);
 print_linked_list(list1);
 print_linked_list(list2);
 print_linked_list(list3);

 LLNode *merged = merge_sorted_lists(lists, 3);
 print_linked_list(merged);

return 0;
}
