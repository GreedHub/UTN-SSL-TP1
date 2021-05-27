all : TP1.c
	mkdir -p ./Debug ./Dist
	gcc  -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"./Debug/TP1.d" -MT"./TP1.o" -o "./Debug/TP1.o" "./TP1.c"
	gcc  -o "./Dist/TP1" ./Debug/TP1.o

clean :
	rm -rf ./Dist/TP1 ./Debug/*