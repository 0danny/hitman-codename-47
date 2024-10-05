#include "constructors.h"

namespace Constructors
{
    void CreateHooks()
    {
        printf("[CONSTRUCTOR HOOK]: Creating constructor hooks...\n");

        if (MH_CreateHook(refTabAddress, (LPVOID)&Constructors::RefTabHook, NULL) != MH_OK)
        {
            printf("[CONSTRUCTOR HOOK]: Could not hook RefTab constructor.\n");
        }

        if (MH_CreateHook(equRefTabAddress, (LPVOID)&Constructors::EquRefTabHook, NULL) != MH_OK)
        {
            printf("[CONSTRUCTOR HOOK]: Could not hook EquRefTab constructor.\n");
        }

        if (MH_CreateHook(strRefTabAddress, (LPVOID)&Constructors::StrRefTabHook, NULL) != MH_OK)
        {
            printf("[CONSTRUCTOR HOOK]: Could not hook StrRefTab constructor.\n");
        }

        if (MH_CreateHook(zconsoleCommandAddress, (LPVOID)&Constructors::ZConsoleCommandHook, reinterpret_cast<LPVOID *>(&originalZConsoleCommand)) != MH_OK)
        {
            printf("[CONSTRUCTOR HOOK]: Could not hook ZConsoleCommand constructor.\n");
        }
    }

    RefTab *__fastcall RefTabHook(RefTab *_this, void *_EDX, int p_poolSize, int p_size)
    {
        // printf("[CONSTRUCTOR HOOK]: RefTab called -> Pool Size: %d, Size: %d\n", p_poolSize, p_size); //spams the console

        return new RefTab(p_poolSize, p_size);
    }

    EquRefTab *__fastcall EquRefTabHook(EquRefTab *_this, void *_EDX, int p_poolSize, int p_size)
    {
        printf("[CONSTRUCTOR HOOK]: EquRefTab called -> Pool Size: %d, Size: %d\n", p_poolSize, p_size);

        return new EquRefTab(p_poolSize, p_size);
    }

    StrRefTab *__fastcall StrRefTabHook(StrRefTab *_this, void *_EDX, int p_poolSize, int p_size)
    {
        printf("[CONSTRUCTOR HOOK]: StrRefTab called -> Pool Size: %d, Size: %d\n", p_poolSize, p_size);

        return new StrRefTab(p_poolSize, p_size);
    }

    ZConsoleCommand *__fastcall ZConsoleCommandHook(ZConsoleCommand *_this, void *_EDX)
    {
        printf("[CONSTRUCTOR HOOK]: ZConsoleCommand called\n");

        return new (_this) ZConsoleCommand();
    }
}