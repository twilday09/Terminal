/*++
Copyright (c) Microsoft Corporation

Module Name:
- ApiRoutines.h

Abstract:
- This file defines the interface to respond to all API calls.

Author:
- Michael Niksa (miniksa) 12-Oct-2016

Revision History:
- Adapted from original items in srvinit.cpp, getset.cpp, directio.cpp, stream.cpp
--*/

#pragma once

#include "..\server\IApiRoutines.h"

class ApiRoutines : public IApiRoutines
{
#pragma region ObjectManagement
    /*HRESULT CreateInitialObjects(_Out_ InputBuffer** const ppInputObject,
    _Out_ SCREEN_INFORMATION** const ppOutputObject);
    */

#pragma endregion

#pragma region L1
    HRESULT GetConsoleInputCodePageImpl(_Out_ ULONG* const pCodePage);

    HRESULT GetConsoleOutputCodePageImpl(_Out_ ULONG* const pCodePage);

    HRESULT GetConsoleInputModeImpl(_In_ InputBuffer* const pContext,
                                    _Out_ ULONG* const pMode);

    HRESULT GetConsoleOutputModeImpl(_In_ SCREEN_INFORMATION* const pContext,
                                     _Out_ ULONG* const pMode);

    HRESULT SetConsoleInputModeImpl(_In_ InputBuffer* const pContext,
                                    _In_ ULONG const Mode);

    HRESULT SetConsoleOutputModeImpl(_In_ SCREEN_INFORMATION* const pContext,
                                     _In_ ULONG const Mode);

    HRESULT GetNumberOfConsoleInputEventsImpl(_In_ InputBuffer* const pContext,
                                              _Out_ ULONG* const pEvents);

    HRESULT PeekConsoleInputAImpl(_In_ IConsoleInputObject* const pInContext,
                                  _Out_writes_to_(cRecords, *pcRecordsWritten) INPUT_RECORD* const pRecords,
                                  _In_ size_t const cRecords,
                                  _Out_ size_t* const pcRecordsWritten,
                                  _In_ INPUT_READ_HANDLE_DATA* const pInputReadHandleData,
                                  _Outptr_result_maybenull_ IWaitRoutine** const ppWaiter);

    HRESULT PeekConsoleInputWImpl(_In_ IConsoleInputObject* const pInContext,
                                  _Out_writes_to_(cRecords, *pcRecordsWritten) INPUT_RECORD* const pRecords,
                                  _In_ size_t const cRecords,
                                  _Out_ size_t* const pcRecordsWritten,
                                  _In_ INPUT_READ_HANDLE_DATA* const pInputReadHandleData,
                                  _Outptr_result_maybenull_ IWaitRoutine** const ppWaiter);

    HRESULT ReadConsoleInputAImpl(_In_ IConsoleInputObject* const pInContext,
                                  _Out_writes_to_(cRecords, *pcRecordsWritten) INPUT_RECORD* const pRecords,
                                  _In_ size_t const cRecords,
                                  _Out_ size_t* const pcRecordsWritten,
                                  _In_ INPUT_READ_HANDLE_DATA* const pInputReadHandleData,
                                  _Outptr_result_maybenull_ IWaitRoutine** const ppWaiter);

    HRESULT ReadConsoleInputWImpl(_In_ IConsoleInputObject* const pInContext,
                                  _Out_writes_to_(cRecords, *pcRecordsWritten) INPUT_RECORD* const pRecords,
                                  _In_ size_t const cRecords,
                                  _Out_ size_t* const pcRecordsWritten,
                                  _In_ INPUT_READ_HANDLE_DATA* const pInputReadHandleData,
                                  _Outptr_result_maybenull_ IWaitRoutine** const ppWaiter);

