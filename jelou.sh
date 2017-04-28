x=`ls -l *.dat`

for a in $x
do
	./FCFS  < $a
done

echo "Done batch processing!!"
