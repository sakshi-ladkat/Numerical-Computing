import numpy as np

class PowerMethod:
    def __init__(self,A,tol=1e-6,max_iter=1000):
        self.A = A
        self.tol = tol
        self.max_iter = max_iter
    
    def compute(self,x0=None):
        n = self.A.shape[0]
        if x0 is None:
            x = np.ones(n)
        else:
            x = x0
        
        x = x/np.linalg.norm(x)
        eigenvalue = 0
        iterartions = []

        for k in range(self.max_iter):
            x_new = np.dot(self.A,x)
            x_new_norm = np.linalg.norm(x_new)
            x_new = x_new / x_new_norm

            eigenvalue_new = np.dot(x_new.T,np.dot(self.A,x_new))

            iterartions.append((k+1,eigenvalue_new,x_new.copy()))

            if np.abs(eigenvalue_new - eigenvalue) < self.tol:
                return eigenvalue_new, x_new, iterartions
            
            x = x_new
            eigenvalue = eigenvalue_new

        print("Warning: Power method did not converge within max iterations")
        return eigenvalue,x,iterartions
            
    def read_matrix(filename):
        with open(filename,'r') as f:
            matrix =[list(map(float,line.split())) for line in f]
        return np.array(matrix)
    
    def read_vector(filename):
        with open(filename,'r') as f:
            vector = list(map(float,f.readline().split()))
        return np.array(vector)
    
    
        