!include "MUI.nsh"

!define MUI_ICON "install icon.ico"
!define MUI_UNICON "uninstall icon.ico"

!define APP_NAME "Hitvidio"
!define APP_TARGET "hitvidio-editor"

!define MUI_FINISHPAGE_RUN "$INSTDIR\hitvidio-editor.exe"

SetCompressor lzma

Name ${APP_NAME}


!ifdef X64
InstallDir "$PROGRAMFILES64\${APP_NAME}"
!else
InstallDir "$PROGRAMFILES32\${APP_NAME}"
!endif

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_LICENSE LICENSE
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_COMPONENTS
!insertmacro MUI_PAGE_INSTFILES

!define MUI_FINISHPAGE_NOAUTOCLOSE
!define MUI_FINISHPAGE_RUN_TEXT "Run ${APP_NAME}"
!define MUI_FINISHPAGE_RUN_FUNCTION "LaunchHitvidio"
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_LANGUAGE "English"

Section "Hitvidio (required)"

  SectionIn RO

  SetOutPath $INSTDIR

  File /r hitvidio\*

  WriteUninstaller "$INSTDIR\uninstall.exe"

SectionEnd

Section "Create Desktop shortcut"
  CreateShortCut "$DESKTOP\${APP_NAME}.lnk" "$INSTDIR\${APP_TARGET}.exe"
SectionEnd

Section "Create Start Menu shortcut"
  CreateDirectory "$SMPROGRAMS\${APP_NAME}"
  CreateShortCut "$SMPROGRAMS\${APP_NAME}\${APP_NAME}.lnk" "$INSTDIR\${APP_TARGET}.exe"
  CreateShortCut "$SMPROGRAMS\${APP_NAME}\Uninstall ${APP_NAME}.lnk" "$INSTDIR\uninstall.exe"
SectionEnd

Section "Associate *.hvd files with Hitvidio"
  WriteRegStr HKCR ".hvd" "" "HitvidioEditor.HVDFile"
  WriteRegStr HKCR ".hvd" "Content Type" "application/vnd.hitvidio-project"
  WriteRegStr HKCR "HitvidioEditor.HVDFile" "" "Hitvidio project file"
  WriteRegStr HKCR "HitvidioEditor.HVDFile\DefaultIcon" "" "$INSTDIR\hitvidio-editor.exe,1"
  WriteRegStr HKCR "HitvidioEditor.HVDFile\shell\open\command" "" "$\"$INSTDIR\hitvidio-editor.exe$\" $\"%1$\""
  System::Call 'shell32.dll::SHChangeNotify(i, i, i, i) v (0x08000000, 0, 0, 0)'
SectionEnd

UninstPage uninstConfirm
UninstPage instfiles

Section "uninstall"

  rmdir /r "$INSTDIR"

  Delete "$DESKTOP\${APP_NAME}.lnk"
  rmdir /r "$SMPROGRAMS\${APP_NAME}"

  DeleteRegKey HKCR ".hvd"
  DeleteRegKey HKCR "HitvidioEditor.HVDFile"
  DeleteRegKey HKCR "HitvidioEditor.HVDFile\DefaultIcon" ""
  DeleteRegKey HKCR "HitvidioEditor.HVDFile\shell\open\command" ""
  System::Call 'shell32.dll::SHChangeNotify(i, i, i, i) v (0x08000000, 0, 0, 0)'
SectionEnd

Function LaunchHitvidio
  ExecShell "" "$INSTDIR\${APP_TARGET}.exe"
FunctionEnd