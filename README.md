![PicsArt_03-26-10 30 20](https://user-images.githubusercontent.com/80537042/112663494-1939a400-8e83-11eb-9f48-343069d3306b.jpg)
# XLR8-An Android utility tools works in Fastboot
(Not released yet,Under development)

•Factory Reset Protection (FRP), is a security feature on Android devices with Android OS Version 5.1 (Lollipop) and higher. The FRP provides a built-in security feature you are able to use that protects your device and information, including screen locks and data encryptions.


• Fast boot app for android reboots the shell instead of completely reloading bootloader and OS and is faster. ... On other android phones, you can use fast boot as an alternative, which will help you eliminate minor lags and free up RAM in critical times 


• Fastboot is a tool/protocol for writing data directly to your phone's flash memory. In practical use, it is used to flash images such as recoveries, bootloaders, and kernels to your Android device. Outside of the obvious, you can also restore nandroid backups, change your splash screen, and flash system updates.
# Why XLR8?
The most important reason to use XLR8  is because of its simplicity to use and features it offers. It can eliminate fingerprints from your android phone and wipes off all types of existing locks from your android phone and tablet.

The common problem faced by most android users these days is Factory Reset Protection lock a.k.a the FRP lock. Android Fastboot tool helps in deleting Google account from your phone, thus bypassing the FRP lock.

Similarly, Mi/Redmi phone users face Mi Account lock, and this tool can also remove Mi Account lock from your Xiaomi phone or tablet.
Other features like unlock the bootloader, Boot into EDL Mode, and Samsung Download Mode makes this more useful and necessary.

# XLR8(Fastboot tool for android:3)

•Mediatek(All bit & also dimensity)

•Snapdragon(Also supports SD 888)

•Kirin(soon,i Couldn't break the huawei's frp system)

•Exynos

•Spreadtrum(UniSOC)

 -------------------------------------------
# XLR8 Features
•Remove Pattern,password,pin.

•Remove Mi Account

•Enter EDL Mode – Emergency Download Mode

•Unlock Bootloader

•Unlock Yureka Bootloader

•Boot into Samsung Download Mode

•Remove Spd FRP (Spreadtrum FRP Remove)
(Also UniSOC)

•Remove Qualcomm FRP (Snapdragon FRP Remove)

•Remove Xiaomi FRP

•Remove Lenovo FRP

•Remove Motorola FRP(Idk if ppl use moto but it's a gem)

•Remove Yuphoria FRP

•Remove HTC FRP

•Micromax FRP ADB Mode

Note: Some of these code are cloned from google git
# Standaloe ADB Build by Karfield:
===
adb is a useful tool for debugging android devices, you can download the
binary from google/android.com(mostly), but it only supports small amount
devices. To support some specific android device, you need to add the VID,
add udev rule, etc.
If you want to support your devices natively of adb, you should change the
usb_vendors.c code, then build the whole android source to get the adb tool.
It cause too much to gain the benity.

This project is to build the adb source standalone out of the Android build
script system. I merged the main adb source with some essential libraries
(libcutils and libzipfile), and add Makefile for it.

* This project has supported fastboot (from 0.1.0).

===
INSTRUCTIONS:

1. After get the source, you can change the usb_vendor_ids.c to add your VID.
    use debian/gen_udev_rules.sh to generate udev rule for those VID.

2. make
    build the adb and fastboot

3. make install
    install the adb and fastboot into /usr/bin/ configure the udev

4. copy 51-android.rules to /etc/udev/rules.d/

===
TO BUILD .DEB PACKAGE

1. Check dpkg tools (dpkg-dev, dh-make, debhelper, fakeroot, etc.)

2. run `dpkg-buildpackage -rfakeroot -b` to generate .deb package
    (To install the package, you could use `sudo dpkg -i ../adb_x.x.x-1.xxx.deb`)

===
OR DOWNLOAD the prebuilt package

https://github.com/downloads/karfield/adb/adb_0.1.0-1_amd64.deb

install the deb by graphic installer or command(`sudo dpkg -i xxx.deb`)

For Mac
===

Howto compile?
git clone this repo. run
 ./autogen.sh
 make install

to support homebrew use
 1. brew create https://github.com/downloads/karfield/adb/adb-mac-1.0.1.tgz

Give a name: Adb4Mac

 2. brew edit Adb4Mac

Modify like this:
    require 'formula'

    class Adb4Mac < Formula
        homepage 'https://git.hub/karfield/adb/'
        url 'https://github.com/downloads/karfield/adb/adb-1.0.1.tgz'
        md5 '308a5476fc096a8a525d07279a6f6aa3' ## dont mod this line, it's auto-gen
        
        def install
           system "./autogen.sh"
           system "./configure", "--prefix=#{prefix}"
           system 'make install'
        end
    end

 3. brew install Adb4Mac

if you don't compile this on your mac, just download the excutable bin files,
   copy them (adb and fastboot) into wherever you wannt.
   OR run install-adb-for-mac.sh(download https://github.com/downloads/karfield/adb/install-adb-for-mac.tar.gz)

Enjoy it!

Check out his for further explanation: [https://github.com/karfield/adb]

>I'm busy with my study rn,it'll be late,maybe too late to release. 
Have a nice day,peace;)
Support me by forking,starring my repository.
GG
