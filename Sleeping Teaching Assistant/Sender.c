#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
  
// structure for message queue 
struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[100]; 
} student; 
  
int main() 
{ 
    key_t key; 
    int msgid; 
  
    // ftok to generate unique key 
    key = ftok("progfile", 65); 
  
    // msgget creates a message queue 
    // and returns identifier 
    msgid = msgget(key, 0666 | IPC_CREAT); 
    student.mesg_type = 1; 
  
    printf("Number of Students: "); 
    gets(student.mesg_text); 
  
    // msgsnd to send message 
    msgsnd(msgid, &student, sizeof(student), 0); 
  
    // display the message 
    printf("Number of Students: %s \n", student.mesg_text); 
  
    return 0; 
} 