'use strict';

const util = require('util');
const common = require('../common');

const inputs = {
  'string': ['Hello, my name is %s', 'Fred'],
  'string-2': ['Hello, %s is my name', 'Fred'],
  'number': ['Hi, I was born in %d', 1989],
  'replace-object': ['An error occurred %j', { msg: 'This is an error' }],
  'unknown': ['hello %a', 'test'],
  'no-replace': [1, 2],
  'no-replace-2': ['foobar', 'yeah', 'mensch', 5],
  'only-objects': [{ msg: 'This is an error' }, { msg: 'This is an error' }],
  'many-%': ['replace%%%%s%%%%many%s%s%s', 'percent'],
  'object-to-string': ['foo %s bar', { toString() { return 'bla'; } }],
  'object-%s': ['foo %s bar', { a: true, b: false }],
};

const bench = common.createBenchmark(main, {
  n: [1e5],
  type: Object.keys(inputs)
});

function main({ n, type }) {
  // For testing, if supplied with an empty type, default to string.
  const [first, second] = inputs[type || 'string'];

  bench.start();
  for (let i = 0; i < n; i++) {
    util.format(first, second);
  }
  bench.end(n);
}