    HRESULT ReadConsoleAImpl(_In_ IConsoleInputObject* const pInContext,
                             _Out_writes_to_(cchTextBuffer, *pcchTextBufferWritten) char* const psTextBuffer,
                             _In_ size_t const cchTextBuffer,
                             _Out_ size_t* const pcchTextBufferWritten,
                             _Outptr_result_maybenull_ IWaitRoutine** const ppWaiter,
                             _In_reads_opt_(cchInitialData) char* const psInitialData,
                             _In_ size_t const cchInitialData,
                             _In_reads_opt_(cchExeName) wchar_t* const pwsExeName,
                             _In_ size_t const cchExeName,
                             _In_ INPUT_READ_HANDLE_DATA* const pHandleData,
                             _In_ HANDLE const hConsoleClient,
                             _In_ DWORD const dwControlWakeupMask,
                             _Out_ DWORD* const pdwControlKeyState);

    HRESULT ReadConsoleWImpl(_In_ IConsoleInputObject* const pInContext,
                             _Out_writes_to_(cchTextBuffer, *pcchTextBufferWritten) wchar_t* const pwsTextBuffer,
                             _In_ size_t const cchTextBuffer,
                             _Out_ size_t* const pcchTextBufferWritten,
                             _Outptr_result_maybenull_ IWaitRoutine** const ppWaiter,
                             _In_reads_opt_(cchInitialData) wchar_t* const pwsInitialData,
                             _In_ size_t const cchInitialData,
                             _In_reads_opt_(cchExeName) wchar_t* const pwsExeName,
                             _In_ size_t const cchExeName,
                             _In_ INPUT_READ_HANDLE_DATA* const pHandleData,
                             _In_ HANDLE const hConsoleClient,
                             _In_ DWORD const dwControlWakeupMask,
                             _Out_ DWORD* const pdwControlKeyState);

    HRESULT WriteConsoleAImpl(_In_ IConsoleOutputObject* const pOutContext,
                              _In_reads_(cchTextBufferLength) const char* const psTextBuffer,
                              _In_ size_t const cchTextBufferLength,
                              _Out_ size_t* const pcchTextBufferRead,
                              _Outptr_result_maybenull_ IWaitRoutine** const ppWaiter);

    HRESULT WriteConsoleWImpl(_In_ IConsoleOutputObject* const pOutContext,
                              _In_reads_(cchTextBufferLength) const wchar_t* const pwsTextBuffer,
                              _In_ size_t const cchTextBufferLength,
                              _Out_ size_t* const pcchTextBufferRead,
                              _Outptr_result_maybenull_ IWaitRoutine** const ppWaiter);

#pragma region ThreadCreationInfo
    HRESULT GetConsoleLangIdImpl(_Out_ LANGID* const pLangId);
#pragma endregion

#pragma endregion

#pragma region L2

    //HRESULT FillConsoleOutputAttributeImpl(_In_ SCREEN_INFORMATION* const pContext,
    //                                               _In_ WORD const Attribute,
    //                                               _In_ DWORD const LengthToWrite,
    //                                               _In_ COORD const StartingCoordinate,
    //                                               _Out_ DWORD* const pCellsModified);

    //HRESULT FillConsoleOutputCharacterAImpl(_In_ SCREEN_INFORMATION* const pContext,
    //                                                _In_ char const Character,
    //                                                _In_ DWORD const LengthToWrite,
    //                                                _In_ COORD const StartingCoordinate,
    //                                                _Out_ DWORD* const pCellsModified);

    //HRESULT FillConsoleOutputCharacterWImpl(_In_ SCREEN_INFORMATION* const pContext,
    //                                                _In_ wchar_t const Character,
    //                                                _In_ DWORD const LengthToWrite,
    //                                                _In_ COORD const StartingCoordinate,
    //                                                _Out_ DWORD* const pCellsModified);

    //// Process based. Restrict in protocol side?
    //HRESULT GenerateConsoleCtrlEventImpl(_In_ ULONG const ProcessGroupFilter,
    //                                             _In_ ULONG const ControlEvent);

    HRESULT SetConsoleActiveScreenBufferImpl(_In_ SCREEN_INFORMATION* const pNewContext);

    HRESULT FlushConsoleInputBuffer(_In_ InputBuffer* const pContext);

