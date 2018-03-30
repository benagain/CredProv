@echo Start cppcheck %time%
@mkdir log 2>nul
@pushd ..
..\Tools\cppcheck\cppcheck --enable=style --xml --xml-version=2 -j 10 --inline-suppr --suppressions-list=build\cppcheck-suppress.txt -D_UNICODE . 1> build\log\cppcheck-files.txt 2> build\log\cppcheck-result.xml
@popd
@echo End cppcheck %time%
