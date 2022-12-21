
void Program() { 
if (tk.ID == idTK) {
Statements();
} else { error(); }
}
void Statements() { 
if (tk.ID == idTK) {
Statement();
if (tk.ID == scTK) {
tk = scanner();
Mstatements();
} else { error(); }
} else { error(); }
}
void Mstatements() { 
if (tk.ID == idTK) {
Statement();
if (tk.ID == scTK) {
tk = scanner();
Mstatements();
} else { error(); }
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
} else { error(); }
} else { error(); }
}
void Var() { 
if (tk.ID == typeTk) {
if (tk.ID == typeTK) {
tk = scanner();
if (tk.ID == idTK) {
tk = scanner();
Varr();
} else { error(); }
} else { error(); }
} else { error(); }
}
void Varr() { 
if (tk.ID == isTk) {
if (tk.ID == isTK) {
tk = scanner();
Expr();
} else { error(); }
} else { error(); }
}
void Expr() { 
if (tk.ID == exprTK) {
if (tk.ID == exprTK) {
tk = scanner();
} else { error(); }
} else { error(); }
}
void Func() { 
if (tk.ID == takesTk) {
Takes();
Return();
if (tk.ID == doesTK) {
tk = scanner();
Block();
} else { error(); }
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
} else { error(); }
} else { error(); }
} else { error(); }
} else { return; }
}
void Takes() { 
if (tk.ID == takesTK) {
if (tk.ID == takesTK) {
tk = scanner();
Param();
Params();
} else { error(); }
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
} else { error(); }
} else { error(); }
} else { error(); }
} else if (tk.ID == refTK) {
if (tk.ID == refTK) {
tk = scanner();
if (tk.ID == typeTK) {
tk = scanner();
if (tk.ID == idTK) {
tk = scanner();
} else { error(); }
} else { error(); }
} else { error(); }
}  else { error(); }
}
void Params() { 
if (tk.ID == typeTK || tk.ID == refTK) {
Param();
Params();
} else { return; }
}
void Block() { 
if (tk.ID == l_braceTK) {
if (tk.ID == l_braceTK) {
tk = scanner();
Internalstats();
if (tk.ID == r_braceTK) {
tk = scanner();
} else { error(); }
} else { error(); }
} else { error(); }
}
void Internalstats() { 
if (tk.ID == idTK) {
Internalstat();
if (tk.ID == scTK) {
tk = scanner();
Minternalstats();
} else { error(); }
} else { error(); }
}
void Minternalstats() { 
if (tk.ID == idTK) {
Internalstat();
if (tk.ID == scTK) {
tk = scanner();
Minternalstats();
} else { error(); }
} else { return; }
}
void Internalstat() { 
if (tk.ID == idTK) {
if (tk.ID == idTK) {
tk = scanner();
Id();
} else { error(); }
} else { error(); }
}
void ID() { 
if (tk.ID == isTK) {
if (tk.ID == isTK) {
tk = scanner();
Expr();
} else { error(); }
} else if (tk.ID == l_parenTK) {
if (tk.ID == l_parenTK) {
tk = scanner();
Actualparams();
if (tk.ID == r_parenTK) {
tk = scanner();
} else { error(); }
} else { error(); }
}  else { error(); }
}
void Actualparems() { 
if (tk.ID == idTK) {
if (tk.ID == idTK) {
tk = scanner();
Actualparamss();
} else { error(); }
} else { return; }
}
void Actualparamss() { 
if (tk.ID == commaTk) {
if (tk.ID == commaTK) {
tk = scanner();
if (tk.ID == idTK) {
tk = scanner();
Actualparamss();
} else { error(); }
} else { error(); }
} else { return; }
}