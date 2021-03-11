DROP TABLE IF EXISTS product_audit;
CREATE TABLE product_audit (
    id SERIAL PRIMARY KEY NOT NULL,
    username VARCHAR(64),
    time_stamp TIMESTAMP,
    eid INTEGER
);


CREATE OR REPLACE FUNCTION
    t2_2()
RETURNS trigger AS $$

DECLARE
    username VARCHAR(64);
    time_stamp TIMESTAMP;

BEGIN

    SELECT current_user INTO username;
    SELECT now() INTO time_stamp;

    IF NEW.quantity < OLD.quantity THEN
        INSERT INTO product_audit 
            (username, time_stamp, eid) 
        VALUES 
            (username, time_stamp, NEW.eid);
    END IF;

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;


CREATE TRIGGER t2_2
    BEFORE UPDATE ON stock
    FOR EACH ROW EXECUTE PROCEDURE t2_2();