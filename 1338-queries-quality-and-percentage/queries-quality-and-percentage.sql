SELECT 
    query_name,
     round(avg(rating/position), 2) as quality,
       round(avg(if (rating<3, 1, 0))*100, 2) as poor_query_percentage 
FROM Queries
GROUP BY query_name;
