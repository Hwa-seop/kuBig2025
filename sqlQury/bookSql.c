#include <stdio.h>
#include <string.h>
#include <mysql.h> //sudo apt install libmysql++*
//dpkg -L libmysqlclient-dev | grep mysql.h
// cc -o bookSql bookSql.c -I/usr/include/mysql -L/usr/lib/mysql -lmysqlclient
typedef struct {
    int bookid;
    char bookname[40];
    char publisher[40];
    int price;
}Book;
void fetch_books(MYSQL *conn);
void add_books(MYSQL *conn);

int main(void)
{
    MYSQL *conn;
    char *host = "localhost";
    char *user = "myuser";
    char *pass = "0000";
    char *db = "mydb";
    int port = 3306;
    int choice;
    
    //연결
    conn = mysql_init(NULL); //db 연결
    if(mysql_real_connect(conn,host,user,pass,db,port,NULL,0))
    printf("MYSQL 연결 성공\n");
    
    else{
        printf("MYSQL 연결 실패\n");
        return 1;
    }
    while(true)
    {
        printf("1, 2번 고르세요!");
        scanf("%d",&choice);
        switch (choice){
        case 1:
            fetch_books(conn);
            break; 
        case 2:
            add_books(conn);
            break;              
        }
    }

    mysql_close(conn);
    
    return 0;
}
void add_books(MYSQL *conn)
{
    printf("----도서 추가----\n");
    Book newbook;
    char query[255];
    

    // 정보 입력 scanf
    // query 문 작성 strcpy..."insert..." 
    // sprintf(query,"insert into Book values (%d, '%s', '%s', %d)",newbook.bookid,);
    // query 요청 mysql_query();
    return;

}

void fetch_books(MYSQL *conn){
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    strcpy(query,"select * from Book");
    // 쿼리 요청
    if(mysql_query(conn,query))
     {
         printf("쿼리 실패\n");
         return ;   
     }
     res = mysql_store_result(conn);
     if(!res)
     {
        printf("가져오기 실패");
        return;
     }
     Book book[100]; // 스택에 저장
     int i=0;
     //데이터 베이스의 정보를 구조체에 저장 -ORM
     while(row = mysql_fetch_row(res))
     {
         book[i].bookid=atoi(row[0]);
         strcpy(book[i].bookname, row[1]);
         strcpy(book[i].publisher, row[2]);
         book[i].price=atoi(row[3]);
         ++i;
     };
     for(int j=0;j<i;j++)
     {
         printf("%d \t%s \t%s \t%d \n",
             book[j].bookid,book[j].bookname,
             book[j].publisher,book[j].price);
     }
}
