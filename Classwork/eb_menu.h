#pragma once
class eb_menu
{
public:
	virtual void setMnths(double*) = 0;
	virtual void prntMnths() = 0;
	virtual ~eb_menu() = default;
};
// user