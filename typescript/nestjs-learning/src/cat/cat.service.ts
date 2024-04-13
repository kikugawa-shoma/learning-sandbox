import { Injectable } from '@nestjs/common';

type Cat = {
  name: string;
};

const allCats: Cat[] = [
  {
    name: 'tama',
  },
  {
    name: 'pochi',
  },
];

@Injectable()
export class CatsService {
  findAll = () => {
    return allCats;
  };
}
