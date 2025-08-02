select V.customer_id,count(V.visit_id) as count_no_trans
from Visits as V
where V.visit_id not in
(select T.visit_id from Transactions as T)
group by customer_id