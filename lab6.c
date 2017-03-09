  #include<stdio.h> 
  #include<unistd.h> 
  #include<stdlib.h> 
  
  int main() 
  { 
     pid_t pid; 
     int tmp = 10; 
 
     printf ( "The main program process ID is %d\n\n", getpid() ); 
     printf ( "Calling fork now\n\n" ); 
     // The return value to the parent process will be the Process ID (PID) of the child 
     // The child gets a return value of 0 
   
     pid = fork(); 
     printf ( "fork has been called, pid returned is %d\n", pid ); 
 
     
     if ( pid == 0  ) //child
     { 
        printf ( "CHILD: I am child my pid is: %d\n\n", getpid() ); 
		printf ( "CHILD: fork value returned is %d\n", pid ); 
        printf ( "CHILD: the value of tmp is: %d\n", tmp );
        tmp += 1;
        printf ( "CHILD: the value of tmp is now: %d\n", tmp );
        printf ( "CHILD: my parent value is: %d\n", getppid() ); 
     } 
     else if ( pid > 0) //parent
     { 
        printf ( "PARENT: I am parent my pid is: %d\n\n", getpid() ); 
		printf ( "PARENT: fork value returned is %d\n", pid ); 
        printf ( "PARENT: the value of tmp is: %d\n", tmp );
        printf ( "PARENT: my ppid value is: %d\n", getppid() );
     } 
     else 
        printf ( "Fork failed, no child\n" ); 
  return 0; 
  }
