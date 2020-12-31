@0   lineno:2   Program children: @1 
@1   lineno:2   StmtType:compound_stmt     children: @2 @5 @8 @11 @14 @46 @50 @54 
@2   lineno:2   StmtType:declare           children: @3 @4 
@3   lineno:2   TYPE:int         
@4   lineno:2   VarType:int   VarName:a          
@5   lineno:3   Expression:=   children: @6 @7 
@6   lineno:3   VarType:int   VarName:a          
@7   lineno:3   CONST:Interger   value:0     
@8   lineno:4   StmtType:declare           children: @9 @10 
@9   lineno:4   TYPE:int         
@10  lineno:4   VarType:int   VarName:b          
@11  lineno:5   Expression:=   children: @12 @13 
@12  lineno:5   VarType:int   VarName:b          
@13  lineno:5   CONST:Interger   value:0     
@14  lineno:6   StmtType:while             children: @15 @18 
@15  lineno:6   Expression:<   children: @16 @17 
@16  lineno:6   VarType:int   VarName:a          
@17  lineno:6   CONST:Interger   value:100   
@18  lineno:7   StmtType:compound_stmt     children: @19 @41 
@19  lineno:7   StmtType:if                children: @20 @23 @27 
@20  lineno:7   Expression:==  children: @21 @22 
@21  lineno:7   VarType:int   VarName:a          
@22  lineno:7   CONST:Interger   value:5     
@23  lineno:8   StmtType:compound_stmt     children: @24 
@24  lineno:8   Expression:=   children: @25 @26 
@25  lineno:8   VarType:int   VarName:b          
@26  lineno:8   CONST:Interger   value:25    
@27  lineno:9   StmtType:if                children: @28 @31 @35 
@28  lineno:9   Expression:==  children: @29 @30 
@29  lineno:9   VarType:int   VarName:a          
@30  lineno:9   CONST:Interger   value:10    
@31  lineno:10  StmtType:compound_stmt     children: @32 
@32  lineno:10  Expression:=   children: @33 @34 
@33  lineno:10  VarType:int   VarName:b          
@34  lineno:10  CONST:Interger   value:42    
@35  lineno:12  StmtType:compound_stmt     children: @36 
@36  lineno:12  Expression:=   children: @37 @38 
@37  lineno:12  VarType:int   VarName:b          
@38  lineno:12  Expression:*   children: @39 @40 
@39  lineno:12  VarType:int   VarName:a          
@40  lineno:12  CONST:Interger   value:2     
@41  lineno:14  Expression:=   children: @42 @43 
@42  lineno:14  VarType:int   VarName:a          
@43  lineno:14  Expression:+   children: @44 @45 
@44  lineno:14  VarType:int   VarName:a          
@45  lineno:14  CONST:Interger   value:1     
@46  lineno:16  StmtType:print             children: @47 
@47  lineno:16  Expression:,   children: @48 @49 
@48  lineno:16  CONST:ConstStr   value:"%d\n" 
@49  lineno:16  VarType:int   VarName:a          
@50  lineno:17  StmtType:print             children: @51 
@51  lineno:17  Expression:,   children: @52 @53 
@52  lineno:17  CONST:ConstStr   value:"%d\n" 
@53  lineno:17  VarType:int   VarName:b          
@54  lineno:18  StmtType:return            children: @55 
@55  lineno:18  CONST:Interger   value:0     
