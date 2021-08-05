# minitalk
This project's goal is to create a communication program in the form of a client and server.

# Usage
1. *Launche the `server`*  
To handle the 2 programs, run in the background or open a separate terminal.  
It display its PID.  

2. *Run the `client`*  
It takes as parameters :
- The server PID.
- The string that should be sent.

# Example
```
$ ./server &
[1] 79739
SERVER PID : 79739

$ ./client 79739 test
CLIENT PID: 79767
from 79767 : test
Successfully sent message.
```
