 gcc -o main main.c
perf record -g ./main

# make graph
git clone https://github.com/brendangregg/FlameGraph.giti

perf script | ./FlameGraph/stackcollapse-perf.pl | ./FlameGraph/flamegraph.pl > out.svg

#除了 perf script 外，还可以使用 perf report 来查看和渲染结果。<F3>:w

perf report -n --stdio

https://mp.weixin.qq.com/s/A19RlLhSgbzw8UU4p1TZNA
