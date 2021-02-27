# mount point	fstype    device    	[device2]

/boot			emmc	/dev/block/platform/mtk-msdc.0/by-name/boot		flags=display="Boot";backup=1
/logo			emmc	/dev/block/platform/mtk-msdc.0/by-name/logo		flags=display="Logo";backup=1;flashimg=1
/recovery		emmc	/dev/block/platform/mtk-msdc.0/by-name/recovery	flags=display="Recovery";backup=1
/nvram			emmc	/dev/block/platform/mtk-msdc.0/by-name/nvram	flags=display="Nvram";backup=1;flashimg=1
/secro			emmc	/dev/block/platform/mtk-msdc.0/by-name/secro	flags=backup=1;subpartitionof=/nvram
/expdb			emmc	/dev/block/platform/mtk-msdc.0/by-name/expdb	flags=display="expdb";backup=1;flashimg=1
/lk				emmc	/dev/block/platform/mtk-msdc.0/by-name/lk		flags=display="Uboot";backup=1;flashimg=1
/para			emmc	/dev/block/platform/mtk-msdc.0/by-name/para		flags=display="Parametr";backup=1
/tee1			emmc	/dev/block/platform/mtk-msdc.0/by-name/tee1		flags=display="Tee";backup=1;flashimg=1
/tee2			emmc	/dev/block/platform/mtk-msdc.0/by-name/tee1		flags=subpartitionof=/tee1;backup=1
/persistent		emmc	/dev/block/platform/mtk-msdc.0/by-name/frp		flags=display="persistent";backup=1
/metadata		emmc	/dev/block/platform/mtk-msdc.0/by-name/metadata	flags=display="metadata";backup=1;flashimg=1
/proinfo		emmc	/dev/block/platform/mtk-msdc.0/by-name/proinfo	flags=display="Proinfo";backup=1;flashimg=1
/protect_f		ext4	/dev/block/platform/mtk-msdc.0/by-name/protect1	flags=backup=1;subpartitionof=/proinfo
/protect_s		ext4	/dev/block/platform/mtk-msdc.0/by-name/protect2	flags=backup=1;subpartitionof=/proinfo
/nvdata			ext4	/dev/block/platform/mtk-msdc.0/by-name/nvdata	flags=display="NvData";backup=1;flashimg=1
/system_image	emmc	/dev/block/platform/mtk-msdc.0/by-name/system
/system			ext4	/dev/block/platform/mtk-msdc.0/by-name/system
/cache			ext4	/dev/block/platform/mtk-msdc.0/by-name/cache
/data			ext4	/dev/block/platform/mtk-msdc.0/by-name/userdata	length=-16384,encryptable=/dev/block/platform/mtk-msdc.0/by-name/metadata

# vold
/external_sd		auto		/dev/block/mmcblk1p1	/dev/block/mmcblk1    flags=display="External SD-card";storage;wipeingui;removable;backup=0
/usbotg			auto    /dev/block/sda1	 /dev/block/sda			flags=display="USB-OTG";storage;wipeingui;removable;backup=0


