import webbrowser
import SQL
import pyautogui
import sqlite3
import os
#import pandas as pd

urL='https://dash.misthost.net/'
db = sqlite3.connect('login.db')
switch = 0
acul1 = []
acul2 = []

def OK():
   print("Stupid")
   while True:
      webbrowser.get('windows-default').open_new(urL)

d = int(input("Press (2)login (1)singin:"))

if d == 1:
   user = str(input("請輸入帳號:"))
   password = str(input("密碼:"))
   SQL.SQL.main(user,password)
elif d == 2:
   user = str(input("請輸入帳號:"))
   password = str(input("密碼:"))

   rows = db.execute("select * from USER;")
   bins = db.execute("select * from PASSWORD")


   for row in rows:
      for field in row:
         acul1.append(str(field))

   for bin in bins:
      for j in bin:
         acul2.append(str(j))

   time = len(acul1)

   for k in range(0,time):
      if user == str(acul1[k]) and str(password == acul2[k]):
         print("Welcome")
         break
      else:
         switch += 1
   if switch == len(acul1):
      print("Wrong username or password")

else:
   print("What do you mean?")
   OK()

db.close()
'''acul2 = acul1
   for row in rows:
      for field in row:
         if not switch:
            if a == field:
               switch = True
         else:
            switch = False

         if switch:
            if b == field:
               switch == 0
               print("Welcome")
               break
            else:
               switch = False

            check += 1
else:
   OK()

if check == len(acul2):
   print("Login faild")
   OK()

check = 0
switch = 0
acul1 = 0'''

'''   c = len(e)

   for i in range(c):
      if a == e[i][0] and b == e[i][1]:
         print(Welcome)
      else:
         OK()

   db.close()
else:
   print("???")
   OK()
'''