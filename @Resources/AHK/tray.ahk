#SingleInstance, force
#NoTrayIcon
DetectHiddenWindows, On
SetWinDelay, 0
X = %1%
Y = %2%
direction = %3%
IfWinActive, ahk_class NotifyIconOverflowWindow
	WinHide, ahk_class NotifyIconOverflowWindow
Else 
{
	ControlClick, %4%, ahk_class Shell_TrayWnd
	WinGetPos,,,WidthOfTray,HeightOfTray,ahk_class NotifyIconOverflowWindow
	TrueX := X-WidthOfTray/2
	TrueY := Y-1.5
	WinSet, Transparent, 0, ahk_class NotifyIconOverflowWindow
	ControlClick, %4%, ahk_class Shell_TrayWnd
	WinMove, ahk_class NotifyIconOverflowWindow, , %TrueX%, %TrueY%
	WinSet, Transparent, OFF, ahk_class NotifyIconOverflowWindow
loop 
{
	WinMove, ahk_class NotifyIconOverflowWindow, , %TrueX%, %TrueY%
	IfWinNotActive, ahk_class NotifyIconOverflowWindow
	ExitApp

}
}

ExitApp