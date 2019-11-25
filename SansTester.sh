color()(set -o pipefail;"$@" 2>&1>&3|sed $'s,.*,\e[31m&\e[m,'>&2)3>&1

clear
echo "
░░░░░░░░██████████████████
░░░░████░░░░░░░░░░░░░░░░░░████
░░██░░░░░░░░░░░░░░░░░░░░░░░░░░██
░░██░░░░░░░░░░░░░░░░░░░░░░░░░░██
██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██
██░░░░██████░░░░░░░░░░██████░░░░██
██░░░░██████░░░░░░░░░░██████░░░░██
██░░░░██████░░░░██░░░░██████░░░░██
░░██░░░░░░░░░░██████░░░░░░░░░░██
████░░██░░░░░░░░░░░░░░░░░░██░░████
██░░░░██████████████████████░░░░██
██░░░░░░██░░██░░██░░██░░██░░░░░░██
░░████░░░░██████████████░░░░████
░░░░░░████░░░░░░░░░░░░░░████
░░░░░░░░░░██████████████
"

echo "Oh hey, didya want to test your program? (Y/N)"
read answer
if [ "$answer" != "${answer#[Yy]}" ] ;then
	echo "Want me to test EVERYTHING? (Y/N)" 
else
	echo "Goodbye..."
	fi

read answer2
if [ "$answer2" != "${answer2#[Yy]}" ] ;then
    echo "Alright..." 
else
    echo "Farewell..."
	fi
sleep 1

clear
echo "
░░░░░░░░██████████████████
░░░░████░░░░░░░░░░░░░░░░░░████
░░██░░░░░░░░░░░░░░░░░░░░░░░░░░██
░░██░░░░░░░░░░░░░░░░░░░░░░░░░░██
██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██
██░░░░░░░░░░░░░░░░░░░░██████░░░░██
██░░░░░░░░░░░░░░░░░░░░██████░░░░██
██░░░░██████░░░░██░░░░██████░░░░██
░░██░░░░░░░░░░██████░░░░░░░░░░██
████░░██░░░░░░░░░░░░░░░░░░██░░████
██░░░░██████████████████████░░░░██
██░░░░░░██░░██░░██░░██░░██░░░░░░██
░░████░░░░██████████████░░░░████
░░░░░░████░░░░░░░░░░░░░░████
░░░░░░░░░░██████████████
"
echo "You're gonna have a bad time..."
sleep 1
clear

make -C FILE_TESTS/ && make -C FILE_TESTS/ testing

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
echo "TESTING WITH FILE INPUT"
echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"

echo "EMPTY FILE TEST"
./FILE_TESTS/test_gnl FILE_TESTS/empty_file

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 1


echo "SHORT FILE TEST"
./FILE_TESTS/test_gnl FILE_TESTS/short_file

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 1

echo "NEWLINES ONLY TEST!"
./FILE_TESTS/test_gnl FILE_TESTS/newlines_file

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 1

echo "MULTILINE FILE TEST!"
./FILE_TESTS/test_gnl FILE_TESTS/multiline_file

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 1

echo "NULL FILE TEST!"
./FILE_TESTS/test_gnl FILE_TESTS/NULL_file

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 1

echo "RANDOM FILE TEST!"
./FILE_TESTS/test_gnl FILE_TESTS/random_file

sleep 1
echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
echo "END OF TESTING"
echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
make -C FILE_TESTS/ fclean
