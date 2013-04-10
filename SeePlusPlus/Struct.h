#ifndef TEST_STRUCT
#define TEST_STRUCT
#include <string>

struct TestStruct {
	int memberInt;
	void set(int);
	void show();
};

struct Lib {
	std::string a;
	std::string b;
	std::string c;
};

class Libc {
private:
	std::string a;
	std::string b;
	std::string c;
public:
	void seta(std::string);
	void setb(std::string);
	void setc(std::string);
	std::string geta(void);
	std::string getb(void);
	std::string getc(void);
};

void set(TestStruct*,int);
void show(TestStruct*);

#endif