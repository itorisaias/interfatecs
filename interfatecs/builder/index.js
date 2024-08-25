const fsPromises = require('fs/promises');
const path = require('path');
const help = require('./help');
const pdfParse = require('pdf-parse');

const { build, resolvePath } = help;

const year = '2016';
const phase = null;

(async () => {
  const allFiles = await fsPromises.readdir(path.resolve(__dirname, '..', year))
  const problems = allFiles
    .filter(file => file.endsWith('.pdf') && file.length <= 5)
    .map(file => file.replace('.pdf', ''))
    .map(problem => ({ ...resolvePath({ year, problem }), letter: problem }));

  for (const problem of problems) {
    const pdfBuffer = await fsPromises.readFile(problem.pdf);
    const data = await pdfParse(pdfBuffer);
    const basename = data.text.match(/(Arquivo fonte:|Source file:)\s*(.*)\./);

    if (!basename) {
      console.error('Error:', problem.letter);
      continue;
    }

    const config = {
      basename: basename[2],
      fullname: `Interfatecs - ${year} - ${problem.letter} (${basename[2]})`,
      timelimit: 10,
      probleminput: problem.input,
      problemsol: problem.output,
      problemdesc: problem.pdf,
       download: problem.download
    };

    build(config);
  }
})()
