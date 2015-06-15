# photobooth



## Setup

### Install Raspbian

1. Format SD card
  1. Open Disk Utility.
  2. Find the SD card in the left side of the window.
  3. Click the ERASE tab in the middle of the window.
  4. Next, click on the “Format” dropdown menu.
2. Write image (from Terminal)
  1. ```diskutil list```
  2. ```diskutil unmountDisk /dev/<disk# from diskutil>```
  3. ```sudo dd bs=1m if=image.img of=/dev/<disk# from diskutil>```

### Install openframeworks

1. Make sure the CPU has 192MB of RAM 
  1. ```sudo raspi-config```
  2. Select 1 Expand Filesystem
  3. Select 8 Advanced Options
  4. Select A3 Memory Split
  5. Type 64
  6. ```sudo reboot```
2. Update the system
  1. ```sudo apt-get clean```
  2. ```sudo apt-get update```
  3. ```sudo apt-get upgrade```
3. Donwload openframeworks
  1. ```curl -O <url to openframeworks tar>```
  2. ```mkdir openFrameworks```
  3. ```tar vxfz <path to tar> -C openFrameworks --strip-components 1```
4. Compile openframeworks
  1. ```cd openFrameworks```
  2. ```sudo scripts/linux/debian_armv6/install_dependencies.sh```
  3. ```make Release -C libs/openFrameworksCompiled/project```

### Compile project
1. ```cd <path to photobooth>```
2. ```make```
3. ```make run```





