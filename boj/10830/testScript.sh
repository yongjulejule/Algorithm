while true; do echo 3 > a; jot -r 1 10000000000000 >> a ; jot -r 9 >> a; cat a | ./a.out >my.log ; cat a | ./test > test.log; diff my.log test.log; done;
