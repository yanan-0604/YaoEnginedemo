#include<WeiYao.h>
class Eidtor :public WeiYaoEngine {
public:
	Eidtor() {};
	~Eidtor() {};
};
WeiYaoEngine*Create()
{
	return new Eidtor();
}
