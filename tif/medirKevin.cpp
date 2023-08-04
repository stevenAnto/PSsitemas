#include <iostream>
#include <Windows.h>
#include <Psapi.h>

using namespace std;

int main() {
    DWORD targetProcessId; // ID del proceso que deseas monitorear
    cout << "Ingresa el ID del proceso que deseas monitorear: ";
    cin >> targetProcessId;

    HANDLE targetProcessHandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, targetProcessId);
    if (targetProcessHandle == NULL) {
        cerr << "No se pudo abrir el proceso. Asegurate de tener los permisos adecuados o de que el proceso existe." << endl;
        return 1;
    }

    while (true) {
        // Verificar si el proceso sigue siendo válido
        DWORD exitCode;
        if (GetExitCodeProcess(targetProcessHandle, &exitCode) && exitCode != STILL_ACTIVE) {
            cout << "El proceso con ID " << targetProcessId << " se ha cerrado. Saliendo del programa." << endl;
            break;
        }

        // Obtener el uso de CPU
        FILETIME createTime, exitTime, kernelTime, userTime;
        if (GetProcessTimes(targetProcessHandle, &createTime, &exitTime, &kernelTime, &userTime)) {
            ULARGE_INTEGER kernelTimeUL, userTimeUL;
            kernelTimeUL.LowPart = kernelTime.dwLowDateTime;
            kernelTimeUL.HighPart = kernelTime.dwHighDateTime;
            userTimeUL.LowPart = userTime.dwLowDateTime;
            userTimeUL.HighPart = userTime.dwHighDateTime;

            DWORD totalMs = static_cast<DWORD>((kernelTimeUL.QuadPart + userTimeUL.QuadPart) / 10000);
            cout << "Uso de CPU: " << totalMs << " ms" << endl;
        } else {
            cerr << "No se pudo obtener el uso de CPU." << endl;
        }

        // Obtener el uso de memoria
        PROCESS_MEMORY_COUNTERS_EX memoryCounters;
        if (GetProcessMemoryInfo(targetProcessHandle, reinterpret_cast<PROCESS_MEMORY_COUNTERS*>(&memoryCounters), sizeof(memoryCounters))) {
            SIZE_T memoryUsage = memoryCounters.PrivateUsage;
            cout << "Uso de memoria: " << memoryUsage / (1024 * 1024) << " MB" << endl;
        } else {
            cerr << "No se pudo obtener el uso de memoria." << endl;
        }

        Sleep(1000); // Esperar un segundo antes de actualizar la información nuevamente
    }

    CloseHandle(targetProcessHandle);
    return 0;
}