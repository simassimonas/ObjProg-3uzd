main: functions.o
  g++ -o run main.cpp functions.o
fun: 
  g++ -c functions.cpp
clean: 
  rm *.o run
