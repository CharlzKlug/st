library (purrr)

mlps <- function () {
    return (mkCoefs())
}

                                        #rm01, rm02, ..., rm10 -- исходные вектора

noise <- function (x) {
    if (x >= 10)
        return (rnorm (1, x, sqrt (x)))
    else return (x)
}

noiseNormal <- function (vctr) {
    tmpVctr <- unlist (map (vctr, noise))
    return (tmpVctr)
}

superposition <- function (koeffs) {
    result <- rm01 * koeffs [1] + rm02 * koeffs [2] +
        rm03 * koeffs [3] + rm04 * koeffs [4] +
        rm05 * koeffs [5] + rm06 * koeffs [6] +
        rm07 * koeffs [7] + rm08 * koeffs [8] +
        rm09 * koeffs [9] + rm10 * koeffs [10]
    result <- noiseNormal (result * 10^5)
    max <- max (result)
    return (result / 8700)
}

getBins <- function (n, vctr) {
    tmp <- c ()
    len <- length (vctr)
    group <- len / n
    for (i in (seq (1, len, by = group))) {
        tmp <- c (tmp, mean (vctr [i : (i + group - 1)]))
    }
    return (tmp)
}

randomSpectrum <- function () {
    superposition (mlps ())
}

mk20BinsRnd <- function () {
    myKoefs <- mlps ()
    mySpectrum <- superposition (myKoefs)
    bins <- getBins (20, mySpectrum [300:730])
    bins <- c (bins, (firstNullsCount (myKoefs)) / 10)
    bins <- c (bins, (firstNullsCount (myKoefs)))
    return (bins)
}

mk20BinsRange <- function (startLayer, endLayer) {
    myKoefs <- seq (from = 0, to = 0, length = (startLayer - 1))
    myKoefs <- c (myKoefs, (sample (1:10,
    (endLayer - startLayer + 1), replace = TRUE)))
    myKoefs <- c (myKoefs, seq (from = 0, to = 0, length = (10 - endLayer)))
    mySpectrum <- superposition (myKoefs)
    bins <- getBins (20, mySpectrum [300:730])
    bins <- c (bins, (firstNullsCount (myKoefs)) / 10)
    bins <- c (bins, (firstNullsCount (myKoefs)))
    return (bins)
}

mk100BinsRndThick <- function () {
    myKoefs <- mlps ()
    materialThickness <- length (myKoefs [myKoefs > 0])
    mySpectrum <- superposition (myKoefs)
    bins <- getBins (100, mySpectrum [300:730])
    bins <- c (bins, materialThickness / 10)
    bins <- c (bins, materialThickness)
    return (bins)
}

mkDataFrameThickness <- function (n) {
    tmpDF <- data.frame ()
    for (i in (seq (1, n))) {
        tmpDF <- rbind (tmpDF, (mk100BinsRndThick ()))
    }
    names (tmpDF) [1:102] <- c ("x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8",
                               "x9", "x10", "x11", "x12", "x13", "x14", "x15",
                               "x16", "x17", "x18", "x19", "x20", "x21", "x22",
                               "x23", "x24", "x25", "x26", "x27", "x28", "x29",
                               "x30", "x31", "x32", "x33", "x34", "x35", "x36",
                               "x37", "x38", "x39", "x40", "x41", "x42", "x43",
                               "x44", "x45", "x46", "x47", "x48", "x49", "x50",
                               "x51", "x52", "x53", "x54", "x55", "x56", "x57",
                               "x58", "x59", "x60", "x61", "x62", "x63", "x64",
                               "x65", "x66", "x67", "x68", "x69", "x70", "x71",
                               "x72", "x73", "x74", "x75", "x76", "x77", "x78",
                               "x79", "x80", "x81", "x82", "x83", "x84", "x85",
                               "x86", "x87", "x88", "x89", "x90", "x91", "x92",
                               "x93", "x94", "x95", "x96", "x97", "x98", "x99",
                               "x100", "r", "thickness")
    return (tmpDF)
}
    
mkDataFrame <- function (n) {
    tmpDF <- data.frame ()
    for (i in (seq (1, n))) {
        tmpDF <- rbind (tmpDF, (mk20BinsRnd ()))
    }
    names (tmpDF) [1:22] <- c ("x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8",
                               "x9", "x10", "x11", "x12", "x13", "x14", "x15",
                               "x16", "x17", "x18", "x19", "x20", "r", "depth")
    return (tmpDF)
}

