#! /bin/bash

if [ $1 -eq 1 ]; then
    echo 0
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p01-airport1-p1.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p01-domain.pddl &> ./logs/airport_p01-airport1-p1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 0
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p02-airport1-p1.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p02-domain.pddl &> ./logs/airport_p02-airport1-p1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 0
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p03-airport1-p2.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p03-domain.pddl &> ./logs/airport_p03-airport1-p2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 1
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p04-airport2-p1.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p04-domain.pddl &> ./logs/airport_p04-airport2-p1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 1
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p05-airport2-p1.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p05-domain.pddl &> ./logs/airport_p05-airport2-p1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 1
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p06-airport2-p2.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p06-domain.pddl &> ./logs/airport_p06-airport2-p2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 1
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p07-airport2-p2.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p07-domain.pddl &> ./logs/airport_p07-airport2-p2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 2
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p08-airport2-p3.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p08-domain.pddl &> ./logs/airport_p08-airport2-p3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 2
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p09-airport2-p4.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p09-domain.pddl &> ./logs/airport_p09-airport2-p4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 2
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p10-airport3-p1.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p10-domain.pddl &> ./logs/airport_p10-airport3-p1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 2
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p11-airport3-p1.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p11-domain.pddl &> ./logs/airport_p11-airport3-p1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 3
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p12-airport3-p2.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p12-domain.pddl &> ./logs/airport_p12-airport3-p2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 3
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p13-airport3-p2.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p13-domain.pddl &> ./logs/airport_p13-airport3-p2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 3
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p14-airport3-p3.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p14-domain.pddl &> ./logs/airport_p14-airport3-p3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 3
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p15-airport3-p3.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p15-domain.pddl &> ./logs/airport_p15-airport3-p3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 4
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p16-airport3-p4.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p16-domain.pddl &> ./logs/airport_p16-airport3-p4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 4
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p17-airport3-p5.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p17-domain.pddl &> ./logs/airport_p17-airport3-p5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 4
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p18-airport3-p6.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p18-domain.pddl &> ./logs/airport_p18-airport3-p6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 4
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p19-airport3-p6.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p19-domain.pddl &> ./logs/airport_p19-airport3-p6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 5
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p20-airport3-p7.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p20-domain.pddl &> ./logs/airport_p20-airport3-p7_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 5
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p21-airport4halfMUC-p2.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p21-domain.pddl &> ./logs/airport_p21-airport4halfMUC-p2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 5
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p22-airport4halfMUC-p3.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p22-domain.pddl &> ./logs/airport_p22-airport4halfMUC-p3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 5
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p23-airport4halfMUC-p4.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p23-domain.pddl &> ./logs/airport_p23-airport4halfMUC-p4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 6
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p24-airport4halfMUC-p4.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p24-domain.pddl &> ./logs/airport_p24-airport4halfMUC-p4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 6
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p25-airport4halfMUC-p5.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p25-domain.pddl &> ./logs/airport_p25-airport4halfMUC-p5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 6
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p26-airport4halfMUC-p6.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p26-domain.pddl &> ./logs/airport_p26-airport4halfMUC-p6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 6
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p27-airport4halfMUC-p6.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p27-domain.pddl &> ./logs/airport_p27-airport4halfMUC-p6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 7
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p28-airport4halfMUC-p7.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p28-domain.pddl &> ./logs/airport_p28-airport4halfMUC-p7_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 7
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p29-airport4halfMUC-p8.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p29-domain.pddl &> ./logs/airport_p29-airport4halfMUC-p8_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 7
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p30-airport4halfMUC-p8.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p30-domain.pddl &> ./logs/airport_p30-airport4halfMUC-p8_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 7
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p31-airport4halfMUC-p9.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p31-domain.pddl &> ./logs/airport_p31-airport4halfMUC-p9_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 8
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p32-airport4halfMUC-p10.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p32-domain.pddl &> ./logs/airport_p32-airport4halfMUC-p10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 8
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p33-airport4halfMUC-p10.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p33-domain.pddl &> ./logs/airport_p33-airport4halfMUC-p10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 8
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p34-airport4halfMUC-p11.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p34-domain.pddl &> ./logs/airport_p34-airport4halfMUC-p11_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 8
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p35-airport4halfMUC-p12.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p35-domain.pddl &> ./logs/airport_p35-airport4halfMUC-p12_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 9
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p36-airport5MUC-p2.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p36-domain.pddl &> ./logs/airport_p36-airport5MUC-p2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 9
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p37-airport5MUC-p3.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p37-domain.pddl &> ./logs/airport_p37-airport5MUC-p3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 9
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p38-airport5MUC-p3.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p38-domain.pddl &> ./logs/airport_p38-airport5MUC-p3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 9
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p39-airport5MUC-p4.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p39-domain.pddl &> ./logs/airport_p39-airport5MUC-p4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 10
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p40-airport5MUC-p4.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p40-domain.pddl &> ./logs/airport_p40-airport5MUC-p4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 10
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p41-airport5MUC-p4.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p41-domain.pddl &> ./logs/airport_p41-airport5MUC-p4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 10
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p42-airport5MUC-p5.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p42-domain.pddl &> ./logs/airport_p42-airport5MUC-p5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 10
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p43-airport5MUC-p5.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p43-domain.pddl &> ./logs/airport_p43-airport5MUC-p5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 11
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p44-airport5MUC-p5.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p44-domain.pddl &> ./logs/airport_p44-airport5MUC-p5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 11
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p45-airport5MUC-p6.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p45-domain.pddl &> ./logs/airport_p45-airport5MUC-p6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 11
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p46-airport5MUC-p6.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p46-domain.pddl &> ./logs/airport_p46-airport5MUC-p6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 11
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p47-airport5MUC-p8.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p47-domain.pddl &> ./logs/airport_p47-airport5MUC-p8_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 12
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p48-airport5MUC-p9.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p48-domain.pddl &> ./logs/airport_p48-airport5MUC-p9_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 12
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p49-airport5MUC-p10.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p49-domain.pddl &> ./logs/airport_p49-airport5MUC-p10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 12
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/airport/p50-airport5MUC-p15.pddl /home/pommerening/projects/fastdownward/benchmarks/airport/p50-domain.pddl &> ./logs/airport_p50-airport5MUC-p15_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 12
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-10-0.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-10-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 13
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-10-1.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-10-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 13
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-10-2.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-10-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 13
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-11-0.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-11-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 13
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-11-1.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-11-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 14
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-11-2.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-11-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 14
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-12-0.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-12-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 14
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-12-1.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-12-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 14
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-13-0.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-13-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 15
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-13-1.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-13-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 15
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-14-0.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-14-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 15
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-14-1.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-14-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 15
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-15-0.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-15-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 16
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-15-1.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-15-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 16
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-16-1.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-16-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 16
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-16-2.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-16-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 16
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-17-0.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-17-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 17
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-4-0.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-4-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 17
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-4-1.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-4-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 17
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-4-2.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-4-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 17
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-5-0.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-5-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 18
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-5-1.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-5-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 18
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-5-2.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-5-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 18
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-6-0.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-6-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 18
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-6-1.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-6-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 19
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-6-2.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-6-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 19
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-7-0.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-7-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 19
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-7-1.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-7-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 19
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-7-2.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-7-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 20
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-8-0.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-8-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 20
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-8-1.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-8-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 20
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-8-2.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-8-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 20
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-9-0.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-9-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 21
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-9-1.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-9-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 21
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/blocks/probBLOCKS-9-2.pddl /home/pommerening/projects/fastdownward/benchmarks/blocks/domain.pddl &> ./logs/blocks_probBLOCKS-9-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 21
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile1 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 21
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile10 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 22
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile11 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile11_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 22
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile12 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile12_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 22
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile13 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile13_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 22
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile14 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile14_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 23
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile15 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile15_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 23
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile16 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile16_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 23
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile17 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile17_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 23
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile18 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile18_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 24
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile19 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile19_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 24
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile2 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 24
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile20 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 24
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile21 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile21_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 25
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile22 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile22_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 25
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile3 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 25
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile4 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 25
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile5 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 26
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile6 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 26
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile7 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile7_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 26
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile8 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile8_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 26
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/depot/pfile9 /home/pommerening/projects/fastdownward/benchmarks/depot/domain.pddl &> ./logs/depot_pfile9_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 27
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile1 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 27
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile10 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 27
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile11 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile11_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 27
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile12 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile12_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 28
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile13 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile13_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 28
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile14 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile14_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 28
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile15 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile15_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 28
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile16 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile16_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 29
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile17 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile17_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 29
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile18 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile18_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 29
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile19 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile19_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 29
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile2 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 30
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile20 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 30
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile3 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 30
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile4 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 30
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile5 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 31
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile6 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 31
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile7 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile7_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 31
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile8 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile8_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 31
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/driverlog/pfile9 /home/pommerening/projects/fastdownward/benchmarks/driverlog/domain.pddl &> ./logs/driverlog_pfile9_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 32
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile1 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 32
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile10 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 32
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile11 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile11_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 32
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile12 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile12_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 33
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile13 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile13_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 33
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile14 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile14_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 33
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile15 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile15_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 33
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile16 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile16_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 34
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile17 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile17_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 34
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile18 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile18_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 34
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile19 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile19_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 34
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile2 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 35
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile20 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 35
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile3 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 35
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile4 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 35
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile5 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 36
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile6 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 36
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile7 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile7_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 36
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile8 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile8_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 36
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/pfile9 /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_pfile9_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 37
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-10-1.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-10-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 37
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-10-2.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-10-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 37
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-10-3.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-10-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 37
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-10-4.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-10-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 38
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-10-5.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-10-5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 38
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-11-1.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-11-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 38
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-11-2.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-11-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 38
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-11-3.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-11-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 39
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-11-4.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-11-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 39
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-11-5.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-11-5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 39
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-12-1.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-12-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 39
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-12-2.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-12-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 40
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-12-3.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-12-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 40
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-12-4.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-12-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 40
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-12-5.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-12-5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 40
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-13-1.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-13-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 41
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-13-2.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-13-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 41
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-13-3.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-13-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 41
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-13-4.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-13-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 41
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-13-5.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-13-5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 42
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-2-1.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-2-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 42
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-2-2.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-2-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 42
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-2-3.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-2-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 42
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-2-4.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-2-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 43
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-2-5.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-2-5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 43
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-3-1.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-3-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 43
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-3-2.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-3-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 43
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-3-3.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-3-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 44
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-3-4.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-3-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 44
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-3-5.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-3-5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 44
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-4-1.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-4-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 44
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-4-2.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-4-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 45
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-4-3.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-4-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 45
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-4-4.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-4-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 45
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-4-5.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-4-5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 45
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-5-1.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-5-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 46
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-5-2.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-5-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 46
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-5-3.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-5-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 46
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-5-4.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-5-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 46
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-5-5.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-5-5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 47
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-6-1.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-6-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 47
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-6-2.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-6-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 47
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-6-3.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-6-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 47
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-6-4.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-6-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 48
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-6-5.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-6-5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 48
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-7-1.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-7-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 48
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-7-2.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-7-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 48
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-7-3.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-7-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 49
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-7-4.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-7-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 49
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-7-5.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-7-5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 49
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-8-1.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-8-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 49
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-8-2.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-8-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 50
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-8-3.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-8-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 50
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-8-4.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-8-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 50
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-8-5.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-8-5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 50
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-9-1.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-9-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 51
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-9-2.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-9-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 51
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-9-3.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-9-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 51
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-9-4.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-9-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 51
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/freecell/probfreecell-9-5.pddl /home/pommerening/projects/fastdownward/benchmarks/freecell/domain.pddl &> ./logs/freecell_probfreecell-9-5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 52
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob01.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob01_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 52
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob02.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob02_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 52
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob03.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob03_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 52
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob04.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob04_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 53
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob05.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob05_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 53
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob06.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob06_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 53
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob07.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob07_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 53
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob08.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob08_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 54
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob09.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob09_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 54
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob10.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 54
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob11.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob11_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 54
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob12.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob12_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 55
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob13.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob13_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 55
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob14.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob14_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 55
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob15.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob15_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 55
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob16.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob16_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 56
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob17.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob17_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 56
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob18.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob18_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 56
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob19.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob19_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 56
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/gripper/prob20.pddl /home/pommerening/projects/fastdownward/benchmarks/gripper/domain.pddl &> ./logs/gripper_prob20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 57
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-10-0.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-10-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 57
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-10-1.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-10-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 57
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-11-0.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-11-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 57
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-11-1.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-11-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 58
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-12-0.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-12-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 58
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-12-1.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-12-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 58
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-13-0.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-13-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 58
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-13-1.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-13-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 59
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-14-0.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-14-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 59
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-14-1.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-14-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 59
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-15-0.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-15-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 59
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-15-1.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-15-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 60
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-4-0.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-4-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 60
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-4-1.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-4-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 60
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-4-2.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-4-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 60
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-5-0.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-5-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 61
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-5-1.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-5-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 61
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-5-2.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-5-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 61
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-6-0.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-6-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 61
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-6-1.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-6-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 62
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-6-2.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-6-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 62
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-6-9.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-6-9_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 62
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-7-0.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-7-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 62
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-7-1.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-7-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 63
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-8-0.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-8-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 63
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-8-1.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-8-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 63
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-9-0.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-9-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 63
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics00/probLOGISTICS-9-1.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics00/domain.pddl &> ./logs/logistics00_probLOGISTICS-9-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 64
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob01.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob01_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 64
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob02.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob02_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 64
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob03.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob03_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 64
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob04.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob04_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 65
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob05.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob05_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 65
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob06.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob06_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 65
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob07.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob07_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 65
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob08.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob08_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 66
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob09.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob09_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 66
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob10.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 66
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob11.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob11_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 66
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob12.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob12_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 67
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob13.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob13_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 67
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob14.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob14_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 67
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob15.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob15_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 67
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob16.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob16_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 68
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob17.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob17_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 68
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob18.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob18_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 68
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob19.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob19_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 68
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob20.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 69
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob21.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob21_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 69
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob22.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob22_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 69
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob23.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob23_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 69
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob24.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob24_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 70
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob25.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob25_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 70
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob26.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob26_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 70
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob27.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob27_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 70
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob28.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob28_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 71
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob29.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob29_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 71
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob30.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 71
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob31.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob31_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 71
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob32.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob32_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 72
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob33.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob33_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 72
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob34.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob34_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 72
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/logistics98/prob35.pddl /home/pommerening/projects/fastdownward/benchmarks/logistics98/domain.pddl &> ./logs/logistics98_prob35_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 72
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s1-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s1-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 73
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s1-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s1-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 73
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s1-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s1-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 73
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s1-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s1-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 73
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s1-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s1-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 74
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s10-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s10-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 74
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s10-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s10-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 74
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s10-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s10-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 74
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s10-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s10-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 75
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s10-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s10-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 75
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s11-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s11-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 75
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s11-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s11-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 75
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s11-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s11-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 76
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s11-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s11-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 76
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s11-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s11-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 76
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s12-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s12-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 76
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s12-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s12-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 77
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s12-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s12-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 77
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s12-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s12-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 77
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s12-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s12-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 77
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s13-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s13-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 78
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s13-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s13-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 78
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s13-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s13-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 78
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s13-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s13-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 78
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s13-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s13-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 79
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s14-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s14-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 79
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s14-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s14-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 79
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s14-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s14-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 79
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s14-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s14-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 80
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s14-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s14-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 80
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s15-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s15-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 80
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s15-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s15-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 80
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s15-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s15-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 81
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s15-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s15-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 81
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s15-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s15-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 81
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s16-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s16-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 81
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s16-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s16-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 82
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s16-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s16-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 82
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s16-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s16-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 82
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s16-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s16-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 82
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s17-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s17-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 83
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s17-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s17-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 83
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s17-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s17-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 83
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s17-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s17-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 83
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s17-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s17-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 84
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s18-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s18-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 84
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s18-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s18-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 84
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s18-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s18-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 84
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s18-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s18-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 85
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s18-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s18-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 85
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s19-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s19-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 85
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s19-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s19-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 85
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s19-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s19-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 86
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s19-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s19-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 86
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s19-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s19-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 86
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s2-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s2-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 86
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s2-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s2-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 87
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s2-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s2-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 87
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s2-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s2-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 87
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s2-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s2-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 87
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s20-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s20-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 88
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s20-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s20-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 88
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s20-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s20-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 88
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s20-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s20-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 88
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s20-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s20-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 89
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s21-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s21-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 89
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s21-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s21-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 89
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s21-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s21-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 89
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s21-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s21-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 90
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s21-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s21-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 90
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s22-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s22-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 90
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s22-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s22-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 90
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s22-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s22-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 91
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s22-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s22-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 91
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s22-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s22-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 91
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s23-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s23-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 91
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s23-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s23-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 92
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s23-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s23-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 92
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s23-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s23-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 92
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s23-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s23-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 92
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s24-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s24-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 93
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s24-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s24-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 93
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s24-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s24-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 93
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s24-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s24-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 93
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s24-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s24-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 94
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s25-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s25-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 94
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s25-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s25-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 94
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s25-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s25-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 94
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s25-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s25-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 95
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s25-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s25-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 95
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s26-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s26-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 95
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s26-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s26-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 95
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s26-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s26-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 96
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s26-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s26-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 96
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s26-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s26-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 96
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s27-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s27-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 96
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s27-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s27-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 97
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s27-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s27-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 97
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s27-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s27-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 97
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s27-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s27-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 97
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s28-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s28-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 98
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s28-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s28-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 98
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s28-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s28-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 98
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s28-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s28-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 98
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s28-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s28-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 99
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s29-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s29-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 99
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s29-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s29-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 99
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s29-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s29-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 99
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s29-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s29-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 100
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s29-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s29-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 100
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s3-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s3-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 100
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s3-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s3-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 100
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s3-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s3-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 101
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s3-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s3-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 101
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s3-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s3-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 101
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s30-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s30-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 101
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s30-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s30-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 102
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s30-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s30-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 102
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s30-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s30-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 102
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s30-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s30-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 102
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s4-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s4-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 103
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s4-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s4-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 103
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s4-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s4-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 103
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s4-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s4-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 103
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s4-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s4-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 104
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s5-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s5-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 104
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s5-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s5-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 104
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s5-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s5-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 104
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s5-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s5-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 105
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s5-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s5-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 105
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s6-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s6-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 105
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s6-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s6-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 105
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s6-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s6-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 106
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s6-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s6-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 106
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s6-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s6-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 106
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s7-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s7-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 106
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s7-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s7-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 107
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s7-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s7-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 107
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s7-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s7-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 107
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s7-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s7-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 107
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s8-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s8-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 108
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s8-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s8-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 108
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s8-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s8-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 108
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s8-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s8-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 108
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s8-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s8-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 109
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s9-0.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s9-0_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 109
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s9-1.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s9-1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 109
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s9-2.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s9-2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 109
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s9-3.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s9-3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 110
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/miconic/s9-4.pddl /home/pommerening/projects/fastdownward/benchmarks/miconic/domain.pddl &> ./logs/miconic_s9-4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 110
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob01.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob01_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 110
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob02.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob02_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 110
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob03.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob03_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 111
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob04.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob04_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 111
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob05.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob05_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 111
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob06.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob06_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 111
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob07.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob07_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 112
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob08.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob08_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 112
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob09.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob09_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 112
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob10.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 112
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob11.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob11_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 113
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob12.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob12_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 113
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob13.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob13_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 113
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob14.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob14_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 113
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob15.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob15_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 114
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob16.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob16_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 114
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob17.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob17_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 114
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob18.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob18_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 114
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob19.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob19_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 115
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob20.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 115
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob21.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob21_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 115
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob22.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob22_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 115
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob23.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob23_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 116
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob24.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob24_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 116
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob25.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob25_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 116
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob26.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob26_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 116
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob27.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob27_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 117
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob28.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob28_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 117
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob29.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob29_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 117
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob30.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 117
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob31.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob31_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 118
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob32.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob32_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 118
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob33.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob33_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 118
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob34.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob34_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 118
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mprime/prob35.pddl /home/pommerening/projects/fastdownward/benchmarks/mprime/domain.pddl &> ./logs/mprime_prob35_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 119
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob01.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob01_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 119
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob02.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob02_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 119
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob03.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob03_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 119
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob04.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob04_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 120
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob05.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob05_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 120
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob06.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob06_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 120
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob07.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob07_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 120
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob08.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob08_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 121
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob09.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob09_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 121
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob10.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 121
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob11.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob11_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 121
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob12.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob12_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 122
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob13.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob13_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 122
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob14.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob14_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 122
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob15.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob15_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 122
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob16.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob16_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 123
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob17.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob17_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 123
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob18.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob18_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 123
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob19.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob19_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 123
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob20.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 124
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob21.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob21_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 124
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob22.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob22_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 124
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob23.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob23_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 124
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob24.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob24_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 125
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob25.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob25_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 125
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob26.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob26_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 125
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob27.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob27_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 125
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob28.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob28_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 126
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob29.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob29_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 126
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/mystery/prob30.pddl /home/pommerening/projects/fastdownward/benchmarks/mystery/domain.pddl &> ./logs/mystery_prob30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 126
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p01.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p01.pddl &> ./logs/openstacks-strips_p01_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 126
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p02.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p02.pddl &> ./logs/openstacks-strips_p02_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 127
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p03.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p03.pddl &> ./logs/openstacks-strips_p03_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 127
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p04.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p04.pddl &> ./logs/openstacks-strips_p04_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 127
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p05.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p05.pddl &> ./logs/openstacks-strips_p05_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 127
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p06.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p06.pddl &> ./logs/openstacks-strips_p06_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 128
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p07.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p07.pddl &> ./logs/openstacks-strips_p07_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 128
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p08.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p08.pddl &> ./logs/openstacks-strips_p08_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 128
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p09.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p09.pddl &> ./logs/openstacks-strips_p09_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 128
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p10.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p10.pddl &> ./logs/openstacks-strips_p10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 129
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p11.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p11.pddl &> ./logs/openstacks-strips_p11_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 129
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p12.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p12.pddl &> ./logs/openstacks-strips_p12_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 129
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p13.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p13.pddl &> ./logs/openstacks-strips_p13_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 129
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p14.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p14.pddl &> ./logs/openstacks-strips_p14_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 130
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p15.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p15.pddl &> ./logs/openstacks-strips_p15_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 130
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p16.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p16.pddl &> ./logs/openstacks-strips_p16_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 130
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p17.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p17.pddl &> ./logs/openstacks-strips_p17_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 130
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p18.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p18.pddl &> ./logs/openstacks-strips_p18_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 131
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p19.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p19.pddl &> ./logs/openstacks-strips_p19_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 131
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p20.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p20.pddl &> ./logs/openstacks-strips_p20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 131
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p21.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p21.pddl &> ./logs/openstacks-strips_p21_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 131
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p22.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p22.pddl &> ./logs/openstacks-strips_p22_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 132
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p23.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p23.pddl &> ./logs/openstacks-strips_p23_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 132
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p24.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p24.pddl &> ./logs/openstacks-strips_p24_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 132
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p25.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p25.pddl &> ./logs/openstacks-strips_p25_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 132
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p26.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p26.pddl &> ./logs/openstacks-strips_p26_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 133
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p27.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p27.pddl &> ./logs/openstacks-strips_p27_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 133
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p28.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p28.pddl &> ./logs/openstacks-strips_p28_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 133
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p29.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p29.pddl &> ./logs/openstacks-strips_p29_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 133
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/p30.pddl /home/pommerening/projects/fastdownward/benchmarks/openstacks-strips/domain_p30.pddl &> ./logs/openstacks-strips_p30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 134
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p01.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p01.pddl &> ./logs/pathways-noneg_p01_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 134
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p02.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p02.pddl &> ./logs/pathways-noneg_p02_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 134
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p03.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p03.pddl &> ./logs/pathways-noneg_p03_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 134
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p04.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p04.pddl &> ./logs/pathways-noneg_p04_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 135
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p05.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p05.pddl &> ./logs/pathways-noneg_p05_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 135
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p06.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p06.pddl &> ./logs/pathways-noneg_p06_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 135
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p07.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p07.pddl &> ./logs/pathways-noneg_p07_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 135
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p08.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p08.pddl &> ./logs/pathways-noneg_p08_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 136
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p09.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p09.pddl &> ./logs/pathways-noneg_p09_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 136
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p10.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p10.pddl &> ./logs/pathways-noneg_p10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 136
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p11.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p11.pddl &> ./logs/pathways-noneg_p11_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 136
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p12.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p12.pddl &> ./logs/pathways-noneg_p12_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 137
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p13.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p13.pddl &> ./logs/pathways-noneg_p13_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 137
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p14.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p14.pddl &> ./logs/pathways-noneg_p14_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 137
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p15.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p15.pddl &> ./logs/pathways-noneg_p15_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 137
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p16.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p16.pddl &> ./logs/pathways-noneg_p16_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 138
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p17.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p17.pddl &> ./logs/pathways-noneg_p17_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 138
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p18.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p18.pddl &> ./logs/pathways-noneg_p18_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 138
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p19.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p19.pddl &> ./logs/pathways-noneg_p19_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 138
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p20.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p20.pddl &> ./logs/pathways-noneg_p20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 139
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p21.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p21.pddl &> ./logs/pathways-noneg_p21_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 139
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p22.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p22.pddl &> ./logs/pathways-noneg_p22_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 139
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p23.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p23.pddl &> ./logs/pathways-noneg_p23_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 139
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p24.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p24.pddl &> ./logs/pathways-noneg_p24_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 140
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p25.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p25.pddl &> ./logs/pathways-noneg_p25_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 140
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p26.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p26.pddl &> ./logs/pathways-noneg_p26_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 140
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p27.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p27.pddl &> ./logs/pathways-noneg_p27_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 140
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p28.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p28.pddl &> ./logs/pathways-noneg_p28_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 141
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p29.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p29.pddl &> ./logs/pathways-noneg_p29_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 141
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/p30.pddl /home/pommerening/projects/fastdownward/benchmarks/pathways-noneg/domain_p30.pddl &> ./logs/pathways-noneg_p30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 141
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p01-net1-b6-g2.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p01-net1-b6-g2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 141
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p02-net1-b6-g4.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p02-net1-b6-g4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 142
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p03-net1-b8-g3.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p03-net1-b8-g3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 142
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p04-net1-b8-g5.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p04-net1-b8-g5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 142
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p05-net1-b10-g4.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p05-net1-b10-g4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 142
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p06-net1-b10-g6.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p06-net1-b10-g6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 143
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p07-net1-b12-g5.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p07-net1-b12-g5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 143
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p08-net1-b12-g7.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p08-net1-b12-g7_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 143
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p09-net1-b14-g6.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p09-net1-b14-g6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 143
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p10-net1-b14-g8.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p10-net1-b14-g8_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 144
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p11-net2-b10-g2.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p11-net2-b10-g2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 144
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p12-net2-b10-g4.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p12-net2-b10-g4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 144
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p13-net2-b12-g3.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p13-net2-b12-g3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 144
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p14-net2-b12-g5.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p14-net2-b12-g5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 145
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p15-net2-b14-g4.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p15-net2-b14-g4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 145
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p16-net2-b14-g6.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p16-net2-b14-g6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 145
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p17-net2-b16-g5.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p17-net2-b16-g5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 145
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p18-net2-b16-g7.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p18-net2-b16-g7_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 146
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p19-net2-b18-g6.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p19-net2-b18-g6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 146
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p20-net2-b18-g8.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p20-net2-b18-g8_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 146
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p21-net3-b12-g2.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p21-net3-b12-g2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 146
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p22-net3-b12-g4.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p22-net3-b12-g4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 147
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p23-net3-b14-g3.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p23-net3-b14-g3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 147
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p24-net3-b14-g5.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p24-net3-b14-g5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 147
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p25-net3-b16-g5.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p25-net3-b16-g5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 147
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p26-net3-b16-g7.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p26-net3-b16-g7_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 148
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p27-net3-b18-g6.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p27-net3-b18-g6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 148
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p28-net3-b18-g7.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p28-net3-b18-g7_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 148
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p29-net3-b20-g6.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p29-net3-b20-g6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 148
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p30-net3-b20-g8.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p30-net3-b20-g8_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 149
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p31-net4-b14-g3.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p31-net4-b14-g3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 149
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p32-net4-b14-g5.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p32-net4-b14-g5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 149
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p33-net4-b16-g5.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p33-net4-b16-g5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 149
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p34-net4-b16-g6.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p34-net4-b16-g6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 150
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p35-net4-b18-g4.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p35-net4-b18-g4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 150
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p36-net4-b18-g6.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p36-net4-b18-g6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 150
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p37-net4-b20-g5.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p37-net4-b20-g5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 150
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p38-net4-b20-g7.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p38-net4-b20-g7_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 151
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p39-net4-b22-g7.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p39-net4-b22-g7_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 151
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p40-net4-b22-g8.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p40-net4-b22-g8_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 151
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p41-net5-b22-g2.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p41-net5-b22-g2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 151
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p42-net5-b22-g4.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p42-net5-b22-g4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 152
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p43-net5-b24-g3.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p43-net5-b24-g3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 152
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p44-net5-b24-g5.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p44-net5-b24-g5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 152
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p45-net5-b26-g4.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p45-net5-b26-g4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 152
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p46-net5-b26-g6.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p46-net5-b26-g6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 153
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p47-net5-b28-g5.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p47-net5-b28-g5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 153
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p48-net5-b28-g7.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p48-net5-b28-g7_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 153
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p49-net5-b30-g6.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p49-net5-b30-g6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 153
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/p50-net5-b30-g8.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-notankage/domain.pddl &> ./logs/pipesworld-notankage_p50-net5-b30-g8_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 154
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p01-net1-b6-g2-t50.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p01-net1-b6-g2-t50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 154
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p02-net1-b6-g4-t50.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p02-net1-b6-g4-t50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 154
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p03-net1-b8-g3-t80.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p03-net1-b8-g3-t80_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 154
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p04-net1-b8-g5-t80.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p04-net1-b8-g5-t80_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 155
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p05-net1-b10-g4-t50.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p05-net1-b10-g4-t50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 155
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p06-net1-b10-g6-t50.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p06-net1-b10-g6-t50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 155
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p07-net1-b12-g5-t80.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p07-net1-b12-g5-t80_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 155
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p08-net1-b12-g7-t80.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p08-net1-b12-g7-t80_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 156
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p09-net1-b14-g6-t50.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p09-net1-b14-g6-t50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 156
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p10-net1-b14-g8-t50.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p10-net1-b14-g8-t50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 156
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p11-net2-b10-g2-t30.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p11-net2-b10-g2-t30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 156
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p12-net2-b10-g4-t60.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p12-net2-b10-g4-t60_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 157
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p13-net2-b12-g3-t70.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p13-net2-b12-g3-t70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 157
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p14-net2-b12-g5-t30.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p14-net2-b12-g5-t30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 157
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p15-net2-b14-g4-t30.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p15-net2-b14-g4-t30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 157
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p16-net2-b14-g6-t80.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p16-net2-b14-g6-t80_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 158
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p17-net2-b16-g5-t20.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p17-net2-b16-g5-t20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 158
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p18-net2-b16-g7-t60.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p18-net2-b16-g7-t60_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 158
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p19-net2-b18-g6-t60.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p19-net2-b18-g6-t60_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 158
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p20-net2-b18-g8-t90.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p20-net2-b18-g8-t90_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 159
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p21-net3-b12-g2-t60.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p21-net3-b12-g2-t60_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 159
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p22-net3-b12-g4-t60.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p22-net3-b12-g4-t60_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 159
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p23-net3-b14-g3-t60.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p23-net3-b14-g3-t60_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 159
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p24-net3-b14-g5-t60.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p24-net3-b14-g5-t60_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 160
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p25-net3-b16-g5-t60.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p25-net3-b16-g5-t60_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 160
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p26-net3-b16-g7-t70.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p26-net3-b16-g7-t70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 160
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p27-net3-b18-g6-t70.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p27-net3-b18-g6-t70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 160
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p28-net3-b18-g7-t70.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p28-net3-b18-g7-t70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 161
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p29-net3-b20-g6-t70.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p29-net3-b20-g6-t70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 161
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p30-net3-b20-g8-t70.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p30-net3-b20-g8-t70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 161
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p31-net4-b14-g3-t20.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p31-net4-b14-g3-t20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 161
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p32-net4-b14-g5-t30.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p32-net4-b14-g5-t30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 162
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p33-net4-b16-g5-t60.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p33-net4-b16-g5-t60_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 162
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p34-net4-b16-g6-t60.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p34-net4-b16-g6-t60_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 162
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p35-net4-b18-g4-t90.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p35-net4-b18-g4-t90_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 162
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p36-net4-b18-g6-t90.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p36-net4-b18-g6-t90_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 163
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p37-net4-b20-g5-t60.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p37-net4-b20-g5-t60_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 163
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p38-net4-b20-g7-t60.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p38-net4-b20-g7-t60_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 163
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p39-net4-b22-g7-t50.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p39-net4-b22-g7-t50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 163
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p40-net4-b22-g8-t50.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p40-net4-b22-g8-t50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 164
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p41-net5-b22-g2-t20.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p41-net5-b22-g2-t20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 164
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p42-net5-b22-g4-t50.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p42-net5-b22-g4-t50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 164
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p43-net5-b24-g3-t80.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p43-net5-b24-g3-t80_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 164
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p44-net5-b24-g5-t80.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p44-net5-b24-g5-t80_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 165
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p45-net5-b26-g4-t50.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p45-net5-b26-g4-t50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 165
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p46-net5-b26-g6-t50.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p46-net5-b26-g6-t50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 165
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p47-net5-b28-g5-t50.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p47-net5-b28-g5-t50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 165
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p48-net5-b28-g7-t50.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p48-net5-b28-g7-t50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 166
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p49-net5-b30-g6-t50.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p49-net5-b30-g6-t50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 166
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/p50-net5-b30-g8-t50.pddl /home/pommerening/projects/fastdownward/benchmarks/pipesworld-tankage/domain.pddl &> ./logs/pipesworld-tankage_p50-net5-b30-g8-t50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 166
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p01-s2-n1-l2-f50.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p01-domain.pddl &> ./logs/psr-small_p01-s2-n1-l2-f50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 166
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p02-s5-n1-l3-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p02-domain.pddl &> ./logs/psr-small_p02-s5-n1-l3-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 167
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p03-s7-n1-l3-f70.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p03-domain.pddl &> ./logs/psr-small_p03-s7-n1-l3-f70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 167
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p04-s8-n1-l4-f10.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p04-domain.pddl &> ./logs/psr-small_p04-s8-n1-l4-f10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 167
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p05-s9-n1-l4-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p05-domain.pddl &> ./logs/psr-small_p05-s9-n1-l4-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 167
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p06-s10-n1-l4-f50.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p06-domain.pddl &> ./logs/psr-small_p06-s10-n1-l4-f50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 168
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p07-s11-n1-l4-f70.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p07-domain.pddl &> ./logs/psr-small_p07-s11-n1-l4-f70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 168
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p08-s12-n1-l5-f10.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p08-domain.pddl &> ./logs/psr-small_p08-s12-n1-l5-f10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 168
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p09-s13-n1-l5-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p09-domain.pddl &> ./logs/psr-small_p09-s13-n1-l5-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 168
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p10-s17-n2-l2-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p10-domain.pddl &> ./logs/psr-small_p10-s17-n2-l2-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 169
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p11-s18-n2-l2-f50.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p11-domain.pddl &> ./logs/psr-small_p11-s18-n2-l2-f50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 169
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p12-s21-n2-l3-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p12-domain.pddl &> ./logs/psr-small_p12-s21-n2-l3-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 169
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p13-s22-n2-l3-f50.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p13-domain.pddl &> ./logs/psr-small_p13-s22-n2-l3-f50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 169
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p14-s23-n2-l3-f70.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p14-domain.pddl &> ./logs/psr-small_p14-s23-n2-l3-f70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 170
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p15-s24-n2-l4-f10.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p15-domain.pddl &> ./logs/psr-small_p15-s24-n2-l4-f10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 170
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p16-s29-n2-l5-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p16-domain.pddl &> ./logs/psr-small_p16-s29-n2-l5-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 170
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p17-s30-n2-l5-f50.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p17-domain.pddl &> ./logs/psr-small_p17-s30-n2-l5-f50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 170
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p18-s31-n2-l5-f70.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p18-domain.pddl &> ./logs/psr-small_p18-s31-n2-l5-f70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 171
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p19-s33-n3-l2-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p19-domain.pddl &> ./logs/psr-small_p19-s33-n3-l2-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 171
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p20-s34-n3-l2-f50.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p20-domain.pddl &> ./logs/psr-small_p20-s34-n3-l2-f50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 171
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p21-s35-n3-l2-f70.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p21-domain.pddl &> ./logs/psr-small_p21-s35-n3-l2-f70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 171
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p22-s37-n3-l3-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p22-domain.pddl &> ./logs/psr-small_p22-s37-n3-l3-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 172
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p23-s38-n3-l3-f50.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p23-domain.pddl &> ./logs/psr-small_p23-s38-n3-l3-f50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 172
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p24-s39-n3-l3-f70.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p24-domain.pddl &> ./logs/psr-small_p24-s39-n3-l3-f70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 172
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p25-s40-n3-l4-f10.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p25-domain.pddl &> ./logs/psr-small_p25-s40-n3-l4-f10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 172
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p26-s41-n3-l4-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p26-domain.pddl &> ./logs/psr-small_p26-s41-n3-l4-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 173
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p27-s42-n3-l4-f50.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p27-domain.pddl &> ./logs/psr-small_p27-s42-n3-l4-f50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 173
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p28-s43-n3-l4-f70.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p28-domain.pddl &> ./logs/psr-small_p28-s43-n3-l4-f70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 173
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p29-s45-n3-l5-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p29-domain.pddl &> ./logs/psr-small_p29-s45-n3-l5-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 173
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p30-s46-n3-l5-f50.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p30-domain.pddl &> ./logs/psr-small_p30-s46-n3-l5-f50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 174
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p31-s49-n4-l2-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p31-domain.pddl &> ./logs/psr-small_p31-s49-n4-l2-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 174
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p32-s50-n4-l2-f50.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p32-domain.pddl &> ./logs/psr-small_p32-s50-n4-l2-f50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 174
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p33-s51-n4-l2-f70.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p33-domain.pddl &> ./logs/psr-small_p33-s51-n4-l2-f70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 174
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p34-s55-n4-l3-f70.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p34-domain.pddl &> ./logs/psr-small_p34-s55-n4-l3-f70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 175
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p35-s57-n5-l2-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p35-domain.pddl &> ./logs/psr-small_p35-s57-n5-l2-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 175
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p36-s65-n6-l2-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p36-domain.pddl &> ./logs/psr-small_p36-s65-n6-l2-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 175
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p37-s67-n6-l2-f70.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p37-domain.pddl &> ./logs/psr-small_p37-s67-n6-l2-f70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 175
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p38-s78-n3-l3-f50.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p38-domain.pddl &> ./logs/psr-small_p38-s78-n3-l3-f50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 176
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p39-s79-n3-l3-f70.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p39-domain.pddl &> ./logs/psr-small_p39-s79-n3-l3-f70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 176
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p40-s80-n3-l4-f10.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p40-domain.pddl &> ./logs/psr-small_p40-s80-n3-l4-f10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 176
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p41-s81-n3-l4-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p41-domain.pddl &> ./logs/psr-small_p41-s81-n3-l4-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 176
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p42-s82-n3-l4-f50.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p42-domain.pddl &> ./logs/psr-small_p42-s82-n3-l4-f50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 177
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p43-s83-n3-l4-f70.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p43-domain.pddl &> ./logs/psr-small_p43-s83-n3-l4-f70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 177
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p44-s89-n4-l2-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p44-domain.pddl &> ./logs/psr-small_p44-s89-n4-l2-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 177
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p45-s94-n4-l3-f50.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p45-domain.pddl &> ./logs/psr-small_p45-s94-n4-l3-f50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 177
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p46-s97-n5-l2-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p46-domain.pddl &> ./logs/psr-small_p46-s97-n5-l2-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 178
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p47-s98-n5-l2-f50.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p47-domain.pddl &> ./logs/psr-small_p47-s98-n5-l2-f50_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 178
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p48-s101-n5-l3-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p48-domain.pddl &> ./logs/psr-small_p48-s101-n5-l3-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 178
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p49-s105-n6-l2-f30.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p49-domain.pddl &> ./logs/psr-small_p49-s105-n6-l2-f30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 178
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/psr-small/p50-s107-n6-l2-f70.pddl /home/pommerening/projects/fastdownward/benchmarks/psr-small/p50-domain.pddl &> ./logs/psr-small_p50-s107-n6-l2-f70_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 179
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p01.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p01_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 179
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p02.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p02_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 179
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p03.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p03_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 179
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p04.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p04_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 180
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p05.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p05_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 180
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p06.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p06_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 180
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p07.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p07_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 180
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p08.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p08_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 181
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p09.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p09_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 181
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p10.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 181
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p11.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p11_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 181
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p12.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p12_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 182
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p13.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p13_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 182
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p14.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p14_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 182
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p15.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p15_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 182
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p16.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p16_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 183
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p17.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p17_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 183
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p18.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p18_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 183
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p19.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p19_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 183
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p20.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 184
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p21.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p21_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 184
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p22.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p22_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 184
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p23.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p23_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 184
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p24.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p24_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 185
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p25.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p25_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 185
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p26.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p26_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 185
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p27.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p27_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 185
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p28.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p28_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 186
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p29.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p29_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 186
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p30.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 186
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p31.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p31_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 186
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p32.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p32_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 187
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p33.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p33_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 187
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p34.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p34_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 187
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p35.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p35_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 187
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p36.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p36_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 188
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p37.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p37_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 188
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p38.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p38_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 188
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p39.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p39_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 188
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/rovers/p40.pddl /home/pommerening/projects/fastdownward/benchmarks/rovers/domain.pddl &> ./logs/rovers_p40_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 189
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p01.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p01_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 189
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p02.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p02_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 189
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p03.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p03_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 189
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p04.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p04_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 190
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p05.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p05_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 190
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p06.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p06_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 190
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p07.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p07_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 190
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p08.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p08_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 191
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p09.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p09_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 191
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p10.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 191
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p11.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p11_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 191
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p12.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p12_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 192
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p13.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p13_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 192
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p14.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p14_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 192
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p15.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p15_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 192
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p16.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p16_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 193
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p17.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p17_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 193
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p18.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p18_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 193
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p19.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p19_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 193
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p20.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 194
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p21.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p21_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 194
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p22.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p22_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 194
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p23.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p23_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 194
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p24.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p24_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 195
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p25.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p25_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 195
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p26.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p26_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 195
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p27.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p27_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 195
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p28.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p28_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 196
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p29.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p29_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 196
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/tpp/p30.pddl /home/pommerening/projects/fastdownward/benchmarks/tpp/domain.pddl &> ./logs/tpp_p30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 196
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p01.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p01.pddl &> ./logs/trucks-strips_p01_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 196
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p02.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p02.pddl &> ./logs/trucks-strips_p02_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 197
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p03.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p03.pddl &> ./logs/trucks-strips_p03_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 197
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p04.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p04.pddl &> ./logs/trucks-strips_p04_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 197
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p05.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p05.pddl &> ./logs/trucks-strips_p05_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 197
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p06.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p06.pddl &> ./logs/trucks-strips_p06_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 198
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p07.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p07.pddl &> ./logs/trucks-strips_p07_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 198
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p08.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p08.pddl &> ./logs/trucks-strips_p08_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 198
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p09.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p09.pddl &> ./logs/trucks-strips_p09_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 198
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p10.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p10.pddl &> ./logs/trucks-strips_p10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 199
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p11.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p11.pddl &> ./logs/trucks-strips_p11_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 199
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p12.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p12.pddl &> ./logs/trucks-strips_p12_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 199
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p13.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p13.pddl &> ./logs/trucks-strips_p13_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 199
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p14.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p14.pddl &> ./logs/trucks-strips_p14_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 200
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p15.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p15.pddl &> ./logs/trucks-strips_p15_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 200
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p16.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p16.pddl &> ./logs/trucks-strips_p16_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 200
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p17.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p17.pddl &> ./logs/trucks-strips_p17_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 200
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p18.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p18.pddl &> ./logs/trucks-strips_p18_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 201
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p19.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p19.pddl &> ./logs/trucks-strips_p19_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 201
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p20.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p20.pddl &> ./logs/trucks-strips_p20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 201
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p21.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p21.pddl &> ./logs/trucks-strips_p21_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 201
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p22.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p22.pddl &> ./logs/trucks-strips_p22_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 202
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p23.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p23.pddl &> ./logs/trucks-strips_p23_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 202
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p24.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p24.pddl &> ./logs/trucks-strips_p24_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 202
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p25.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p25.pddl &> ./logs/trucks-strips_p25_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 202
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p26.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p26.pddl &> ./logs/trucks-strips_p26_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 203
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p27.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p27.pddl &> ./logs/trucks-strips_p27_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 203
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p28.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p28.pddl &> ./logs/trucks-strips_p28_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 203
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p29.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p29.pddl &> ./logs/trucks-strips_p29_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 203
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/p30.pddl /home/pommerening/projects/fastdownward/benchmarks/trucks-strips/domain_p30.pddl &> ./logs/trucks-strips_p30_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 204
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile1 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile1_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 204
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile10 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile10_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 204
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile11 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile11_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 204
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile12 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile12_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 205
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile13 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile13_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 205
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile14 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile14_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 205
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile15 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile15_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 205
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile16 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile16_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 206
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile17 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile17_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 206
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile18 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile18_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 206
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile19 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile19_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 206
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile2 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile2_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 207
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile20 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile20_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 207
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile3 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile3_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 207
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile4 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile4_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 207
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile5 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile5_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 0 ]; then
    echo 208
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile6 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile6_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 1 ]; then
    echo 208
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile7 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile7_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 2 ]; then
    echo 208
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile8 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile8_$JOB_ID.$SGE_TASK_ID.log
fi
if [ $1 -eq 3 ]; then
    echo 208
    relaxed_delete/build/hplusbnb  /home/pommerening/projects/fastdownward/benchmarks/zenotravel/pfile9 /home/pommerening/projects/fastdownward/benchmarks/zenotravel/domain.pddl &> ./logs/zenotravel_pfile9_$JOB_ID.$SGE_TASK_ID.log
fi
