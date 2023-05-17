set yrange[0:*]
set xlabel "n"
set ylabel "t"
plot "SMBest.txt" w l ti "Best Case","SMAvg.txt" w l ti "Average Case", "SMWorst.txt" w l ti "Worst Case"
set term png
set output "SMG.png"
replot
set term x11