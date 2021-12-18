## Candidates

get closest index in the searched group from top (ra)
and from the bottom (rra)

the returned values are stored in:
route->candidate_top_position (position) and route->candidate_top_index (value)
route->candidate_btm_position (position) and route->candidate_btm_index (value)

## Placement

gets the destination (in stack B) of both candidates.

route->candidate_top_destination
route->candidate_btm_destination