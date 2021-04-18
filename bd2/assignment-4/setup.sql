CREATE DATABASE tp2;

\c tp2;

DROP TABLE IF EXISTS test;
CREATE TABLE test(
    id SERIAL,
    A INT,
    B INT,
    C INT,
    D INT
);
