-- 문제 설명
-- 낚시앱에서 사용하는 FISH_INFO 테이블은 잡은 물고기들의 정보를 담고 있습니다. FISH_INFO 테이블의 구조는 다음과 같으며 ID, FISH_TYPE, LENGTH, TIME은 각각 잡은 물고기의 ID, 물고기의 종류(숫자), 잡은 물고기의 길이(cm), 물고기를 잡은 날짜를 나타냅니다.

-- Column name	Type	Nullable
-- ID	INTEGER	FALSE
-- FISH_TYPE	INTEGER	FALSE
-- LENGTH	FLOAT	TRUE
-- TIME	DATE	FALSE
-- 단, 잡은 물고기의 길이가 10cm 이하일 경우에는 LENGTH 가 NULL 이며, LENGTH 에 NULL 만 있는 경우는 없습니다.

-- FISH_NAME_INFO 테이블은 물고기의 이름에 대한 정보를 담고 있습니다. FISH_NAME_INFO 테이블의 구조는 다음과 같으며, FISH_TYPE, FISH_NAME 은 각각 물고기의 종류(숫자), 물고기의 이름(문자) 입니다.

-- Column name	Type	Nullable
-- FISH_TYPE	INTEGER	FALSE
-- FISH_NAME	VARCHAR	FALSE
-- 문제
-- FISH_NAME_INFO에서 물고기의 종류 별 물고기의 이름과 잡은 수를 출력하는 SQL문을 작성해주세요.

-- 물고기의 이름 컬럼명은 FISH_NAME, 잡은 수 컬럼명은 FISH_COUNT로 해주세요.
-- 결과는 잡은 수 기준으로 내림차순 정렬해주세요.

-- FISH_INFO 테이블이 다음과 같고

-- ID	FISH_TYPE	LENGTH	TIME
-- 0	0	13.37	2021/12/04
-- 1	0	50	2020/03/07
-- 2	0	40	2020/03/07
-- 3	1	43.33	2022/03/09
-- 4	1	NULL	2022/04/08
-- 5	2	32	2020/04/28
-- FISH_NAME_INFO 테이블이 다음과 같다면

-- FISH_TYPE	FISH_NAME
-- 0	BASS
-- 1	SNAPPER
-- 2	ANCHOVY
-- 종류가 0인 물고기는 3마리, 1인 물고기는 2마리, 2인 물고기는 1마리를 잡았으며, 각각 이름이 'BASS', 'SNAPPER', 'ANCHOVY' 입니다. 따라서 잡은 수를 기준으로 내림차순 정렬하면 결과는 다음과 같습니다.

-- FISH_COUNT	FISH_NAME
-- 3	BASS
-- 2	SNAPPER
-- 1	ANCHOVY
SELECT COUNT(i.ID) AS FISH_COUNT,n.FISH_NAME FROM FISH_INFO i JOIN FISH_NAME_INFO n ON i.FISH_TYPE = n.FISH_TYPE GROUP BY n.FISH_NAME ORDER BY FISH_COUNT DESC;
