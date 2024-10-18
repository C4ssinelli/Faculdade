USE Trabalho;


/*INSERT INTO VENDEDOR (Estado_Residência, Crédito, Data_Registro, Senha, Apelido, Quantidade_Vendas)
VALUES ("SP", 0.00, current_date(), 12345, "Pingu", 0);

INSERT INTO VENDEDOR (Estado_Residência, Crédito, Data_Registro, Senha, Apelido, Quantidade_Vendas)
VALUES ("GO", 120.00, current_date(), 45678, "Baiano", 20);*/

INSERT INTO CLIENTE (Data_Registro, Senha, Crédito, Estado_Residência, Apelido)
VALUES(current_date(), 147258, 0.50, "RJ", "Nikocado");

INSERT INTO CLIENTE (Data_Registro, Senha, Crédito, Estado_Residência, Apelido)
VALUES(current_date(), 963852, 50.50, "MT", "Avocado");

INSERT INTO PRODUTO 
	SET idVendedor = (
			SELECT idVendedor
            FROM VENDEDOR
            WHERE idVendedor = 1),
		Calibre = ".50",
		Preço = 10.5,
		Peso = 10,
		Nome = "HTI";

INSERT INTO PRODUTO 
	SET idVendedor = (
			SELECT idVendedor
            FROM VENDEDOR
            WHERE idVendedor = 1),
		Calibre = ".44",
		Preço = 105.5,
		Peso = 0.5,
		Nome = "Desert";

INSERT INTO PRODUTO 
	SET idVendedor = (
			SELECT idVendedor
            FROM VENDEDOR
            WHERE idVendedor = 1),
		Calibre = ".38",
		Preço = 10.50,
		Peso = 0.1,
		Nome = "Balas .38";

INSERT INTO ARMA 
	SET idProduto = (
			SELECT idProduto
            FROM PRODUTO
            WHERE idProduto = "1"),
		Tipo_de_Arma = "Rifle", 
		Tipo_de_Ação = "Alavanca", 
        Balas_Carregador = 5, 
        Ano = 2015, 
        Alcance = 1.5;

INSERT INTO ARMA 
	SET idProduto = (
			SELECT idProduto
            FROM PRODUTO
            WHERE idProduto = "2"),
		Tipo_de_Arma = "Pistola", 
		Tipo_de_Ação = "Semi", 
        Balas_Carregador = 12, 
        Ano = 2002, 
        Alcance = 0.2;

INSERT INTO MUNIÇÃO 
	SET idProduto = (
			SELECT idProduto
            FROM PRODUTO
            WHERE idProduto = "1"),
		Quantidade_Caixa = 50,
		Fabricante = "Winchester P.C.";

INSERT INTO MODIFICAÇÕES 
	SET idMunição = (
			SELECT idMunição
            FROM MUNIÇÃO
            WHERE idMunição = "1"),
		Nome = "Explosiva";
        
INSERT INTO MODIFICAÇÕES 
	SET idMunição = (
			SELECT idMunição
            FROM MUNIÇÃO
            WHERE idMunição = "1"),
		Nome = "Incendiária";

INSERT INTO ESTOQUE 
	SET idProduto = (
			SELECT idProduto
            FROM PRODUTO
            WHERE idProduto = "1"),
		Quantidade = 15,
		Lote = 1520;
        
INSERT INTO ESTOQUE 
	SET idProduto = (
			SELECT idProduto
            FROM PRODUTO
            WHERE idProduto = "2"),
		Quantidade = 25,
		Lote = 1521;

INSERT INTO PRODUTOS_OPERAÇÃO 
	SET idProduto = (
			SELECT idProduto
            FROM PRODUTO
            WHERE idProduto = "1");
            
INSERT INTO PRODUTOS_OPERAÇÃO 
	SET idProduto = (
			SELECT idProduto
            FROM PRODUTO
            WHERE idProduto = "2");

INSERT INTO OPERAÇÃO 
	SET idProdutos_Operação = (
			SELECT idProdutos_Operação
            FROM PRODUTOS_OPERAÇÃO
            WHERE idProdutos_Operação = 2),
		Preço_Produto = (
			SELECT P.Preço_com_Taxa
            FROM PRODUTO AS P JOIN PRODUTOS_OPERAÇÃO AS O ON
				(O.IdProdutos_Operação = 2) AND (O.idProduto = P.IdProduto)),
		Frete = 15.50;
        
