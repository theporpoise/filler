#!/usr/bin/
cd ../ && make
cd resources/

echo "\nas player 1, game map02, I am the O's\n"

./filler_vm -f maps/map02 -p1 ../filler -p2 players/carli.filler > file.txt
grep "== *" file.txt
echo ""
rm file.txt

./filler_vm -f maps/map02 -p1 ../filler -p2 players/carli.filler > file.txt
grep "== *" file.txt
echo ""
rm file.txt

./filler_vm -f maps/map02 -p1 ../filler -p2 players/carli.filler > file.txt
grep "== *" file.txt
echo ""
rm file.txt

./filler_vm -f maps/map02 -p1 ../filler -p2 players/carli.filler > file.txt
grep "== *" file.txt
echo ""
rm file.txt

./filler_vm -f maps/map02 -p1 ../filler -p2 players/carli.filler > file.txt
grep "== *" file.txt
echo ""
rm file.txt

echo "\nas player 2, game map02, I am the X's\n"

./filler_vm -f maps/map02 -p2 ../filler -p1 players/carli.filler > file.txt
grep "== *" file.txt
echo ""
rm file.txt

./filler_vm -f maps/map02 -p2 ../filler -p1 players/carli.filler > file.txt
grep "== *" file.txt
echo ""
rm file.txt

./filler_vm -f maps/map02 -p2 ../filler -p1 players/carli.filler > file.txt
grep "== *" file.txt
echo ""
rm file.txt

./filler_vm -f maps/map02 -p2 ../filler -p1 players/carli.filler > file.txt
grep "== *" file.txt
echo ""
rm file.txt

./filler_vm -f maps/map02 -p2 ../filler -p1 players/carli.filler > file.txt
grep "== *" file.txt
echo ""
rm file.txt



























