SELECT t.machine_id, round(AVG(t.diff),3) AS processing_time
FROM (
    SELECT s.machine_id, s.process_id, (e.timestamp - s.timestamp) AS diff
    FROM Activity s
    JOIN Activity e
      ON s.machine_id = e.machine_id 
     AND e.process_id = s.process_id
    WHERE s.activity_type = 'start' 
      AND e.activity_type = 'end'
) AS t
GROUP BY machine_id;
