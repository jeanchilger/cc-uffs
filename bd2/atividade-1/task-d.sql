SELECT * FROM employees;


-- Inserts a new employee and adds additional information about
-- who inserted and when.
CREATE OR REPLACE FUNCTION
    insert_employee_managed(
        id INTEGER,
        name VARCHAR(50),
        birth_date DATE,
        wage FLOAT
    )
RETURNS VOID AS $$
DECLARE

BEGIN
    -- Alter table first
    ALTER TABLE IF EXISTS employees
        ADD COLUMN IF NOT EXISTS user_added VARCHAR(50);
    ALTER TABLE IF EXISTS employees
        ADD COLUMN IF NOT EXISTS date_added DATE;

    -- Insert employee and additional informations
    INSERT INTO employees (
        id, name, birth_date, wage, user_added, date_added
    )
    VALUES (
        id, name, birth_date, wage, CURRENT_USER, CURRENT_DATE 
    );
END;
$$ LANGUAGE plpgsql;


-- Applies function and shows new table;
SELECT insert_employee_managed(
    99, 'Last Inserted Employee', '2020-02-20', 1000
);

SELECT * FROM employees; 
