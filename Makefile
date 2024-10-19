

# Define the object file to be built
obj-m := main.o

# Default rule to build the module
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

# Rule to insert the module
load:
	sudo insmod main.ko

# Rule to remove the module
unload:
	sudo rmmod main

# Clean up the generated files
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
