import { pandas } from "./data";
import { ApolloServer } from "@apollo/server";
import { expressMiddleware } from "@apollo/server/express4";
import { readFileSync } from "fs";
import { fileURLToPath } from "url";
import path from "path";
import express from "express";
import http from "http";
import cors from "cors";

const __filename = fileURLToPath(import.meta.url);

const __dirname = path.dirname(__filename);

const port = 4000;

const typeDefs = readFileSync(__dirname + "/product.graphql", {
  encoding: "utf-8",
});
const resolvers = {
  Query: {
    allPandas: (_, args, context) => {
      return pandas;
    },
    panda: (_, args, context) => {
      return pandas.find((p) => p.name == args.name);
    },
  },
};

export const server = new ApolloServer({ typeDefs, resolvers });

// await server.start();

// const app = express();
// const httpServer = http.createServer(app);

// app.use(
//   "/",
//   cors<cors.CorsRequest>(),
//   express.json(),
//   expressMiddleware(server)
// );

// // Modified server startup
// (async () => {
//   await new Promise<void>((resolve) =>
//     httpServer.listen({ port: 4000 }, resolve)
//   );
//   console.log(`🚀 Server ready at http://localhost:4000/`);
// })();
