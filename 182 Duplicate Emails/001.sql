SELECT DISTINCT(A.Email)
FROM Person AS A, Person AS B
WHERE A.Email = B.Email AND A.Id != B.Id;