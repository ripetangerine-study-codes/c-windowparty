
// windowparty.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#ifndef UNICODE
#define UNICODE
#endif

#include <iostream>
#include <windows.h>
#include <WinUser.h>

// 무한 < esc로 종료
// 2초에 한번씩 마우스를 따라다니면서 윈도우 창이뜸
//LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    return DefWindowProc(hwnd, uMsg, wParam, lParam);
//}
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wRaram, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdshow) 
{
    // register window class
    const wchar_t CLASS_NAME[] = L'sample window class';
    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    RegisterClass(&wc);
}


int main()
{
    HINSTANCE hInstance = GetModuleHandle(NULL);                                                
    std::cout << "Hello World!\n";

    HWND hwnd = CreateWindowExW(WS_EX_TOPMOST | WS_EX_LAYERED, ...);

    POINT pt;
    while (true) {
        // ESC 키를 누르면 프로그램 종료 (안전장치)
        if (GetAsyncKeyState(VK_ESCAPE)) break;

        // 마우스 좌표 가져오기
        GetCursorPos(&pt);

        // 창 위치를 마우스 좌표(+약간의 오프셋)로 이동
        SetWindowPos(hwnd, HWND_TOPMOST, pt.x + 10, pt.y + 10, 0, 0, SWP_NOSIZE);

        Sleep(10); // CPU 점유율 폭주 방지
    }
    return 0;
}


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
