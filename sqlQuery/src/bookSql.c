#include "booksql.h"

void print_menu(void) // 도서관리 첫 화면 출력 함수
{
    system("clear");
    printf("===도서 관리 시스템===\n");
    printf("0. 도서 조회\n");
    printf("1. 도서 추가\n");
    printf("2. 도서 삭제\n");
    printf("3. 도서 변경\n");
    printf("4. 쿼리문 입력\n");
    printf("5. 종료\n");
    printf("위의 번호에서 1개를 선택하세요: ");
};

void fetch_books(MYSQL*conn) //select
{
    MYSQL_RES *res;
    MYSQL_ROW row;
    char query[255];
    strcpy(query,"select *from Book");//쿼리 요청

    if(mysql_query(conn,query))
    {
        printf("쿼리 실패\n");
        return ;
    }
    res=mysql_store_result(conn);
    if(!res)
    {
        printf("가져오기 실패");
        return ;
    }
    Book *pBook;
    pBook=(Book*)malloc(sizeof(Book));
    int i=0;
   //데이터 베이스의 정보를 구조체에 저장
   while(row = mysql_fetch_row(res))
   {
    (pBook+i)->bookid=atoi(row[0]);
    strcpy((pBook+i)->bookname,row[1]);
    strcpy((pBook+i)->publisher,row[2]);
    (pBook+i)->price=atoi(row[3]);
    ++i;
    pBook=realloc(pBook, sizeof(Book)*(i+1));
};
    for(int j=0;j<i;j++){
        printf("%d \t%s \t%s \t%d \n",
        (pBook+j)->bookid,(pBook+j)->bookname,
        (pBook+j)->publisher,(pBook+j)->price);
}
free(pBook);
waitEnter();

};

void insert_books(MYSQL*conn)
{
    printf("-----도서 추가----\n");
    Book newbook;
    char query[255];
    printf("도서 ID: ");
    scanf("%d%*c",&newbook.bookid);
    printf("도서명: ");
    scanf("%s%*c",newbook.bookname);
    printf("저 자: ");
    scanf("%s%*c",newbook.publisher);
    printf("도서 가격: ");
    scanf("%d%*c",&newbook.price);

    sprintf(query,"insert into Book values (%d,'%s','%s',%d)",
    newbook.bookid,newbook.bookname,newbook.publisher,newbook.price);

    if(mysql_query(conn,query))
    {
        printf("데이터 입력 실패: %s\n",mysql_error(conn));
    }
    else{
        printf("입력 성공\n");
    }
    return ;
}

void delete_books(MYSQL*conn)
{
    int bookid;
    printf("-----도서 삭제-----\n");
    Book newbook;
    char query[255];
    printf("삭제할 도서의 bookid(숫자)를 입력하세요.");
    scanf("%d%*c",&bookid);
    sprintf(query,"delete from Book where bookid=%d",bookid);

    if(mysql_query(conn,query))
    {
        printf("데이터 삭제 실패: %s\n",mysql_error(conn));
    }
    else{
        printf("도서 삭제 성공!!\n");
    }
};

void update_books(MYSQL*conn)
{
    printf("-----도서 정보 변경-----\n");
    Book newbook;
    char query[255];
    int bookid;
    char new_name[40];
    char new_publisher[40];
    int new_price;
    
    printf("수정할 도서의 ID를 입력하세요: ");
    scanf("%d%*c",&bookid);
    printf("새 도서명: ");
    scanf("%s%*c",new_name);
    printf("새 출판사 명: ");
    scanf("%s%*c",new_publisher);
    printf("새 가격: ");
    scanf("%d%*c",&new_price);

    sprintf(query,"update Book set bookname='%s',publisher='%s',price=%d where bookid =%d",
        new_name,new_publisher,new_price,bookid);

    if(mysql_query(conn,query))
    {
        printf("도서 정보 변경 실패: %s\n",mysql_error(conn));
    }
    else{
        printf("도서 정보 변경 성공!\n");
    }
}; 
void query_books(MYSQL*conn)
{
         // 쿼리 스트링을 받아서
     // 쿼리 요청
     // 결과 프린트
     MYSQL_RES *res;
     MYSQL_ROW row;
     char query[255];
     printf("실행할 쿼리를 넣어 주세요: ");
     fgets(query, sizeof(query), stdin);
     query[strcspn(query, "\n")] = 0;

     if (mysql_query(conn, query))
     {
         printf("쿼리 실패, %s\n", mysql_error(conn));
         return;
     }
     res = mysql_store_result(conn);
     if (res)
     {
         while (row = mysql_fetch_row(res))
         {
             for (int i = 0; i < mysql_num_fields(res); ++i)
             {
                 printf("%s\t", row[i]);
             }
             printf("\n");
         }
     }
     else
     {
         printf("요청한 데이터가 없습니다.\n");
     }
waitEnter();
}; 

void waitEnter(void)
{
    printf("엔터를 쳐 주세요.\n");
    while(getchar()!= '\n')
        ;
}