INSERT INTO OPERAÇÃO 
	SET idProdutos_Operação = (
			SELECT idProdutos_Operação
            FROM PRODUTOS_OPERAÇÃO
            WHERE idProdutos_Operação = 1),
		Preço_Produto = (
			SELECT P.Preço_com_Taxa
            FROM PRODUTO AS P JOIN PRODUTOS_OPERAÇÃO AS O ON
				(O.IdProdutos_Operação = 1) AND (O.idProduto = P.IdProduto)),
		Frete = 10;
        


INSERT INTO COMPRA 
	SET idOperação = (
			SELECT idOperação
            FROM OPERAÇÃO
            WHERE idOperação = 1),
		idVendedor = 1,
		Local_Retirada = (
			SELECT Estado_Residência
            FROM VENDEDOR
            WHERE idVendedor = 1),
		Meio_Pagamento = "Bitcoin";
	
INSERT INTO COMPRA 
	SET idOperação = (
			SELECT idOperação
            FROM OPERAÇÃO
            WHERE idOperação = 2),
		idVendedor = 1,
		Local_Retirada = (
			SELECT Estado_Residência
            FROM VENDEDOR
            WHERE idVendedor = 1),
		Meio_Pagamento = "Bitcoin";
        


INSERT INTO VENDA 
	SET idOperação = (
			SELECT idOperação
            FROM OPERAÇÃO
            WHERE idOperação = 1),
		idCliente = 1,
		Local_Entrega = (
			SELECT Estado_Residência
            FROM CLIENTE
            WHERE idCliente = 1);
            
INSERT INTO VENDA 
	SET idOperação = (
			SELECT idOperação
            FROM OPERAÇÃO
            WHERE idOperação = 2),
		idCliente = 1,
		Local_Entrega = (
			SELECT Estado_Residência
            FROM CLIENTE
            WHERE idCliente = 1);

INSERT INTO AVALIAÇÃO
	SET idVendedor = 1,
		Nota = 10,
        Comentário = "Horrível, nota 10";
        
INSERT INTO AVALIAÇÃO
	SET idVendedor = 1,
		Nota = 3,
        Comentário = "Entrega veio sem algumas balas";
        
UPDATE ESTOQUE
SET Quantidade = 9
WHERE idProduto = 1;

UPDATE ESTOQUE
SET Quantidade = 25
WHERE idProduto = 1;

SELECT *
FROM VENDEDOR;        

SELECT *
FROM CLIENTE;

SELECT *
FROM PRODUTO;

SELECT *
FROM ARMA;

SELECT *
FROM MODIFICAÇÕES;

SELECT *
FROM ESTOQUE;

SELECT *
FROM MUNIÇÃO;

SELECT *
FROM PRODUTOS_OPERAÇÃO;

SELECT *
FROM OPERAÇÃO;

SELECT *
FROM COMPRA;

SELECT *
FROM VENDA;

SELECT *
FROM AVALIAÇÃO;

SELECT V.apelido, C.Local_Retirada
FROM VENDEDOR AS V JOIN COMPRA AS C ON
	(V.idVendedor = C.idVendedor);
    
SELECT C.apelido, V.Local_Entrega
FROM VENDA AS V JOIN CLIENTE AS C ON
	(V.idCliente = C.idCliente);
    
SELECT CL.apelido, VR.apelido
FROM COMPRA AS C JOIN VENDA AS V ON
	(C.idOperação = V.idOperação) JOIN
    CLIENTE AS CL ON
    (V.idCliente = CL.idCliente) JOIN
    VENDEDOR AS VR ON
    (C.idVendedor = VR.idVendedor);
    
SELECT A.nota, V.Apelido, A.Comentário
FROM VENDEDOR AS V JOIN AVALIAÇÃO AS A ON
	(V.idVendedor = A.idVendedor);
    
SELECT P.Nome, A.Tipo_de_Arma, A.Ano, E.Quantidade
FROM PRODUTO AS P JOIN ARMA AS A ON
	(P.idProduto = A.idProduto) JOIN
    ESTOQUE AS E ON
	(P.idProduto = E.idProduto);