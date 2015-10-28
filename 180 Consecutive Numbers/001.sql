SELECT DISTINCT A.num
FROM Logs A, Logs B, Logs C
WHERE A.num = B.num AND
      A.num = C.num AND
      A.ID + 1 = B.ID AND
      A.ID + 2 = C.ID;

