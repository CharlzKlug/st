bla <- function(a){
    a^2
}

                                        # First income function
incomeA <- function(X){
    1 - exp(-X)
}

                                        # Second income function
incomeB <- function(Y){
    1 - exp(-2 * Y)
}

                                        # Calculate total income
totalIncome <- function(x, funds){
    incomeA(x) + incomeB(funds - x)
}

                                        # Left finance one
financeA <- function(X){
    0.75 * X
}

                                        # Left finance two
financeB <- function(Y){
    0.3 * Y
}

                                        # Last step optimizing
lastSteering <- function(funds){
    Reduce(function(x, y) if (totalIncome(x, funds) > totalIncome(y, funds))
                              x
                          else y,
           seq(0, funds, funds/10))
}

makeFrame <- function(funds){
    bestSteer <- lastSteering(funds)
    maxIncome <- totalIncome(bestSteer, funds)
    data.frame(funds, maxIncome, bestSteer)
}

                                        # Maximal funds in the end of n-th year
maxFund <- function(f0, n){
    (0.75^n) * f0
}

                                        # Minimal funds in the end of n-th year
minFund <- function(f0, n){
    (0.3^n) * f0
}

                                        # Make start frame
makeStartFrame <- function(minFunds, maxFunds){
    step <- (maxFunds - minFunds) / 10
    currentFunds <- minFunds
    resultFrame <- makeFrame(currentFunds)
    currentFunds <- currentFunds + step
    while (currentFunds < maxFunds){
        tmpFrame <- makeFrame(currentFunds)
        currentFunds <- currentFunds + step
        resultFrame <- rbind(resultFrame, tmpFrame)
    }
    resultFrame
}
