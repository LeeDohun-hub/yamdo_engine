#include "yaApplication.h"
#include "yaInput.h"
#include "yaTime.h"


namespace ya
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
		, mGameObjects{}
	{

	}
	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeEtc();

		//for (size_t i = 0; i < 100; i++)
		//{
		//	GameObject* gameObj = new GameObject();
		//	gameObj->SetPosition(rand() % 1600, rand() % 900);
		//	mGameObjects.push_back(gameObj);
		//
		//}

	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		//mPlayer.Update();
		Time::Update();

		//pPlayer->Update();
		//for (size_t i = 0; i < mGameObjects.size(); i++)
		//{
		//	//(*mGameObjects[i]).
		//	mGameObjects[i]->Update();
		//}
	}
	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{

		clearRenderTarget();
		Time::Render(mBackHdc);
		
		//for (size_t i = 0; i < mGameObjects.size(); i++)
		//{
		//	//(*mGameObjects[i]).
		//	mGameObjects[i]->Render(mBackHdc);
		//}
		//BackBuffer�� �ִ°� ���� Buffer�� ����(�׷��ش�)
		copyRenderTarget(mBackHdc, mHdc);
	}

	void Application::clearRenderTarget()
	{
		//clear
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}

	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);

	}

	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(hwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(hwnd, true);
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		//������ �ػ󵵿� �´� �����(��ȭ��)����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//����۸� ����ų DC����
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::initializeEtc()
	{
		Input::Initailize();
		Time::Initialize();
	}
}
