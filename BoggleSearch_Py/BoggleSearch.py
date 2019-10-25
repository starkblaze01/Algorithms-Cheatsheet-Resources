from functools import reduce

def findword(board, word):
    width = len(board[0])
    mergedBoard = reduce(lambda prev, this: prev + this, board)

    if len(word) == 1:
        if word[0] in mergedBoard:
            return True
        else: return False
        
    chWithInds = {}
    
    for ch in word:
        if(ch in mergedBoard):
            if(ch not in chWithInds):
                if(mergedBoard.count(ch) > 1):
                    thisInds = [ind for ind, val in enumerate(mergedBoard) if val == ch]
                else:
                    thisInds = [mergedBoard.index(ch)]

                chWithInds[ch] = thisInds

        else:
            return False

    prevIndCache = []
    matched = False
    for i, ch in enumerate(word[1:], 1):
        
        thisChInds = chWithInds[ch]

        if(prevIndCache != []):
            prevChInds = prevIndCache
            prevIndCache = []
        else:
            prevChInds = chWithInds[word[i-1]]

        matched = False
        
        for tI in thisChInds:
            
            thisCoord = ((tI - (tI % width)) / width, tI % width)
            
            for pI in prevChInds:
                prevCoord = ((pI - (pI % width)) / width, pI % width)

                rowDiff = thisCoord[0] - prevCoord[0]
                colDiff = thisCoord[1] - prevCoord[1]

                #print(ch, thisCoord, word[i-1], prevCoord, rowDiff, colDiff)
            
                if((rowDiff in [-1, 0, 1]) and (colDiff in [-1, 0, 1])):
                    prevIndCache.append(tI)

                    if(pI in chWithInds[word[i - 1]]): chWithInds[word[i - 1]].remove(pI)
                    
                    matched = True
                    break

        if not matched: break
        
    if(matched): return True
    else: return False

#_______ALTERNATE________

def findWord(board, word):
    width = len(board[0])
    mergedBoard = reduce(lambda prev, this: prev + this, board)

    if len(word) == 1:
        if word[0] in mergedBoard:
            return True
        else: return False
    
    if(word[0] in mergedBoard):
        startChInds = [ind for ind, val in enumerate(mergedBoard) if val == word[0]]
        
        for stChInd in startChInds:

            prevInd = stChInd
            for ch in word[1:]:
                
                if(mergedBoard[prevInd - 1] == ch): prevInd -= 1
                elif(mergedBoard[prevInd + 1] == ch): prevInd += 1
                
                elif(mergedBoard[prevInd - width] == ch): prevInd = prevInd - width
                elif(mergedBoard[prevInd - width - 1] == ch): prevInd = prevInd - width - 1
                elif(mergedBoard[prevInd - width + 1] == ch): prevInd = prevInd - width + 1

                elif(mergedBoard[prevInd + width] == ch): prevInd = prevInd - width
                elif(mergedBoard[prevInd - width - 1] == ch): prevInd = prevInd + width - 1
                elif(mergedBoard[prevInd - width + 1] == ch): prevInd = prevInd + width + 1

                else: break

            else: return True

        else: return False
                
            
    else: return False


# Final program:
visited = []

def find_word(board, word):
    global visited
    visited = [[False for j in range(len(board[0]))] for i in range(len(board))]

    for r in range(len(board)):
        for c in range(len(board[r])):
            if(word[0] == board[r][c] and search(r, c, 0, board, word)):
                return True
    return False

def search(r, c, index, board, word):
    global visited
    
    if(index == len(word)):
        return True
    
    if(r < 0 or r >= len(board) or c < 0 or c >= len(board[r]) or board[r][c] != word[index] or visited[r][c]):
        return False
    
    visited[r][c] = True
    if(search(r - 1, c, index + 1, board, word) or 
    search(r - 1, c - 1, index + 1, board, word) or
    search(r - 1, c + 1, index + 1, board, word) or
    
    search(r + 1, c, index + 1, board, word) or
    search(r + 1, c + 1, index + 1, board, word) or
    search(r + 1, c - 1, index + 1, board, word) or
    
    search(r, c - 1, index + 1, board, word) or
    search(r, c + 1, index + 1, board, word)):
        return True
    
    visited[r][c] = False
    return False



def Test():
    testBoard = [
      ["E","A","R","A"],
      ["N","L","E","C"],
      ["I","A","I","S"],
      ["B","Y","O","R"]
    ]
    
    assert( find_word(testBoard, "C"               ) == True)
    assert( find_word(testBoard, "EAR"             ) == True)
    assert( find_word(testBoard, "EARS"            ) == False)
    assert( find_word(testBoard, "BAILER"          ) == True)
    assert( find_word(testBoard, "RSCAREIOYBAILNEA") == True)
    assert( find_word(testBoard, "CEREAL"          ) == False)
    assert( find_word(testBoard, "ROBES"           ) == False)

def callAll():
    testBoard = [
      ["E","A","R","A"],
      ["N","L","E","C"],
      ["I","A","I","S"],
      ["B","Y","O","R"]
    ]
    
    find_word(testBoard, "C"               )
    find_word(testBoard, "EAR"             )
    find_word(testBoard, "EARS"            )
    find_word(testBoard, "BAILER"          )
    find_word(testBoard, "RSCAREIOYBAILNEA")
    find_word(testBoard, "CEREAL"          )
    find_word(testBoard, "ROBES"           )

Test()
