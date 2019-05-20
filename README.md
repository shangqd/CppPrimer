
git config --local user.name "lihp"
git config --local user.email "peacechzh@126.com"

mkdir build
cd build
cmake .. -DCMAKE_BUILD_TYPE=Debug

make
