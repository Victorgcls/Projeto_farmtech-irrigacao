umidade <- c(35, 40, 38, 30, 45)
dados_farmtech <- data.frame(leitura = 1:length(umidade), valor = umidade)

media_umidade <- mean(dados_farmtech$valor)
limiar_critico <- 40

cat("--- MONITORAMENTO FARMTECH SOLUTIONS ---\n")
cat("Média de Umidade do Solo:", media_umidade, "%\n")

if (media_umidade < limiar_critico) {
  cat("Status: ABAIXO DO LIMIAR\n")
  cat("Recomendação: IRRIGAR\n")
} else {
  cat("Status: UMIDADE ADEQUADA\n")
  cat("Recomendação: NÃO IRRIGAR\n")
}