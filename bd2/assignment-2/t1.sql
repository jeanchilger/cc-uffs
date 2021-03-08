CREATE OR REPLACE FUNCTION 
    t1_1()
RETURNS trigger AS $$
DECLARE
    available_seats INT;

BEGIN
    SELECT number_of_free_seats 
        FROM available_flights 
        INTO available_seats
        WHERE available_flights.num_flight = NEW.num_flight;

    IF available_seats > 0 THEN
        UPDATE available_flights
            SET number_of_free_seats = number_of_free_seats - 1,
                price = price + 50
            WHERE available_flights.num_flight = NEW.num_flight;
    ELSE
        RAISE NOTICE 'Nenhum acento disponível!!';
        RETURN null;
    END IF;

    RETURN NEW;

END;
$$ LANGUAGE plpgsql;


CREATE TRIGGER t1_1
    BEFORE INSERT ON bookings
    FOR EACH ROW EXECUTE PROCEDURE t1_1();