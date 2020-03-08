[官方教程](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
[reference](https://mp.weixin.qq.com/s?__biz=MzI5MTM1MTQwMw==&mid=2247511665&idx=1&sn=49950fd6eb911c7f82eda36670a54fa2&chksm=ec131075db6499638b39f858934e52c66f25b4847d8106c60ace6487382405991cb6297c15b1&scene=27#wechat_redirect)
一般来说，用CMakeLists来链接第三方库通常都离不开三个命令：
```cmake
# 参数QUIET表示紧调包没有被发现时的警告信息，REQUIRED表示若包没有找到则cmake过程停止
find_package(第三方包名 需要的最低版本号 REQUIRED/QUIET)
# 寻找包的头文件
include_directories(${包_INCLUDE_DIRS})
# 链接包的第三方库（这里是${包_LIBS}还是${包_LIBRARIES}需要依据具体的包来看）
target_link_libraries(${包_LIBS}或${包_LIBRARIES})
```
例
```cmake
# 明确find_package的寻找路径
set(OpenCV_DIR /usr/local/opencv2.4.14/share/OpenCV)
find_package(OpenCV 2.4 REQUIRED)
# 告诉系统头文件在哪里
include_directories(SYSTEM ${OpenCV_INCLUDE_DIRS} /usr/local/opencv2.4.13/include)
# 告诉第三方库文件在哪里
link_directories(${OpenCV_LIBRARY_DIRS} /usr/local/opencv2.4.13/lib)
# 将库文件与项目链接上
target_link_libraries(${项目名} ${OpenCV_LIBRARY_DIRS})
```
