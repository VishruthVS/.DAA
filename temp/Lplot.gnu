set yrange [0:]
set xlabel "n"
set ylabel "t"
plot "Lcount.txt" w l ti "Largest", "Ucount.txt" w l ti "Unique"
set term png
set output "LU.png"
replot
set term x11