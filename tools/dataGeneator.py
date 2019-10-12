#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 11 20:34:01 2019

@author: Zhengyi Xiao
"""

import random
import pandas as pd 
import os
from scipy.stats import uniform
from scipy.stats import norm
from scipy.stats import gamma
from scipy.stats import expon
from scipy.stats import poisson
from scipy.stats import binom
from scipy.stats import bernoulli

def main():
    path = os.getcwd()
    
    ## Uniform Distribution
    n = 10000
    start = 0
    width = 10
    data_uniform = uniform.rvs(size=n, loc = start, scale=width)
    df = pd.DataFrame(data_uniform)
    df.to_csv(os.path.join(path,r'uniform.csv'))
    
    ## Normal Distribution
    data_normal = norm.rvs(size=10000,loc=0,scale=1)
    df = pd.DataFrame(data_normal)
    df.to_csv(os.path.join(path,r'norm.csv'))    

    ## Gamma Distribution
    data_gamma = gamma.rvs(a=5, size=10000)
    df = pd.DataFrame(data_gamma)
    df.to_csv(os.path.join(path,r'gamma.csv'))  
    
    ## Exponential Distribution
    data_expon = expon.rvs(scale=1,loc=0,size=10000)
    df = pd.DataFrame(data_expon)
    df.to_csv(os.path.join(path,r'expon.csv'))     
    
    ## Poisson Distribution
    data_poisson = poisson.rvs(mu=3, size=10000)
    df = pd.DataFrame(data_poisson)
    df.to_csv(os.path.join(path,r'poisson.csv')) 

    ## Binomial Distribution
    data_binom = binom.rvs(n=10,p=0.8,size=10000)    
    df = pd.DataFrame(data_binom)
    df.to_csv(os.path.join(path,r'binom.csv'))    
    
    ## Bernoulli Distribution
    data_bern = bernoulli.rvs(size=10000,p=0.6)
    df = pd.DataFrame(data_bern)
    df.to_csv(os.path.join(path,r'bernoulli.csv'))  
    
    ## Random 10000 float numbers between 0 and 1
    arr = []
    for i in range(10000):
        arr.append(random.uniform(0, 1))
    df = pd.DataFrame(arr)
    df.to_csv(os.path.join(path,r'0-1.csv'))  
    
    ## Ascending numbers
    arr = []
    for i in range(10000):
        arr.append(i)
    df = pd.DataFrame(arr)
    df.to_csv(os.path.join(path,r'bestCase.csv'))
    
    ## Descending numbers
    arr = []
    for i in range(10000):
        arr.append(10000 - i)
    df = pd.DataFrame(arr)
    df.to_csv(os.path.join(path,r'worstCase.csv'))
    
if __name__== "__main__":
  main()