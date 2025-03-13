#include <stdio.h>
#include <string.h>
#include <mysql.h>

typedef struct{
    int bookid;
    char bookname[40];
    char publisher[40];
    int price;
}Book;   //Book 으로 구조화

enum menu{    //enum 함수명 번호지정 0번부터
    SELECT,   // 0
    INSERT,   // 1
    DELETE,   // 2
    ALTER,   // 3
    QUERY    // 4
};
// 사용할 함수 정의
void fetch_books(MYSQL*conn);

int main(void){
    MYSQL *conn
}






