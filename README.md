# Library Management
Object Oriented Programming to Implement Library Management System using C++.
The Project stores record of books and students, entered by administrator using the admin menu. Once Student ID and Book ID is created, students can issue the books from **Main Menu** using their created ID. Books issued by Students are recorded and can be returned back by depositing it.


# Working
The code consist of 3 classes: **Book** , **Student** and **Admin** class. The Project is implemented using Multilevel Inheritance such that **Book** class inherits **Student** class and **Admin** class inherits **Book**. The Admin Menu is protected by password, username is **admin** and password **admin123**. When the code is compiled and executed, Main Menu appears. It consist of options to Show all books, Issue Book, Deposit Book, Show Students or enter Admin Menu or else to exit. The Book can only be issued when students and books are stored. When Admin Menu is enterd, initially it asks for username and password, then the Admin Menu options is displayed.

For Books, there are 3 options either to create books, show books or delete books and for students there are 4 options, create student, list them all or modify or delete students. Books stores Book ID, Name of Book and Book Category while student stores Student ID, Student Name and Student Class.


It is important that all the ID's in the code accepts only integer values others are string types. To change the limit of students and books, nbooks and nstudents variable value has to be changed initially. Also the password can be changed.  