    HRESULT SetConsoleInputCodePageImpl(_In_ ULONG const CodePage);

    HRESULT SetConsoleOutputCodePageImpl(_In_ ULONG const CodePage);

    HRESULT GetConsoleCursorInfoImpl(_In_ SCREEN_INFORMATION* const pContext,
                                     _Out_ ULONG* const pCursorSize,
                                     _Out_ BOOLEAN* const pIsVisible);

    HRESULT SetConsoleCursorInfoImpl(_In_ SCREEN_INFORMATION* const pContext,
                                     _In_ ULONG const CursorSize,
                                     _In_ BOOLEAN const IsVisible);

    //// driver will pare down for non-Ex method
    HRESULT GetConsoleScreenBufferInfoExImpl(_In_ SCREEN_INFORMATION* const pContext,
                                             _Out_ CONSOLE_SCREEN_BUFFER_INFOEX* const pScreenBufferInfoEx);

    HRESULT SetConsoleScreenBufferInfoExImpl(_In_ SCREEN_INFORMATION* const pContext,
                                             _In_ const CONSOLE_SCREEN_BUFFER_INFOEX* const pScreenBufferInfoEx);

    HRESULT SetConsoleScreenBufferSizeImpl(_In_ SCREEN_INFORMATION* const pContext,
                                           _In_ const COORD* const pSize);

    HRESULT SetConsoleCursorPositionImpl(_In_ SCREEN_INFORMATION* const pContext,
                                         _In_ const COORD* const pCursorPosition);

    HRESULT GetLargestConsoleWindowSizeImpl(_In_ SCREEN_INFORMATION* const pContext,
                                            _Out_ COORD* const pSize);

    HRESULT ScrollConsoleScreenBufferAImpl(_In_ SCREEN_INFORMATION* const pContext,
                                           _In_ const SMALL_RECT* const pSourceRectangle,
                                           _In_ const COORD* const pTargetOrigin,
                                           _In_opt_ const SMALL_RECT* const pTargetClipRectangle,
                                           _In_ char const chFill,
                                           _In_ WORD const attrFill);

    HRESULT ScrollConsoleScreenBufferWImpl(_In_ SCREEN_INFORMATION* const pContext,
                                           _In_ const SMALL_RECT* const pSourceRectangle,
                                           _In_ const COORD* const pTargetOrigin,
                                           _In_opt_ const SMALL_RECT* const pTargetClipRectangle,
                                           _In_ wchar_t const wchFill,
                                           _In_ WORD const attrFill);

    HRESULT SetConsoleTextAttributeImpl(_In_ SCREEN_INFORMATION* const pContext,
                                        _In_ WORD const Attribute);

    HRESULT SetConsoleWindowInfoImpl(_In_ SCREEN_INFORMATION* const pContext,
                                     _In_ BOOLEAN const IsAbsoluteRectangle,
                                     _In_ const SMALL_RECT* const pWindowRectangle);

    //HRESULT ReadConsoleOutputAttributeImpl(_In_ SCREEN_INFORMATION* const pContext,
    //                                               _In_ const COORD* const pSourceOrigin,
    //                                               _Out_writes_to_(AttributeBufferLength, *pAttributeBufferWritten) WORD* const pAttributeBuffer,
    //                                               _In_ ULONG const AttributeBufferLength,
    //                                               _Out_ ULONG* const pAttributeBufferWritten);

    //HRESULT ReadConsoleOutputCharacterAImpl(_In_ SCREEN_INFORMATION* const pContext,
    //                                                _In_ const COORD* const pSourceOrigin,
    //                                                _Out_writes_to_(TextBufferLength, *pTextBufferWritten) char* const pTextBuffer,
    //                                                _In_ ULONG const pTextBufferLength,
    //                                                _Out_ ULONG* const pTextBufferWritten);

    //HRESULT ReadConsoleOutputCharacterWImpl(_In_ SCREEN_INFORMATION* const pContext,
    //                                                _In_ const COORD* const pSourceOrigin,
    //                                                _Out_writes_to_(TextBufferLength, *pTextBufferWritten) wchar_t* const pTextBuffer,
    //                                                _In_ ULONG const TextBufferLength,
    //                                                _Out_ ULONG* const pTextBufferWritten);

