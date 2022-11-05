<h1 align="center">Hi 👋, I'm Salama</h1>
<h3 align="center">Dev/student at 42abudhabi</h3>

- 👨‍💻 All of my projects are available at [https://github.com/s-almanso](https://github.com/s-almanso)

- 📫 How to reach me **salmanso@student.42abudhabi.ae**

# Minitalk
This project is a small introduction to data exchange programs using UNIX signals, where you are asked to realize a communication program in the form of a client and a server.

### What is Minitalk?
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
## ft_whatever:

### The get_next_line function will coordinate and call the other functions:

- declare the static variable,
- if the file descriptor fd or the BUFFER_SIZE is invalid, return NULL right away,
- call the reading function,
- if the static variable is not null or empty:
assign the result of the function to save the extra characters to the static variable,
- assign the result of the function to get the line to another variable that we will return shortly,
- if the variable we want to return, the line, is null or empty, free any allocated memory and return NULL,
- otherwise, return the line.

---
## The ft read & save:

### This function will read from the file descriptor in a loop until we detect a \n or the end of the file:

- create a reading loop that stops when the read function returns 0, which means we are at the end of the file and there is nothing left to read,
- read from the file descriptor,
- if read returns -1, there was an error, free all allocated memory and stop everything,
- save the read characters in a static variable (strjoin the buffer to the static),
- check to see if there is a \n in the static variable using ft_strchr: if yes, stop the loop, if no, continue.

---

# Summary of the Client functions
## The ft save line:

### If this function is called, it means we know for a fact that there is a \n in the static variable (or that there is nothing left to read in the file). We will extract the characters up to the \n to get the line we must later return:

- count the number of characters to and including the \n if there is one,
- malloc a string of the counted size, + 1 for the final \0,
- copy the characters until the \n or the \0 and add the final \0,
- return the malloc’d string.

---

## The ft save remaining:

### As with the previous function, by the time we call this function, we know that there is a \n in the static variable. If we have reached the end of the file, there is no need to call this function because we will end up returning the last line with the previous function. We must now “reset” the static variable by taking all the characters after the \n:

- measure the size of the string in the static variable, minus the number of characters until the \n (included!), + 1 for the final \0,
- malloc a string of that size,
- copy the characters and add the final \0,
- return the new malloc’d string.

---
<h3 align="left">Connect with me:</h3>
<p align="left">
<a href="https://twitter.com/_thesalama" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/twitter.svg" alt="_thesalama" height="30" width="40" /></a>
<a href="https://instagram.com/batsaam_" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/instagram.svg" alt="batsaam_" height="30" width="40" /></a>
</p>

<h3 align="left">Languages and Tools:</h3>
<p align="left"> <a href="https://www.arduino.cc/" target="_blank" rel="noreferrer"> <img src="https://cdn.worldvectorlogo.com/logos/arduino-1.svg" alt="arduino" width="40" height="40"/> </a> <a href="https://www.cprogramming.com/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/c/c-original.svg" alt="c" width="40" height="40"/> </a> <a href="https://www.docker.com/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/docker/docker-original-wordmark.svg" alt="docker" width="40" height="40"/> </a> <a href="https://git-scm.com/" target="_blank" rel="noreferrer"> <img src="https://www.vectorlogo.zone/logos/git-scm/git-scm-icon.svg" alt="git" width="40" height="40"/> </a> <a href="https://www.linux.org/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/linux/linux-original.svg" alt="linux" width="40" height="40"/> </a> <a href="https://www.mathworks.com/" target="_blank" rel="noreferrer"> <img src="https://upload.wikimedia.org/wikipedia/commons/2/21/Matlab_Logo.png" alt="matlab" width="40" height="40"/> </a> <a href="https://pandas.pydata.org/" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/2ae2a900d2f041da66e950e4d48052658d850630/icons/pandas/pandas-original.svg" alt="pandas" width="40" height="40"/> </a> <a href="https://www.python.org" target="_blank" rel="noreferrer"> <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/python/python-original.svg" alt="python" width="40" height="40"/> </a> <a href="https://pytorch.org/" target="_blank" rel="noreferrer"> <img src="https://www.vectorlogo.zone/logos/pytorch/pytorch-icon.svg" alt="pytorch" width="40" height="40"/> </a> <a href="https://scikit-learn.org/" target="_blank" rel="noreferrer"> <img src="https://upload.wikimedia.org/wikipedia/commons/0/05/Scikit_learn_logo_small.svg" alt="scikit_learn" width="40" height="40"/> </a> <a href="https://seaborn.pydata.org/" target="_blank" rel="noreferrer"> <img src="https://seaborn.pydata.org/_images/logo-mark-lightbg.svg" alt="seaborn" width="40" height="40"/> </a> <a href="https://www.tensorflow.org" target="_blank" rel="noreferrer"> <img src="https://www.vectorlogo.zone/logos/tensorflow/tensorflow-icon.svg" alt="tensorflow" width="40" height="40"/> </a> </p>