mkDepthTest <- function (startLayer, endLayer, n) {
    tmpDF <- data.frame ()
    for (i in (seq (1, n))) {
        tmpDF <- rbind (tmpDF, (mk20BinsRange (startLayer, endLayer)))
    }
    names (tmpDF) [1:22] <- c ("x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8",
                               "x9", "x10", "x11", "x12", "x13", "x14", "x15",
                               "x16", "x17", "x18", "x19", "x20", "r", "depth")
    return (tmpDF)
}
#trainingSetClearMaterial <- mkDataFrame (5000)
#write.csv(trainingSetClearMaterial, "trainingSetClearMaterial.csv", row.names = FALSE)
#nnClear <- neuralnet (r ~ x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10 + x11 + x12 + x13 + x14 + x15 + x16 + x17 + x18 + x19 + x20, data = trainingSetClearMaterial, hidden = 10, act.fct = "logistic", linear.output = F)

#write.csv (testD1, "testD1.csv", row.names = TRUE)
                                        #resultsd1 <- predict (nnClear, testD1 [, 1:20])

                                        #testSet <- mkDataFrame (1000)

#results <- predict (nnClear, testSet [, 1:20])

#errors <- abs (testSet[21] - results)
#trainingSetThickness <- mkDataFrameThickness (5000)

#nnThickness <- neuralnet (r ~ x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10 + x11 + x12 + x13 + x14 + x15 + x16 + x17 + x18 + x19 + x20 + x21 + x22 + x23 + x24 + x25 + x26 + x27 + x28 + x29 + x30 + x31 + x32 + x33 + x34 + x35 + x36 + x37 + x38 + x39 + x40 + x41 + x42 + x43 + x44 + x45 + x46 + x47 + x48 + x49 + x50 + x51 + x52 + x53 + x54 + x55 + x56 + x57 + x58 + x59 + x60 + x61 + x62 + x63 + x64 + x65 + x66 + x67 + x68 + x69 + x70 + x71 + x72 + x73 + x74 + x75 + x76 + x77 + x78 + x79 + x80 + x81 + x82 + x83 + x84 + x85 + x86 + x87 + x88 + x89 + x90 + x91 + x92 + x93 + x94 + x95 + x96 + x97 + x98 + x99 + x100, data = trainingSetThickness, hidden = 2, act.fct = "logistic", linear.output = F)

#compare.dataframe <- cbind (results$net.result, testSet[21])
#trainingSetContaminationThickness <- mkDataFrameThickness (5000)

#nnContaminated <- neuralnet (r ~ x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10 + x11 + x12 + x13 + x14 + x15 + x16 + x17 + x18 + x19 + x20, data = trainingSetContaminationThickness, hidden = 10, act.fct = "logistic", linear.output = F)


                                        # Как установить пакет: https://www.r-bloggers.com/2013/01/how-to-install-packages-on-r-screenshots/
                                        # > install.packages("neuralnet")
# Загрузка пакета: library(neuralnet)
#> trainingSet <- mkDataFrame (5000)
#n> nn <- neuralnet (r ~ x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10 + x11 + x12 + x13 + x14 + x15 + x16 + x17 + x18 + x19 + x20, data = trainingSet, hidden = 10, act.fct = "logistic", linear.output = F)
#Предупреждение:
#Algorithm did not converge in 1 of 1 repetition(s) within the stepmax. 
#testSet <- mkDataFrame (100)
#rslts <- compute (nn, testSet [, 1:20])
#Ошибка в cbind(1, pred) %*% weights[[num_hidden_layers + 1]] :
#  требует числовых/комплексных матричных/векторных аргументов
#traningSet <- mkDataFrame (1000)
#> nn <- neuralnet (r ~ x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10 + x11 + x12 + x13 + x14 + x15 + x16 + x17 + x18 + x19 + x20, data = traningSet, hidden = 10, act.fct = "logistic", linear.output = F)
#> rslts <- compute (nn, testSet [, 1:20])
#> rslts$net.result - testSet [, 21]

#normKoefs <- c (0.55, 1.11, 2.40, 2.21, 1.75, 1.48, 1.21, 1.02, 0.89,
#                0.78, 0.68, 0.61, 0.57, 0.39, 0.30, 0.27, 0.26, 0.90,
#                1.49, 0.01)

