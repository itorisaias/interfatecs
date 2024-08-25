const helper = require('./help');

if (args.length === 0) {
  console.log("Nenhum parâmetro fornecido. Use 'node index.js <ano> ?<fase>' para gerar os problemas.");
} 

const year = args[0];
const phase = args[1] || null;

(async () => {
  const problems = await helper.getProblemList({ year, phase })

  for (const problem of problems) {
    const basename = await helper.extractBaseName(problem.pdf);

    if (!basename) {
      console.error('Error:', problem.letter);
      continue;
    }

    build({
      basename: basename,
      fullname: `Interfatecs - ${year} - ${problem.letter} (${basename})`,
      timelimit: 10,
      probleminput: problem.input,
      problemsol: problem.output,
      problemdesc: problem.pdf,
       download: problem.download
    });
  }
})()
