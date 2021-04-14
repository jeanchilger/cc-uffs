import psycopg2

conn = psycopg2.connect(
        host="localhost",
        database="tp2",
        user="postgres",
        password="postgres")

cur = conn.cursor()

cur.execute("INSERT INTO test values (1, 2, 3)")

conn.commit()

cur.close()
