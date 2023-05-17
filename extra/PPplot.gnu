set yrange [0:*]
set xlabel "n"
set ylabel "t"
plot "PPcount.txt" w l ti "SSort"
set term png
set output "PPG.png"
replot
set term x11