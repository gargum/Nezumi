# Build Instructions

This is a folder full of one can use QMK to install onto one's Nezumi.

To do this, first use Git to download QMK, specifically the master repo.

After QMK has been installed onto one's machine, simply copy the nezumi folder
into the ~/qmk_firmware/keyboards directory, before entering the command . . .

qmk flash -kb nezumi -km default

This command should allow you to flash the appropriate firmware 
onto the RP2040-based microcontroller.
