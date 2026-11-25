@echo off
REM ============================================================
REM Compila o trabalho sem depender do latexmk/Perl.
REM Faz sozinho: pdflatex -> biber (se houver referencias) -> pdflatex x2
REM
REM Uso no TexWorks: configure esta ferramenta em
REM   Editar > Preferencias > Typesetting > (botao "+")
REM     Nome:       compilar
REM     Programa:   compile.bat
REM     Argumentos: $fullname
REM e marque "compilar" como ferramenta padrao.
REM ============================================================
setlocal
set "JOBNAME=%~n1"

pdflatex -interaction=nonstopmode -synctex=1 "%JOBNAME%.tex"
if errorlevel 1 goto :fim

if exist "%JOBNAME%.bcf" (
    biber "%JOBNAME%"
)

pdflatex -interaction=nonstopmode -synctex=1 "%JOBNAME%.tex"
pdflatex -interaction=nonstopmode -synctex=1 "%JOBNAME%.tex"

:fim
endlocal
