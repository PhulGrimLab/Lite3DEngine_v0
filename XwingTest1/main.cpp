#include <Windows.h>

// 전역 변수
bool g_running = true;

// 윈도우 프로시저 함수 선언
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		g_running = false; // 프로그램 종료 플래그 설정
		PostQuitMessage(0); // 메시지 루프 종료
		return 0;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}

/// <summary>
/// 게임엔진의 진입점입니다.
/// </summary>
/// <param name="hInstance">현재 프로세스의 인스턴스 핸들입니다.</param>
/// <param name="hPrevInstance">이전 인스턴스의 핸들(항상 NULL).</param>
/// <param name="lpCmdLine">명령줄 인수 문자열입니다.</param>
/// <param name="nCmdShow">윈도우 표시 방법입니다.</param>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 윈도우 클래스 등록
	WNDCLASS wc = {};
	wc.lpfnWndProc = WindowProc; // 윈도우 프로시저 함수 설정
	wc.hInstance = hInstance; // 인스턴스 핸들 설정
	wc.lpszClassName = L"Lite3DEngineWindow"; // 클래스 이름 설정

	RegisterClass(&wc); // 윈도우 클래스 등록

	// 윈도우 생성
	HWND hwnd = CreateWindowEx(
		0, // 확장 스타일
		wc.lpszClassName, // 클래스 이름
		L"Lite3D Engine", // 윈도우 제목
		WS_OVERLAPPEDWINDOW, // 윈도우 스타일
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, // 위치와 크기
		NULL, // 부모 윈도우 없음
		NULL, // 메뉴 없음
		hInstance, // 인스턴스 핸들
		NULL // 추가 매개변수 없음
	);

	ShowWindow(hwnd, nCmdShow); // 윈도우 표시

	// 게임 루프
	MSG msg = {};

	while (g_running)
	{
		// 메시지 처리 (논블로킹)
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))		//PeekMessage를 쓰면 계속 렌더링이 가능하다.
		{
			TranslateMessage(&msg); // 메시지 번역
			DispatchMessage(&msg); // 메시지 전달
		}
		//=====================
		// 여기부터 엔진 영역
		//=====================

		// 화면 그리기 (GDI 사용)
		HDC hdc = GetDC(hwnd); // 디바이스 컨텍스트 가져오기

		RECT rect;
		GetClientRect(hwnd, &rect); // 클라이언트 영역의 크기 가져오기

		// 배경을 검은색으로 채우기
		HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 0)); // 검은색 브러시 생성
		FillRect(hdc, &rect, hBrush); // 클라이언트 영역을 검은색으로 채우기
		DeleteObject(hBrush); // 브러시 객체 삭제

		// 텍스트 출력
		SetTextColor(hdc, RGB(0, 255, 0)); // 텍스트 색상을 녹색으로 설정
		SetBkMode(hdc, TRANSPARENT); // 배경 투명 모드 설정
		TextOut(hdc, 10, 10, L"Hello, Lite3D Engine!", 22); // 텍스트 출력

		ReleaseDC(hwnd, hdc); // 디바이스 컨텍스트 해제

		// ======================
		// 이후 여기에:
		// - 렌더러
		// - 카메라
		// - 3D 변환
		// ======================
	}

	return 0;
}