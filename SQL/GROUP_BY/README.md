# GROUP BY

</br>

Difference between `DISTINCT + ORDER BY`

`GROUP BY` is a aggregate function, while `DISTINCT` returns only its criteria.  
If there has been 3 transactions in `2021-02-26`,
`GROUP BY` will gather those 3 transactions information while `DISTINCT` will only show the very fist transaction

</br>
   
```sql
SELECT category_col, AGG_FUNC(data_col)   
FROM table   
GROUP BY category_col   
   
SELECT category_col, AGG_FUNC(data_col)   
FROM table   
WHERE category_col != 'A'   
GROUP BY category_col    
   
SELECT title, SUM(rental_duration)   
FROM film   
GROUP BY title   
ORDER BY SUM(rental_duration)   
   
SELECT title, SUM(rental_duration)   
FROM film   
GROUP BY title   
ORDER BY SUM(rental_duration)   
LIMIT 5   
```

</br>

payment 테이블에  
그간 고객들의 구매기록이 있다고 하자.  
특정 고객들은 꾸준히 구매를 했을꺼고, payment 테이블에는 그 고객들이 **한번 왔을 때 구매한 총액이** amount에 있을 것.

### 어떤 고객이 그동안 제일 많이 팔아줬는지를 내림차순으로 정렬해보자

SELECT customer_id, SUM(amount)  
FROM payment  
GROUP BY customer_id  
ORDER BY SUM(amount) DESC

</br>
   
---
   
   
## HAVING
   
```sql
SELECT customer_id, SUM(amount)
FROM payment
WHERE customer_id NOT IN (183,173)
GROUP BY customer_id
ORDER BY SUM(amount) ASC
LIMIT 5
```
   
customer_id 의 조건을 따지는건 WHERE에서 가능하다

```sql
SELECT customer_id, SUM(amount)
FROM payment
GROUP BY customer_id
ORDER BY SUM(amount) ASC
LIMIT 5
```

위와같은 절에서 SUM(amount)가 100 이상인것들에서 따져보고 싶다고 하자.

```sql
SELECT customer_id, SUM(amount)
FROM payment
WHERE SUM(amount) > 100 --ERROR
GROUP BY customer_id
ORDER BY SUM(amount) ASC
LIMIT 5
```

이러면 집계함수(_Aggregate function_)는 WHERE 에서 사용할 수 없다는 에러가 뜬다.

**왜냐면 `SELECT` 에서 명시해준 SUM(amount) 는 GROUP BY 문이 실행되기 전 까지 실행되지 않기 때문이다. 그래서 존재하지 않는 값에 대해 WHERE 문을 호출할 수 없는것**

집계된 정보에 조건문을 넣고싶다면? => HAVING

```sql
SELECT customer_id, SUM(amount)
FROM payment
GROUP BY customer_id
HAVING SUM(amount) > 100
ORDER BY SUM(amount) ASC
LIMIT 5
```

**HAVING 절은 반드시 GROUP BY 다음에 와야한다**
