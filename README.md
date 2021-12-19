## Candidates

candidate 1 -> 2 -> 3 -> 4

candidate 
	index
	position
	nra
	nrra
	destination
	nrb
	nrrb




get closest index in the searched group from top (ra)
and from the bottom (rra)

the returned values are stored in:
route->candidate_top_position (position) and route->candidate_top_index (value)
route->candidate_btm_position (position) and route->candidate_btm_index (value)

from top
index position
number of ra to get there
number of rra to get there

find position of top in b
number of rb to get there
number of rrb to get there


compare 
ra + rrb w/
rra + rb w/
highest between rra and rrb w/
highest between ra and rb w/

lowest wins.


variables:

index
positiona
nra
nrra
destinationb
nrb
nrrb



## Placement

gets the destination (in stack B) of both candidates.

route->candidate_top_destination
route->candidate_btm_destination

# 10 Numbers
GROUP:	4

# 12 Numbers
GROUP:	9

# 100 Numbers
GROUP:	17

5	928
7	841
10	740
16	708
17	673	!
18	676	!
19	687
20	713
22	672	!
23	696
24	714
25	738

# 500 Numbers
GROUP:	42

17	8598
25	7259
30	6554
31	6464	!
32	6638
33	6617
35	6692
38	6597
39	6598
40	6429	!
41	6478
42	6313	!
43	6449
44	6578
50	6809

# 1000

GROUP:	50

25	23366
30	20892
40	18765
45	18059
50	17423	!
55	17638
60	17461
100	20455
200	31869
400	49182
650	64982