# comparison.dataframe <- cbind (testSet [, 21], rslts$net.result)
normKoefs <- c (2.566936e-01, 2.929657e-01, 3.517302e-01, 7.486530e-01, 1.155444e+00, 1.241752e+00, 1.159898e+00, 1.042294e+00, 9.232302e-01, 8.257689e-01, 7.754014e-01, 7.020019e-01, 6.316111e-01, 5.766771e-01, 5.308360e-01, 4.881761e-01, 4.557788e-01, 4.254173e-01, 3.990443e-01, 3.750266e-01, 3.448866e-01, 3.260854e-01, 3.103488e-01, 2.979622e-01, 2.920946e-01, 2.778698e-01, 2.135556e-01, 1.727564e-01, 1.539572e-01, 1.405960e-01, 1.335691e-01, 1.291173e-01, 1.286864e-01, 1.269546e-01, 1.544766e-01, 7.372758e-01, 1.265124e+00, 2.203627e-01, 3.240232e-03, 3.286787e-06)

mk20BinsRndNorm <- function () {
    myKoefs <- mlps ()
    mySpectrum <- superposition (myKoefs)
    bins <- (getBins (40, (mySpectrum [1:730])) / normKoefs)
    bins <- c (bins, sapply (myKoefs, (function (x) {
        return (x / 10)
    })))
    return (bins)
}

mkR <- function () {
    vl <- sample (0:1, 1)
    return (c (vl, vl))
}

mkDataFrameNorm <- function (n) {
    tmpDF <- data.frame ()
    for (i in (seq (1, n))) {
        tmpDF <- rbind (tmpDF, (mk20BinsRndNorm ()))
    }
    names (tmpDF) [1:50] <- c ("x1", "x2", "x3", "x4", "x5", "x6", "x7", "x8",
                               "x9", "x10", "x11", "x12", "x13", "x14", "x15",
                               "x16", "x17", "x18", "x19", "x20", "x21", "x22", "x23", "x24", "x25", "x26", "x27", "x28", "x29", "x30", "x31", "x32", "x33", "x34", "x35", "x36", "x37", "x38", "x39", "x40", "r1", "r2",
                               "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10"
                               )
    return (tmpDF)
}

mkTdf <- function (n) {
    tmpDF <- data.frame ()
    for (i in (seq (1, n))) {
        tmpDF <- rbind (tmpDF, (mkR ()))
    }
    names (tmpDF) [1:2] <- c ("x", "r")
    return (tmpDF)
}
                                        #matThick -- толщина радиоактивного слоя
                                        #matThickN -- нормированная толщина радиоактивного слоя
                                        # trainSetNorm <- mkDataFrameNorm (5000)
                                        # nnNorm <- neuralnet (r ~ x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10 + x11 + x12 + x13 + x14 + x15 + x16 + x17 + x18 + x19 + x20, data = trainingSet, hidden = c(10, 5), act.fct = "logistic", linear.output = F)
                                        # testSetNorm <- mkDataFrameNorm (1000)
                                        # rsltsNorm <- compute (nnNorm, testSetNorm [, 1:20])$net.result
                                        # resCeil <- round (rsltsNorm * 10)
                                        # err <- testSetNorm [,22] - resCeil [,1]




mkCoefs <- function() {
    a1 <- sample (0:10, 1)
    a2 <- sample (-5:10, 1)
    a3 <- sample (1:3, 1)
    rf <- function (x) {
        a1 / (exp (abs (((x - a2) / a3)^3)))
    }
    return (round (rf (1:10)))
}

firstNullsCount <- function (vector) {
    i <- 1
    repeat {
        if (length (vector) < i) {break}
        if (vector [i] != 0) {break}
        i <- i + 1
    }
    return (i-1)
}

                                        #nn0 <- neuralnet (r0 ~ x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10 + x11 + x12 + x13 + x14 + x15 + x16 + x17 + x18 + x19 + x20, data = trainSetNorm, act.fct = "logistic", linear.output = TRUE)
                                        #trainSetNorm <- cbind (trainSetNorm, sapply (trainSetNorm [,22], ft))

                                        #install.packages ("purrr")
                                        #library ("purrr")
