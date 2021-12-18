## Candidates

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