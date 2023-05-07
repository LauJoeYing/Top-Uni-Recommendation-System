Why all struct outside class?
So we can easily delete all memory when we exit system, and also easier to reference.


In case of the use of extern, the way to use it is one normal declaration and multiple "extern" declaration.


Actually, why not put only UI and inaccessible method in public, other put in private, eg. deleteuseraccount is called in AdminMenu(), no other class or function use it even in public.


!!!Favourite is not included yet....!!!