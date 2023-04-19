#define  _CRT_SECURE_NO_WARNINGS

//多分支编译条件(p187-174)
//#if 1
//#endif  =>if判断为真执行//...

int main() {

#if 0	//常量表达式
	//...
#elif 0	//常量表达式
	//...
#else 0	//常量表达式
	//...
#endif // 1

	return 0;
}