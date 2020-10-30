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
