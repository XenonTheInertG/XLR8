@echo off
fastboot devices
pause
fastboot erase recovery
fastboot flash recovery recovery.img
fastboot oem reboot-recovery
pause

#Copyright© XenonTheInertG
