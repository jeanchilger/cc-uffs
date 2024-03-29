import psycopg2

class DBManager:
    def __init__(
            self, host="localhost", database="tp2",
            user="postgres", password="postgres"):
        self.connection = psycopg2.connect(
                host=host, database=database,
                user=user, password=password)

    def _execute_query(self, sql, get_pk=False, is_select=False):
        """
        Executes a SQL query.

        Args:
            sql (string): SQL query to be executed
        """

        cursor = self.connection.cursor()
        
        cursor.execute(sql)
        self.connection.commit()
        
        _value = None
        if get_pk:
            _value = cursor.fetchone()[0]
        
        if is_select:
            _value = cursor.fetchone()

        cursor.close()

        return _value
    
    def select(
            self, table_name="test",
            columns=("A", "B", "C", "D"), pk_name="id",
            pk_value=None):

        if pk_value is not None:
            sql = "SELECT {} FROM {} WHERE {} = {};".format(
                    ",".join(columns), table_name,
                    pk_name, pk_value)

        else:
            sql = "SELECT {} FROM {};".format(",".join(columns), table_name)

        return self._execute_query(sql, is_select=True)

    def drop_table(self, table_name="test"):
        """[summary]

        Args:
            table_name ([type]): [description]
        """

        sql = "DROP TABLE IF EXISTS {}".format(table_name)

        self._execute_query(sql)

    def create_table(
            self, table_name="test",
            columns=("A", "B", "C", "D"), pk_name="id"):
        """[summary]

        Args:
            table_name (str, optional): [description]. Defaults to "test".
            columns (tuple, optional): [description]. Defaults to ("A", "B", "C", "D").
            pk_name (str, optional): [description]. Defaults to "id".
        """

        _columns = ["{} SERIAL".format(pk_name)]
        for column in columns:
            _columns.append("{} INT".format(column))

        sql = "CREATE TABLE {}({})".format(table_name, ",".join(_columns))

        self._execute_query(sql)

    def insert(
            self, values, table_name="test",
            columns=("A", "B", "C", "D"), pk_name="id"):
        """[summary]

        Args:
            values (tuple): [description]
            table_name (str, optional): [description].
                Defaults to "test".
            columns (tuple, optional): [description].
                Defaults to ("A", "B", "C", "D").
        """

        sql = "INSERT INTO {}({}) values {} RETURNING {};".format(
                table_name, ",".join(columns),
                values, pk_name)

        return self._execute_query(sql, get_pk=True)

    def update(
                self, new_values, columns, pk_value,
                pk_name="id", table_name="test"):
        """[summary]

        Args:
            new_values (tuple or string): [description]
            columns (tuple or string): [description]
            pk_value (string): [description]
            pk_name (str, optional): [description]. Defaults to "id".
            table_name (str, optional): [description]. Defaults to "test".
        """

        _set_columns = ""

        for column, value in zip(columns, new_values):
            _set_columns += "{} = {},".format(column, value)    

        _set_columns = _set_columns[0:-1]

        sql = "UPDATE {} SET {} WHERE {} = {};".format(
                table_name, _set_columns, pk_name, pk_value)

        self._execute_query(sql)
