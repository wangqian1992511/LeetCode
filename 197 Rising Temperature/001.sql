SELECT Wa.Id As Id
FROM Weather Wa, Weather Wb
WHERE TO_DAYS(Wa.Date) = TO_DAYS(Wb.Date) + 1 AND
      Wa.Temperature > Wb.Temperature