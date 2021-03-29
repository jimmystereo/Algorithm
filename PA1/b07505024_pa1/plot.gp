numbers = 4000



set autoscale y
set autoscale x
plot sprintf("./outputs/QS%i.case1.out",numbers) usi 1:2
plot sprintf("./inputs/%i.case3.in",numbers) usi 1:2

# if you want to save to png files
set terminal png
set output sprintf("./plots/%i.case1.out.png",numbers)
replot