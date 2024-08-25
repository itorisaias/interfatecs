const helper = require('./help');

const args = process.argv.slice(2); 

if (args.length === 0) {
  console.error("Nenhum parâmetro fornecido.\nUse 'node index.js <ano> ?<fase>' para gerar os problemas.");
  return 1;
} 

const year = args[0];
const phase = args[1] || null;
const falied = [];

(async () => {
  const problems = await helper.getProblemList({ year, phase })

  for (const problem of problems) {
    const basename = await helper.extractBaseName(problem.pdf);

    if (!basename) {
      console.error('Error:', problem.letter);
      continue;
    }

    try {
      helper.build({
        basename: basename,
        fullname: `Interfatecs - ${year} - ${problem.letter} (${basename})`,
        timelimit: 10,
        probleminput: problem.input,
        problemsol: problem.output,
        problemdesc: problem.pdf,
         download: problem.download
      });
    } catch (error) {
      console.error('Error:', error, problem.letter);
      falied.push(problem.letter);
    }
  }

  if (falied.length > 0) {
    console.error('Problemas que falharam:', falied);
  }
})()
