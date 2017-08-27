from tkinter import *

def display_answer(answer):
	for j in range(len(answer)):
		Label(bg = 'black',fg='white',text=answer[j], relief=RIDGE,width=30).grid(row=j,column=0)
