@echo Start doxygen %time%
@mkdir log 2>nul
..\..\Tools\Doxygen\Bin\doxygen Doxygen.doxcfg >log\Output.txt 2>log\Error.txt
@echo End doxygen %time%
