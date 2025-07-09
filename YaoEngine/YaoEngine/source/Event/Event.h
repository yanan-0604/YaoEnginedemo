#pragma once
enum class EventType {
	None=0,
	AppClose,		
	WindowResize,	WindowClose,	
	MousePress,		MouseRelease,	Mousescoll,
	KeyPress,		KeyRelease,		
	
};
class Event
{
public:
	virtual ~Event() = default;

	virtual char* Getname()=0;
private:
	char* Name;
	EventType type;
};
class WindowResize :public Event {
public:
	//~WindowResize() {};
	WindowResize(int x, int y) { wide= x; height = y; }
	virtual char* Getname()override {  return "s"; }
	int wide, height;
private:
	
};

