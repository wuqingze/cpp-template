#### 用Makefile构建c++经典项目结构的步骤

- [x] 头文件 源文件 main引用 跑起来
- [x] 头文件 源文件 Google test跑起来
- [x] Google Test 指定 适配 参数
- [x] 多层目录结构头文件 源文件 跑起来
- [x] 多层目录结构头文件 源文件 Google test跑起来
- [ ] 引入第三方库 跑起来

#### 项目结构

Makefile定义了一些语法，用来自动化编译整个项目。其实编译c++工程原理上来说并不复杂，
- 定义头文件的位置，参数`-I`,这样g++知道在哪里寻找头文件
- `-l`选项，提供第三方库
- g++一次只会编译一个源文件，期间和任何其他文件没有关系。
- 最后是将`.o`文件链接在一起形成二进制文件

本质上来说，Makefile的原理就是将g++编译链接的过程通过固定的语法进行自动化处理了，而不需要一遍一遍的编写g++命令。具体的Makefile语法和语义在后面详细介绍。

build目录是g++编译源文件产生的目标文件`.o`文件存放的目录。`.o`文件是编译单个文件生成的中间机器码文件，`.o`文件是多平台兼容的机器码。build内的目录严格与include中的目录相等。但是它额外拥有一个test目录用来存放编译的Google Test`.o`文件。

src目录严格与include目录相等，存放相对于头文件一一对应的源文件。

test目录存放Google Test测试文件。Google Test测试文件只需要一个main函数，其余文件只需要标记测试标识，据可以根据 --gtest_filter参数测试模块。

```
.
├── Makefile
├── README.md
├── bin
├── build
│   ├── test
│   └── utility
├── css-for-font.js
├── gtest
├── include
│   ├── SingleInstance.h
│   ├── foo.h
│   └── utility
│       └── CalculateUtility.h
├── index.html
├── md2html.sh
├── src
│   ├── SingleInstance.cpp
│   ├── foo.cpp
│   ├── main.cpp
│   └── utility
│       └── CalculateUtility.cpp
├── test
│   ├── demo-test.cpp
│   ├── test00.cpp
│   └── utility-test.cpp
```

#### g++和gcc的区别

~直观上，gcc不能编译c++文件，gcc如果要编译cpp文件，需要`gcc -lstdc++`的选项。虽然表面上只不过是gcc多了一个-lstdc++选项，但是内部机制还是有很大的不同~。通过实验，gcc还是老实编译c文件比较好。


#### Makefile文本内容
```
# 项目名称
TARGET = demo00 

# 编译器设置
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -pedantic
GoogleTest = -lgtest -lgtest_main -pthread

# 头文件和库文件的路径
INCLUDE_DIRS = -I./include -I./include/utility -I./include/third_party_library
LIB_DIRS = -L./lib

# 需要链接的库文件
LIBS = 

# 源文件和对象文件
SRC_FILES := $(shell find src -type f -name '*.cpp')
OBJ_FILES := $(patsubst src/%.cpp, ./build/%.o, $(SRC_FILES))
#SRC_FILES := $(wildcard ./src/*.cpp)
#OBJ_FILES := $(patsubst ./src/%.cpp, ./build/%.o, $(SRC_FILES))

# 测试文件和测试目标
#TEST_SRC_FILES := $(wildcard ./test/*.cpp)
TEST_SRC_FILES := $(shell find test -type f -name '*.cpp')
TEST_OBJ_FILES := $(patsubst test/%.cpp, ./build/test/%.o, $(TEST_SRC_FILES))

# 测试可执行文件名
TEST_TARGET = gtest 

# 编译测试代码
#test: $(TEST_TARGET)

# 默认的目标，编译可执行文件
all: $(TARGET)
hello: $(TEST_TARGET)

# Google Test所依赖的项目的.o文件，需排除mian.o
OBJ_FILES_WITHOUT_MAIN = $(filter-out ./build/main.o, $(OBJ_FILES))

# 编译每个源文件
#./build/%.o: ./src/%.cpp
./build/%.o: ./src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) -c -o $@ $<

# 链接目标文件
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $(LIB_DIRS) -o $@ $^ $(LIBS)

# 编译测试文件
./build/test/%.o: ./test/%.cpp 
	$(CXX) $(CXXFLAGS) $(INCLUDE_DIRS) $(LIB_DIRS) -c -o $@ $<

# 链接测试目标
$(TEST_TARGET): $(TEST_OBJ_FILES) $(OBJ_FILES_WITHOUT_MAIN)
	$(CXX) $(CXXFLAGS)  $(INCLUDE_DIRS) $(LIB_DIRS) -o $@ $^ $(LIBS) $(GoogleTest)

# 清除编译生成的文件
clean:
	rm -f $(TARGET) $(TEST_TARGETS) 
	find ./build -name "*.o" -type f -delete
.PHONY: hello 
```

#### 头文件中的宏、c++中的静态变量
每个头文件都需要定义宏，是为了在编译的时候不重复引入相同的头文件。**静态变量**需要初始化，否则编译器无法为静态变量分配内存空间。
