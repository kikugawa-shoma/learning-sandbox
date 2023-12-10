import List from "@mui/material/List";
import ListItem from "@mui/material/ListItem";
import ListItemText from "@mui/material/ListItemText";
import ListItemAvatar from "@mui/material/ListItemAvatar";
import Avatar from "@mui/material/Avatar";
import React from "react";
import { Build } from "@mui/icons-material";

export const Skills = () => {
  return (
    <>
      <h2 style={{ textAlign: "center" }}>Skills</h2>
      <List sx={{ width: "100%", bgcolor: "background.paper" }}>
        {skillDataElements.map((skillDataElement) => {
          return (
            <SkillItem {...skillDataElement} key={skillDataElement.title} />
          );
        })}
      </List>
    </>
  );
};

type SkillItemProp = {
  icon: string | React.ReactElement;
  title: string;
  description: string;
};

const SkillItem = ({ icon, title, description }: SkillItemProp) => {
  return (
    <ListItem>
      <ListItemAvatar>
        {typeof icon === "string" ? (
          <Avatar src={icon}></Avatar>
        ) : (
          <Avatar>{icon}</Avatar>
        )}
      </ListItemAvatar>
      <ListItemText primary={title} secondary={description} />
    </ListItem>
  );
};

const skillDataElements: SkillItemProp[] = [
  {
    icon: "/nodejs-3.svg",
    title: "Node.js/TypeScript/JavaScript",
    description:
      "業務で2年ほど使用しています。下記のGraphQLを使ったBackend for frontendのサーバーとNext.jsのfrontendのサーバーをNode.jsを使用して開発していました。今最も書き慣れている言語です。",
  },
  {
    icon: "/graphql-logo-2.svg",
    title: "GraphQL(Apollo)",
    description:
      "業務で2年ほど使用しておりました。社内でGraphQLの採用実績のない中でGraphQLサーバーを構築・開発・運用し、PoCとして技術検証と社内への水平展開を担当しました。",
  },
  {
    icon: "/docker-4.svg",
    title: "Docker/Docker Compose",
    description:
      "DockerとDocker Composeの概念とコマンド体系を理解し、使用できます。ローカル環境でフロントエンドアプリケーションコンテナ、バックエンドAPIコンテナ、DBコンテナの構成の開発環境を独力で構築することができます。",
  },
  {
    icon: "/python-logo-only.svg",
    title: "Python",
    description:
      "業務で1年と、大学学部・大学院時代に研究と趣味の競技プログラミングで使用していました。flaskを使って簡単なwebアプリケーションを書いたこともあります。",
  },
  {
    icon: "/next-js.svg",
    title: "Next.js/React",
    description:
      "業務で半年程と趣味で学習を進めています(バージョンアップが早いのでキャッチアップが大変。。。)。このポートフォリオサイトもNext.jsを使用して作成しています。",
  },
  {
    icon: "/c.svg",
    title: "C++",
    description:
      "大学学部時代に講義でC++を使う講義を受講し、プログラミングに興味を持つきっかけとなった言語です。大学学部・大学院時代に趣味の競技プログラミングで使用してました。大学院の受業でフルスクラッチでニューラルネットワークを書く課題があり、言語は自由だったのでC++を選択し、MNISTの手書き文字認識プログラムを実装した経験があります。",
  },
  {
    icon: "/jenkins-1.svg",
    title: "Jenkins",
    description:
      "CI/CD ジョブの作成のため業務で使用しました。自動テストの実行と、リリース時のデプロイイメージのビルド・イメージレジストリへのプッシュを行うジョブを作成した経験があります。",
  },
  {
    icon: "/github-icon-1.svg",
    title: "GitHub Actions",
    description:
      "CI/CD workflowの作成のため業務で使用しました。自動テストの実行と、リリース時のデプロイイメージのビルド・イメージレジストリへのプッシュを行うworkflowを作成した経験があります。",
  },
  {
    icon: <Build></Build>,
    title: "MATLAB",
    description: "大学院時代に研究で使用していました。",
  },
];
