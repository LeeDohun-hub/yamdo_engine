#include "yaGameObject.h"
#include "yaInput.h"
#include "yaTime.h"
namespace ya
{
	GameObject::GameObject() : mX(0), mY(0)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		const int speed = 200.0f;

		if (Input::GetKey(eKeyCode::A))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += speed * Time::DeltaTime();
		}
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
		//�Ķ� �귯�� ����
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		//�Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));

		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		//�ٽ� ��� �����귯���� ����
		SelectObject(hdc, oldBrush);

		// �Ķ� �귯�� ����
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}

