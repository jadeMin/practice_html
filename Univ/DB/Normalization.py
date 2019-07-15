import math; 
  
def findPowerSet(powerset, S, F): 
    set_size = len(powerset) 
    pow_set_size = (int) (math.pow(2, set_size)); 
    counter = 0
    j = 0
    subset = []
    length = len(powerset)
    result = {''}
    result.remove('')

    for counter in range(0, pow_set_size): 
        for j in range(0, set_size): 
            if((counter & (1 << j)) > 0): 
                subset.append(powerset[j])
        closure = frozenset(subset)
        if S.issubset(xplus(closure, F)) == True:
            if length >= len(subset):
                length = len(subset)
                result.add(closure)
        subset.clear()
    return result

def xplus(X, F):
    X_plus = X
    while True:
        oldX_plus = X_plus
        for Y, Z in F:
            if Y <= X_plus:
                X_plus = X_plus | Z
        if oldX_plus == X_plus:
            break
    return X_plus

def candkey(S, F):
    return findPowerSet(powerset, S, F);

    

S = {'a', 'b', 'c', 'd'}
F = \
[
({'a', 'b'}, {'c'}),
({'c'}, {'d'}),
({'d'}, {'a'})
]

powerset = list(S)
print(candkey(S, F))

#################################################

def get_subsets(fullset):
    listrep = list(fullset)
    subsets = []
    for i in range(2**len(listrep)):
        subset = []
        for k in range(len(listrep)):      
            if i & 1<<k:
                subset.append(listrep[k])
        subsets.append(subset)    
    return subsets

S = {'ssn', 'ename', 'pnumber', 'pname', 'plocation', 'hours'}
subsets = get_subsets(S)
print(subsets)
print(len(subsets))

####################################################

import math; 

def xplus(X, F):
    X_plus = X
    while True:
        oldX_plus = X_plus
        for Y, Z in F:
            if Y <= X_plus:
                X_plus = X_plus | Z
        if oldX_plus == X_plus:
            break
    return X_plus

  
def findPowerSet3nf(powerset, S, F, Y, Z): 
    set_size = len(powerset) 
    pow_set_size = (int) (math.pow(2, set_size)); 
    counter = 0
    j = 0
    subset = []
    length = len(powerset)

    for counter in range(0, pow_set_size): 
        for j in range(0, set_size): 
            if((counter & (1 << j)) > 0): 
                subset.append(powerset[j])
        closure = frozenset(subset)
        if S.issubset(xplus(closure, F)) == True:
            if length >= len(subset):
                length = len(subset)
                if closure.issubset(Y) == True:
                    return True
                else:
                    if Z.issubset(closure) == True:
                        return True
        subset.clear()
    return False


def is_3nf(S, F):
    powerset = list(S)
    flag = True
    for Y, Z in F:
        if findPowerSet3nf(powerset, S, F, Y, Z) == False:
            flag = False
            break
    return flag

def findPowerSetBcnf(powerset, S, F, Y): 
    set_size = len(powerset) 
    pow_set_size = (int) (math.pow(2, set_size)); 
    counter = 0
    j = 0
    subset = []
    length = len(powerset)

    for counter in range(0, pow_set_size): 
        for j in range(0, set_size): 
            if((counter & (1 << j)) > 0): 
                subset.append(powerset[j])
        closure = frozenset(subset)
        if S.issubset(xplus(closure, F)) == True:
            if length >= len(subset):
                length = len(subset)
                if closure.issubset(Y) == True:
                    return True
        subset.clear()
    return False

def is_bcnf(S, F):
    powerset = list(S)
    flag = True
    for Y, Z in F:
        if findPowerSetBcnf(powerset, S, F, Y) == False:
            flag = False
            break
    return flag


        
S = {'a', 'b', 'c'}
F = [({'a', 'b'}, {'c'}), ({'c'}, {'a'})]

print(is_3nf(S, F))
print(is_bcnf(S, F))