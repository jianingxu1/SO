all: mem1_previo mem2_previo mem3_previo mem1 mem2 mem1_v2 mem1_v3 mem2_v2

mem1_previo: mem1_previo.c
	gcc -o mem1_previo mem1_previo.c

mem2_previo: mem2_previo.c
	gcc -o mem2_previo mem2_previo.c

mem3_previo: mem3_previo.c
	gcc -o mem3_previo mem3_previo.c

mem1: mem1.c
	gcc -o mem1 mem1.c

mem2: mem2.c
	gcc -o mem2 mem2.c

mem1_v2: mem1_v2.c
	gcc -o mem1_v2 mem1_v2.c

mem1_v3: mem1_v3.c
	gcc -o mem1_v3 mem1_v3.c

mem2_v2: mem3_v2.c
	gcc -o mem3_v2 mem3_v2.c

mem1_dynamic: mem1.c
	gcc -o mem1_dynamic mem1.c

mem1_static: mem1.c
	gcc -o mem1_static mem1.c -static

clean:
	rm -f *.o mem1_previo mem2_previo mem3_previo mem1 mem2 mem1_v2 mem1_v3 mem2_v2