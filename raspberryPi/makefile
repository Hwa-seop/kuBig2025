TARGET= helloRaspberry switch_led device_gpio interupt led_pwm tone_buzzer hard_tone_buzzer I2c_rgb_led
all: ${TARGET}
CFLAGS = -lwiringPi

% : %.c
	cc -o $@ $< ${CFLAGS}
clean :
	rm ${TARGET}

