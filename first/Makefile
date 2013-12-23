all: first

first: main.obj task1.obj task2.obj task3.obj task4.obj task5.obj task6.obj
	g++ main.obj task1.obj task2.obj task3.obj task4.obj task5.obj task6.obj -o first.exe

main.obj: main.cpp
	g++ -c main.cpp -o main.obj

task1.obj: task1.cpp
	g++ -c task1.cpp -o task1.obj

task2.obj: task2.cpp
	g++ -c task2.cpp -o task2.obj
    
task3.obj: task3.cpp
	g++ -c task3.cpp -o task3.obj
  
task4.obj: task4.cpp
	g++ -c task4.cpp -o task4.obj
    
task5.obj: task5.cpp
	g++ -c task5.cpp -o task5.obj
    
task6.obj: task6.cpp
	g++ -c task6.cpp -o task6.obj

clean:
	rm -rf *.obj first.exe
