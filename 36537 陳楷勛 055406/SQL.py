import sqlite3
import os

class SQL:
   def main(a,b) -> None:
      parms1 = (str(a))
      parms2 = (str(b))
      if not os.path.isfile('login.db'):
         db = sqlite3.connect('login.db')
         db.execute("CREATE TABLE USER (user CHAR(50));")
         db.execute("CREATE TABLE PASSWORD (password CHAR(50));")
         db.execute("INSERT INTO USER (user) VALUES (?);", parms1)
         db.execute("INSERT INTO PASSWORD (password) VALUES (?);", parms2)
      else:
         db = sqlite3.connect("login.db")
         db.execute("INSERT INTO USER (user) VALUES(?);",parms1)
         db.execute("INSERT INTO PASSWORD (password) VALUES(?);",parms2)

      db.commit()
      db.close()
