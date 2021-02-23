\c task_one


SELECT * FROM employees;


-- Removes (DELETE) employees whose wage is greater than average.
CREATE OR REPLACE FUNCTION
    remove_above_avg()
RETURNS VOID AS $$
DECLARE
    avg_wage FLOAT;
BEGIN
    SELECT avg(wage)
        FROM employees
        INTO avg_wage;

    raise notice 'avg shit: %', avg_wage;

    DELETE FROM employees
        WHERE wage > avg_wage;
END;
$$ LANGUAGE plpgsql;


-- Applies function and show table;
SELECT remove_above_avg();

SELECT * FROM employees; 
