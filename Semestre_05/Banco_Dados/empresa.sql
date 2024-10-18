CREATE DATABASE empresa;
USE empresa;

CREATE TABLE funcionarios(
	cod						smallint,
    p_nome					VARCHAR(20),
	s_nome					VARCHAR(20),
    dt_nsct					DATE,
    CPF						VARCHAR(10),
	RG						VARCHAR(10),
    ender					VARCHAR(10),
	CEP						VARCHAR(10),
    cidade					VARCHAR(10),
    fone					VARCHAR(10),
    funcao					VARCHAR(20),
	salario					float,
    cod_dep					smallint,
    PRIMARY KEY(cod)
);

CREATE TABLE departamentos(
	cod						smallint,
    nome					VARCHAR(20),
    loc						VARCHAR(20),
    cod_ger					smallint,
    PRIMARY KEY(cod),
    FOREIGN KEY(cod_ger)	REFERENCES funcionarios(cod)
);

ALTER TABLE funcionarios ADD CONSTRAINT cod_dep
FOREIGN KEY (cod_dep) REFERENCES departamentos(cod);

DROP TABLE funcionarios;

INSERT INTO funcionarios
	SET cod = '3',
		p_nome = 'vini',
        s_nome = 'garcia',
		dt_nsct	= '2002-06-01',
		CPF	= '12347',
		RG = '98763',
		ender = 'eaq',
		CEP	= '123372',
		cidade = 'Sao Paulo',
		fone = '123',
		funcao = 'policia',
		salario = '50.00';

INSERT INTO departamentos
	SET cod = '2',
		nome = 'ca',
        loc = 'botucatu',
		cod_ger = (
			SELECT cod
            FROM funcionarios
			WHERE cod = '1'
        );

UPDATE funcionarios
SET cod_dep = '2'
WHERE cod = '3';