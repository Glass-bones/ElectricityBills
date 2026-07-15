#pragma once
#include <span>
class eb_menu
{
public:
	virtual void setMnths(std::span<const double>) = 0;
	//span для проверки размеров вводимого массива, предотвращения возможности выхода за его границы, альтернатива - заменить вообще все массивы в проекте на тип векторов
	virtual void prntMnths() = 0;
	virtual ~eb_menu() = default;
};
// user