# poco_uri_normal
Временное решение для нормализации строк к проекту extFilter
Для сборки должна быть установленна библиотека Poco https://pocoproject.org/releases/poco-1.7.8/poco-1.7.8p3.tar.gz

Опции в extfilter.ini должны быть установлены:

url_normalization = true

remove_dot = true

CentOS требует установленной переменной LD_LIBRARY_PATH
для запуска пример в файле start.sh