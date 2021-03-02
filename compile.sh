mkdir build -p
cd build
cmake ..
make
[ -f ../out ] && rm ../out/*
mkdir ../out -p
cp ./*.elf ../out
cp ./*.uf2 ../out
cp ./*.bin ../out