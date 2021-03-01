## AS

```sql
SELECT column AS new_name   -- column name of OUTPUT will be new_name
FROM payment
```

```sql
SELECT SUM(column) AS new_name
```

**AS operator gets excuted at the very end of a query**

```sql
SELECT COUNT(customer_id) AS amt_of_customer, customer_id
FROM payment
GROUP BY customer_Id
HAVING amt_of_customer > 10 -- ERROR
```

This is illegal because `amt_of_customer` defined after `GROUP BY` executed

</br>

---

</br>
   
## Inner join   
   
**교집합**    
   
```sql
SELECT * FROM tableA
INNER JOIN tableB
ON tableA.col_match = tableB.col_match
```
   
```sql
SELECT customer.store_id, payment.customer_id ,payment.amount
FROM customer
INNER JOIN payment
ON customer.customer_id = payment.customer_id;
```

이렇게 여러개를 적어줄 수 있다.
**customer_id 의 경우 두개의 table에 모두 존재하므로, 정확히 테이블을 명시해주어야함**

</br>

---

</br>   
   
## Full Outer Join   
   
**합집합**   
   
```sql
SELECT *
FROM Regisitrations
FULL OUTER JOIN Logins
ON Registrations.name = Logins.name
```   
   
중복되는 name 은 한번만 보여줌
