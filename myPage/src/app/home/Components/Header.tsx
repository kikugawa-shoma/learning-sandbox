import AppBar from "@mui/material/AppBar";
import HomeIcon from "@mui/icons-material/Home";
import { GitHub } from "@mui/icons-material";
import { Button, IconButton, Toolbar } from "@mui/material";
import Box from "@mui/material/Box";
import styles from "./Header.module.css";
import MenuIcon from "@mui/icons-material/Menu";

export const Header = () => {
  return (
    <>
      <Box>
        <AppBar>
          <Toolbar>
            <IconButton href="/home">
              <HomeIcon fontSize="large"></HomeIcon>
            </IconButton>
            <div className={styles.headerSpace}></div>
            <IconButton href="https://github.com/kikugawa-shoma/">
              <GitHub sx={{ mr: 3 }} fontSize="large"></GitHub>
            </IconButton>
            <IconButton>
              <MenuIcon fontSize="large"></MenuIcon>
            </IconButton>
          </Toolbar>
        </AppBar>
      </Box>
      <div className={styles.headerInit}></div>
    </>
  );
};
