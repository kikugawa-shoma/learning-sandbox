import type { Config } from "jest";
// import { defaults } from "jest-config";

const config: Config = {
  transform: {
    "\\.[jt]sx?$": ["ts-jest", { useESM: true }],
  },
  moduleDirectories: ["node_modules", "src"],
};

export default config;
