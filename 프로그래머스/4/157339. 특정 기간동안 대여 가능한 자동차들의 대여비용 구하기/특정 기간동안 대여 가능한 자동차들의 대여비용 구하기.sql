


-- 자동차 ID, 자동차 종류, 대여 금액(컬럼명: FEE) 리스트
SELECT      CAR.CAR_ID
            , CAR.CAR_TYPE
            # , HIS.START_DATE
            # , HIS.END_DATE
            , ROUND(CAR.DAILY_FEE * 30 -
                (CAR.DAILY_FEE * 30 * PLAN.DISCOUNT_RATE / 100))
                AS FEE
FROM        CAR_RENTAL_COMPANY_CAR              CAR
# JOIN        CAR_RENTAL_COMPANY_RENTAL_HISTORY   HIS
#   ON        CAR.CAR_ID      = HIS.CAR_ID
JOIN        CAR_RENTAL_COMPANY_DISCOUNT_PLAN    PLAN
  ON        CAR.CAR_TYPE    = PLAN.CAR_TYPE
  AND       PLAN.DURATION_TYPE = '30일 이상'
-- 1) 자동차 종류가 '세단' 또는 'SUV' 인 자동차 중
WHERE       CAR.CAR_TYPE        IN ('세단', 'SUV')
-- 2) 2022년 11월 1일부터 2022년 11월 30일까지 대여 가능하고
  AND       CAR.CAR_ID NOT IN
            (
            SELECT  HIS_IN.CAR_ID
            FROM    CAR_RENTAL_COMPANY_RENTAL_HISTORY HIS_IN
            WHERE   START_DATE <= '2022-11-30'
              AND   END_DATE >= '2022-11-01'
            )
--    30일간의 대여 금액이 50만원 이상 200만원 미만인 자동차
  AND      (CAR.DAILY_FEE * 30 -
                (CAR.DAILY_FEE * 30 * PLAN.DISCOUNT_RATE / 100)
           ) BETWEEN 500000 AND 2000000
ORDER BY    FEE DESC, CAR_TYPE, CAR_ID DESC
;