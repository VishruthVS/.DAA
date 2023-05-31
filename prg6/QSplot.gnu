set xlabel "n"
set ylabel "t"
plot "QSBest.txt" w lp ti "Best Case", "QSWorst.txt" w lp smooth bezier ti "Worst Case", "QSAvg.txt" w lp ti "Average Case"
set term png
set output "QSG.png"
replot
set term x11
