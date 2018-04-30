from tkinter import *

def display_answer(answer):
	for j in range(len(answer)):
		Label(bg = 'black',fg='white',text=answer[j],font = "Helvetica 15 bold", relief=RIDGE,width=30).grid(row=j,column=0)
