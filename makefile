build:
	g++ lanParty.cpp Echipa.cpp Echipa.hpp Player.cpp Player.hpp Lista.cpp Lista.hpp utilis.hpp utilis.cpp nod.hpp nod.cpp Coada.cpp Coada.hpp Stiva.cpp Stiva.hpp BTS.hpp BTS.cpp -o lanParty
run:
	./lanParty c.in d.in r.out
clean:
	rm lanParty
