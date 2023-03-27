<h1 align="center">
	minitalk
</h1>

## About 

This project is about data exchange between programs using UNIX signals. It consists of having one progam <b>server</b> recieving a string from <b>client</b>.

## Implementation

It consists of two output files <b>server</b> and <b>client</b>. Server is started first and outputs its PID. Client is started after with <b>server</b> PID 
as an argument and a string. 

To do this we convert every char of the string passed as an arg to binary. We use SIGUSR2 and SIGUSR1
as '1' and '0' and send information to <b>server</b> in blocks of 8 bytes(one char). Once <b>server</b>  receives 8 signals in sequence, it then 
converts the sequence from binary
into a char and writes them. Once the string passed as arg has been sent, the client then sends 8 bytes in '0' that represent the string NULL byte.

The <b>server</b> and <b>client</b> are comunicating using <b>signal</b> and <b>kill</b>.

## Bonus

For the bonus part <b>server</b> must confirm that it has received a signal from <b>client</b> and send a confirmation signal back to it.

To do this i make use of <a href="https://man7.org/linux/man-pages/man2/sigaction.2.html">sigaction</a> in <b>server</b> which allows me to get the pid 
of the program that sent the signal to it. Once the NULL byte has been recieved in <b>server</b> a signal is then sent back to <b>client</b>, it then outputs
confirmation that received the signal.
