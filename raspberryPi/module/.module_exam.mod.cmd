savedcmd_/home/hs/kuBig2025/raspberryPi/module/module_exam.mod := printf '%s\n'   module_exam.o | awk '!x[$$0]++ { print("/home/hs/kuBig2025/raspberryPi/module/"$$0) }' > /home/hs/kuBig2025/raspberryPi/module/module_exam.mod
