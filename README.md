# Simple KVS 만들기

#### 1. 문제
###### 최근 데이터의 다양화에 따라 데이터를 Key 와 Value 의 간단한 셋으로 저장하는 Key-value Store 가 널리 활용되고 있다. 
###### 본 과제는 Simple KVS를 라이브러리 형태로 제공하는 프로그램을 만든다.

#### 2. 세부사항
* Key 와 Value 는 각각 문자열로 주어진다. 
* key 는 최대 16바이트 크기의 문자열이다.  
* put: key, value, value 의 크기를 인자로 받아 KVS에 저장하는 함수 
* get: key 가 주어지면 해당하는 value 를 돌려주고, value의 size 는 주어진 인자에 저장하는 함수. 
* open: KVS의 초기화 작업을 수행하는 함수 
* close: KVS가 사용하는 메모리를 반납하고 종료하는 함수. 
* main: 메인함수. 사용자로부터 명령어 라인에 put 과 get 요청이 적혀있는 파일명 2개와 결과 값을 저장할 파일명 1개를 입력받아, put 과 get 을 각각 차례대로 실행하고, get 요청의 결과 값을 result.txt 에 저장해주는 함수 

#### 3. 소스코드
###### 소스코드는 아래와 같이 4개의 파일로 구성되며, 각각의 파일은 아래와 같은 내용을 구현한다.
이름|세부내용|
---|---|
kvs.h | 헤더파일 |
put.c | int put (char* key, char* value, int nbytes) |
get.c | char* get (char *key, int* nbytes) |
open.c | int open () |
close.c | void close () |
test_static.c | int main (int argc, char* argv[]) |
test_dll.c | int main (int argc, char* argv[]) |

#### 4. 빌드
* Makefile 을 아래의 사항이 동작하도록 작성한다. 
* make static : KVS 소스코드를 정적라이브러리로 만든 후 해당 라이브러리를 사용하여 test_static.c 코드가 컴파일 되어 test_static 실행파일을 생성 
* make dll : KVS 소스코드를 동적라이브러리로 만든 후 해당 라이브러리를 사용하여 test_static.c 코드가 실행되도록 test_dll 실행파일을 생성. 

#### 5. 실행예시
* put.txt : key, value 의 내용을 가지고 있음.

```
Mike Seoul
Hakim Sanfrancisco 
Ted Boston
Eunji Madion
Ted Texas
```

 - get.txt: key 를 가지고 있음.
``` 
Ted 
Mike
```

 - 실행
```
$) tar xvzf kvs_20191232.tar.gz 
$) cd kvs_20191232 
$) make_static 
$) ./test_static put.txt get.txt result_static.txt 
$) cat result_static.txt 
Texas 
Seoul 

$) make_dll
$) ./test_dll put.txt get.txt result_dll.txt 
$) cat result_dll.txt 
Texas 
Seoul 
```
