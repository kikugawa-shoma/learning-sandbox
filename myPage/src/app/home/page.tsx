import { Header, About, Skills } from "./Components";
import CssBaseline from "@mui/material/CssBaseline";

const Home = () => {
  return (
    <>
      <CssBaseline>
        <Header />
        <About />
        <Skills />
        <div style={{ height: "2000px" }}></div>
      </CssBaseline>
    </>
  );
};

export default Home;
