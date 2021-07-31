# [Problem H: Kayaking Trip](https://nbhspc21.kattis.com/problems/nbhspc21.kayakingtrip)

You want to go for a trip where you would be travelling down a river by kayak. Since you do not have your own kayak, you have to rent one. Along the river, there are a number of places (stations) where a kayak can be returned, and another one can be rented. For each pair of such places, you have the price to rent the kayak from that place and return it at the other place down the river (nobody attempts to go upstream, in the opposite direction of the river’s natural flow). You would like to plan your trip (i.e., where you will stop to return your kayak and rent another one), so that you will pay the smallest amount possible overall for kayak renting. Note: you must start from the first station, and go all the way to the very last one.

![reference image](https://nbhspc21.kattis.com/problems/nbhspc21.kayakingtrip/file/statement/en/img-0001.png)

## Input
The input starts with the total number of stations along the river, as a positive integer n. In our example below (and in the related picture above), there are 8 stations, and we will number them from 1 to 8. Then there are n−1 lines, each containing the cost to each of the stations downstream from that point. So for example here, the first line indicates that it costs $10 to go from station 1 to 2, $15 to go from station 1 to 3, $17 to go from station 1 to 4, and etc. The second line indicates that it costs $4 to go from station 2 to 3, $10 to go from station 2 to 4, and etc. The last line is the cost between the last 2 stations. Your program should use this information to figure out the plan (i.e., sequence of stops) that would be the least expensive overall. For example, the plan illustrated in the picture above has an overall cost of $36 (10 + 14 + 12). However, for the example input below, the best plan would be to go from station 1 to 4 ($17), then 4 to 5 ($1), then 5 to 7 ($8), and finally 7 to 8 ($3), for a total cost of $29.

The value n is guaranteed to be less than 30. All input costs are positive whole numbers less than 1000. The input will be such that there is only one possible least-expensive solution.

## Output
The output should first indicate which stations to stop at, as a sequence of station numbers separated by a space. Station numbers should be given in ascending order. The second line of output should be the total cost for that best plan. Note: it is guaranteed that there will not be 2 plans with the same best overall cost.

## Sample Input 1
```
8
10 15 17 24 30 35 45
4 10 14 15 20 25
10 11 12 20 22
1 5 15 16
7 8 12
15 20
3
```

## Sample Output 1
```
1 4 5 7 8
29
```
