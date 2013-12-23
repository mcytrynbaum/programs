from pylab import * 

def ols(x,y,data):
    '''
    Compute prediction for new data using least-squares estimator
    where x is design array and y is response array. x and data are not 
    assumed to have intercepts.
    '''

    #Adjust for single slice
    if len(x.shape) == 1:
        x.shape = (len(x),1)

    if len(data.shape) == 1:
        data.shape = (len(data),1)

    y.shape = (len(y),1)

    #Include intercept in test and training matrices
    onecol1 = ones((x.shape[0],1))
    onecol2 = ones((data.shape[0],1))

    x = hstack((onecol1,x))
    data = hstack((onecol2,data))

    #Compute OLS estimator
    theta = linalg.solve(dot(x.T,x), dot(x.T, y))

    return dot(data,theta)

def weighted(x,y,data,tau):
    '''
    Compute prediction for new data using linearly-weighted least squares
    estimator, where x is design array and y is response array
    '''

    if len(x.shape) == 1:
        x.shape = (len(x),1)

    if len(data.shape) == 1:
        data.shape = (len(data),1)
    
    #Include intercept in test and training matrices
    onecol1 = ones((x.shape[0],1))
    onecol2 = ones((data.shape[0],1))

    x = hstack((onecol1,x))
    data = hstack((onecol2,data))

    #Form weight matrices and predictions 
    pred = zeros(data.shape[0])
    for i in range(0,len(data)):
        xpred = data[i,1]
        w = map(lambda z: exp(-((z - xpred)**2)/(2 * tau**2)),x[:,1])
        w = diag(w)
        theta = linalg.solve(dot(x.T,dot(w,x)),dot(x.T,dot(w,y)))
        
        pred[i] = dot(data[i,:],theta)
    
    return pred

def plot_weighted(x,y,tau):

    mesh = linspace(-5,12,100)
    pred = weighted(x,y,mesh,tau)

    figure()

    scatter(x,y)
    plot(mesh,pred)



def plot_ols(x,y):

    mesh = linspace(-5,12,100)
    pred = ols(x,y,mesh)

    figure()

    scatter(x,y)
    plot(mesh,pred)
    







