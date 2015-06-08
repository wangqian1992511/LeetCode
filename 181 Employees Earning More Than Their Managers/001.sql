SELECT A.Name as Employee
FROM Employee as A, Employee as B
Where B.Id = A.ManagerId AND A.Salary > B.Salary;