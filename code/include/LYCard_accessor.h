



/*
本来以下变量为全局变量，但是把它们设计成只能通过访问器子程序访问，而外部不可以直接访问变量，设计方法如下：（该文件类似与面向对象语言的一个类）
*/
void set_icdev(int dev);
int get_icdev();

void set_errorCode(int eCode);
int get_errorCode();

const char* get_errorInfo();

const char* get_n_lysid();
