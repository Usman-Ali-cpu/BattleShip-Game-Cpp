import sqlite3


def query_table():
    """function to get records from table Employee."""
    """ Establishing connection with sqlite and gettingcursor object"""
    conn = sqlite3.connect('ZYXCorp')
    cursor = conn.cursor()
    """ getting first and last name of Directors and Managers """
    query = """SELECT first_name, last_name FROM Employee WHERE job_title = 'Director' or job_title = 'Manager'"""
    result = cursor.execute(query).fetchall()
    print("Directors and Managers:")
    """ print each fetch row """
    for row in result:
        print(row[0], row[1])
    """ getting call engineers info having salary > 12000 """
    query = """SELECT * FROM Employee WHERE job_title = 'Engineer' and salary > 120000 """
    result = cursor.execute(query).fetchall()
    print()  # prints a blank line
    print("Engineers with salary > 120000:")
    """ print each fetched record """
    for row in result:
        print(row)


def update_table():
    """
        function to update table Employee.
        """
    """ Establishing connection with sqlite and getting
        cursor object"""
    conn = sqlite3.connect('ZYXCorp')
    cursor = conn.cursor()
    """ Increase Employee number 5555 pay to 125000,
        and display a message that the update was successful. """

    query = """ UPDATE Employee SET salary = 125000 WHERE employee_number = 5555 """
    cursor.execute(query)
    conn.commit()
    print("The update was successful")
    """ DELETE Employee whose employee number is 6666
        and print a success message."""
    query = " DELETE FROM Employee WHERE employee_number = 6666 "
    cursor.execute(query)
    conn.commit()
    query = """UPDATE Employee SET job_title = 'Manager', salary = 166000 WHERE employee_number = 3333"""
    cursor.execute(query)
    conn.commit()
    print("The update was successful\n")
    """ close connection and call query_table() function"""
    conn.close()
    query_table()


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
    VALUES(1111,'Angus','Young','Director',225000)"""
    cursor.execute(insert1)
    conn.commit()
    """ Inserting second row with provided data."""
    insert2 = """INSERT INTO Employee(employee_number,first_name,last_name,job_title,salary)
    VALUES(2222,'Penelope','Cruz','Manager',175000)"""
    cursor.execute(insert2)
    conn.commit()
    """ Inserting third row with provided data."""
    insert3 = """INSERT INTO Employee(employee_number,first_name,last_name,job_title,salary)
    VALUES(3333,'James','Hetfield','Engineer',135000)"""
    cursor.execute(insert3)
    conn.commit()
    """ Inserting fourth row with provided data."""
    insert4 = """INSERT INTO Employee(employee_number,first_name,last_name,job_title,salary)
    VALUES(4444,'Dave','Grohl','Engineer',130000)"""
    cursor.execute(insert4)
    conn.commit()
    """ Inserting fifth row with provided data."""
    insert5 = """INSERT INTO Employee(employee_number,first_name,last_name,job_title,salary)
    VALUES(5555,'Susanna','Hoffs','Engineer',110000)"""
    cursor.execute(insert5)
    conn.commit()
    """ Inserting sixth row with provided data."""
    insert6 = """INSERT INTO Employee(employee_number,first_name,last_name,job_title,salary)
    VALUES(6666,'Salma','Hayek','Engineer',150000)"""
    cursor.execute(insert6)
    conn.commit()
    """ Inserting seventh row with provided data."""
    insert7 = """INSERT INTO Employee(employee_number,first_name,last_name,job_title,salary)
    VALUES(7777,'Saul','Hudson','Engineer',95000)"""
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
