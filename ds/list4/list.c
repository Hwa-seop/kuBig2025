#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void initList(List *pList,int eleSize)
{
    // pList->ptr = malloc(sizeof(Node)); // dummy node.
    pList->ptr = malloc(sizeof(Node) /* +eleSize */);
    pList->ptr->next = NULL;
    pList->eleSize = eleSize;
}
//더미노드 만드는이유: 삭제를 위해
void cleanupList(List *pList)
{
    Node*p=pList->ptr;
    while(p ){
        Node *tmp = p;
        p = p->next;
        free(tmp);
    }
}

void insertFirstNode(List *pList,const void *pData)
{
    Node *p = malloc(sizeof(Node) + pList->eleSize);
    // p->data = data;
    // memcpy((unsigned char *)p + sizeof(Node), pData, pList->eleSize);
    memcpy(p+1,pData,pList->eleSize);
    p->next = pList->ptr->next;
    pList->ptr->next = p;
}

void insertNode(List *pList, const void *pPrevData, const void *pData)
{
    Node *p = pList->ptr->next;
    while (p){
        // if (p->data == prevData){
        if (memcmp(p + 1, pPrevData, pList->eleSize) == 0){
            break;
        }
        p = p->next;
    }

    if(p ){
        // Node *tmp = malloc(sizeof(Node));
        Node*tmp=malloc(sizeof(Node)+pList->eleSize);
        // tmp->data = data;
        memcpy(tmp+1,pData,pList->eleSize);
        tmp->next = p->next;
        p->next = tmp;
    }else{
        // X
    }

}

void deleteNode(List *pList, const void *pData)
{
    Node *p = pList->ptr->next;
    Node *p2 = pList->ptr; //더미노드를 가리킴

    while (p){
        // if (p->data == data)
        if(memcmp(p+1,pData,pList->eleSize)==0)    
            break;

        p = p->next;
        p2 = p2->next;
    }
    if(p ){
        p2->next = p->next;
        free(p);
    }
}

void printList(const List *pList, void (*print)(const void *))
{
    Node *p = pList->ptr->next;
    printf("[");
    while(p ){
        // printf("%d",p->data);
        print(p+1);
        printf((p->next) ? ", " : "");
        p = p->next;
    }
    printf("]\n");
}

