DROP TABLE IF EXISTS product_audit;
CREATE TABLE product_audit (
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

    INSERT INTO product_audit VALUES (username, time_stamp, NEW.eid);

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;


CREATE TRIGGER t2_2
    BEFORE UPDATE ON stock
    FOR EACH ROW EXECUTE PROCEDURE t2_2();