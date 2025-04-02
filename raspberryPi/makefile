TARGET= helloRaspberry switch_led device_gpio interupt led_pwm tone_buzzer hard_tone_buzzer i2c_rgb_led i2c_rgb_led2 i2c_rgb_led_swtich i2c_servo
all: ${TARGET}
CFLAGS = -lwiringPi

% : %.c
	cc -o $@ $< ${CFLAGS}
clean :
	rm ${TARGET}


