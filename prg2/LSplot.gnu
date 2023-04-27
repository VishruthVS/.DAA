set yrange [0:*]
set xlabel "n"
set ylabel "t"
plot "LSBest.txt" w l ti "Best Case", "LSWorst.txt" w l smooth bezier ti "Worst Case", "LSAvg.txt" w l ti "Average Case"
set term png
set output "LSG.png"
replot
set term x11