#include "booksql.h"

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
    conn=mysql_init(NULL);// Mysql 초기화
    if(mysql_real_connect(conn,host,user,pass,db,port,NULL,0)) //MySQL 서버에 연결을 시도함.
    // 성공하면 MYSQL* 포인터 (conn과 동일) 반환 → if 문이 true로 실행됨.
        printf("MYSQL 연결 성공\n");
    else{
        printf("MYSQL 연결 실패: %s\n", mysql_error(conn));
        //mysql_error(conn)을 사용하면 왜 실패했는지 확인할 수 있습니다.
        return 1;
    }

    while(true)
    {
        print_menu();
        scanf("%d%*c",&choice); //%*c는 다음 문자(개행)를 읽고 버린다.
        switch(choice){
        case SELECT:
            fetch_books(conn);
            break;
        case INSERT:
            insert_books(conn);
            break;    
        case DELETE:
            delete_books(conn);
            break;
        case UPDATE:
            update_books(conn);
            break;
        case QUERY:
            query_books(conn);
            break;
        case EXIT:
            mysql_close(conn);
            return 0;
        }
    }
    mysql_close(conn);

return 0;
    
}