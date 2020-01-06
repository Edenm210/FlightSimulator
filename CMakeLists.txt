cmake_minimum_required(VERSION 3.15)
project(project3)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)

include_directories(.)

add_executable(project3
        lexer.cpp
        lexer.h
        main.cpp
        OpenServerCommand.h
        OpenServerCommand.cpp
        IfCommand.h
        IfCommand.cpp
        CommandsMap.h
        CommandsMap.cpp
        Command.h
        UnaryOperator.h
        UnaryOperator.cpp
        BinaryOperator.h
        BinaryOperator.cpp
        Expression.h
        WhileCommand.h
        WhileCommand.cpp
        Variable.h
        Variable.cpp
        Interpreter.h
        Interpreter.cpp
        Expression.h
        Var.h
        Var.cpp
        Value.h
        Value.cpp
        VariableMap.h
        VariableMap.cpp
        Parser.h
        Parser.cpp
        PrintCommand.h
        PrintCommand.cpp
        SleepCommand.h
        SleepCommand.cpp
        threadsManager.h
        threadsManager.cpp
        ConditionCommand.h
        ConditionCommand.cpp
        DefineVarCommand.h
        DefineVarCommand.cpp
        OpenClientCommand.h
        OpenClientCommand.cpp)