    //HRESULT WriteConsoleInputAImpl(_In_ InputBuffer* const pContext,
    //                                       _In_reads_(InputBufferLength) const INPUT_RECORD* const pInputBuffer,
    //                                       _In_ ULONG const InputBufferLength,
    //                                       _Out_ ULONG* const pInputBufferRead);

    //HRESULT WriteConsoleInputWImpl(_In_ InputBuffer* const pContext,
    //                                       _In_reads_(InputBufferLength) const INPUT_RECORD* const pInputBuffer,
    //                                       _In_ ULONG const InputBufferLength,
    //                                       _Out_ ULONG* const pInputBufferRead);

    //HRESULT WriteConsoleOutputAImpl(_In_ SCREEN_INFORMATION* const pContext,
    //                                        _In_reads_(pTextBufferSize->X * pTextBufferSize->Y) const CHAR_INFO* const pTextBuffer,
    //                                        _In_ const COORD* const pTextBufferSize,
    //                                        _In_ const COORD* const pTextBufferSourceOrigin,
    //                                        _In_ const SMALL_RECT* const pTargetRectangle,
    //                                        _Out_ SMALL_RECT* const pAffectedRectangle);

    //HRESULT WriteConsoleOutputWImpl(_In_ SCREEN_INFORMATION* const pContext,
    //                                        _In_reads_(pTextBufferSize->X * pTextBufferSize->Y) const CHAR_INFO* const pTextBuffer,
    //                                        _In_ const COORD* const pTextBufferSize,
    //                                        _In_ const COORD* const pTextBufferSourceOrigin,
    //                                        _In_ const SMALL_RECT* const pTargetRectangle,
    //                                        _Out_ SMALL_RECT* const pAffectedRectangle);

    //HRESULT WriteConsoleOutputAttributeImpl(_In_ SCREEN_INFORMATION* const pContext,
    //                                                _In_reads_(AttributeBufferLength) const WORD* const pAttributeBuffer,
    //                                                _In_ ULONG const AttributeBufferLength,
    //                                                _In_ const COORD* const pTargetOrigin,
    //                                                _Out_ ULONG* const pAttributeBufferRead);

    //HRESULT WriteConsoleOutputCharacterAImpl(_In_ SCREEN_INFORMATION* const pContext,
    //                                                 _In_reads_(TextBufferLength) const char* const pTextBuffer,
    //                                                 _In_ ULONG const TextBufferLength,
    //                                                 _In_ const COORD* const pTargetOrigin,
    //                                                 _Out_ ULONG* const pTextBufferRead);

    //HRESULT WriteConsoleOutputCharacterWImpl(_In_ SCREEN_INFORMATION* const pContext,
    //                                                 _In_reads_(TextBufferLength) const wchar_t* const pTextBuffer,
    //                                                 _In_ ULONG const TextBufferLength,
    //                                                 _In_ const COORD* const pTargetOrigin,
    //                                                 _Out_ ULONG* const pTextBufferRead);

    //HRESULT ReadConsoleOutputA(_In_ SCREEN_INFORMATION* const pContext,
    //                                   _Out_writes_(pTextBufferSize->X * pTextBufferSize->Y) CHAR_INFO* const pTextBuffer,
    //                                   _In_ const COORD* const pTextBufferSize,
    //                                   _In_ const COORD* const pTextBufferTargetOrigin,
    //                                   _In_ const SMALL_RECT* const pSourceRectangle,
    //                                   _Out_ SMALL_RECT* const pReadRectangle);

    //HRESULT ReadConsoleOutputW(_In_ SCREEN_INFORMATION* const pContext,
    //                                   _Out_writes_(pTextBufferSize->X * pTextBufferSize->Y) CHAR_INFO* const pTextBuffer,
    //                                   _In_ const COORD* const pTextBufferSize,
    //                                   _In_ const COORD* const pTextBufferTargetOrigin,
    //                                   _In_ const SMALL_RECT* const pSourceRectangle,
    //                                   _Out_ SMALL_RECT* const pReadRectangle);

