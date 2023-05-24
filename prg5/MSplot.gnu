set xlabel "n"
set ylabel "t"
plot "MSBest.txt" w l ti "Best Case", "MSWorst.txt" w l smooth bezier ti "Worst Case", "MSAvg.txt" w l ti "Average Case"
set term png
set output "MSG.png"
replot
set term x11