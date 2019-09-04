cat $1 | grep SC8T | awk '{print $1}' | sort | uniq -c | sort 

