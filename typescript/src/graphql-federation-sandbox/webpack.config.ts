import { Configuration } from "webpack";
import path from "path";

const config: Configuration = {
  entry: "./src/index.ts",
  mode: "production",
  output: {
    filename: "index.js",
    path: path.resolve(__dirname, "dist"),
  },
  module: {
    rules: [
      {
        test: /\.tsx?$/,
        use: {
          loader: "ts-loader",
          options: {
            configFile: "tsconfig.webpack.json",
          },
        },
        exclude: /node_modules/,
      },
    ],
  },
  resolve: {
    extensions: [".ts", ".js"],
    modules: [path.resolve(__dirname, "src"), "node_modules"],
  },
};

export default config;
