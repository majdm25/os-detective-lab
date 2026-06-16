CC=gcc

all:
	$(CC) src/manager.c -o manager
	$(CC) src/worker_cpu.c -o worker_cpu
	$(CC) src/worker_memory.c -o worker_memory
	$(CC) src/worker_io.c -o worker_io
	$(CC) src/zombie_demo.c -o zombie_demo

clean:
	rm -f manager
	rm -f worker_cpu
	rm -f worker_memory
	rm -f worker_io
	rm -f zombie_demo
	rm -f activity.log
