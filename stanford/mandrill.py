from numpy import * 
from random import *

# Want a general algorithm, given an image of any size, RGB values in R^3 
# with k centroids to start off the algorithm. We assume a matrix A is given

def step(A, C): 
    '''
    Do one step of k-means on the image A with k centroids, where C
    is a 3 x k matrix containing centroid values
    '''

    (m,n) = A.shape[0], A.shape[1]
    k = C.shape[1]

    # Create matrix of distances and preferred centroid
    P = zeros((m,n))
    N = zeros((C.shape[0], C.shape[1])) #new centroid vector 
    count = zeros((1,C.shape[1])) #count vectors belonging to old centroid

    for i in range(0,m):
        for j in range(0,n):

            #Calculate index of best centroid 
            ind = best(A,C,i,j)

            N[:,ind] += A[i,j,:]
            count[0,ind] += 1
             
    #improve this
    for i in range(0,C.shape[1]):
        N[:,i] = N[:,i] / count[0,i]

    return N


def best(A,C,i,j):

    v = A[i,j,:]
    best_dist = 1e32
    best_ind = 0 

    for k in range(0, C.shape[1]):
        cand = linalg.norm(v - C[:,k]) 
        if cand < best_dist: 
            best_ind = k
            best_dist = cand

    return best_ind

    
def iterate(A,k):

    #Define starting centroids, k in total
    (m,n) = (A.shape[0], A.shape[1])
    C = zeros((3,k))

    #Build centroids 
    for i in range(0,k):
        rnd1 = randint(0,m-1)
        rnd2 = randint(0,n-1)
        C[:,i] = A[rnd1,rnd2,:]

    for i in range(0,30):
        print i
        C = step(A,C)

    return C

def comp(A,C):
    '''
    Given an array of cluster centroids in RGB space, compress the image 
    given by A according to least Euclidean distance (k-means clustering)
    '''

    (m,n) = A.shape[0], A.shape[1]
    k = C.shape[1]
    for i in range(0,m):
        print i
        for j in range(0,n):
            ind = best(A,C,i,j)
            A[i,j,:] = C[:,ind]

    return A





