set xlabel "n"
set ylabel "t"
plot "HSBest.txt" w l ti "Best Case", "HSWorst.txt" w l smooth bezier ti "Worst Case", "HSAvg.txt" w l ti "Average Case"
set term png
set output "HSG.png"
replot
set term x11