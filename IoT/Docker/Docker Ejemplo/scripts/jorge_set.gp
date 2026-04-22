set terminal png
set output 'output/jorge_set.png'
set title 'Grafica generada por Jorge'
set xlabel 'X'
set ylabel 'Y'
set grid
plot 'output/jorge_set.txt' using 1:2 with lines title 'y = x^2'
