from tkinter import *
from easygui import*
from numpy import *
import math
import gaussian as xy



#   http://www.python-course.eu/tkinter_layout_management.php   -> Important source to learn 

# This integer box  takes the input of the order of the matrix, where the default value is set to null
n = integerbox(msg="Input the order of the matrix", 
    title = "Gauss Elimenation with pivoting",
    lowerbound = 0)
# Now we are using tkinter to take input of the augmented matrix

n = int(n)
rows = []
root  = Tk()
for i in range(n):
    cols = []
    for j in range(n+1):
        e = Entry(root,relief=RIDGE,bg='black',fg= 'white',font = "Helvetica 15 bold")
        e.grid(row=i, column=j, sticky=NSEW)
        cols.append(e)
    rows.append(cols)


def onPress():
    matr = []
    for row in rows:
        columns = []
        for col in row:
            question = col.get()
            if len(question)==0:
                msgbox("Empty cell", "Warning!")
                sys.exit()
            elif question[0]!="-":
                if question.isdigit():
                    columns.append(question)
                else:
                    msgbox("Invalid integer or blank entry !!!", "Warning!")
                    sys.exit()
            else:
                if question[1:].isdigit(): 
                    columns.append(question)
                else:
                    msgbox("Invalid integer or blank entry !!!", "Warning!")
                    sys.exit()
        matr.append(columns)
    a = matr
    root.destroy()
    try:
        xy.Gauss_elimination(a,n)
    except Exception as ex:
        msgbox("Error!!!!!!division by zero")


            

Button(text='OK', command=onPress).grid()

mainloop()