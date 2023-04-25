n1=5.5

n2=2.7
n3=`echo "scale=2; $n1 * $n2" | bc -l`

echo $n3
