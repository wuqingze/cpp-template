# 项目名称
TARGET = demo00 

# 编译器设置
CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -pedantic
GoogleTest = -lgtest -lgtest_main -pthread

# 头文件和库文件的路径
INCLUDE_DIRS = -I./include -I./include/project_name -I./include/third_party_library
LIB_DIRS = -L./lib

# 需要链接的库文件
LIBS = 

# 源文件和对象文件
SRC_FILES := $(wildcard ./src/*.cpp)
OBJ_FILES := $(patsubst ./src/%.cpp, ./build/%.o, $(SRC_FILES))

# 测试文件和测试目标
TEST_SRC_FILES := $(wildcard ./test/*.cpp)
TEST_OBJ_FILES := $(patsubst ./test/%.cpp, ./build/test/%.o, $(TEST_SRC_FILES))

# 测试可执行文件名
TEST_TARGET = gtest 

# 编译测试代码
#test: $(TEST_TARGET)

# 默认的目标，编译可执行文件
all: $(TARGET)
hello: $(TEST_TARGET)

OBJ_FILES_WITHOUT_MAIN = $(filter-out ./build/main.o, $(OBJ_FILES))

# 编译每个源文件
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
	rm -f $(TARGET) $(TEST_TARGETS) ./build/*.o ./build/test/*.o
.PHONY: hello 
