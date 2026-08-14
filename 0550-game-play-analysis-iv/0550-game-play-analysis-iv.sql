SELECT
    ROUND(
        COUNT(DISTINCT a.player_id) /(select count(distinct w.player_id) from Activity w),
        2
    ) AS fraction
FROM Activity a
JOIN (
    SELECT
        player_id,
        MIN(event_date) AS first_date
    FROM Activity
    GROUP BY player_id
) x
ON a.player_id = x.player_id
AND a.event_date = DATE_ADD(x.first_date, INTERVAL 1 DAY);