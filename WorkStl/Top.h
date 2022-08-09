#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>



class Remote {
public:
	bool on;
	bool off;
	std::string channel;
	int numberChannel;
public:
	
	Remote(bool on = true, bool off = false, const std::string& channel = "FirstChannel", int numberChannel = 0) {
		this->on = on;  this->off = off; this->channel = channel;
		this->numberChannel = numberChannel;
	}

	friend std::ostream& operator<<(std::ostream& os, const Remote& st){
		os << st.channel << st.numberChannel;
		return os;
	}

	bool CheckOn(bool on) { return on; }
	bool CheckOff(bool off) { return off; }
};

