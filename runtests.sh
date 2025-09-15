#!/bin/bash

make clean && make

if [[ ! -x mastermind ]]; then
    echo "mastermind file could not be compiled so tests cannot run"
    exit
fi

echo -e "1234" | ./mastermind 1234 | grep -i 'you win' >/dev/null
if [[ $? -ne 0 ]]; then
    echo "Test with secret 1234 and guess 1234 failed"
    exit
fi

echo -e "4321\n1212\n1234" | ./mastermind 1234 | grep -i 'you win' >/dev/null
if [[ $? -ne 0 ]]; then
    echo "Test with secret 1234 and guesses 4321,1212,1234 failed"
    exit
fi

echo -e "1111\n1243\n4321\n4433\n9876\n8765\n1234" | ./mastermind 1234 | grep -i 'you win' >/dev/null
if [[ $? -ne 0 ]]; then
    echo "Test with secret 1234 and guesses 1111,1234,4321,4433,9876,8765,1234 failed"
    exit
fi

echo "All tests pass, but the tests are not comprehensive!"
echo "Make sure your code really does what it should."
