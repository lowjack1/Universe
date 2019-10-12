class NormN():
    """
        Nth norm of a vector is calculated as the Nth root of the sum of the elements of 
        that vector raised to N. 
    """
    def __init__(self, num):
        """
            Initialize the eval function using the number of the norm, the number can't be
            equal to 0, so the initializing function treats it in order to make it equal to
            1 if it was 0.
            
            Args:
                num: The number of the norm being defined.
        """
        self.num = num
        if self.num == 0:
            self.num = 1
        self.eval = self.generate_norm_function()

    def normalize_terms(self,x):
        """
            Makes the vector values be between a range of [-1, 1].
            Args:
                x: The vector that must be normalized
            Returns:
                v: Normalized vector.
                beta: The number by which the vector was divided.
        """
        beta = abs(max(x[0], key=abs))
        if beta == 0:
            beta = 1
        v = [element/beta for element in x[0]]
        return v, beta
        
    def generate_norm_function(self):
        """
            A function to generate the norm function based on the stablished number.]
            
            Returns:
                f: The function that calculates the Nth norm.
        """
        def f(x):
            """
                Function that calcultes the Nth norm of a vector using numeric methods.
                
                Args:
                    x: Vector which norm must be calculated.
                Returns:
                    x_norm: Norm of the vector x 
            """
            v, beta = self.normalize_terms(x)
            v_norm = (sum(element**self.num for element in v))**(1/self.num)
            x_norm = v_norm * beta
            return x_norm
        return f
