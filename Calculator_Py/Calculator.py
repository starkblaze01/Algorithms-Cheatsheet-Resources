class Calculator(object):
  def applyOp(self, x, y, op):
      if op == '+': return x + y
      elif op == '-': return x - y
      elif op == '*': return x * y
      elif op == '/': return x / y
  
  def precedence(self, op):
      if(op == '*' or op == '/'):
          return 1
      elif(op == '+' or op == '-'):
          return 2
      else:
          return 0
  
  def evaluate(self, string):
      tokens = string.split()
      
      valStack = []
      opStack = []
      
      for t in tokens:
          if (t.isnumeric() or ('.' in t)):
              valStack.append(float(t))
          elif t =='(':
              opStack.append(t)
          elif t == ')':
              thisOp = opStack.pop()
              while(thisOp != '('):
                  y = valStack.pop()
                  x = valStack.pop()
                  
                  valStack.append(self.applyOp(x, y, op))
                  
                  thisOp = opStack.pop()
          else:
              while(len(opStack) != 0 and self.precedence(t) >= self.precedence(opStack[-1])):
                  y = valStack.pop()
                  x = valStack.pop()
                  
                  op = opStack.pop()
                  
                  valStack.append(self.applyOp(x, y, op))
              
              opStack.append(t)
      
      while(len(opStack)):
          y = valStack.pop()
          x = valStack.pop()
            
          op = opStack.pop()
            
          valStack.append(self.applyOp(x, y, op))
        
      return valStack[-1]

c = Calculator()
print(c.evaluate("1.1 + 2.2 + 3.3"))
