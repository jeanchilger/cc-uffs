\c task_one


SELECT * FROM employees;


-- Increases wages of employees whose id is greater than
-- 'id' by an ammount of 'percentage'.
-- 'id' = N, 'percentage' = X.
CREATE OR REPLACE FUNCTION
    apply_selective_increase(
        base_id INTEGER,
        percent_abs INTEGER
    )
RETURNS VOID AS $$
DECLARE
    percentage FLOAT;
BEGIN
    percentage := percent_abs / 100.0;
    UPDATE employees 
        SET wage = wage + wage * percentage
        WHERE id > base_id;
END;
$$ LANGUAGE plpgsql;


-- Applies function and show table;
SELECT apply_selective_increase(2, 50);

SELECT * FROM employees; 
