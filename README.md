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

# 12 Numbers

# 100 Numbers

# 500 Numbers

10:		4
12:		9
50:		11
100:	17
200:	20
300:	26
400:	37
500:	42
1000:	50

# 1000