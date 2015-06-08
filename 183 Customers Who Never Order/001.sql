SELECT A.Name as Customers
FROM Customers as A
WHERE A.Id NOT IN (
    SELECT B.CustomerId
    FROM Orders as B);