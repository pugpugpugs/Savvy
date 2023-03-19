#pragma once

#ifdef SAVVY_BUILD_DLL
	#define SAVVY_API __declspec(dllexport)
#else
	#define SAVVY_API __declspec(dllimport)
#endif

namespace sve
{
	enum class Layout
	{
		Standard
	};
	//enum class TileBag
	//{
	//	Standard
	//};

	struct Options
	{
		Layout layout = Layout::Standard;
		//TileBag boardtype = TileBag::Standard;
	};

	class SAVVY_API Engine
	{
	public:
		void Start(Options options);
		void Start();
		void Update();
		void Test();
		//void Render();
	private:
		//Game game;
	};
}