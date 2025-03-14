#pragma once

#include <mysql.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int bookid;
    char bookname[40];
    char publisher[40];
    int price;
}Book;   //Book 으로 구조화

enum menu{    //enum 함수명 번호지정 0번부터
    SELECT,   // 0
    INSERT,   // 1
    DELETE,   // 2
    UPDATE,   // 3 ALTER->UPDATE
    QUERY,   // 4
    EXIT    // 5 종료
};
// 사용할 함수 정의
void fetch_books(MYSQL*conn); //SELECT
void insert_books(MYSQL*conn); //INSERT
void delete_books(MYSQL*conn); //DELETE
void update_books(MYSQL*conn); //UPDATE
void query_books(MYSQL*conn); //QUERY
void waitEnter(void); 
void print_menu();