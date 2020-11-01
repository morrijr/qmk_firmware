# Getting ready
rm -rf qmk_firmware/
sudo apt install git python3 python3-pip
python3 -m pip install --user qmk
qmk setup morrijr/qmk_firmware
cd qmk_firmware/
git remote -v
git checkout -b claw
git status
git checkout master
git pull
git checkout claw
git rebase master
git status

rm -rf keyboards/claw/v1
mkdir -p keyboards/claw/v1
cp -Rv keyboards/handwired/onekey/* keyboards/claw/v1/
# delete a load of stuff.

make handwired/bluepill/bluepill70:default
make handwired/onekey/blackpill_f411:default

make claw/v1/f411:default
qmk compile -kb <keyboard> -km default
qmk compile -kb claw/v1 -km default
qmk compile -kb claw/v1/f411 -km default

rm .build/*.bin ; qmk compile -kb claw/v1/f411 -km default && cp .build/claw_*.bin /mnt/c/Users/john/Downloads/

** TODO: fully define cpu pins for full matrix
** TODO: add joystick button. ? To matrix?

F411

3v3     3v3
G       GND
5v      5v
B9      
B8      
B7      
B6      
B5      Not 5v tolerant
B4      
B3      
A15     
A12     USB?
A11     USB?
A10     USB?
A9      DON'T USE; USB?
A8      USB?
B15     GOOD column 0 r,f,v
B14     GOOD column 1 e,d,c
B13     GOOD column 2 w,s,x
B12     GOOD column 3 q,a,z

VBAT    Battery
C13     GOOD row 0 q,w,e,r
C14     GOOD row 1 a,s,d,f
C15     GOOD row 2 z,x,c,v
R       Reset
A0      Not 5v tolerant
A1      
A2      
A3      
A4      
A5      
A6      
A7      
B0      Joystick X?
B1      Joystick Y?
B2      DON'T USE; BOOT
B10     Joystick Button
3v3     3v3
G       GND
5v      5v

Promicro

