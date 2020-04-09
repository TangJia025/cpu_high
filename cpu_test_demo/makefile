CC = gcc
CXX = g++

MYFLAGS = -DTEST_DEBUG=0 -DZZCFG_DEBUG=0 -MMD -Wall -g

INC += -I.
LIB = -L./lib 
SRC_DIR = ./
OBJ_DIR = ./obj/

TARGET = cpu_perf_test cpu_bind_test cpu_cache_test 

#$(OBJ_DIR)CAgentRuleCacheManager.o \

OBJS = \
		$(OBJ_DIR)cpu_perf_test.o \
		$(OBJ_DIR)CAgentRuleV1.o \
		$(OBJ_DIR)CHttpPare.o\
		$(OBJ_DIR)CommUtil.o\

CPU_BIND_OBJS = \
				$(OBJ_DIR)cpu_bind_test.o\

CPU_CACHE_OBJS = \
				$(OBJ_DIR)cpu_cache_test.o\


OBJ_SUB_DIRS = $(sort $(dir  $(OBJS) $(CPU_BIND_OBJS) $(CPU_CACHE_OBJS)))

DEPENDS = $(patsubst %.o, %.d, $(OBJS) $(CPU_BIND_OBJS) $(CPU_CACHE_OBJS))

.PHONY: all clean init

all:init $(TARGET)
#	@echo -e "\033[1;32m\nSuccess!\033[0m"
#	ldd -r $(WORKER_TARGET) $(PROXY_TARGET) $(CHECK_TARGET)


#test1: $(OBJS)
#	@echo -e "\033[1;33m\nLinking $< ==> $@\033[0m"
#	$(CXX) $(MYFLAGS) $^ -o $@ $(LIB)

cpu_perf_test: $(OBJS)
	@echo -e "\033[1;33m\nLinking $< ==> $@\033[0m"
	$(CXX) $(MYFLAGS) $^ -o $@ $(LIB)

cpu_bind_test: $(CPU_BIND_OBJS)
	@echo -e "\033[1;33m\nLinking $< ==> $@\033[0m"
	$(CXX) $(MYFLAGS) $^ -o $@ $(LIB)

cpu_cache_test: $(CPU_CACHE_OBJS)
	@echo -e "\033[1;33m\nLinking $< ==> $@\033[0m"
	$(CXX) $(MYFLAGS) $^ -o $@ $(LIB)



$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@echo -e "\033[1;33m\nCompiling $< ==> $@\033[0m"
	$(CXX) $(MYFLAGS) -c -o $@ $(INC) $< 

clean:
	rm -f $(OBJS) $(DEPENDS) $(TARGET)

init:
	mkdir -p $(sort ./ $(TAR_DIR) $(SRC_DIR) $(OBJ_DIR) $(OBJ_SUB_DIRS))

-include $(DEPENDS)
