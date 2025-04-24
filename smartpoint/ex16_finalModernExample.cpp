// 목표 : STL과 스마트포인터를 사용해서 데이터베이스 엔진을 만들어라.
// 스마트 포인터 활용 shared_ptr,unique_ptr,
// 쓰레드 활용 nultithread,mutex,atomic -> 내부 구조 동기화 위한 락 구조 설계
// 데이터삽입 insert(key,value);
// 데이터 검색 find(key);
// 데이터 삭제 remove(key);
// class DataBase
// 저장용 컨테이너 - unordered_map
// 컬럼 추가(타입정하기)