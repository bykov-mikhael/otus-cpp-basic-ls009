message("Проверка версии cmake...")
cmake_minimum_required(VERSION 3.20)
project(server
        VERSION 1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD          11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

message("Создание исполняемого файла...")
add_executable(server src/main.cpp)

find_package(Boost REQUIRED COMPONENTS)
target_link_libraries(server PRIVATE Boost::boost)

message("Устанавливаем флаги компилятора...")
set(CMAKE_CXX_FLAGS "-Wall -Werror -pedantic -fsanitize=address -fsanitize=undefined")
# -fsanitize=thread

# CMAKE_CXX_FLAGS
# CMAKE_CXX_FLAGS_DEBUG           -g -O0
# CMAKE_CXX_FLAGS_RELEASE         -O3 -DNDEBUG
# CMAKE_CXX_FLAGS_RELWITHDEBINFO  -O2 -g -DNDEBUG
# CMAKE_CXX_FLAGS_MINSIZEREL      -Os -DNDEBUG

#создает по умолчанию SHARED библиотеки
# set(BUILD_SHARED_LIBS yes)

# Static - указывает статическую библиотеку или архив. В Windows имя библиотеки по умолчанию будет
# targetName.lib, а на Unix-подобных платформах, как правило, libtargetName.a.

# Shared - указывает разделяемую или динамически подключаемую библиотеку. В Windows имя библиотеки по
# умолчанию будет targetName.dll, на платформах Apple - libtargetName.dylib, а на других Unix-подобных
# платформах обычно libtargetName.so. На платформах Apple разделяемые библиотеки также могут быть
# помечены как фреймворки, эта тема рассматривается в разделе 22.3, "Фреймворки".

# Module - определяет библиотеку, которая в некотором роде похожа на разделяемую библиотеку, но предназначена
# для динамической загрузки во время выполнения, а не для непосредственного связывания с библиотекой
# или исполняемым файлом. Обычно это подключаемые модули или дополнительные компоненты, которые
# пользователь может выбирать, загружать их или нет. На платформах Windows для DLL не создается
# библиотека импорта.

# add_library(targetName [STATIC | SHARED | MODULE]
#                        [EXCLUDE_FROM_ALL]
#                        source 1 [source2])

# Private - Частные зависимости указывают, что библиотека A использует библиотеку B в своей собственной
# внутренней реализации. Все остальное, что ссылается на библиотеку A, не обязано знать о B, потому что
# она является деталью внутренней реализации A.

# Public - Публичные зависимости указывают, что библиотека A не только использует библиотеку B внутри, но и
# использует B в своем интерфейсе. Это означает, что A нельзя использовать без B, поэтому все, что
# использует A, также будет иметь прямую зависимость от B. Примером может быть функция, определенная
# в библиотеке A, которая имеет по крайней мере один параметр типа, определенного и реализованного в
# библиотеке B, поэтому код не может вызвать функцию из A без предоставления параметра, тип которого
# получен из B.

# Interface - Интерфейсные зависимости указывают, что для использования библиотеки A необходимо также использовать
# часть библиотеки B. Это отличается от публичной зависимости тем, что библиотека A не требует B внутри, она
# использует B только в своем интерфейсе. Примером того, как это может быть полезно, является работа с
# целевыми библиотеками, определенными с помощью INTERFACE-формы add_library(), например, при
# использовании целевой библиотеки для представления зависимостей библиотеки только для заголовков (см.
# главу 16, Типы целевых библиотек).


# target_link_libraries(targetName
#                       <PRIVATE | PUBLIC | INTERFACE item1 [item2]>
#                       [<PRIVATE | PUBLIC | INTERFACE item3 [item4]>])

# add_library(collector src1.cpp)
# add_library(algo src2.cpp)
# add_library(engine src3.cpp)
# add_library(ui src4.cpp)
# add_executable(myApp main.cpp)
# target_link_libraries(collector
#                       PUBLIC  ui
#                       PRIVATE algo engine)
# target_link_libraries(myApp PRIVATE collector)

# Команда add_subdirectory() позволяет проекту включить в сборку еще один каталог. Этот каталог должен иметь
# свой собственный файл CMakeLists.txt, который будет обработан в момент вызова команды add_subdirectory(),
# и для него будет создан соответствующий каталог в дереве сборки проекта.
# add_subdirectory(srcDir [bin dir] [exclude_from_all])

# CMAKE_SOURCE_DIR
# Самый верхний каталог дерева исходных текстов (т.е. где находится самый верхний файл CMakeLists.txt).
# Эта переменная никогда не меняет своего значения.
# CMAKE_BINARY_DIR
# Самый верхний каталог дерева сборки. Эта переменная никогда не меняет своего значения.
# CMAKE_CURRENT_SOURCE_DIR
# Каталог файла CMakeLists.txt, который в данный момент обрабатывается CMake. Он обновляется каждый
# раз, когда новый файл обрабатывается в результате вызова add_subdirectory(), и восстанавливается
# обратно, когда обработка этого каталога завершена.
# CMAKE_CURRENT_BINARY_DIR
# Каталог сборки, соответствующий файлу CMakeLists.txt, который в данный момент обрабатывается CMake.
# Он изменяется при каждом вызове add_subdirectory() и восстанавливается при возврате add_subdirectory().

# add_library(targetName [STATIC | SHARED | MODULE | OBJECT]
#                        [EXCLUDE_FROM_ALL]
#                        source1 [source2])

# Общая библиотека будет создана, если указано ключевое слово SHARED или MODULE. Альтернативно, если не
# указано ключевое слово STATIC, SHARED, MODULE или OBJECT, будет создана разделяемая библиотека, если
# переменная BUILD_SHARED_LIBS имеет значение true во время вызова add_library()

# На большинстве платформ на базе Unix имя файла библиотеки STATIC или SHARED по умолчанию имеет
# приставку lib, в то время как MODULE может этого не делать