    HRESULT GetConsoleTitleAImpl(_Out_writes_to_(cchTitleBufferSize, *pcchTitleBufferWritten) _Always_(_Post_z_) char* const psTitleBuffer,
                                 _In_ size_t const cchTitleBufferSize,
                                 _Out_ size_t* const pcchTitleBufferWritten,
                                 _Out_ size_t* const pcchTitleBufferNeeded);

    HRESULT GetConsoleTitleWImpl(_Out_writes_to_(cchTitleBufferSize, *pcchTitleBufferWritten) _Always_(_Post_z_) wchar_t* const pwsTitleBuffer,
                                 _In_ size_t const cchTitleBufferSize,
                                 _Out_ size_t* const pcchTitleBufferWritten,
                                 _Out_ size_t* const pcchTitleBufferNeeded);

    HRESULT GetConsoleOriginalTitleAImpl(_Out_writes_to_(cchTitleBufferSize, *pcchTitleBufferWritten) _Always_(_Post_z_) char* const psTitleBuffer,
                                         _In_ size_t const cchTitleBufferSize,
                                         _Out_ size_t* const pcchTitleBufferWritten,
                                         _Out_ size_t* const pcchTitleBufferNeeded);

    HRESULT GetConsoleOriginalTitleWImpl(_Out_writes_to_(cchTitleBufferSize, *pcchTitleBufferWritten) _Always_(_Post_z_) wchar_t* const pwsTitleBuffer,
                                         _In_ size_t const cchTitleBufferSize,
                                         _Out_ size_t* const pcchTitleBufferWritten,
                                         _Out_ size_t* const pcchTitleBufferNeeded);

    HRESULT SetConsoleTitleAImpl(_In_reads_or_z_(cchTitleBufferSize) const char* const psTitleBuffer,
                                 _In_ size_t const cchTitleBufferSize);

    HRESULT SetConsoleTitleWImpl(_In_reads_or_z_(cchTitleBufferSize) const wchar_t* const pwsTitleBuffer,
                                 _In_ size_t const cchTitleBufferSize);

#pragma endregion

#pragma region L3
    HRESULT GetNumberOfConsoleMouseButtonsImpl(_Out_ ULONG* const pButtons);

    HRESULT GetConsoleFontSizeImpl(_In_ SCREEN_INFORMATION* const pContext,
                                   _In_ DWORD const FontIndex,
                                   _Out_ COORD* const pFontSize);

    //// driver will pare down for non-Ex method
    HRESULT GetCurrentConsoleFontExImpl(_In_ SCREEN_INFORMATION* const pContext,
                                        _In_ BOOLEAN const IsForMaximumWindowSize,
                                        _Out_ CONSOLE_FONT_INFOEX* const pConsoleFontInfoEx);

    HRESULT SetConsoleDisplayModeImpl(_In_ SCREEN_INFORMATION* const pContext,
                                      _In_ ULONG const Flags,
                                      _Out_ COORD* const pNewScreenBufferSize);

    HRESULT GetConsoleDisplayModeImpl(_In_ SCREEN_INFORMATION* const pContext,
                                      _Out_ ULONG* const pFlags);

    HRESULT AddConsoleAliasAImpl(_In_reads_or_z_(cchSourceBufferLength) const char* const psSourceBuffer,
                                 _In_ size_t const cchSourceBufferLength,
                                 _In_reads_or_z_(cchTargetBufferLength) const char* const psTargetBuffer,
                                 _In_ size_t const cchTargetBufferLength,
                                 _In_reads_or_z_(cchExeNameBufferLength) const char* const psExeNameBuffer,
                                 _In_ size_t const cchExeNameBufferLength);

