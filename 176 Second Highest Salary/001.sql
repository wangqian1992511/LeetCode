SELECT MAX(Salary)
FROM Employee
WHERE Salary < 
      (SELECT MAX(Salary)
       FROM Employee)