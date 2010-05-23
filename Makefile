CC = clang

TARGET = bf
SRCS = $(wildcard src/*.c)
OBJS = $(subst src,build,$(SRCS:%.c=%.o))

all: $(TARGET)

build:
	@mkdir -p $@

build/%.o: src/%.c build
	$(CC) -c -o $@ $<

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -rf build *~ $(TARGET)
