### Combine Two Tables
```
  SELECT P.FirstName, P.LastName, A.City, A.State 
  FROM Person P
  LEFT JOIN Address A
  ON P.PersonID = A.PersonID;
```

### Second Highest Salary
```
SELECT MAX(Salary) AS SecondHighestSalary 
FROM Employee
WHERE Salary < (SELECT MAX(Salary) FROM Employee);
```

### Nth Highest Salary
```
#slow due to row wise execution

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT(Salary) AS getNthHighestSalary
      FROM Employee e1
      WHERE N-1=(SELECT COUNT(DISTINCT(Salary)) from Employee e2 where e2.salary > e1.salary)
  );
END
```



### Rank Scores

```

```

### Employees Earning More Than Their Managers  
```
#slow
SELECT E.Name AS Employee
FROM Employee E, Employee M
WHERE E.ManagerId = M.Id and E.Salary > M.Salary;

#intermediate
SELECT E.Name AS Employee
FROM Employee E join Employee M
on E.ManagerId = M.Id 
WHERE E.Salary > M.Salary;


#fastest
SELECT E.Name AS Employee
FROM Employee E inner join Employee M
on E.ManagerId = M.Id 
WHERE E.Salary > M.Salary;
```


### Consecutive Numbers
```
SELECT DISTINCT(l1.Num) as ConsecutiveNums
FROM Logs l1, Logs l2, Logs l3
WHERE l1.Id = l2.Id-1 and l2.Id = l3.Id-1 and l1.Num = l2.Num and l2.Num = l3.Num; 
```

### Duplicate Emails
```
#slow, can be improved using joins
SELECT Email
FROM Person
GROUP BY Email
Having COUNT(Email) > 1;
```

### Customers Who Never Order


```
SELECT Name as Customers FROM Customers
WHERE Id NOT IN(SELECT CustomerId FROM Orders);
```
