# Covid-Outbreak-Game

COVID Outbreak: Escape the Fall Semester assignment for EC 327: Introduction to Software Engineering, introducing User-Defined Types, Encapsulation, Operator Overloading, Interacting Objects, Linked Lists, etc.

The game consists of students that can move between classrooms and doctor's offices. At classrooms, students can go to class and earn credits by doing assignments. At doctor's offices, students must get vaccine booster shots periodically to make it through the semester. You “win” the game by getting all the credits you need without being hospitalized.

Here is a description of the commands and their input values:

m ID x y

    "move": command Student ID to move to location (x, y)

d ID1 ID2

    "move towards a DoctorsOffice": command Student ID1 to start heading to DoctorsOffice ID2.

c ID1 ID2

    "move towards a Classroom": command Student ID1 to start heading towards ClassRoom ID2.

s ID

    "stop": command Student ID to stop doing whatever it is doing

v ID vaccine_amount

    "buy vaccines": command StudentID to buy vaccine_amount of vaccines at a DoctorsOffice.

a ID assignment_amount

    "complete assignment_amount assignments at a ClassRoom": command Student ID to complete assignment_amount of training units at a ClassRoom.

g

    "go": advance one-time step by updating each object once.

r

    "run": advance one-time step and update each object, and repeat until either the update function returns true for at least one of the objects, or 5 time steps have been done.

q

    "quit": terminate the program
