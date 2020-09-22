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
