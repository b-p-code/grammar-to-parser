
void Program() { 
if (tk.ID == idTK) {
Statements();
} else { error(); }
}
void Statements() { 
if (tk.ID == idTK) {
Statement();
} else { error(); }
}
void Mstatements() { 
if (tk.ID == idTK) {
Statement();
} else { return; }
}
void Statement() { 
if (tk.ID == idTK) {
Def();
} else { error(); }
}
void Def() { 
if (tk.ID == idTK) {
Deff();
} else { error(); }
}
void Deff() { 
if (tk.ID == exprTK) {
Expr();
} else if (tk.ID == isTK) {
Globalassign();
}  else { error(); }
}
void Globalassign() { 
if (tk.ID == isTk) {
if (tk.ID == isTK) {
tk = scanner();
Expr();
}
} else { error(); }
}
void Var() { 
if (tk.ID == typeTk) {
if (tk.ID == typeTK) {
tk = scanner();
if (tk.ID == idTK) {
tk = scanner();
Varr();
}
}
} else { error(); }
}
void Varr() { 
if (tk.ID == isTk) {
if (tk.ID == isTK) {
tk = scanner();
Expr();
}
} else { error(); }
}
void Expr() { 
if (tk.ID == exprTK) {
if (tk.ID == exprTK) {
tk = scanner();
}
} else { error(); }
}
void Func() { 
if (tk.ID == takesTk) {
Takes();
} else { error(); }
}
void Return() { 
if (tk.ID == returnsTK) {
if (tk.ID == returnsTK) {
tk = scanner();
if (tk.ID == typeTK) {
tk = scanner();
if (tk.ID == commaTK) {
tk = scanner();
}
}
}
} else { return; }
}
void Takes() { 
if (tk.ID == takesTK) {
if (tk.ID == takesTK) {
tk = scanner();
Param();
}
} else { return; }
}
void Param() { 
if (tk.ID == typeTK) {
if (tk.ID == typeTK) {
tk = scanner();
if (tk.ID == idTK) {
tk = scanner();
if (tk.ID == commaTK) {
tk = scanner();
}
}
}
} else if (tk.ID == refTK) {
if (tk.ID == refTK) {
tk = scanner();
if (tk.ID == typeTK) {
tk = scanner();
if (tk.ID == idTK) {
tk = scanner();
}
}
}
}  else { error(); }
}
void Params() { 
if (tk.ID == typeTK || tk.ID == refTK) {
Param();
} else { return; }
}
void Block() { 
if (tk.ID == l_braceTK) {
if (tk.ID == l_braceTK) {
tk = scanner();
Internalstats();
}
} else { error(); }
}
void Internalstats() { 
if (tk.ID == idTK) {
Internalstat();
} else { error(); }
}
void Minternalstats() { 
if (tk.ID == idTK) {
Internalstat();
} else { return; }
}
void Internalstat() { 
if (tk.ID == idTK) {
if (tk.ID == idTK) {
tk = scanner();
Id();
}
} else { error(); }
}
void ID() { 
if (tk.ID == isTK) {
if (tk.ID == isTK) {
tk = scanner();
Expr();
}
} else if (tk.ID == l_parenTK) {
if (tk.ID == l_parenTK) {
tk = scanner();
Actualparams();
}
}  else { error(); }
}
void Actualparems() { 
if (tk.ID == idTK) {
if (tk.ID == idTK) {
tk = scanner();
Actualparamss();
}
} else { return; }
}
void Actualparamss() { 
if (tk.ID == commaTk) {
if (tk.ID == commaTK) {
tk = scanner();
if (tk.ID == idTK) {
tk = scanner();
Actualparamss();
}
}
} else { return; }
}