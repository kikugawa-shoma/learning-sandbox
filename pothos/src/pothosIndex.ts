import { createYoga } from "graphql-yoga";
import { createServer } from "node:http";
import SchemaBuilder from "@pothos/core";

const builder = new SchemaBuilder({});

builder.queryType({
  fields: (t) => ({
    hello: t.string({
      args: {
        name: t.arg.string(),
      },
      resolve: (_, { name }) => `hello, ${name || "World"}`,
    }),
  }),
});

builder.toSchema();

const yoga = createYoga({
  schema: builder.toSchema(),
});

const server = createServer(yoga);

server.listen(3000);
