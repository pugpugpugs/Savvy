#pragma once

#ifdef SAVVY_BUILD_DLL
#define SAVVY_API __declspec(dllexport)
#else
#define SAVVY_API __declspec(dllimport)
#endif

enum class Layout
{
	Standard
};

struct Options
{
	Layout layout = Layout::Standard;
};

struct State
{
	static inline std::string Play{ "Play" };
	static inline std::string MainMenu{ "MainMenu" };
};