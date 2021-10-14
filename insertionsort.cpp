For I = 1 to n-1

Key = a[I]

J = I - 1

While J>=0 and a[J] > Key

Set a[J+1] = a[J]

J = J - 1

a[J+1] = Key
