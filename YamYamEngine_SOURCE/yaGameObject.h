#pragma once
#include "CommonInclude.h"
namespace ya
{
	// 게임 오브젝트의 기본 클래스
	// 모든 게임 오브젝트는 이 클래스를 상속받아야 한다.
	// 이 클래스는 게임 오브젝트의 기본적인 속성과 기능을 정의한다.
	// Actor

	class GameObject
	{
	public:
		GameObject();
		~GameObject();
		
		void Update();
		void LateUpdate();
		void Render(HDC hdc);
		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX()
		{
			return mX;
		}
		float GetPositionY()
		{
			return mY;
		}
	private:
		//게임 오브젝트의 좌표
		float mX;
		float mY;

	};


}

