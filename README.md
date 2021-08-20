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

## How does the pattern lock works?

Really, the pattern lock is the SHA1 hash sequence of digits (0-8) with length from 3 (4 since Android 2.3.3) to 8.

Since Android does not allows the pattern to repeat "balls" and it does not use a salt when computing the SHA1 hash, it really takes a very short period of time to crack the hash and get the pattern.

The gesture board is a 3x3 matrix, and can be repressented as follows (each digit represents a "ball"):

    -------------------
    | 0 |  | 1 |  | 2 |
    -------------------
    | 3 |  | 4 |  | 5 |
    -------------------
    | 6 |  | 7 |  | 8 |
    -------------------

So if you set the pattern lock to 0 -> 1 -> 2 -> 5 -> 4, the SHA1 hash will be output of SHA1("\x00\x01\x02\x05\x04"), and that is the hash to be cracked by this tool.


## Where can I find the hash?

The hash is stored at "/data/system/gesture.key", and (From a rooted device) can be downloaded as follows:

    ~$ android-sdk-linux/platform-tools/adb pull /data/system/gesture.key
    0 KB/s (20 bytes in 0.071s)
    ~$ ls -l gesture.key
    -rw-r--r-- 1 sch3m4 sch3m4 20 ago 21 15:21 gesture.key
    ~$


## How does this tool works?

Let's see a basic output:

    ~$ python aplc.py
    
    [i] Taken from: http://forensics.spreitzenbarth.de/2012/02/28/cracking-the-pattern-lock-on-android/
    
    [+] Usage: aplc.py /path/to/gesture.key
    
    ~$ 

And now the output with a given gesture.key:

    ~$ python aplc.py gesture.sample.key 
    
    
    [i] Taken from: http://forensics.spreitzenbarth.de/2012/02/28/cracking-the-pattern-lock-on-android/
    
    [:D] The pattern has been FOUND!!! => 210345876
    
    [+] Gesture:
    
    -----  -----  -----
    | 3 |  | 2 |  | 1 |  
    -----  -----  -----
    -----  -----  -----
    | 4 |  | 5 |  | 6 |  
    -----  -----  -----
    -----  -----  -----
    | 9 |  | 8 |  | 7 |  
    -----  -----  -----
    
    It took: 0.8151 seconds
    ~$

(Too see module interface,head over to aplc folder)

## Research & Credits

The information above has been taken from http://forensics.spreitzenbarth.de/2012/02/28/cracking-the-pattern-lock-on-android/



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
