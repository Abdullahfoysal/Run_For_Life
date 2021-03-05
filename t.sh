g++ -c main.cpp -I include
 g++ main.o -o app-run -L lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
./app-run
