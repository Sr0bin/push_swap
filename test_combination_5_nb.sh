for i in $(seq 1 120)
do
	line=$(head -n $i case.txt | tail -1)
	./push_swap $line | wc -l
done
