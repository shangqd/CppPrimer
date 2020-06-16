
git config --local user.name "lihp"  
git config --local user.email "peacechzh@126.com"  

mkdir build  
cd build  
cmake .. -DCMAKE_BUILD_TYPE=Debug  
make -j4  

## 设置core文件可以不限制的生成
ulimit -c unlimited

## 查看
ulimit -c

## 生成core文件 
gcore pid 

## gdb 调试  

## 内存调试工具
valgrind  
