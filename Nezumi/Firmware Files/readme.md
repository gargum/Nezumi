# Build Instructions

This is a folder one can use QMK to install.

To do that, first use Git to download QMK, specifically the master repo.

After QMK has been installed onto one's machine, simply copy the nezumi folder
into the ~/qmk_firmware/keyboards directory, before typing . . .

qmk flash -kb nezumi -km default

This command should allow you to flash the appropriate firmware 
onto the RP2040-based microcontroller.