    HRESULT AddConsoleAliasWImpl(_In_reads_or_z_(cchSourceBufferLength) const wchar_t* const pwsSourceBuffer,
                                 _In_ size_t const cchSourceBufferLength,
                                 _In_reads_or_z_(cchTargetBufferLength) const wchar_t* const pwsTargetBuffer,
                                 _In_ size_t const cchTargetBufferLength,
                                 _In_reads_or_z_(cchExeNameBufferLength) const wchar_t* const pwsExeNameBuffer,
                                 _In_ size_t const cchExeNameBufferLength);

    HRESULT GetConsoleAliasAImpl(_In_reads_or_z_(cchSourceBufferLength) const char* const psSourceBuffer,
                                 _In_ size_t const cchSourceBufferLength,
                                 _Out_writes_to_(cchTargetBufferLength, *pcchTargetBufferWritten) _Always_(_Post_z_) char* const psTargetBuffer,
                                 _In_ size_t const cchTargetBufferLength,
                                 _Out_ size_t* const pcchTargetBufferWritten,
                                 _In_reads_or_z_(cchExeNameBufferLength) const char* const psExeNameBuffer,
                                 _In_ size_t const cchExeNameBufferLength);

    HRESULT GetConsoleAliasWImpl(_In_reads_or_z_(cchSourceBufferLength) const wchar_t* const pwsSourceBuffer,
                                 _In_ size_t const cchSourceBufferLength,
                                 _Out_writes_to_(cchTargetBufferLength, *pcchTargetBufferWritten) _Always_(_Post_z_) wchar_t* const pwsTargetBuffer,
                                 _In_ size_t const cchTargetBufferLength,
                                 _Out_ size_t* const pcchTargetBufferWritten,
                                 _In_reads_or_z_(cchExeNameBufferLength) const wchar_t* const pwsExeNameBuffer,
                                 _In_ size_t const cchExeNameBufferLength);

    HRESULT GetConsoleAliasesLengthAImpl(_In_reads_or_z_(cchExeNameBufferLength) const char* const psExeNameBuffer,
                                         _In_ size_t const cchExeNameBufferLength,
                                         _Out_ size_t* const pcchAliasesBufferRequired);

    HRESULT GetConsoleAliasesLengthWImpl(_In_reads_or_z_(cchExeNameBufferLength) const wchar_t* const pwsExeNameBuffer,
                                         _In_ size_t const cchExeNameBufferLength,
                                         _Out_ size_t* const pcchAliasesBufferRequired);

    HRESULT GetConsoleAliasExesLengthAImpl(_Out_ size_t* const pcchAliasExesBufferRequired);

    HRESULT GetConsoleAliasExesLengthWImpl(_Out_ size_t* const pcchAliasExesBufferRequired);

    HRESULT GetConsoleAliasesAImpl(_In_reads_or_z_(cchExeNameBufferLength) const char* const psExeNameBuffer,
                                   _In_ size_t const cchExeNameBufferLength,
                                   _Out_writes_to_(cchAliasBufferLength, *pcchAliasBufferWritten) _Always_(_Post_z_) char* const psAliasBuffer,
                                   _In_ size_t const cchAliasBufferLength,
                                   _Out_ size_t* const pcchAliasBufferWritten);

    HRESULT GetConsoleAliasesWImpl(_In_reads_or_z_(cchExeNameBufferLength) const wchar_t* const pwsExeNameBuffer,
                                   _In_ size_t const cchExeNameBufferLength,
                                   _Out_writes_to_(cchAliasBufferLength, *pcchAliasBufferWritten) _Always_(_Post_z_) wchar_t* const pwsAliasBuffer,
                                   _In_ size_t const cchAliasBufferLength,
                                   _Out_ size_t* const pcchAliasBufferWritten);

    HRESULT GetConsoleAliasExesAImpl(_Out_writes_to_(cchAliasExesBufferLength, *pcchAliasExesBufferWritten) _Always_(_Post_z_) char* const psAliasExesBuffer,
                                     _In_ size_t const cchAliasExesBufferLength,
                                     _Out_ size_t* const pcchAliasExesBufferWritten);

