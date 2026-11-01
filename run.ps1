param(
    [Parameter(Position = 0)]
    [string]$Source
)

$ErrorActionPreference = "Stop"

$gcc   = "D:\Dev-Cpp\MinGW64\bin\gcc.exe"
$flags = @(
    "-std=c99",
    "-Wall",
    "-Wextra",
    "-finput-charset=UTF-8",
    "-fexec-charset=UTF-8",
    "-g"
)

if (-not $Source) {
    $Source = Read-Host "Enter .c file path (e.g. di5/swap_task.c)"
}

$src = Resolve-Path -LiteralPath $Source -ErrorAction SilentlyContinue
if (-not $src) {
    Write-Host "[ERROR] File not found: $Source" -ForegroundColor Red
    exit 1
}

$srcPath = $src.Path
$exePath = [System.IO.Path]::ChangeExtension($srcPath, ".exe")

Write-Host "[BUILD] $srcPath" -ForegroundColor Cyan
& $gcc @flags $srcPath -o $exePath
if ($LASTEXITCODE -ne 0) {
    Write-Host "[FAILED] compile error, see above" -ForegroundColor Red
    exit $LASTEXITCODE
}

Write-Host "[RUN] $exePath" -ForegroundColor Green
Write-Host "----------------------------------------"
& $exePath
Write-Host "----------------------------------------"
