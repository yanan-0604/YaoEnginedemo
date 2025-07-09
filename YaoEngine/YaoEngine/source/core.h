#ifdef WEIYAO_DLL
#define WEIYAOAPI 
#define WEIYAOAPI __declspec(dllexport)
#else
#define WEIYAOAPI __declspec(dllimport)
#endif


#ifdef _DEBUG
#define debug(x)  x
#define gldebug(x) x\
while(auto error=glGetError())\
{\
	std::cout<<error<<endl\
}\


#else

#define debug(x) 
#define gldebug(x) x

#endif



