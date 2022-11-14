<h1 align="center">Hi 👋, I'm Salama</h1>
<h3 align="center">Dev/student at 42abudhabi</h3>

- 👨‍💻 All of my projects are available at [https://github.com/s-almanso](https://github.com/s-almanso)

- 📫 How to reach me **salmanso@student.42abudhabi.ae**

# Minitalk
This project is a small introduction to data exchange programs using UNIX signals, where you are asked to realize a communication program in the form of a client and a server.

### <I> What is Minitalk? </I>
Minitalk is an individual project at <b>42</b> the goal is to code a small data exchange program using UNIX signals. It introduces a highly interesting new concept in C programming: <a href="https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/">bitwise operations.</a>


#### Objectives
- Unix logic

#### Skills
- Unix
- Rigor

## Getting started
**Follow the steps below**
```bash
# Clone the project and access the folder
git clone https://github.com/s-almanso/42Cursos-Minitalk && cd 42Cursos-Minitalk/

# Excute the mandatory part
Make all

# After succesfully compiling both files
# to excute the server & get the PID
./server

# Open a new terminal for the client
# In order for the client to communicate with the server use the below format
./client <PID> "any-text"

# In order to clean excutable/object file run any of the following commands
Make clean
Make fclean

# You can also clean and re-excute
Make re

# Well done!
```

# Summary of the Server functions
## main function:
- The main in the server is used to keep the server running, the server should run and display the server's unique PID.
- When some process is formed and is running, a unique id is assigned to it. This is the process id <b>(PID)</b>. The <b>getpid()</b> function helps in returning the id of the process that is currently called.
- The <b>signal()</b> function sets a function to handle signal i.e. a signal handler. It accepts two values, int SIGUSR1/2 and the processed signal from our fucntion ft_signal.

### <b> void ft_putchar(char c) & void ft_putnbr(int n) </b>

- The functions are used to print the PID and the new line.

### <b> void ft_signal(int sig) </b>
- Declare a static char variable to save the value of the bits we receive from the client.
- Declare a static int variable to count the number of bits received.
- Shift the bits to the left by 1 everytime we get a signal in order to save the recieved bit.
- The signal recieved will either be a one or zero since we declared that SIGUSR2 = 1, everytime we get a SIGUSR2 signal from the client we OR it with 1.
- Once the bitcount is 8 then in this case we recieved the full charachter, thus display it and return the bitcount and bits to zero.

---
# Summary of the Client functions
## main function:
- Declare an int pid, to save the pid as int.
- Declare a char *sig to save the signal we want to send.
- Declare an int i to loop through the PID to check if it's valid.
- The first part of the main is to check if the arguments and the PID are valid and ft_error is used to display the error msg.
- ft_atoi is called in order to conv the PID to int value in order to kill it to the server (send it).
- The handler function is used to send check if the PID valid and within 4 digits and if the sig is not empty.

### <b>void sigtokill(pid_t pid, char *sig)</b>
- the sigtokill will send the individual bits of the charachter to the server using the kill function.
- The kill() function sends a signal to a process or process group specified by pid. The signal to be sent is specified by sig and is either 0 or one of the signals from the list in the <sys/signal.h> header file.
- The process sending the signal must have appropriate authority to the receiving process or processes. The kill() function is successful if the process has permission to send the signal sig to any of the processes specified by pid. If kill() is not successful, no signal is sent and it will <b>return -1</b>.
- A process can use kill() to send a signal to itself. If the signal is not blocked in the sending thread, and if no other thread has the sig unblocked or is waiting in a sigwait function for sig, either sig or at least one pending unblocked signal is delivered to the sender before kill() returns
- The <b>usleep()</b> function suspends a thread for the number of microseconds specified by the of useconds parameter. (Because of processor delays, the thread can be suspended slightly longer than this specified time.) The thread does not resume until either the specified interval of time passes or a signal is delivered whose action is to call a signal-catching function, to end the request, or to terminate the process.
- the usleep() value is set to 160us after testing it with a big article and I didn't encounter any signals mixing.

---
<h3 align="left">Connect with me:</h3>
<p align="left">
<a href="https://twitter.com/_thesalama" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/twitter.svg" alt="_thesalama" height="30" width="40" /></a>
<a href="https://instagram.com/batsaam_" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/instagram.svg" alt="batsaam_" height="30" width="40" /></a>
</p>

<h3 align="left">Languages and Tools:</h3>
<p align="left"> <a href="https://www.arduino.cc/" target="_blank" rel="noreferrer"> <img src="https://cdn.worldvectorlogo.com/logos/arduino-1.svg" alt="arduino" width="40" height="40"/> </a> <a href="https://www.cprogramming.com/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/> </a> <a href="https://www.docker.com/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/docker/docker-original-wordmark.svg" alt="docker" width="40" height="40"/> </a> <a href="https://git-scm.com/" target="_blank" rel="noreferrer"> <img src="https://www.vectorlogo.zone/logos/git-scm/git-scm-icon.svg" alt="git" width="40" height="40"/> </a> <a href="https://www.linux.org/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/linux/linux-original.svg" alt="linux" width="40" height="40"/> </a> <a href="https://www.mathworks.com/" target="_blank" rel="noreferrer"> <img src="https://upload.wikimedia.org/wikipedia/commons/2/21/Matlab_Logo.png" alt="matlab" width="40" height="40"/> </a> <a href="https://pandas.pydata.org/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/2ae2a900d2f041da66e950e4d48052658d850630/icons/pandas/pandas-original.svg" alt="pandas" width="40" height="40"/> </a> <a href="https://www.python.org" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/python/python-original.svg" alt="python" width="40" height="40"/> </a> <a href="https://pytorch.org/" target="_blank" rel="noreferrer"> <img src="https://www.vectorlogo.zone/logos/pytorch/pytorch-icon.svg" alt="pytorch" width="40" height="40"/> </a> <a href="https://scikit-learn.org/" target="_blank" rel="noreferrer"> <img src="https://upload.wikimedia.org/wikipedia/commons/0/05/Scikit_learn_logo_small.svg" alt="scikit_learn" width="40" height="40"/> </a> <a href="https://seaborn.pydata.org/" target="_blank" rel="noreferrer"> <img src="https://seaborn.pydata.org/_images/logo-mark-lightbg.svg" alt="seaborn" width="40" height="40"/> </a> <a href="https://www.tensorflow.org" target="_blank" rel="noreferrer"> <img src="https://www.vectorlogo.zone/logos/tensorflow/tensorflow-icon.svg" alt="tensorflow" width="40" height="40"/> </a> </p>

