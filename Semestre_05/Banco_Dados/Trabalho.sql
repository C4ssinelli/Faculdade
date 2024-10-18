CREATE DATABASE Trabalho;

USE Trabalho;

CREATE TABLE PRODUTO
(
	idProduto				smallint		not NULL		AUTO_INCREMENT,
    idVendedor				smallint		not NULL,
    Calibre					VARCHAR(45),
    Preço					FLOAT,
    Peso					FLOAT,
	Nome					VARCHAR(45),
    Preço_com_Taxa			FLOAT,
    PRIMARY KEY(idProduto)
);

CREATE TABLE ARMA
(
	idArma					smallint		not NULL		AUTO_INCREMENT,
    idProduto				smallint		not NULL,
    Tipo_de_Arma			VARCHAR(45),
    Tipo_de_Ação 			VARCHAR(45),
    Balas_Carregador		VARCHAR(45),
    Ano						INT,
    Alcance					bigint,
    PRIMARY KEY(idArma),
    FOREIGN KEY(idProduto) REFERENCES PRODUTO(idProduto)
);

CREATE TABLE MUNIÇÃO
(
	idMunição				smallint		not NULL		AUTO_INCREMENT,
    idProduto				smallint		not NULL,
    Quantidade_Caixa	 	INT,
    Fabricante				VARCHAR(45),
    PRIMARY KEY(idMunição),
    FOREIGN KEY(idProduto) REFERENCES PRODUTO(idProduto)
);

CREATE TABLE MODIFICAÇÕES
(
	idModificação			smallint		not NULL		AUTO_INCREMENT,
    idMunição				smallint		not NULL,
    Nome					VARCHAR(45),
    PRIMARY KEY(idModificação),
    FOREIGN KEY(idMunição) REFERENCES MUNIÇÃO(idMunição)
);

CREATE TABLE ESTOQUE
(
	idEstoque				smallint		not NULL		AUTO_INCREMENT,
    idProduto				smallint		not NULL,
    Quantidade				INT,
    Lote					INT,
    Aviso					TINYINT,
    PRIMARY KEY(idEstoque),
    FOREIGN KEY(idProduto) REFERENCES PRODUTO(idProduto)
);

CREATE TABLE PRODUTOS_OPERAÇÃO
(
	idProdutos_Operação		smallint		not NULL		AUTO_INCREMENT,
    idProduto				smallint		not NULL,
    PRIMARY KEY(idProdutos_Operação),
    FOREIGN KEY(idProduto) REFERENCES PRODUTO(idProduto)
);

CREATE TABLE OPERAÇÃO
(
	idOperação				smallint		not NULL		AUTO_INCREMENT,
    idProdutos_Operação		smallint		not NULL,
    Preço_Produto			FLOAT,
    Frete					FLOAT,
    PRIMARY KEY(idOperação),
    FOREIGN KEY(idProdutos_Operação) REFERENCES PRODUTOS_OPERAÇÃO(idProdutos_Operação)
);

CREATE TABLE VENDEDOR
(
	idVendedor				smallint		not NULL		AUTO_INCREMENT,
    Estado_Residência		VARCHAR(3),
    Crédito					FLOAT,
    Data_Registro			DATE,
    Senha					VARCHAR(45),
    Apelido					VARCHAR(45),
    Quantidade_Vendas		INT,
    Aviso					TINYINT,
    PRIMARY KEY(idVendedor)
);

ALTER TABLE ESTOQUE ALTER COLUMN Aviso SET DEFAULT 0;

CREATE TABLE COMPRA
(
	idCompra				smallint		not NULL		AUTO_INCREMENT,
    idOperação				smallint		not NULL,
    idVendedor				smallint		not NULL,
    Local_Retirada			VARCHAR(45),
    Meio_Pagamento			VARCHAR(45),
    PRIMARY KEY(idCompra),
    FOREIGN KEY(idOperação) REFERENCES OPERAÇÃO(idOperação),
    FOREIGN KEY(idVendedor) REFERENCES VENDEDOR(idVendedor)
);

CREATE TABLE CLIENTE
(
	idCliente				smallint		not NULL		AUTO_INCREMENT,
    Data_Registro			DATE,
    Senha					VARCHAR(45),
    Crédito					FLOAT,
    Estado_Residência		VARCHAR(3),
    Apelido					VARCHAR(45),
    PRIMARY KEY(idCliente)
);

CREATE TABLE VENDA
(
	idVenda					smallint		not NULL		AUTO_INCREMENT,
    idOperação				smallint		not NULL,
    idCliente				smallint		not NULL,
    Local_Entrega			VARCHAR(45),
    Confirmação_Pagamento	TINYINT,
    PRIMARY KEY(idVenda),
    FOREIGN KEY(idOperação) REFERENCES OPERAÇÃO(idOperação),
    FOREIGN KEY(idCliente) REFERENCES CLIENTE(idCliente)
);

CREATE TABLE AVALIAÇÃO
(
	idAvaliação				smallint		not NULL		AUTO_INCREMENT,
    idVendedor				smallint		not NULL,
    idCliente				smallint,
    Nota					FLOAT,
    Comentário				VARCHAR(45),
    PRIMARY KEY(idAvaliação),
    FOREIGN KEY(idVendedor) REFERENCES VENDEDOR(idVendedor),
    FOREIGN KEY(idCliente) REFERENCES CLIENTE(idCliente)
);

-- DROP DATABASE Trabalho;