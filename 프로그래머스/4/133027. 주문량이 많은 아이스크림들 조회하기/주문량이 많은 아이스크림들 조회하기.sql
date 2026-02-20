-- 코드를 입력하세요
SELECT      J.FLAVOR -- , (SUM(J.TOTAL_ORDER) + SUM(F.TOTAL_ORDER))
FROM        FIRST_HALF  F    /* 상반기 주문 정보 */
JOIN        JULY        J    /* 7월의 아이스크림 주문 정보 */
  ON        F.FLAVOR = J.FLAVOR
 GROUP BY   J.FLAVOR -- , J.SHIPMENT_ID
 ORDER BY   (SUM(J.TOTAL_ORDER) + SUM(F.TOTAL_ORDER)) DESC
LIMIT 3
;
