import { Header, About, Skills } from "./Components";
import CssBaseline from "@mui/material/CssBaseline";
import React from "react";
import { UserDefaultThema } from "@/hooks";

const Home = () => {
  return (
    <>
      <UserDefaultThema>
        <CssBaseline />
        <Header />
        <About />
        <Skills />
        <div style={{ height: "2000px" }}></div>
      </UserDefaultThema>
    </>
  );
};

export default Home;
