SELECT
    x.requester_id AS id,
    x.num
FROM
(
    SELECT
        requester_id,
        SUM(c) AS num
    FROM
    (
        SELECT
            requester_id,
            COUNT(*) AS c
        FROM RequestAccepted
        GROUP BY requester_id

        UNION ALL

        SELECT
            accepter_id AS requester_id,
            COUNT(*) AS c
        FROM RequestAccepted
        GROUP BY accepter_id
    ) AS x
    GROUP BY requester_id
) AS x
ORDER BY x.num DESC
LIMIT 1;