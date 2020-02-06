@echo off
set c=%0
set c=%c:~1,-8%
echo 当前目录为%c%
setlocal EnableDelayedExpansion
for /r %c% %%i in (*.cpp) do (
	set abc=%%i
	del "!abc:~0,-4!.exe" >nul
	echo 正在编译:"!abc!"......
	g++ -g "!abc!" -o "!abc:~0,-4!.exe"
	if exist "!abc:~0,-4!.exe" (
		echo 编译成功,生成:"!abc:~0,-4!.exe".......
		) else (
		echo 编译未成功[老的文件已被删除!]
	)
	echo ============================================
)
endlocal
pause