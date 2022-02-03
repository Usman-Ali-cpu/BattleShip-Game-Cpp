import sqlite3


def query_table():  # t will print the detail of all data in the table Employee
    """function to get records from table Employee."""
    """ Establishing connection with sqlite and gettingcursor object"""
    conn = sqlite3.connect('ZYXCorp')
    cursor = conn.cursor()
    """ getting first and last name  """
    query = """SELECT first_name, last_name  FROM Employee WHERE salary = 10"""
    result = cursor.execute(query).fetchall()
    print("Years_of_service with years_of_service = 10:")
    """ print each fetch row """
    for row in result:
        print(row[0], row[1])

    query = """SELECT * FROM Employee WHERE job_title = 'JDBC' """
    result = cursor.execute(query).fetchall()
    print()  # prints a blank line
    print("Engineers with Job JDBC:")
    """ print each fetched record """
    for row in result:
        print(row)

    query = """SELECT * FROM Employee WHERE job_title = 'Developer' """
    result = cursor.execute(query).fetchall()
    print()  # prints a blank line
    print("All developers:")
    """ print each fetched record """
    for row in result:
        print(row)


# it will update the data of table Employee
def update_table():
    """
        function to update table Employee.
        """
    """ Establishing connection with sqlite and getting
        cursor object"""
    conn = sqlite3.connect('ZYXCorp')
    cursor = conn.cursor()
    query = " DELETE FROM Employee WHERE employee_number = 4444"
    cursor.execute(query)
    conn.commit()
    print("Employee has been deleted Successfully")
    query = """ UPDATE Employee SET job_title = Server  WHERE employee_number = 6666 """
    cursor.execute(query)
    conn.commit()
    print("Employee's Job title has been updated to Server Successfully")
    query = """ UPDATE Employee SET salary = 26 WHERE employee_number = 1111 """
    cursor.execute(query)
    conn.commit()
    print("The update was successful")
    """ close connection and call query_table() function"""
    conn.close()
    query_table()

 # create table Employee


def create_table():
    """
        Create a table named Employee
        in th database called ZYXCorp
    """
    """ connect to database """
    conn = sqlite3.connect('ZYXCorp')
    """ Creating cursor object """
    cursor = conn.cursor()

    sql = '''CREATE TABLE Employee(
    employee_number INT NOT NULL,
    first_name TEXT(30),
    last_name TEXT(30),
    job_title TEXt(30),
    salary INT)'''

    cursor.execute(sql)  # execute sql query to create table
    """ Inserting first row with provided data."""
    insert1 = """INSERT INTO Employee(employee_number,first_name,last_name,job_title,salary)
    VALUES(1111,'Dana','Duffield','Security',25)"""
    cursor.execute(insert1)
    conn.commit()
    """ Inserting second row with provided data."""
    insert2 = """INSERT INTO Employee(employee_number,first_name,last_name,job_title,salary)
    VALUES(2222,'Kari','Olsen','JDBC',10)"""  # insert data into table
    cursor.execute(insert2)
    conn.commit()

    """ Inserting third row with provided data."""
    insert3 = """INSERT INTO Employee(employee_number,first_name,last_name,job_title,salary)
    VALUES(3333,'Urrvano','Gamez','Server',8)"""  # insert data into table
    cursor.execute(insert3)
    conn.commit()
    """ Inserting fourth row with provided data."""
    insert4 = """INSERT INTO Employee(employee_number,first_name,last_name,job_title,salary)
    VALUES(4444,'Julie','King','Server',30)"""  # insert data into table
    cursor.execute(insert4)
    conn.commit()
    """ Inserting fifth row with provided data."""
    insert5 = """INSERT INTO Employee(employee_number,first_name,last_name,job_title,salary)
    VALUES(5555,'Andy','McRight','JDBC',12)"""  # insert data into table
    cursor.execute(insert5)
    conn.commit()
    """ Inserting sixth row with provided data."""
    insert6 = """INSERT INTO Employee(employee_number,first_name,last_name,job_title,salary)
    VALUES(6666,'James','Kreiger','JDBC',20)"""  # insert data into table
    cursor.execute(insert6)
    conn.commit()
    """ Inserting seventh row with provided data."""
    insert7 = """INSERT INTO Employee(employee_number,first_name,last_name,job_title,salary) 
    VALUES(7777,'Christine','Draper','Security',5)"""  # insert data into table
    cursor.execute(insert7)
    conn.commit()
    """ display a message and call update_table() function """
    print("The table was created successfully")
    conn.close()  # close connection
    update_table()  # call update_table() function.


""" execution entry point """
if __name__ == '__main__':
    """ calling create_table() function """
    create_table()
