TARGET= helloRaspberry switch_led device_gpio interupt
all: ${TARGET}
CFLAGS = -lwiringPi

% : %.c
	cc -o $@ $< ${CFLAGS}
clean :
	rm ${TARGET}

