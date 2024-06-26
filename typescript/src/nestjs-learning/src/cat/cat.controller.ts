import { Controller, Get } from '@nestjs/common';
import { CatsService } from './cat.service';

@Controller('cats')
export class CatsController {
  constructor(private catsService: CatsService) {}

  @Get()
  findAll() {
    return this.catsService.findAll();
  }
}
