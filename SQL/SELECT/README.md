## SELECT _column_name_ FROM _table_name_

SELECT c1,c2 FROM table_1  
처럼 두개의 열에서 갖고오는거도 가능.

SELECT \* FROM table_1  
 \* 을 통해 모든 열 갖고오기 가능  
 모든 정보를 갖고와야해서 트래픽에 부담갈 수 있음. 지양하자

CASE: 회원들에게 스팸 메일을 보내고 싶음,  
`SELECT first_name,last_name,email FROM customer`

---

SELECT DISTINCT

## SELECT DISTINCT(_column_) FROM _table_

distinct: 뚜렷한. 구별되는.

SQL 구문에서 고유의 값들의 종류를 가져오고 싶을 경우

중복되는 것들은 순번이 높은 항목만 표시. 나머지는 표시안함  
Useful for show unique value

DISTINCT 옆에 소괄호 붙여도 되고 안붙여도 됨
근데 붙이는게 더 낫다

`SELECT DISTINCT rating FROM film;`  
영화가 백몇개있는데 상영등급인 5종류만 보여줌

---

SELECT COUNT(_foo_) FROM _table_

_table_ 에 존재하는 _foo_ 열을 가지는 행의 개수를 알려줌

**이거는 DISTINCT 랑 다르게 소괄호 꼭 있어야 하는 함수임**

모든 행에 존재하는 열의 개수는 같아서,  
`SELECT COUNT(foo) FROM talbe_1` 하나  
`SELECT COUNT(*) FROM table_1` 하나 둘 다 똑같음.

그래도 `*` 로 하기 보다는 열의 이름을 넣는게 뭐뭐 있는지 안까먹고 좋다~

---

## DISTINCT 와 COUNT의 조합

How many unique names are there in the table?

SELECT COUNT(DISTINCT(names)) FROM table

종류가 몇개있는지 개수를 알고싶을떄...

---

## WHERE

`SELECT col_1 FROM table_1 WHERE conditions`

SELECT title FROM film WHERE release_year > 1997  
개봉년도가 1997 이후인 영화들 select.

`SELECT title FROM film WHERE release_year > 1997 AND rating != 'R'`  
개봉년도가 1997이면서 rating 이 R인 영화.  
rating의 경우 문자 'R' 이라고 따옴표 찍어줘야함

문자 뿐만 아니라 모든 문자열 `'` 홑따옴표로 통일

SELECT COUNT(DISTINCT length) FROM film  
WHERE rating='R'

이렇게 응용도 가능

---

## ORDER BY

정 렬

`SELECT col1, col2 FROM table ORDER BY col1 ASC/DESC`

ASC: 오름차순, DESC: 내림차순

정렬차순 공백으로 남겨두면 default인 ASC 로 정렬됨

`ORDER BY name, age`  
로 했을 경우, `name` 순으로 정렬 하되,
동일 `name`일 경우 `age`순으로 정렬해서 보여준다는 뜻

`ORDER BY name DESC, age ASC`  
로 각각의 컬럼들 정렬조건 다르게 주는거도 가능
