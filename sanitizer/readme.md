#Sanitizer
##

sanitizer标志
sanitizer已经被集成到gcc，在使用只需要设置相应的标志位即可：相应标志如下

地址错误： -fsanitize=address
内存错误： -fsanitize=memory
内存泄漏： -fsanitize=leak
线程竞速问题： -fsanitize=thread
未定义问题： -fsanitize=undefined
为方便回溯可同时添加保留函数指针标志：-fno-omit-frame-pointer

gcc/g++使用sanitizer
gcc/g++编译只需要将sanitizer的标志作为flag设置即可，如下：

gcc/g++ -fsanitize=address -g -fno-omit-frame-pointer test.cpp
1
CMakeLists使用sanitizer
使用CMAKE_CXX_FLAGS或add_compile_options的配置即可使用，如下：

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
1
或

add_compile_options(-fsanitize=address -fsanitize=memory -fno-omit-frame-pointer)
link_libraries(-fsanitize=address -fsanitize=memory)

https://blog.csdn.net/qq_37868450/article/details/118766735