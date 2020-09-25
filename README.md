
#Badges

![cppcheck-action](https://github.com/99002572/linux-OS/workflows/cppcheck-action/badge.svg?branch=master)    [![Codacy Badge](https://app.codacy.com/project/badge/Grade/649949a64bb24a3ca02ed3d91a17e95f)](https://www.codacy.com/manual/99002572/linux-OS/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=99002572/linux-OS&amp;utm_campaign=Badge_Grade)    ![CI](https://github.com/99002572/linux-OS/workflows/CI/badge.svg)



##Sleeping Teaching Assistant Problem.

This project uses 3 semaphores out of which one is a mutex-lock along with a variable.
- sem_t sem_stu - Student
- sem_t sem_ta - TA
- pthread_mutex_t mutex – Access Seats
- int count – Variable for number of waiting students

Initially, the semaphores and the variable are given the following initial values.
- Student = 0
- TA = 0
- Access Seats = 1
- Waiting students = 0

### Four Scenarios

1. There is zero student come to visit TA. TA will check the hallway outside his office to see if there are any othe students seated and waiting for him. If there are none, the TA will sleep in his office.

2. When a student arrives at the TA’s office and finds the TA sleeping. Then the student will awaken the TA and ask for help. When the TA assists the student, the student's semaphore changes from 0 to 1 and waits for the TA's semaphore. When the TA finishes helping one student, he will check if there is any other student waiting in the hallway. If yes, he will help the next student and if not, TA goes back to sleeping and TA's semaphore becomes 1 and awaits student's semaphore.

3. When a student arrives while the TA is busy with another student. Then the student who arrived will have to check if the TA is busy. If the TA is busy, the student will have to wait seated outside in the hallway until the TA is done with his session. When the TA completes his session, the student seated outside will be called in by the TA for a review session. Once all students have finished their sessions and left the TA’s office, the TA will go back to sleep after making sure no students are waiting.

4. When a student arrives while the TA is busy in a review session, and all the seats in the hallway are occupied. Then, student will have to leave the hallway and come back later. When the student comes back, eventually, and there is a seat available, he will take a seat and wait for his turn with the TA.





