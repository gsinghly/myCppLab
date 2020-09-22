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
