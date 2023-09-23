v=c(17,25,38,12,41)
plot(v,col="green",xlab="month",ylab="sales",main="monthly sales")

data1<- c(
)

t.test(col1~cool2,data=datset)
'''col1= response varibale to the left of tilde
col2=predictor variable on the right of tilde
to be used when datset is felxible and sensitive we can ....
'''

#smape dataet
grass(rich,graze)
rich {12,15,40,25,16,20,23,5,8,3}
graze {mow, unmow}
#for this we have two values in col2 which is graze so we need to use subsets

t.test(rich ~ graze, data=grass, subset= graze %in% c('mow','unmow'))

#so that was to pally t.test when predictor values is not ato9mic

#now for another orchid dataset

orchid{closed,open}
attach(orchid)
t.test(open, closed, var.equal=true)
       # to consider both of thier variance to be equal)

#to aply t.test on single column, and specifyy mean to be 5
t.test(orchid$open, mu=5)




#to find corelation and covariance
between x and y is
cor(x,y)  
cov(x,y)
cov2cor(v) 

speed=c(9,25,2,40,23,36,10,28,23,14)
count=c(2,3,5,9,6,3,1,4,2,3)

cor(speed,count)
#to specify which method to use to find correlation
cor(speed,count, method='spearman')
cor(speed,count, method='kendall')

View(women)
#datset that has height and weightof women , now to find correlation of heigh an dweight
cor(women$weight, women$height)
#this is the default pearson method

cor(women)
#this will result in a matrix with the correlations of all possible combinations
#height cor height is 1, and similarly it calaculates every combinations cor


#coariance 
cov(women$height,women$weight)
cov(women)

women.cv=cov(women)
View(women.cv)

cov2cor(women.cv)

#signifance testing in correlation test
cor.test(women$height, women$weight)

#for association we use chisq.test to test for association on a categorical data to find
association between data cataegories
chisq.test(x,y)















#practical list q1

#no of data points, second mean, third standar deviation
x= rnorm(10,20,2)

#generate data points
sample1=rnorm(100,100,5)
library(ggplot2)
install.packages(ggplot2)
install.packages(ggplot)
library((ggplot2))
library(ggplot2)

#visualizing the data
hist(sample1)
plot(sample1,type='l')
barplot(sample1)
plot(sample1)

#hypothesis testing
t.test(sample1, mu=100)
t.test(sample1)

#wilcox testing
wilcox.test(sample1)
wilcox.test(sample1, mu=90, exact = FALSE)

