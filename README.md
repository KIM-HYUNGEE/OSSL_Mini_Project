# OSSL_Mini_Project
Project Title: Online Secondhand Book Market System
===================================================

Overview
--------
> In handong global university, many students are exchanging their used class textbooks. 
> Most people are doing this, because this can help saving money!
> So, I wanted to develop the program that can help buying and selling student's used books.

Make makefile to compile the project code easily
------------------------------------------------
> <pre>
> <code>
> miniProject: main.o base.o extras.o
>  gcc main.o base.o extras.o -o miniProject
> 
> main.o: main.c 
> 	gcc -c main.c -o main.o
> 
> base.o: base.c base.h record.h save.log
> 	gcc -c base.c -o base.o
> 
> extras.o: extras.c extras.h record.h save.log
> 	gcc -c extras.c -o extras.o
> 
> clean:
> 	rm miniProject main.o base.o extras.o
> </code>
> </pre>

Developer Info
--------------
> Developer: Kim Hyungee 

> University: Handong Global University (21900215)

> Development Period: 2020-04-01 ~ 2020-05-01

> Email: 21900215@handong.edu

> Phone Number: 010-xxxx-xxxx

