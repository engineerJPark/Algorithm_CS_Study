#최대값을 시간복잡도 O(n)으로 구하는 알고리즘

price_tag = [10300,9600,9800,8200,7800,8300,9500,9800,10200,9500]

def max_profit(prices):
    n = len(prices)
    maxprofit = 0
    minprice = prices[0]
    
    for x in range(1,n):
        profit = prices[x] - minprice
        
        if profit > maxprofit:
            maxprofit = profit
        if prices[x] < minprice:
            minprice = prices[x]
            
    return maxprofit

print(max_profit(price_tag))