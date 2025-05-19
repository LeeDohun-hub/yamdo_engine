#pragma once
#include "CommonInclude.h"
namespace ya
{
	// ���� ������Ʈ�� �⺻ Ŭ����
	// ��� ���� ������Ʈ�� �� Ŭ������ ��ӹ޾ƾ� �Ѵ�.
	// �� Ŭ������ ���� ������Ʈ�� �⺻���� �Ӽ��� ����� �����Ѵ�.
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
		//���� ������Ʈ�� ��ǥ
		float mX;
		float mY;

	};


}

