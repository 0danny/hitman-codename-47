#pragma once

#include <windows.h>
#include <stdio.h>
#include "common.h"

// 0x27 in size
#pragma pack(push, 1)

class ZSysCom
{
public:
    ZSysCom();

    // Base class members
    u32 m_msgID;        // 0x4
    i32 m_unkInt1;      // 0x8
    void *m_unkPtr;     // 0xC
    boolean m_unkBool1; // 0x10

    boolean m_sendingZMessage; // 0x11
    boolean m_unkBool3;        // 0x12
    char *m_filePath;          // 0x16
    i32 m_lineNum;             // 0x1A
    HWND m_debugHwnd;          // 0x1E
    HWND m_unkHwnd;            // 0x22
    void *m_unkPtr2;           // 0x26

    // Overrides
    virtual i32 FormatString(char *p_resultBuffer, char *p_format, ...);

    // Destroy
    virtual ~ZSysCom();
    virtual void DestroyArrays();

    // Getters
    virtual i32 GetUnkInt1();
    virtual u32 GetMsgID();

    // Debug window stuff
    virtual void ProcessDebugWnd(HWND p_hWnd);
    virtual void SendDebugMsg(WPARAM p_wParam, LPARAM p_lParam, boolean p_sendMessage);
    virtual i32 ForwardWndProc(u32 p_msg, WPARAM p_wParam, LPARAM p_lParam);

    // Logging
    virtual ZSysCom *SetPathAndLine(char *p_filePath, i32 p_lineNum);
    virtual void ThrowFatal(char *p_format, ...);
    virtual void DataToDebug(char *p_format, ...);
    virtual void LogMessage(char *p_format, ...);

    virtual void UnkFunc5(i32 p_unkInt, char *p_format, ...);
    virtual void SendZMessage(char *p_format, ...);
    virtual void UnkFunc7(char *p_format, ...);
    virtual void *UnkFunc8(char *p_unkChar);
    virtual void UnkFunc9();
};

#pragma pack(pop)

extern __declspec(dllimport) ZSysCom *g_pSysCom;
