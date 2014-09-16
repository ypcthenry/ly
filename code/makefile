cflags=-g

obj=obj/LYCard_util.o obj/LYCard_accessor.o obj/LYCard.o
#obj=obj/LYCard_util.o
bin=bin/atest bin/sotest
#lylibso=lib/libutil.so lib/libLYCard.so
#lylibarch=lib/libutil.a lib/libLYCard.a
lylibso=lib/libLYCard.so
lylibarch=lib/libLYCard.a

atest=bin/atest
sotest=bin/sotest

output_file=include/LYCard_type.h include/LYCard_accessor.h include/LYCard.h include/mwic.h lib/libLYCard.so lib/libLYCard.a lib/libmwic.so lib/libmwic.a

test_file=include/util_test.c include/lycard_test.c

image : $(obj) $(lylibso) $(lylibarch) $(bin)
	export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH
	echo -e "如果找不到动态连接库，请先执行>:\n export LD_LIBRARY_PATH=./lib:\$$LD_LIBRARY_PATH"

atest : bin/atest

sotest : bin/sotest



output :
	cp -v lib/lib* ~/lib/
	cp -v include/*.h ~/incl/ 
test : 
	cp $(test_file) ../ly/

clear : 
	rm -rf $(obj) $(bin) $(lylibso) $(lylibarch)

libso : $(lylibso)
libarch: $(atest)

obj/LYCard_util.o : include/LYCard_util.c 
	gcc -c - $(cflags) -o $@ $<

obj/LYCard.o : include/LYCard.c
	gcc -c  $(cflags) -o $@ $<

obj/LYCard_accessor.o : include/LYCard_accessor.c
	gcc -c  $(cflags) -o $@ $<

#lib/libutil.a : obj/LYCard_util.o
#	ar rcs -o $@ $<

lib/libLYCard.a : obj/LYCard_util.o obj/LYCard_accessor.o obj/LYCard.o lib/mwic.o
	#ar rcs $@ obj/LYCard_util.o obj/LYCard_accessor.o obj/LYCard.o
	ar rcs $@ obj/LYCard_util.o obj/LYCard_accessor.o lib/mwic.o obj/LYCard.o #correct 
	#ar rcs $@ obj/LYCard_util.o obj/LYCard_accessor.o obj/LYCard.o lib/mwic.a #error
	#ar rcs lib/libLYCard.a obj/LYCard_util.o obj/LYCard_accessor.o lib/libmwic.a  obj/LYCard.o #error

#lib/util.so : obj/LYCard_util.o
#	gcc -shared -o $@ $<
#	fpic add
lib/libLYCard.so : obj/LYCard_util.o obj/LYCard_accessor.o obj/LYCard.o
	gcc -shared  -o  $@ obj/LYCard_util.o obj/LYCard_accessor.o obj/LYCard.o

bin/sotest : include/lycard_test.c
#gcc -I./include -L./lib -lLYCard -o $@ $< #有时会报错
	gcc  -o   $@ $< -I./include -L./lib -lLYCard -lmwic #注意文件的先后顺序，被调用文件在调用文件后面

bin/atest : include/lycard_test.c
	#gcc $< lib/libmwic.a lib/libLYCard.a -o $@
	gcc $(cflags) $< lib/libLYCard.a -o $@	


