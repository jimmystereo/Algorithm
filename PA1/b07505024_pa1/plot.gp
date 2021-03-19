numbers = 1000000



set autoscale y
set autoscale x
plot sprintf("./inputs/%i.case1.in",numbers) usi 1:2
plot sprintf("./outputs/%i.case1.out",numbers) usi 1:2
# if you want to save to png files
set terminal png
set output sprintf("./plots/%i.case1.out.png",numbers)
replot