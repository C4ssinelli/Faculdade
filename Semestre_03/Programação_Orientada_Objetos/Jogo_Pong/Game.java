// Nomes: Alex Luiz Domingues Cassinelli
// 	      Kaio Henrique Avelino Domeni de Paulo

// RA: 211021849
// 	   211021016

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Game extends JFrame{
	private static final long serialVersionUID = 1L;

	Menu_Principal principal;
	int gWidth = 500;
	int gHeight = 400;
	Dimension screenSize = new Dimension(gWidth, gHeight);

	Image dbImage;
	Graphics dbGraphics;

	static boolean jogo = true;
	boolean gameOver;

	static Bola b = new Bola(250, 200);

	String j1 = JOptionPane.showInputDialog("Digite o apelido, jogador 1:");
	String j2 = JOptionPane.showInputDialog("Digite o apelido, jogador 2:");

	public Game(Menu_Principal princ) {
		principal = princ;
		this.setTitle("Ping!");
		this.setSize(screenSize);
		this.setResizable(false);
		this.setVisible(true);
		this.setBackground(Color.DARK_GRAY);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.addKeyListener(new AL());

		Thread bola = new Thread(b);
		bola.start();
		Thread p1 = new Thread(b.jogador1);
		Thread p2 = new Thread(b.jogador2);
		p2.start();
		p1.start();
	}

	@Override
	public void paint(Graphics g) {
		dbImage = createImage(getWidth(), getHeight());
		dbGraphics = dbImage.getGraphics();
		draw(dbGraphics);
		g.drawImage(dbImage, 0, 0, this);
	}

	public void draw(Graphics g) {
		b.draw(g);
		b.jogador1.draw(g);
		b.jogador2.draw(g);
		getScore(g);
		repaint();
	}

	private void getScore(Graphics g) {
		g.setColor(Color.WHITE);
		g.drawString(j1 + " " + b.pontuacaoJogador1, 40, 40);
		g.drawString(j2 + " " + b.pontuacaoJogador2, 385, 40);
		g.setColor(Color.WHITE);
		if (b.pontuacaoJogador1 >= 5 || b.pontuacaoJogador2 >= 5) {
			setJogo(false);
			gameOver = true;
		}
		if (gameOver)
			g.drawString("Game Over", 200, 200);
		g.setColor(Color.WHITE);
	}

	public class AL extends KeyAdapter {
		@Override
		public void keyPressed(KeyEvent e) {
			b.jogador1.keyPressed(e);
			b.jogador2.keyPressed(e);
		}

		@Override
		public void keyReleased(KeyEvent e) {
			b.jogador1.keyReleased(e);
			b.jogador2.keyReleased(e);
		}

	}

	public static boolean isJogo() {
		return jogo;
	}

	public boolean isGameOver() {
		return gameOver;
	}

	public static void setJogo(boolean jogo) {
		Game.jogo = jogo;
	}
}

class Menu_Principal extends JFrame{

    JButton Iniciar = new JButton("Iniciar Jogo");
    JButton Ajuda = new JButton("Ajuda");
    JButton Sair = new JButton("Sair do Jogo");
    JPanel Painel_01 = new JPanel(new FlowLayout());
    JLabel Mensagem_01 = new JLabel("Insira seu apelido, Jogador 1: ");
    JLabel Mensagem_02 = new JLabel("Insira seu apelido, Jogador 2: ");
    JTextField Nome_Jogador_01 = new JTextField(20);
    JTextField Nome_Jogador_02 = new JTextField(20);
    JPanel Painel_02 = new JPanel(new FlowLayout());
    JPanel Painel_03 = new JPanel(new FlowLayout());
    JPanel Painel_04 = new JPanel(new GridLayout(2, 1));
    JPanel Painel_Final = new JPanel(new BorderLayout());
	Menu_Principal este = this;

    Menu_Principal() {

        super("Ping! Bem-Vindo!");
        Iniciar.setBackground(Color.BLACK);
        Iniciar.setForeground(Color.WHITE);
        Painel_01.add(Iniciar);
        Ajuda.setBackground(Color.BLACK);
        Ajuda.setForeground(Color.WHITE);
        Painel_01.add(Ajuda);
        Sair.setBackground(Color.BLACK);
        Sair.setForeground(Color.WHITE);
        Painel_01.add(Sair);
        Painel_02.add(Mensagem_01);
        Painel_02.add(Nome_Jogador_01);
        Painel_03.add(Mensagem_02);
        Painel_03.add(Nome_Jogador_02);
        Painel_04.add(Painel_02);
        Painel_04.add(Painel_03);
        Painel_Final.add(Painel_04, BorderLayout.CENTER);
        Painel_Final.add(Painel_01, BorderLayout.SOUTH);
        add(Painel_Final);

        Iniciar.addActionListener(new ActionListener(){

            public void actionPerformed(ActionEvent e){
                Game jogo = new Game(este);
            }
        });

        Ajuda.addActionListener(new ActionListener() {

            JPanel Painel_Auxiliar;

            public void actionPerformed(ActionEvent e){
                JOptionPane.showMessageDialog(Painel_Auxiliar, 
                                              "Jogador 1: Use as teclas 'W' e 'S'\nJogador 2: Use as setas 'CIMA' e 'BAIXO'\nO jogo acaba quando alguém atingir 5 pontos.\nBoa Sorte!\n", 
                                              "Ajuda", 
                                              JOptionPane.INFORMATION_MESSAGE);
            }
        });

        Sair.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                System.exit(0);
            }
        });

        pack();
        setVisible(true);
        setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
    }
}

class PP{
    public static void main(String[] args)
    {
        new Menu_Principal();
    }
}