# Define the object file to be built
obj-m := main.o

# Default rule to build the module
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

# Clean up the generated files
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
