# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    fdf_few_files.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drafe <drafe@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 18:27:21 by drafe             #+#    #+#              #
#    Updated: 2019/08/23 18:16:39 by drafe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#make re;
#n=0;
#max=38;
#echo "\n  \n#################################\n"
#echo "          Start tests with errors:"
#while [ "$n" -le "$max" ]; do
#    echo "\n  error_$n:";
#    ./fillit ./tests/error_$n;
#    n=`expr "$n" + 1`;
#done
echo "\n  \n...................................\n"
echo "          Start valid FdF tests:";
n=0;
max=21;
while [ "$n" -le "$max" ]; do
    find maps/ -name '*.fdf' -exec ./fdf {} \;
    n=`expr "$n" + 1`;
done

#echo "\n  \n.......$%^&*$%^&*$%^&*$%^&*$%^&*$%^&*.......\n"
#echo "          Start random tests:";
#n=1;
#max=200;
#mkdir ./tests/rand_tests;
#while [ "$n" -le "$max" ]; do
#    ./rand_test.py | tee ./tests/rand_tests/rand_test_$n | tee -a ./tests/rand_tests/rand_out;
#    time ./fillit ./tests/rand_tests/rand_test_$n | tee -a ./tests/rand_tests/rand_out;
#    n=`expr "$n" + 1`;
#done
echo "\n  !!!Scrtipt:fdf_few_files.sh DONE!!!"
#//printf ("\ni=%d, off_s(-)=%d", i , off_s);
#//printf (" off_s(+)=%d", off_s);