    HRESULT GetConsoleAliasExesWImpl(_Out_writes_to_(cchAliasExesBufferLength, *pcchAliasExesBufferWritten) _Always_(_Post_z_) wchar_t* const pwsAliasExesBuffer,
                                     _In_ size_t const cchAliasExesBufferLength,
                                     _Out_ size_t* const pcchAliasExesBufferWritten);

#pragma region CMDext Private API

    HRESULT ExpungeConsoleCommandHistoryAImpl(_In_reads_or_z_(cchExeNameBufferLength) const char* const psExeNameBuffer,
                                              _In_ size_t const cchExeNameBufferLength);

    HRESULT ExpungeConsoleCommandHistoryWImpl(_In_reads_or_z_(cchExeNameBufferLength) const wchar_t* const pwsExeNameBuffer,
                                              _In_ size_t const cchExeNameBufferLength);

    HRESULT SetConsoleNumberOfCommandsAImpl(_In_reads_or_z_(cchExeNameBufferLength) const char* const psExeNameBuffer,
                                            _In_ size_t const cchExeNameBufferLength,
                                            _In_ size_t const NumberOfCommands);

    HRESULT SetConsoleNumberOfCommandsWImpl(_In_reads_or_z_(cchExeNameBufferLength) const wchar_t* const pwsExeNameBuffer,
                                            _In_ size_t const cchExeNameBufferLength,
                                            _In_ size_t const NumberOfCommands);

    HRESULT GetConsoleCommandHistoryLengthAImpl(_In_reads_or_z_(cchExeNameBufferLength) const char* const psExeNameBuffer,
                                                _In_ size_t const cchExeNameBufferLength,
                                                _Out_ size_t* const pcchCommandHistoryLength);

    HRESULT GetConsoleCommandHistoryLengthWImpl(_In_reads_or_z_(cchExeNameBufferLength) const wchar_t* const pwsExeNameBuffer,
                                                _In_ size_t const cchExeNameBufferLength,
                                                _Out_ size_t* const pcchCommandHistoryLength);

    HRESULT GetConsoleCommandHistoryAImpl(_In_reads_or_z_(cchExeNameBufferLength) const char* const psExeNameBuffer,
                                          _In_ size_t const cchExeNameBufferLength,
                                          _Out_writes_to_(cchCommandHistoryBufferLength, *pcchCommandHistoryBufferWritten) _Always_(_Post_z_) char* const psCommandHistoryBuffer,
                                          _In_ size_t const cchCommandHistoryBufferLength,
                                          _Out_ size_t* const pcchCommandHistoryBufferWritten);

    HRESULT GetConsoleCommandHistoryWImpl(_In_reads_or_z_(cchExeNameBufferLength) const wchar_t* const pwsExeNameBuffer,
                                          _In_ size_t const cchExeNameBufferLength,
                                          _Out_writes_to_(cchCommandHistoryBufferLength, *pcchCommandHistoryBufferWritten) _Always_(_Post_z_) wchar_t* const pwsCommandHistoryBuffer,
                                          _In_ size_t const cchCommandHistoryBufferLength,
                                          _Out_ size_t* const pcchCommandHistoryBufferWritten);

#pragma endregion

    HRESULT GetConsoleWindowImpl(_Out_ HWND* const pHwnd);

    HRESULT GetConsoleSelectionInfoImpl(_Out_ CONSOLE_SELECTION_INFO* const pConsoleSelectionInfo);

    HRESULT GetConsoleHistoryInfoImpl(_Out_ CONSOLE_HISTORY_INFO* const pConsoleHistoryInfo);

    HRESULT SetConsoleHistoryInfoImpl(_In_ const CONSOLE_HISTORY_INFO* const pConsoleHistoryInfo);

    HRESULT SetCurrentConsoleFontExImpl(_In_ SCREEN_INFORMATION* const pContext,
                                        _In_ BOOLEAN const IsForMaximumWindowSize,
                                        _In_ const CONSOLE_FONT_INFOEX* const pConsoleFontInfoEx);

#pragma endregion
};