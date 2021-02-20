SELECT * FROM employees;


-- Increases all wages by 10%.
CREATE OR REPLACE FUNCTION
    increase_wage()
RETURNS VOID AS $$
DECLARE
    percentage float;
BEGIN
    percentage := 10.0 / 100.0;
    UPDATE employees 
        SET wage = wage + wage * percentage;
END;
$$ LANGUAGE plpgsql;


-- Applies function and show table;
SELECT increase_wage();

SELECT * FROM employees; 
