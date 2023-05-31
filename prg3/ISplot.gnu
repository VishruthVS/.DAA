set yrange[-500:*]
set xlabel "n"
set ylabel "t"
plot "ISBest.txt" w l ti "Best Case", "ISWorst.txt" w l smooth bezier ti "Worst Case", "ISAvg.txt" w l ti "Average Case"
set term png
set output "ISG.png"
replot
set term x11