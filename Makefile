COMP = g++
CFLAGS = -D _DEBUG -ggdb3 -g -std=c++17 -O0 -Wall -Wextra -Weffc++ -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat=2 -Winline -Wnon-virtual-dtor -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=2 -Wsuggest-override -Wswitch-default -Wswitch-enum -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -fno-omit-frame-pointer -Wlarger-than=8192 -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,nonnull-attribute,null,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr 
SOURCES = $(wildcard *.cpp)
CRFLAGS = -std=c++17 -DNDEBUG  -O3 

TARGET = solver

debug: $(SOURCES)
	@$(COMP) $(CFLAGS) $(SOURCES) -o $(TARGET)

release: $(SOURCES)
	@$(COMP) $(CRFLAGS) $(SOURCES) -o $(TARGET)

%.o: %.cpp
	@$(COMP) $(CFLAGS) -c $< -o $@

%.out: %.cpp
	@$(COMP) $< -o $@

clean: 
	rm *.o *.out $(TARGET)