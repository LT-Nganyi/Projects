from tkinter import *
import tkinter.font as tk_font




nbs = []

computed =False
app = Tk()
app.geometry("400x410")
app.title("TC Calculator".rjust(50))
app.configure(bg='#71EEB8')

#hoto = PhotoImage(file = r'img\arcpy_!.jpg')
#app.iconphoto(False,photo)
#font_size = tk_font.Font(family="Lucida Grande", size=10)
display = Text(height= 3,width = 45,borderwidth=3)
display.grid(row = 0,columnspan=3,pady=20, padx=15)
def draw_b1():
    clear_answer()
    display.insert(END,1)
    nbs.append(1)
def draw_b2():
    clear_answer()
    display.insert(END,2)
    nbs.append(2)
def draw_b3():
    clear_answer()
    display.insert(END,3)
    nbs.append(3)
def draw_b4():
    clear_answer()
    display.insert(END,4)
    nbs.append(4)
def draw_b5():
    clear_answer()
    display.insert(END,5)
    nbs.append(5)
def draw_b6():
    clear_answer()
    display.insert(END,6)
    nbs.append(6)
def draw_b7():
    clear_answer()
    display.insert(END,7)
    nbs.append(7)
def draw_b8():
    clear_answer()
    display.insert(END,8)
    nbs.append(8)
def draw_b9():
    clear_answer()
    display.insert(END,9)
    nbs.append(9)
def draw_b0():
    clear_answer()
    display.insert(END,0)
    nbs.append(0)
def draw_x():
    clear_answer()
    display.insert(END,'x')
    nbs.append('x')
def draw_():
    clear_answer()
    display.insert(END,'-')
    nbs.append('-')
def draw_plus():
    clear_answer()
    display.insert(END,'+')
    nbs.append('+')
def draw_div():
    clear_answer()
    display.insert(END,'/')
    nbs.append('/')
def clear_display():
    display.delete(1.0,END)
    global nbs 
    print("cleared number storage")
    nbs = []
def compute():
    global computed
    computed = True
    display.delete(1.0,END)
    global nbs
    
    if len(nbs)!= 0:
        #display.insert(END,"Computing")
        nbs= list(map(str,nbs))
        print(nbs)
        nbs_s = ''.join(nbs)
        print(nbs_s)
        if '+' in nbs_s:
            nbs_s = list(map(int,nbs_s.split('+') ))
            display.insert(END,f'{nbs_s[0]+nbs_s[1]}')
        elif '-' in nbs_s:
            nbs_s = list(map(int,nbs_s.split('-') ))
            display.insert(END,f'{nbs_s[0]-nbs_s[1]}')
        elif 'x' in nbs_s:
            nbs_s = list(map(int,nbs_s.split('x') ))
            display.insert(END,f'{nbs_s[0]*nbs_s[1]}')
        
        elif '/' in nbs_s:
            try:
                nbs_s = list(map(int,nbs_s.split('/') ))
                display.insert(END,f'{nbs_s[0]/nbs_s[1]}')
            except ZeroDivisionError:
                print("zero division error")
                display.insert(END,f'Math Error!\nCannot divide by zero.')
                nbs = []
        else: display.insert(END,f'{nbs_s}')
        print(nbs_s)
        nbs = []
    else:
        display.insert(END,0)
def clear_answer():
    global computed
    if computed:
        display.delete(1.0,END)
        computed = False

    

b1 = Button(text='1',command=draw_b1,height=2,width=10,bg='#1a9bd6').grid(row=1,column =0,pady=5)
b2 = Button(text='2',command=draw_b2,height=2,width=10,bg='#1a9bd6').grid(row=1,column =1,pady=5)
b3 = Button(text='3',command=draw_b3,height=2,width =10,bg='#1a9bd6').grid(row = 1, column =2,pady=5)
b4 = Button(text='4',command=draw_b4,height=2,width =10,bg='#1a9bd6').grid(row = 2, column =0,pady=5)
b5 = Button(text='5',command=draw_b5,height=2,width =10,bg='#1a9bd6').grid(row = 2, column =1,pady=5)
b6 = Button(text='6',command=draw_b6,height=2,width =10,bg='#1a9bd6').grid(row = 2, column =2,pady=5)
b7 = Button(text='7',command=draw_b7,height=2,width =10,bg='#1a9bd6').grid(row = 3, column =0,pady=5) 
b8 = Button(text='8',command=draw_b8,height=2,width =10,bg='#1a9bd6').grid(row = 3, column =1,pady=5)
b9 = Button(text='9',command=draw_b9,height=2,width =10,bg='#1a9bd6').grid(row = 3, column =2,pady=5)
plus = Button(text='+',command=draw_plus,height=2,width =10,bg="#FF7F50").grid(row = 4, column =0,pady=5)
b0 = Button(text='0',command=draw_b0,height=2,width =10,bg='#1a9bd6').grid(row = 4, column =1,pady=5)
minus = Button(text='-',command=draw_,height=2,width =10,bg="#FF7F50").grid(row = 4, column =2,pady=5)
div = Button(text='/',command=draw_div,height=2,width =10,bg="#FF7F50").grid(row = 5, column =0,pady=5)
b_space = Button(text='DEL',command=clear_display,height=2,width =10,bg='#FFBF00').grid(row = 5, column =1,pady=5)
mult = Button(text='x',command=draw_x,height=2,width =10,bg="#FF7F50").grid(row = 5, column =2,pady=5)
equal = Button(text='COMPUTE',command=compute,height=2,width= 30,bg='#FFBF00').grid(row = 6, column=0,columnspan=3,pady=5)

#b_space = Button(text='DEL',command=print(),height=2,width =10,bg='#dde80c').grid(row = 6, column =0,pady=5)
#######
#End of UI

app.mainloop()