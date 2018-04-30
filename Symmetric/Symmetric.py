from tkinter import *
from easygui import*
from numpy import *
import math
import os


n = integerbox(msg="Input the order of the matrix", 
    title = "Symmetric matrix operation",
    lowerbound = 0)

n = int(n)
rows = []
root  = Tk()
for i in range(n):
    cols = []
    for j in range(n):
        e = Entry(root,relief=RIDGE,bg='black',fg= 'white',font = "Helvetica 15 bold")
        e.grid(row=i, column=j, sticky=NSEW)
        cols.append(e)
    rows.append(cols)


def onPress():
    matrix = []
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
                    msgbox("Invalid  integer or blank entry !!!", "Warning!")
                    sys.exit()
        matrix.append(columns)
    a = matrix
    root.destroy()
    # Writing into a Matrix.txt file so that symmetric class can use this
    try:
        f = open("Matrix.txt","w+")
        for row in matrix:
            for col in row:
                f.write(col)
                f.write(" ")
            f.write("\n")
        f.close()
    except Exception as ex:
        msgbox("couldn't create a file")




Button(text='OK', command=onPress).grid()
mainloop()




#os.system(" g++ ./test/test_file.cpp")
#os.system(" ./a.out")