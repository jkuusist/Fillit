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
sleep 0.5
clear

make -C Fillit fclean && make -C Fillit

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
echo "Testing Time!"
echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"

echo "1 Invalid"
./Fillit/fillit Test_Files_TBR!/1_INVALID

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 0.2


echo "1 No EOF"
./Fillit/fillit Test_Files_TBR!/1_NoEOF

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 0.2

echo "1 Valid"
./Fillit/fillit Test_Files_TBR!/1_Valid

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 0.2

echo "2_Invalid"
./Fillit/fillit Test_Files_TBR!/2_INVALID

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 0.2

echo "2 No EOF"
./Fillit/fillit Test_Files_TBR!/2_NoEoF

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 0.2

echo "2 Valid"
./Fillit/fillit Test_Files_TBR!/2_Valid

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 0.2

echo "3 INVALID"
./Fillit/fillit Test_Files_TBR!/3_INVALID

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 0.2

echo "3b INVALID"
./Fillit/fillit Test_Files_TBR!/3b_INVALID

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 0.2

echo "3 Valid"
./Fillit/fillit Test_Files_TBR!/3_Valid

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 0.2

echo "4 INVALID"
./Fillit/fillit Test_Files_TBR!/4_INVALID

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 0.2

echo "4 Valid"
./Fillit/fillit Test_Files_TBR!/4_Valid

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 0.2

echo "5 Valid"
./Fillit/fillit Test_Files_TBR!/5_Valid

echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
sleep 0.2

echo "26 Valid"
./Fillit/fillit Test_Files_TBR!/26_Valid

sleep 1
echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
echo "END OF TESTING"
echo "_,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,__,.-'~'-.,_"
make -C Fillit fclean
