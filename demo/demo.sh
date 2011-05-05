sudo insmod ~/linux-2.6/fs/tagfs/tagfs.ko
sudo mkfs -t ext2 /dev/sdb1
sudo mount -t tagfs -o user_xattr /dev/sdb1 /media/tagfs
sudo chown tashields:tashields /media/tagfs

mkdir /media/tagfs/demo
cp dragon.txt /media/tagfs/demo/dragon.txt
cp panda.txt /media/tagfs/demo/panda.txt
cp ice_cream.txt /media/tagfs/demo/ice_cream.txt
cp wolf.txt /media/tagfs/demo/wolf.txt
cp bow.txt /media/tagfs/demo/bow.txt

addtag /media/tagfs/demo/dragon.txt animal fire dragon
addtag /media/tagfs/demo/panda.txt animal bear
addtag /media/tagfs/demo/ice_cream.txt icecream food cold
addtag /media/tagfs/demo/wolf.txt animal wolf
addtag /media/tagfs/demo/bow.txt bow weapon dragon

------------------------------------------------
distag

chtag dragon
lstag

tagcat icecream

distag /media/tagfs/demo/bow.txt

rmtag /media/tagfs/demo/bow.txt dragon

lstag


