#pragma once

class Iterator {
public:
	virtual int next() {
		return 0;
	}

	virtual bool has_next() {
		return false;
	}
};