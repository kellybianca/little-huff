par(mfrow=c(1,2))

list_c <- read.csv("/listaArchive.csv", header=TRUE, sep=",")
plot(list_c$size, ylab="Comparações", xlab="Size", main="LISTA",bty="l", tcl=0.3, col = "red")

size_abb <- read.csv("/treeArchive.csv" , header=TRUE, sep=",")
plot(size_abb$abb, ylab="Comparações", xlab="Size", main="ABB",bty="l",ylim=c(0,2000),tcl=0.3, col = "blue")

