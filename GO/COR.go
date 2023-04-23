package main

import "fmt"

type Pedido struct {
	Numero int
	Valor  float64
}

type Aprovador interface {
	SetProximo(aprovador Aprovador)
	Aprovar(pedido Pedido) bool
}

type AprovadorBase struct {
	proximo Aprovador
}

func (a *AprovadorBase) SetProximo(aprovador Aprovador) {
	a.proximo = aprovador
}

type Diretor struct {
	AprovadorBase
}

func (d *Diretor) Aprovar(pedido Pedido) bool {
	if pedido.Valor < 10000 {
		fmt.Println("O diretor aprovou o pedido:", pedido.Numero)
		return true
	}
	if d.proximo != nil {
		return d.proximo.Aprovar(pedido)
	}
	return false
}

type Gerente struct {
	AprovadorBase
}

func (g *Gerente) Aprovar(pedido Pedido) bool {
	if pedido.Valor < 1000 {
		fmt.Println("O gerente aprovou o pedido:", pedido.Numero)
		return true
	}
	if g.proximo != nil {
		return g.proximo.Aprovar(pedido)
	}
	return false
}

type Funcionario struct {
	AprovadorBase
}

func (f *Funcionario) Aprovar(pedido Pedido) bool {
	fmt.Println("O funcionário aprovou o pedido:", pedido.Numero)
	return true
}

func main() {
	funcionario := &Funcionario{}
	gerente := &Gerente{}
	diretor := &Diretor{}

	funcionario.SetProximo(gerente)
	gerente.SetProximo(diretor)

	pedido1 := Pedido{Numero: 1, Valor: 500}
	pedido2 := Pedido{Numero: 2, Valor: 5000}
	pedido3 := Pedido{Numero: 3, Valor: 15000}

	funcionario.Aprovar(pedido1)
	funcionario.Aprovar(pedido2)
	funcionario.Aprovar(pedido3)
}
