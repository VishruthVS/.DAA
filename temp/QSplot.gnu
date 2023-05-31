set xlabel "n"
set ylabel "t"
plot "QSBest.txt" w l ti "Best Case", "QSWorst.txt" w l smooth bezier ti "Worst Case", "QSAvg.txt" w l ti "Average Case"
set term png
set output "QSG.png"
replot
set term x11