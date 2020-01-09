# **FlightSimulator Project**

This project was created by Eden Moshe and Yakir Moshe as an assignment in Advance Programming course in Computer Science degree studying.

## Authors:
- **Eden Moshe**  
- **Yakir Moshe**
  
  ## Intrudoction:
  The goal of this project is to create a program that controls the Flight Simulator using a set of commands that will be interpreted     and sent to the simulator server.
  This project is a showcase to our programming experience. It contains: Client-Server communication programming, design pattern, data     streaming and parallel programming using Threads.
  
  ## Description:
   
  - Server-Client Communication:
    - The first command in the txt file is openDataServer. this command creates a server thread that runs in the background, receives         data from the simulator and reads it line by line from the simulator.
    In order to send data to the program, the simulator connects to the program as a client.
    The data received from the simulator containes current value of variables the simulator uses.
    These variables are defined in the "generic_small.xml" file. At the beginning of the run, the program stores the variables relevant     information from the file in a database (Unordered Map data structure) called "varsGenMap" that associates a variable name in the       simulator (sim) with a Var object in the program, when the simulator sends a new value it is updated in the data base.
  
    - The second command is connectControlClient- the program connects as a client to the simulator. this command creates a client             thread that runs in the background and sends data to the simulator. the data containes new values to be set to the simulator             variables.
  
  - The input to this program is a Text File (*.txt) with the set of commands to be sent to the airplane in the Simulator.
    the file is sent to the Lexer function that decomposes the code into a vector of strings.
    the program has a database (Unordered Map data structure) of all the commands that can be sent to the Simulator, associates a           command name with a specific command object.
  The Parser function receives the vector and execute each command according to the command object in the map.
  The program defines variables that will be used during the program (it does not have to be associated to any Simulator variable),       these variables are stored in another Unordered Map data structure called "varsFlyMap" that associates the variable's name with the     Var object that containes information about it.
  
  - the commands supportes the following commands: 
    - openDataServer - open data server
    - connectControlClient - connecting as a client
    - if condition
    - while loops
    - printing
    - sleep
    
    all of these commands are used in order to remote control the Flight Simulator program. 
    
  ## Run Instructions:
  * Download FlightGear Simulator - from the link below
  * In the main menu of FlightGear, access the settings and add the following settings in "Additional ‫‪‬‬ ‫‪Settings‬":
    * --generic=socket,out,10,127.0.0.1,5400,tcp,generic_small
    * --telnet=socket,in,10,127.0.0.1,5402,tcp --httpd=8080
  * Open the linux terminal and compile the program:
    * g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread
  * Put your input text file at the same folder with your .cpp files and run the program with the following command (in the linux           terminal): 
    * ./a.out file_name.txt
  * Press "Fly!" on FlightGear simulator.

  ## Files
  * main.cpp
  * main.h

  ##### Execute commands files:
  * Lexer.cpp
  * Lexer.h
  * Parser.cpp
  * Parser.h

  ##### Maps files:
  * VariableMap.cpp
  * VariableMap.h
  * CommandsMap.cpp
  * CommandsMap.h

  ##### Variables files:
  * Var.cpp
  * Var.h
  * Variable.cpp
  * Variable.h

  ##### Expression files:
  * Expression.h
  * BinaryOperator.cpp
  * BinaryOperator.h
  * UnaryOperator.cpp
  * UnaryOperator.h
  * Value.cpp
  * Value.h
  * Interpreter.cpp
  * Interpreter.h

  ##### Commands files:
  * Command.h
  * ConditionCommand.cpp
  * ConditionCommand.h
  * DefineVarCommand.cpp
  * DefineVarCommand.h
  * IfCommand.cpp
  * IfCommand.h
  * OpenClientCommand.cpp
  * OpenClientCommand.h
  * OpenServerCommand.cpp
  * OpenServerCommand.h
  * PrintCommand.cpp
  * PrintCommand.h
  * SleepCommand.cpp
  * SleepCommand.h
  * UpdateVarCommand.cpp
  * UpdateVarCommand.h
  * WhileCommand.cpp
  * WhileCommand.h

  ##### Threads files:
  * ThreadsManager.cpp
  * ThreadsManager.h

  ### Input Files
  * fly.txt

## Links
* Download FlightGear Simulator: https://www.flightgear.org/download/
* GitHub: https://github.com/Edenm210/FlightSimulator
