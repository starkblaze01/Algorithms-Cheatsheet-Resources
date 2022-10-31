def getIntersectionNode(headA,headB):
        cnt1=0
        cnt2=0
        temp1=headA
        while temp1:
                temp1=temp1.next
                cnt1+=1
                
                
        temp2=headB
        while temp2:
                temp2=temp2.next
                cnt2+=1
                
        if cnt2>cnt1:
                l=cnt2-cnt1
                temp1=headB
                temp2=headA
                for i in range(l):
                        temp1=temp1.next
                        
                
                while temp1 and temp2:
                        if temp1==temp2:
                                return temp1
                        
                        
                        temp1=temp1.next
                        temp2=temp2.next
                        
                        
                else:
                        return None
                
                
        else:
                l=cnt1-cnt2
                temp1=headA
                temp2=headB
                for i in range(l):
                        temp1=temp1.next
                        
                
                while temp1 and temp2:
                        if temp1==temp2:
                                return temp1
                        
                        temp1=temp1.next
                        temp2=temp2.next
                        
                        
                else:
                        return None
                
        
