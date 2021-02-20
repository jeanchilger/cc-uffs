-- Creates an 'employees' table.
DROP TABLE IF EXISTS employees;
CREATE TABLE employees (
    id INT,
    name VARCHAR(50),
    birth_date DATE,
    wage FLOAT
);


-- Helper function for random text generation.
-- Code from https://www.simononsoftware.com/random-string-in-postgresql
-- Credits to Szymon Lipiński
CREATE OR REPLACE FUNCTION 
    random_text(length INT) 
RETURNS TEXT AS $$
DECLARE
    possible_chars TEXT := '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ';
    output TEXT := '';
    i INT4;
    chars_size INTEGER := length(possible_chars);
BEGIN
    chars_size := length(possible_chars);
    FOR i IN 1..length LOOP 
        output := output || substr(
            possible_chars, 
            (1 + FLOOR((chars_size - $1 + 1) * random() ))::INTEGER, 1);
    END LOOP;

    RETURN output;
END; 
$$ LANGUAGE plpgsql;


-- Helper function to insert a single employee
CREATE OR REPLACE FUNCTION 
    insert_employee(
        id INTEGER
    ) 
RETURNS VOID AS $$
DECLARE
    birth_date DATE;
    wage FLOAT;
    name VARCHAR(50);
BEGIN
    -- Get random values to insert
    SELECT random() * (4000 - 1000) + 1000 INTO wage;
    SELECT timestamp '1970-01-01' + random() * (timestamp '2002-12-31' - timestamp '1970-01-01') 
        INTO birth_date;
    SELECT random_text((random() * 10 + 3)::INTEGER) INTO name;
     
    INSERT INTO employees VALUES (id, name, birth_date, wage);
END;
$$ LANGUAGE plpgsql;


-- Function to create 'n' employees.
CREATE OR REPLACE FUNCTION
    populate_employees(
        n INTEGER
    )
RETURNS VOID AS $$
DECLARE
    i INT4;
BEGIN
    i := 0;
    LOOP
        i:= i + 1;
        PERFORM insert_employee(i);
        EXIT WHEN i = n;
    END LOOP;
END;
$$ LANGUAGE plpgsql;


SELECT populate_employees(5);

-- Adds an additional employee for easy control.
INSERT INTO employees VALUES (6, 'Control Emp', current_date, 100);
