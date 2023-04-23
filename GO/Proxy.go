package main

import "fmt"

type Usuario interface {
	SolicitarAcesso()
}

type UsuarioReal struct {
	Nome string
}

func (u *UsuarioReal) SolicitarAcesso() {
	fmt.Printf("%s solicitou acesso\n", u.Nome)
}

type ProxyUsuario struct {
	Usuario *UsuarioReal
}

func (pu *ProxyUsuario) SolicitarAcesso() {
	if pu.Usuario == nil {
		pu.Usuario = &UsuarioReal{Nome: "Usuário Real"}
	}
	pu.Usuario.SolicitarAcesso()
}

func main() {
	proxy := &ProxyUsuario{}

	// Aqui ainda não é criado o usuário real
	proxy.SolicitarAcesso()

	// Aqui o usuário real é criado
	proxy.SolicitarAcesso()
}
