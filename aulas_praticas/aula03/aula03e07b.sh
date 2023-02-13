#!/bin/bash
# Calculate the sum of a series of numbers.
SCORE="0"
SUM="0"
MED="0"
COUNT="0"
while true; do
    echo -n "Enter your score [0-10] ('q' to quit, 'r' to restart): "
    read SCORE;
    COUNT=$((COUNT + 1))
    if (("$SCORE" < "0")) || (("$SCORE" > "10")); then
        echo "Try again: "
    elif [[ "$SCORE" == "q" ]]; then
        echo "Sum: $SUM."
        echo "Med: $MED."
        break
    elif [[ "$SCORE" == "r" ]]; then
        SCORE="0"
        SUM="0"
        MED="0"
        COUNT="0"
    else
        SUM=$((SUM + SCORE))
        MED=$((SUM / COUNT))
    fi
done
echo "Exiting."