set yrange [0:*]
set xlabel "n"
set ylabel "t"
plot "SScount.txt" w l smooth bezier ti "SSort"
set term png
set output "SSG.png"
replot
set term x11