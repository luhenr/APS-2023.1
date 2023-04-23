package main

import "fmt"

type Carro struct {
	Marca  string
	Modelo string
	Motor  string
	Cor    string
}

type ConstrutorCarro interface {
	DefinirMarca(marca string) ConstrutorCarro
	DefinirModelo(modelo string) ConstrutorCarro
	DefinirMotor(motor string) ConstrutorCarro
	DefinirCor(cor string) ConstrutorCarro
	Construir() Carro
}

type ConstrutorCarroPadrao struct {
	carro Carro
}

func (ccp *ConstrutorCarroPadrao) DefinirMarca(marca string) ConstrutorCarro {
	ccp.carro.Marca = marca
	return ccp
}

func (ccp *ConstrutorCarroPadrao) DefinirModelo(modelo string) ConstrutorCarro {
	ccp.carro.Modelo = modelo
	return ccp
}

func (ccp *ConstrutorCarroPadrao) DefinirMotor(motor string) ConstrutorCarro {
	ccp.carro.Motor = motor
	return ccp
}

func (ccp *ConstrutorCarroPadrao) DefinirCor(cor string) ConstrutorCarro {
	ccp.carro.Cor = cor
	return ccp
}

func (ccp *ConstrutorCarroPadrao) Construir() Carro {
	return ccp.carro
}

func main() {
	construtor := &ConstrutorCarroPadrao{}
	carro := construtor.
		DefinirMarca("Toyota").
		DefinirModelo("Corolla").
		DefinirMotor("2.0").
		DefinirCor("Branco").
		Construir()

	fmt.Printf("%+v", carro)
}
