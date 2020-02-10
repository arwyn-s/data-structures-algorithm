N = 10000

#Create a list from 2 to N.
sieve = [0]*N

#Iterate the list from p the smallest prime no.
p = 2
#Count up in increments p and mark the numbers.
while (p<=N):
    if (sieve[p-1]==0):
        for i in range (p*p, N+1, p):
            sieve[i-1]+=1
    p+=1

prime_nos = [i for i in range(2,N+1) if sieve[i-1]==0]
print(prime_nos)